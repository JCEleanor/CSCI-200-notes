/* CSCI 200: Final Project - A TODO List Application
 *
 * Author: Eleanor Chiu
 *
 * Description:
 *    This program provides a command-line interface to manage a list of
 *    tasks. Users can create, view, update, and delete tasks. The task
 *    list is persisted to a CSV file.
 */

#include "TodoManager.h"

#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <string>

using namespace std;

// Constants for main menu choices
const int MENU_SHOW_ALL_TASKS = 1;
const int MENU_CREATE_NEW_TASK = 2;
const int MENU_UPDATE_TASK = 3;
const int MENU_DELETE_TASK = 4;
const int MENU_EXIT = 5;

int main()
{

    TodoManager manager("tasks.csv");
    manager.loadFromFile(); // need to load file first to populate the `_task`

    int choice = 0;
    while (choice != MENU_EXIT)
    {
        cout << "\n--- TODO LIST MENU ---" << endl;
        cout << MENU_SHOW_ALL_TASKS << ". Show All Tasks" << endl;
        cout << MENU_CREATE_NEW_TASK << ". Create New Task" << endl;
        cout << MENU_UPDATE_TASK << ". Update Task" << endl;
        cout << MENU_DELETE_TASK << ". Delete Task" << endl;
        cout << MENU_EXIT << ". Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // to prevent infinite loop
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            // Discard invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Skip the rest of the loop and show the menu again
            continue;
        }

        switch (choice)
        {
        case MENU_SHOW_ALL_TASKS:
            manager.readAllTasks();
            break;
        case MENU_CREATE_NEW_TASK:
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
        case MENU_UPDATE_TASK:
            manager.updateTask();
            break;
        case MENU_DELETE_TASK:
            manager.deleteTask();
            break;
        case MENU_EXIT:
            cout << "Exiting program...." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between " << MENU_SHOW_ALL_TASKS << " and " << MENU_EXIT << "." << endl;
            break;
        }
    }

    return 0;
}