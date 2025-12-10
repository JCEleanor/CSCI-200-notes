#include "TodoManager.h"

int main()
{

    TodoManager manager("tasks.csv");
    manager.loadFromFile();

    manager.readAllTasks();
    return 0;
}