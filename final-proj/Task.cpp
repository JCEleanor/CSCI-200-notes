#include "Task.h"
#include <ctime>

Task::Task()
{
}

// Parameterized constructor.
Task::Task(int id, std::string description, int priority, time_t dueDate)
    : _id(id),
      _description(description),
      _priority(priority),
      _dueDate(dueDate),
      _isCompleted(false),
      _createdDate(time(nullptr)),
      _lastModified(time(nullptr))
{
}

int Task::getId() const
{
    return _id;
}

void Task::setId(int id)
{
    this->_id = id;
}

std::string Task::getDescription() const
{
    return _description;
}

void Task::setDescription(const std::string &description)
{
    this->_description = description;
}

int Task::getPriority() const
{
    return _priority;
}

void Task::setPriority(int priority)
{
    this->_priority = priority;
}

bool Task::getIsCompleted() const
{
    return _isCompleted;
}

void Task::setIsCompleted(bool isCompleted)
{
    this->_isCompleted = isCompleted;
}

time_t Task::getDueDate() const
{
    return _dueDate;
}

void Task::setDueDate(time_t dueDate)
{
    this->_dueDate = dueDate;
}

time_t Task::getCreatedDate() const
{
    return _createdDate;
}

void Task::setCreatedDate(time_t createdDate)
{
    this->_createdDate = createdDate;
}

time_t Task::getLastModified() const
{
    return _lastModified;
}

void Task::setLastModified(time_t lastModified)
{
    this->_lastModified = lastModified;
}

std::ostream &operator<<(std::ostream &os, const Task &task)
{
    // get a human-readable time string from the time_t
    time_t dueDate = task.getDueDate();
    std::string dueDateStr = std::ctime(&dueDate);
    dueDateStr.pop_back(); // ctime() adds a newline, so remove it

    os << "ID:          " << task.getId() << "\n"
       << "Description: " << task.getDescription() << "\n"
       << "Priority:    " << task.getPriority() << "\n"
       << "Completed:   " << (task.getIsCompleted() ? "Yes" : "No") << "\n"
       << "Due Date:    " << dueDateStr;
    return os;
}

// Task &Task::operator=(const Task &other) // TODO:
// {
//     // step 1: chcek for self assignment
//     if (this == &other)
//     {
//         return *this;
//     }

//     // step 2 : deallocate old data `this` owns this->deallocate();

//     // step 3 : deep copy
//     // this->deepCopy(other);

//     // step 4 : return the reference to allow chained assignemnt return *this;
// }