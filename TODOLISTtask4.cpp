#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display menu
void showMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!\n";
    } else {
        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        int taskNum;
        cout << "Enter task number to delete: ";
        cin >> taskNum;

        if (taskNum > 0 && taskNum <= tasks.size()) {
            cout << "Task '" << tasks[taskNum - 1] << "' deleted successfully!\n";
            tasks.erase(tasks.begin() + (taskNum - 1));
        } else {
            cout << "Invalid task number!\n";
        }
    }
}

// Main function
int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting... Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    }
}