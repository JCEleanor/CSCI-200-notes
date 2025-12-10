#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>
#include <iostream>

class Task
{
public:
    Task();
    Task(int id, std::string description, int priority, time_t dueDate);
    int getId() const;
    void setId(int id);
    std::string getDescription() const;
    void setDescription(const std::string &description);
    int getPriority() const;
    void setPriority(int priority);
    bool getIsCompleted() const;
    void setIsCompleted(bool isCompleted);
    time_t getDueDate() const;
    void setDueDate(time_t dueDate);
    time_t getCreatedDate() const;
    void setCreatedDate(time_t createdDate);
    time_t getLastModified() const;
    void setLastModified(time_t lastModified);
    // Task &operator=(const Task &other);

private:
    int _id;
    std::string _description;
    int _priority;
    /** 0: incomplete, 1: completed */
    time_t _dueDate;
    bool _isCompleted;
    time_t _createdDate;
    time_t _lastModified;
};

std::ostream &operator<<(std::ostream &os, const Task &task);

#endif
