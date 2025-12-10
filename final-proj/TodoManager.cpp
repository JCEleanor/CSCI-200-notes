#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm> // For std::sort in loadFromFile
#include <limits>    // For std::numeric_limits in updateTask

#include "TodoManager.h"

TodoManager::TodoManager(const std::string &filename)
{
    _filename = filename;
}

time_t TodoManager::_string_to_time_t(const std::string &date_str)
{
    // Initialize tm struct to all zeros
    std::tm t{};

    //  strptime to parse the string into the tm struct
    if (strptime(date_str.c_str(), "%Y-%m-%d", &t) == nullptr)
    {
        std::cerr << "Error parsing date string: " << date_str << std::endl;
        return static_cast<time_t>(-1); // TODO: error handling
    }
    return mktime(&t);
}

Task *TodoManager::_findTaskById(const int id)
{
    for (size_t i = 0; i < _tasks.size(); i++)
    {
        if (_tasks[i].getId() == id)
        {
            return &_tasks[i];
        }
    }

    return nullptr;
}

// a single source of truth for saving to the CSV
void TodoManager::_saveToFile()
{
    std::ofstream fout(_filename); // Opens in write mode, overwriting the file
    if (!fout.is_open())
    {
        std::cerr << "Error: Could not open file " << _filename << " for saving." << std::endl;
        return;
    }

    // Write header
    fout << "id,description,priority,isCompleted,dueDate,createdDate,lastModified" << std::endl;

    // Write all tasks from the vector
    for (const auto &task : _tasks)
    {
        fout << task.getId() << ",\"" << task.getDescription() << "\"," << task.getPriority() << ","
             << (task.getIsCompleted() ? "1" : "0") << "," << task.getDueDate() << ","
             << task.getCreatedDate() << "," << task.getLastModified() << std::endl;
    }
    fout.close();
}

bool TodoManager::loadFromFile()
{
    std::ifstream fin(_filename);
    if (!fin.is_open())
    {
        std::cerr << "Error: Could not open file " << this->_filename << std::endl;
        return false;
    }

    // parse the file to save it into vector
    /**
     * @brief
     *
     * id,description,priority,isCompleted,dueDate,createdDate,lastModified
        1,Buy groceries,3,0,1733812800,1733726400,1733726400
     *
     */
    std::string dummy;
    // to get rid of the first row (column)
    getline(fin, dummy);

    std::string row;
    while (std::getline(fin, row))
    {
        std::stringstream ss(row);
        std::string id_str, description, priority_str, isCompleted_str, dueDate_str, createdDate_str, lastModified_str;
        std::getline(ss, id_str, ',');
        std::getline(ss, description, ',');
        std::getline(ss, priority_str, ',');
        std::getline(ss, isCompleted_str, ',');
        std::getline(ss, dueDate_str, ',');
        std::getline(ss, createdDate_str, ',');
        std::getline(ss, lastModified_str, ',');

        int id = std::stoi(id_str);
        int priority = std::stoi(priority_str);
        bool isCompleted = (isCompleted_str == "1");
        time_t dueDate = std::stoll(dueDate_str);
        time_t createdDate = std::stoll(createdDate_str);
        time_t lastModified = std::stoll(lastModified_str);

        Task task(id, description, priority, dueDate);
        task.setCreatedDate(createdDate);
        task.setLastModified(lastModified);
        task.setIsCompleted(isCompleted);
        this->_tasks.push_back(task);
    }

    // determine the next available ID
    if (!_tasks.empty())
    {
        // Sort tasks by ID to find the largest one, in case the file is not sorted.
        std::sort(_tasks.begin(), _tasks.end(), [](const Task &a, const Task &b)
                  { return a.getId() < b.getId(); });
        _nextId = _tasks.back().getId() + 1;
    }
    else
    {
        _nextId = 1;
    }

    fin.close();
    return true;
}

void TodoManager::readAllTasks() const
{
    if (_tasks.empty())
    {
        std::cout << "No tasks to show" << std::endl;
        return;
    }

    std::cout << "\n--- ALL TASKS ---\n"
              << std::endl;
    for (const Task &task : _tasks)
    {
        std::cout << task << std::endl;
        std::cout << "-------------" << std::endl;
    }
}

void TodoManager::createTask(const std::string &description, int priority, const std::string &dueDate_str)
{

    // step 1: validation check
    if (priority > 10 || priority < 1)
    {
        std::cerr << "Priority out of range. Please try again" << std::endl;
        return;
    }

    time_t dueDate = _string_to_time_t(dueDate_str);
    if (dueDate == static_cast<time_t>(-1))
    {
        std::cerr << "Could not create task due to invalid date format. Please use YYYY-MM-DD." << std::endl;
        return;
    }

    // step 2: generate data and save to csv

    time_t now = time(nullptr);

    // use the next available id and then postfix to increase it
    Task newTask(_nextId++, description, priority, dueDate);
    newTask.setCreatedDate(now);
    newTask.setLastModified(now);
    newTask.setIsCompleted(false);

    _tasks.push_back(newTask);

    _saveToFile();

    // step 3: show sucess message & print the newly created task
    std::cout << "\nTask created successfully:" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << newTask << std::endl;
}

bool TodoManager::updateTask()
{
    if (_tasks.empty())
    {
        std::cout << "No tasks to update." << std::endl;
        return false;
    }

    // step 1: get id
    int taskId;
    std::cout << "Enter the ID of the task to update: " << std::endl;
    std::cout << "Here is the available IDs:";
    for (const Task &t : _tasks)
    {
        std::cout << t.getId() << ", ";
    }
    std::cout << "\n";
    std::cin >> taskId;

    // step 2: find the task
    Task *targetTask = _findTaskById(taskId);
    if (targetTask == nullptr)
    {
        std::cout << "Task with ID " << taskId << " not found." << std::endl;
        return false;
    }

    // Step 3: display the edit menu and loop for changes
    int choice = 0;
    bool needs_save = false;

    while (choice != 5)
    {
        std::cout << "\n--- Editing Task " << targetTask->getId() << " ---" << std::endl;
        std::cout << (*targetTask) << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "1. Update Description" << std::endl;
        std::cout << "2. Update Priority" << std::endl;
        std::cout << "3. Update Due Date" << std::endl;
        std::cout << "4. Toggle Completion Status" << std::endl;
        std::cout << "5. Save and Return to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Add this check right after reading the choice to prevent infinite loops
        if (std::cin.fail())
        {
            choice = 0;                                                         // Set to a value that will trigger the default case
            std::cin.clear();                                                   // Clear the error from cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the bad input
        }

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter new description: ";
            std::string new_desc;
            std::getline(std::cin >> std::ws, new_desc); // std::ws consumes whitespace
            targetTask->setDescription(new_desc);
            needs_save = true;
            break;
        }
        case 2:
        {
            std::cout << "Enter new Priority (1-10): ";
            int new_prio;
            std::cin >> new_prio;

            // validate the user's input
            if (new_prio < 1 || new_prio > 10)
            {
                std::cout << "Invalid priority. Must be a number between 1-10.\n";
                std::cout << "Priority not updated.\n";
            }
            else
            {
                targetTask->setPriority(new_prio);
                needs_save = true;
            }
            break;
        }
        case 3:
        {
            std::cout << "Enter new due date (YYYY-MM-DD): ";
            std::string new_date_str;
            std::cin >> new_date_str;
            time_t new_date = _string_to_time_t(new_date_str);

            if (new_date != static_cast<time_t>(-1))
            {
                targetTask->setDueDate(new_date);
                needs_save = true;
            }
            else
            {
                // The _string_to_time_t function already prints an error
                std::cout << "Due date not updated.\n";
            }
            break;
        }
        case 4:
        {
            // Toggle the current completion status
            targetTask->setIsCompleted(!targetTask->getIsCompleted());
            std::cout << "Task status toggled to: "
                      << (targetTask->getIsCompleted() ? "Complete" : "Incomplete")
                      << std::endl;
            needs_save = true;
            break;
        }
        case 5:
            std::cout << "Returning to main menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        // update last modified date if any of the fields haven been updated
        if (needs_save && choice != 5)
        {
            targetTask->setLastModified(time(nullptr));
        }
    }

    // step 4: save file
    if (needs_save)
    {
        _saveToFile();
        std::cout << "Task " << taskId << " updated successfully." << std::endl;
    }
    else
    {
        std::cout << "No changes were made." << std::endl;
    }

    return true;
}