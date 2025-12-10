#include "TodoManager.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    TodoManager manager("tasks.csv");
    manager.loadFromFile(); // need to load file first to populate the `_task`

    int choice = 0;
    while (choice != 4)
    {
        cout << "\n--- TODO LIST MENU ---" << endl;
        cout << "1. Show All Tasks" << endl;
        cout << "2. Create New Task" << endl;
        cout << "3. Update Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.readAllTasks();
            break;
        case 2:
        {
            string description;
            int priority;
            string dueDate;

            cout << "\n------Create a Task------" << endl;
            cout << "Please enter description for the task: ";
            getline(cin >> ws, description);
            cout << "Choose a priority level from 1-10: ";
            cin >> priority;
            cout << "Enter a due date (YYYY-MM-DD): ";
            cin >> dueDate;
            manager.createTask(description, priority, dueDate);
            break;
        }
        case 3:
            manager.updateTask();
            break;
        case 4:
            cout << "Exiting program...." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}