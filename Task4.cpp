/*
                 TASK 4

               TO-DO LIST

Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks.

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.
*/




#include <iostream>
#include <vector>
#include <string>
#include <limits> // Added for numeric_limits

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Defined text colors 
const string GREEN = "\033[92m";
const string RED = "\033[91m";
const string CYAN = "\033[96m";
const string BOLD = "\033[1m";
const string RESET = "\033[0m";

// Function to display the list of tasks 
void displayTasks(const vector<Task>& tasks) {
    cout << "\n" << GREEN
         << "╔════════════════════════════════════════╗\n"
         << "║  Here are your tasks! 📝              ║\n"
         << "╚════════════════════════════════════════╝\n" << RESET;

    if (tasks.empty()) {
        cout << "Your task list is empty! 🎉 Add some tasks to get started.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << (tasks[i].completed ? " ✅ (Completed)" : " ❌ (Pending)") << endl;
    }
}

// Function to add a new task 
void addTask(vector<Task>& tasks) {
    string description;

    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Add a new task to your list! ✏️   ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;

    cout << "What's your new task? ";
    getline(cin, description);
    tasks.push_back(Task{description, false});
    cout << "🎉 Task added successfully! Great job! 🎉\n";
}

// Function to mark a task as completed 
void markCompleted(vector<Task>& tasks) {
    int index;

    displayTasks(tasks);
    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Mark a task as completed! ✅    ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    cin.ignore();
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a valid number. Please try again.\n" << RESET;
        return;
    }
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "🎉 Task marked as completed! You're on a roll! 🎉\n";
    } else {
        cout << RED << "Hmm, that task number doesn’t seem to be on the list.\n" << RESET;
    }
}

// Function to remove a task 
void removeTask(vector<Task>& tasks) {
    int index;

    displayTasks(tasks);
    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Remove a task from your list! 🗑️  ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the task number to remove: ";
    cin >> index;
    cin.ignore();
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That’s not a valid number. Please try again.\n" << RESET;
        return;
    }
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "🗑️ Task removed successfully! Keep up the great work! 🌟\n";
    } else {
        cout << RED << "Hmm, that task number doesn’t seem to be on the list.\n" << RESET;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    // INTRODUCTION
    cout << CYAN
         << "╔════════════════════════════════════════════════════════════╗\n"
         << "║ " << BOLD << "  Welcome to the To-Do List Manager! 📋  " << RESET << "║\n"
         << "║                                                            ║\n"
         << "║ " << BOLD << "  Organize your tasks and stay on top of things!" << RESET << "   ║\n"
         << "╚════════════════════════════════════════════════════════════╝\n\n" << RESET;

    do {
        cout << "\n"
             << "1. Add Task 📝\n"
             << "2. View Tasks 👁️\n"
             << "3. Mark Task Completed ✅\n"
             << "4. Remove Task 🗑️\n"
             << "5. Exit 🚪\n"
             << "What would you like to do? (1-5): ";
        cin >> choice;
        cin.ignore();
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Oops! Please enter a number between 1 and 5.\n" << RESET;
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "\n" << GREEN << "Goodbye! Keep being awesome and organized! 🌟\n" << RESET;
                break;
       
            default:
            cout << RED << " Oops !  Please Choose A Valid Option Between 1 and 5. \n" << RESET ;
            break;

        }

    } while (choice != 5);

 cout << CYAN
         << "\n╔════════════════════════════════════════════════════╗\n"
         << "║ " << BOLD << "  Thanks for playing! 🎉" << RESET << "                 ║\n"
         << "║ " << BOLD << "  Created with ❤️ by Viraj Tupe" << RESET << "          ║\n"
         << "╚════════════════════════════════════════════════════╝\n" << RESET;

    return 0;
}









   