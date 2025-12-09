#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task
{
public:
    Task();
    Task(int id, std::string description, int priority, time_t dueDate);
    int getId() const;
    void setId(int id);
    std::string getDescription() const;
    void setDescription(std::string description);
    int getPriority() const;
    void setPriority(int priority);
    bool getIsCompleted() const;
    void setIsCompleted(bool isCompleted);
    time_t getDueDate() const;
    void setDueDate(time_t dueDate);
    time_t getCreatedDate() const;
    time_t getLastModified() const;

private:
    int id;
    std::string description;
    int priority;
    bool isCompleted;
    time_t dueDate;
    time_t createdDate;
    time_t lastModified;
};

#endif
