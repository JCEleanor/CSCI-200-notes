#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "TodoManager.h"

TodoManager::TodoManager(const std::string &filename)
{
    _filename = filename;
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