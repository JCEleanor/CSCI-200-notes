#include "TodoManager.h"

#include <algorithm> // For std::sort in loadFromFile
#include <ctime>
#include <fstream>
#include <iomanip> // Required for std::get_time
#include <iostream>
#include <limits> // For std::numeric_limits in updateTask
#include <sstream>
#include <string>

TodoManager::TodoManager(const std::string &filename)
{
    _filename = filename;
}

time_t TodoManager::_string_to_time_t(const std::string &date_str)
{
    std::tm t{}; // Initialize tm struct to all zeros
    std::istringstream ss(date_str);
    ss >> std::get_time(&t, "%Y-%m-%d");

    if (ss.fail())
    {
        std::cerr << "Error parsing date string: " << date_str << ". Please use YYYY-MM-DD format." << std::endl;
        return static_cast<time_t>(-1); // Indicate error
    }
    return mktime(&t);
}

Task *TodoManager::_findTaskById(const int id)
{
    auto it = std::find_if(_tasks.begin(), _tasks.end(), [id](const Task &task)
                           { return task.getId() == id; });

    if (it != _tasks.end())
    {
        return &(*it);
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

void TodoManager::createTask()
{
    // step 1: get user input & validation
    std::string description;
    int priority;
    std::string dueDate_str;

    std::cout << "\n------Create a Task------" << std::endl;
    std::cout << "Please enter description for the task: ";
    std::getline(std::cin >> std::ws, description);
    std::cout << "Choose a priority level from 1-10: ";
    std::cin >> priority;

    if (priority > TodoManager::MAX_PRIORITY || priority < TodoManager::MIN_PRIORITY)
    {
        std::cerr << "Priority out of range. Please try again" << std::endl;
        return;
    }

    std::cout << "Enter a due date (YYYY-MM-DD): ";
    std::cin >> dueDate_str;

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
    std::cout << "Enter the ID of the task to update: ";
    std::cin >> taskId;

    // step 2: find the task
    Task *targetTask = _findTaskById(taskId);
    if (targetTask == nullptr)
    {
        std::cout << "Task with ID " << taskId << " not found. Return back to main menu..." << std::endl;
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

        // Input validation for choice
        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Check if the choice is within the valid range
        if (choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            continue; // Skip the rest of the loop and show the menu again
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

            // Input validation for new_prio
            if (std::cin.fail())
            {
                std::cout << "Invalid input. Priority not updated. Please enter a number." << std::endl;
                std::cin.clear();                                                   // Clear the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
            else if (new_prio < TodoManager::MIN_PRIORITY || new_prio > TodoManager::MAX_PRIORITY)
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

bool TodoManager::deleteTask()
{
    if (_tasks.empty())
    {
        std::cout << "No tasks to delete." << std::endl;
        return false;
    }

    // step 1: Get ID from the user
    int taskId;
    std::cout << "\nEnter the ID of the task to delete: ";
    std::cin >> taskId;

    // Add input validation
    if (std::cin.fail())
    {
        std::cerr << "Invalid ID entered. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    // step 2: Find the task using std::find_if to get an iterator
    auto task_it = std::find_if(_tasks.begin(), _tasks.end(), [taskId](const Task &task)
                                { return task.getId() == taskId; });

    if (task_it == _tasks.end())
    {
        std::cout << "Task with ID " << taskId << " not found." << std::endl;
        return false;
    }

    // step 3: Show the user what they are deleting and ask for confirmation
    std::cout << "\nTask to be deleted:" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << *task_it << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Are you sure you want to permanently delete this task? (y/n): ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        // step 4: Erase the task using the iterator
        _tasks.erase(task_it);

        // step 5: Save the changes back to the file
        _saveToFile();

        std::cout << "Task " << taskId << " has been deleted." << std::endl;
    }
    else
    {
        std::cout << "Deletion cancelled." << std::endl;
    }

    return true;
}