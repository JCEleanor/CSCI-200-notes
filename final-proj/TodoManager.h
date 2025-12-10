#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <vector>
#include <string>
#include <ctime>
#include "Task.h"

class TodoManager
{
public:
    TodoManager(const std::string &filename);
    bool loadFromFile();
    // Write all tasks from vector to CSV
    bool saveToFile();

    void createTask(const std::string &description, int priority, const std::string &dueDate_str);

    // Display all tasks currently in memory
    void readAllTasks() const;

    // Task *readTaskById(int id);

    // Update an existing task, identified by its ID. Returns true if the update was successful, false otherwise
    bool updateTask();

    // Delete a task, identified by its ID. Returns true if the deletion was successful, false otherwise
    bool deleteTask();

    // For testing purpose
    void printAllTasks();

private:
    /** vector storing all Task objects in memory */
    std::vector<Task> _tasks;
    std::string _filename;
    // Track the next available ID for a new task
    int _nextId;

    // Private helper to determine the next ID based on current tasks
    void initializeNextId();
    // Private helper to convert string to time_t
    time_t _string_to_time_t(const std::string &date_str);

    // Find a task by its ID and returns a pointer to it. Returns nullptr if no task is found
    Task *_findTaskById(const int id);

    void _saveToFile();
};

#endif
