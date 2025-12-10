#include "TodoManager.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    TodoManager manager("tasks.csv");
    manager.loadFromFile(); // need to load file first to populate the `_task`

    manager.readAllTasks();

    string description;
    int priority;
    string dueDate;

    std::cout << "------Create a Task------" << std::endl;
    std::cout << "Please enter description for the task: ";
    // Reads entire line
    getline(cin >> ws, description);
    std::cout << "Choose a priority level from 1-10: ";
    cin >> priority;
    std::cout << "Enter a due date (YYYY-MM-DD): ";
    cin >> dueDate;
    manager.createTask(description, priority, dueDate);

    return 0;
}