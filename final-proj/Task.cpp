#include "Task.h"
#include <ctime>

Task::Task()
{
}

// Parameterized constructor.
// Initialize with member initializer list. C++ idiom according to gemini
Task::Task(int id, std::string description, int priority, time_t dueDate)
    : id(id),
      description(description),
      priority(priority),
      dueDate(dueDate),
      isCompleted(false),
      createdDate(time(nullptr)),
      lastModified(time(nullptr)) {}

int Task::getId() const
{
    return id;
}

void Task::setId(int id)
{
    this->id = id;
}

std::string Task::getDescription() const
{
    return description;
}

void Task::setDescription(std::string description)
{
    this->description = description;
}

int Task::getPriority() const
{
    return priority;
}

void Task::setPriority(int priority)
{
    this->priority = priority;
}

bool Task::getIsCompleted() const
{
    return isCompleted;
}

void Task::setIsCompleted(bool isCompleted)
{
    this->isCompleted = isCompleted;
}

time_t Task::getDueDate() const
{
    return dueDate;
}

void Task::setDueDate(time_t dueDate)
{
    this->dueDate = dueDate;
}

time_t Task::getCreatedDate() const
{
    return createdDate;
}

time_t Task::getLastModified() const
{
    return lastModified;
}
