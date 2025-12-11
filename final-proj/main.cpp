/* CSCI 200: Final Project - A TODO List Application
 *
 * Author: Eleanor Chiu
 *
 * Description:
 *    This program provides a command-line interface to manage a list of
 *    tasks. Users can create, view, update, and delete tasks. The task
 *    list is persisted to a CSV file.
 */

#include "Color.h"
#include "CliUtils.h"
#include "TodoManager.h"

#include <format>
#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <string>

using namespace std;

// main menu choices
const int MENU_SHOW_ALL_TASKS = 1;
const int MENU_CREATE_NEW_TASK = 2;
const int MENU_UPDATE_TASK = 3;
const int MENU_DELETE_TASK = 4;
const int MENU_EXIT = 5;

int main()
{
    // FIXME: hard coded filename
    TodoManager manager("tasks.csv");
    manager.loadFromFile(); // need to load file first to populate the `_task`

    int choice = 0;
    while (choice != MENU_EXIT)
    {
        std::cout << Color::BOLD << Color::FG::YELLOW << "--- TODO LIST MENU ---" << Color::RESET << std::endl;

        cout << MENU_SHOW_ALL_TASKS << ". Show All Tasks" << endl;
        cout << MENU_CREATE_NEW_TASK << ". Create New Task" << endl;
        cout << MENU_UPDATE_TASK << ". Update Task" << endl;
        cout << MENU_DELETE_TASK << ". Delete Task" << endl;
        cout << MENU_EXIT << ". Exit" << endl;
        CliUtils::printInstruction("Enter your choice: ");

        cin >> choice;

        // to prevent infinite loop
        if (cin.fail())
        {
            CliUtils::printError("Invalid input. Please enter a number.");
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
            manager.createTask();
            break;
        }
        case MENU_UPDATE_TASK:
            manager.updateTask();
            break;
        case MENU_DELETE_TASK:
            manager.deleteTask();
            break;
        case MENU_EXIT:
            CliUtils::printMessage("Exiting program....");
            break;
        default:
            std::cerr << Color::FG::RED
                      << "Invalid choice. Please enter a number between " << MENU_SHOW_ALL_TASKS << " and " << MENU_EXIT << "." << Color::RESET << endl;
            break;
        }
    }

    return 0;
}