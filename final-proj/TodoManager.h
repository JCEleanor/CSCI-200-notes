#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <vector>
#include <string>
#include <ctime>
#include "Task.h"

/**
 * @brief Manages a collection of tasks, including loading from and saving to a file.
 * 
 */
class TodoManager
{
public:
    static const int MIN_PRIORITY = 1;
    static const int MAX_PRIORITY = 10;

    /**
     * @brief Construct a new Todo Manager object.
     * 
     * @param filename The name of the file to use for loading and saving tasks.
     */
    TodoManager(const std::string &filename);

    /**
     * @brief Loads tasks from the CSV file into memory.
     * 
     * @return true if the file was loaded successfully, false otherwise.
     */
    bool loadFromFile();

    /**
     * @brief Creates a new task and adds it to the list.
     * 
     * @param description The description of the task.
     * @param priority The priority of the task.
     * @param dueDate_str The due date of the task as a string (YYYY-MM-DD).
     */
    void createTask(const std::string &description, const int priority, const std::string &dueDate_str);

    /**
     * @brief Displays all tasks currently in memory to the console.
     * 
     */
    void readAllTasks() const;

    /**
     * @brief Interactively updates an existing task identified by its ID.
     * 
     * @return true if the update was successful, false otherwise.
     */
    bool updateTask();

    /**
     * @brief Interactively deletes a task identified by its ID.
     * 
     * @return true if the deletion was successful, false otherwise.
     */
    bool deleteTask();

private:
    /** vector storing all Task objects in memory */
    std::vector<Task> _tasks;
    std::string _filename;
    // Track the next available ID for a new task
    int _nextId;

    // Private helper to convert string to time_t
    time_t _string_to_time_t(const std::string &date_str);

    // Find a task by its ID and returns a pointer to it. Returns nullptr if no task is found
    Task *_findTaskById(const int id);

    // a single source of truth for saving to the CSV
    void _saveToFile();
};

#endif
