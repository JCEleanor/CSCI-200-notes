#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>
#include <iostream>

/**
 * @brief Represents a single task in the to-do list.
 *
 */
class Task
{
public:
    /**
     * @brief Default constructor for a Task.
     *
     */
    Task();
    /**
     * @brief Parameterized constructor for a Task.
     *
     * @param id The unique identifier for the task.
     * @param description The description of the task.
     * @param priority The priority of the task.
     * @param dueDate The due date of the task.
     */
    Task(int id, std::string description, int priority, time_t dueDate);

    /**
     * @brief Gets the ID of the task.
     * @return The ID of the task.
     */
    int getId() const;

    /**
     * @brief Sets the ID of the task.
     * @param id The new ID for the task.
     */
    void setId(const int id);

    /**
     * @brief Gets the description of the task.
     * @return The description of the task.
     */
    std::string getDescription() const;

    /**
     * @brief Sets the description of the task.
     * @param description The new description for the task.
     */
    void setDescription(const std::string &description);

    /**
     * @brief Gets the priority of the task.
     * @return The priority of the task.
     */
    int getPriority() const;

    /**
     * @brief Sets the priority of the task.
     * @param priority The new priority for the task.
     */
    void setPriority(const int priority);

    /**
     * @brief Gets the completion status of the task.
     * @return True if the task is completed, false otherwise.
     */
    bool getIsCompleted() const;

    /**
     * @brief Sets the completion status of the task.
     * @param isCompleted The new completion status.
     */
    void setIsCompleted(const bool isCompleted);

    /**
     * @brief Gets the due date of the task.
     * @return The due date of the task as a time_t.
     */
    time_t getDueDate() const;

    /**
     * @brief Sets the due date of the task.
     * @param dueDate The new due date for the task.
     */
    void setDueDate(const time_t dueDate);

    /**
     * @brief Gets the creation date of the task.
     * @return The creation date of the task as a time_t.
     */
    time_t getCreatedDate() const;

    /**
     * @brief Sets the creation date of the task.
     * @param createdDate The new creation date for the task.
     */
    void setCreatedDate(const time_t createdDate);

    /**
     * @brief Gets the last modified date of the task.
     * @return The last modified date of the task as a time_t.
     */
    time_t getLastModified() const;

    /**
     * @brief Sets the last modified date of the task.
     * @param lastModified The new last modified date for the task.
     */
    void setLastModified(const time_t lastModified);
    // Task &operator=(const Task &other);

private:
    int _id;
    std::string _description;
    int _priority;
    time_t _dueDate;
    /** 0: incomplete, 1: completed */
    bool _isCompleted;
    time_t _createdDate;
    time_t _lastModified;
};

/**
 * @brief Overloads the << operator to print a Task object to an output stream.
 *
 * @param os The output stream.
 * @param task The Task object to print.
 * @return A reference to the output stream.
 */
std::ostream &operator<<(std::ostream &os, const Task &task);

#endif
