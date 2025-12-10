#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

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

    // Populate _nextId
    _nextId = _tasks[_tasks.size()].getId() + 1;

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

    // step 2: generate data and append to csv

    time_t now = time(nullptr);

    Task newTask(_nextId, description, priority, dueDate);
    newTask.setCreatedDate(now);
    newTask.setLastModified(now);
    newTask.setIsCompleted(false);

    std::ofstream fout(_filename, std::ios_base::app); // flag to append to file rather than overwriting it
    if (!fout.is_open())
    {
        std::cerr << "Error: Could not open file " << _filename << " for writing." << std::endl;
        return;
    }

    // id,description,priority,isCompleted,dueDate,createdDate,lastModified
    fout << newTask.getId() << ","
         << newTask.getDescription() << ","
         << newTask.getPriority() << ","
         << (newTask.getIsCompleted() ? "1" : "0") << ","
         << newTask.getDueDate() << ","
         << newTask.getCreatedDate() << ","
         << newTask.getLastModified() << std::endl;

    fout.close();

    _tasks.push_back(newTask);

    // step 3: show sucess message & print the newly created task
    std::cout << "\nTask created successfully:" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << newTask << std::endl;
}
