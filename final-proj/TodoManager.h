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

    void createTask(const std::string &description, int priority, time_t dueDate);

    // Display all tasks currently in memory
    void readAllTasks() const;

    // Find a task by its ID and returns a pointer to it. Returns nullptr if no task is found with the given ID
    Task *readTaskById(int id);

    // Update an existing task, identified by its ID. Returns true if the update was successful, false otherwise
    bool updateTask(int id, const std::string &description, int priority, bool isCompleted, time_t dueDate);

    // Delete a task, identified by its ID. Returns true if the deletion was successful, false otherwise
    bool deleteTask(int id);

private:
    std::vector<Task> tasks;
    std::string filename;
    // Track the next available ID for a new task
    int nextId;

    // Private helper to determine the next ID based on current tasks
    void initializeNextId();
};

#endif
