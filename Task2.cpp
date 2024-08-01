/*                  TASK 2
               SIMPLE CALCULATOR

A calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/



#include <iostream>
#include <limits>  // For numeric_limits

using namespace std;

// Defined text colors 
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string BLUE = "\033[94m";
const string GREEN = "\033[92m";
const string RED = "\033[91m";

// Function to display the main menu 
void displayMenu() {
    cout << BLUE
         << "╔══════════════════════════════════════════════════╗\n"
         << "║ " << BOLD << "  Welcome to the Simple Calculator! 🧮  " << RESET << "║\n"
         << "║                                                    ║\n"
         << "║ " << BOLD << "  What would you like to do today?" << RESET << "                ║\n"
         << "║                                                    ║\n"
         << "║ " << BOLD << "  1. Addition" << RESET << "                               ║\n"
         << "║ " << BOLD << "  2. Subtraction" << RESET << "                            ║\n"
         << "║ " << BOLD << "  3. Multiplication" << RESET << "                         ║\n"
         << "║ " << BOLD << "  4. Division" << RESET << "                               ║\n"
         << "║ " << BOLD << "  5. Exit" << RESET << "                                   ║\n"
         << "╚══════════════════════════════════════════════════╝\n"
         << "Please enter your choice (1-5): ";
}

// Function to perform addition 
void addition() {
    double a, b;

    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Let’s add some numbers! ✏️       ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the first number: ";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "Enter the second number: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "The result of " << a << " + " << b << " is " << a + b << ". Nice job adding! 🎉\n";
}

// Function to perform subtraction 
void subtraction() {
    double a, b;

    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Time for some subtraction! ✏️   ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the first number: ";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "Enter the second number: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "The result of " << a << " - " << b << " is " << a - b << ". Well done on the subtraction! 👍\n";
}

// Function to perform multiplication 
void multiplication() {
    double a, b;

    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Let’s multiply some numbers! ✏️  ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the first number: ";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "Enter the second number: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "The result of " << a << " * " << b << " is " << a * b << ". You’re multiplying like a pro! 🌟\n";
}

// Function to perform division 
void division() {
    double a, b;

    cout << "\n" << GREEN
         << "╔════════════════════════════════════╗\n"
         << "║  Ready for some division? ✏️      ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;
    cout << "Enter the first number: ";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    cout << "Enter the second number: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Oops! That's not a number. Please enter a valid number: " << RESET;
    }
    if (b != 0) {
        cout << "The result of " << a << " / " << b << " is " << a / b << ". Great division work! 🌟\n";
    } else {
        cout << RED << "Oops! Division by zero is not allowed. Please try again.\n" << RESET;
    }
}

int main() {
    int choice;

    do {
        displayMenu();

        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << RED << "Oops! That’s not a valid choice. Please enter a number between 1 and 5: " << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                cout << "\n" << GREEN << "Goodbye! Have a fantastic day! 👋\n" << RESET;
                break;
            default:
                cout << RED << "Oops! That’s not a valid choice. Please choose a number between 1 and 5.\n" << RESET;
                break;
        }
    } while (choice != 5);

    cout << "\n" << BLUE
         << "╔════════════════════════════════════╗\n"
         << "║      " << BOLD << "Created by Viraj Tupe" << RESET << "        ║\n"
         << "╚════════════════════════════════════╝\n" << RESET;

    return 0;
}
