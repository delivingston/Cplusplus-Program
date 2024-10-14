
/*Dale Livingston II
  09/21/2024
  Project 1: Asking the Enduser to enter a time and display the 12-Hour clock and 34-Hour clock. It asks the user if they want to enter a second, minute, or hour.*/
#include <iostream>
#include <iomanip> // For formatting output
#include <string>

using namespace std;

// Global variables to store the time
int hour = 0;
int minutes = 0;
int seconds = 0;
bool isPM;

// Function to display both the 12-hour and 24-hour clocks
void displayClocks() {
    // Display the 12-hour clock
    // Display the 24-hour clock
    int miltaryClock = isPM ? (hour == 12 ? 12 : hour + 12) : (hour == 12 ? 0 : hour);
    cout << "*****************************************************" << endl;
    cout << "*     12-Hour Clock        *       24-Hour Clock    *" << endl;
    cout << "*     " << setw(2) << setfill('0') << (hour == 0 ? 12 : hour) << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << (isPM ? " PM" : " AM") << "          *       "
        << setw(2) << setfill('0') << miltaryClock << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << "         *" << endl;
    cout << "*****************************************************" << endl;
}

// Function to add hours to the clocks
void addOneHour() {
    hour++;
    if (hour > 12) {
        hour = 1;
    }
    if (hour == 12) {
        isPM = !isPM; // Switch AM/PM when crossing 12-hour boundary
    }
}

// Function to add minutes to the clocks
void addOneMinute() {
    minutes++;
    if (minutes >= 60) {
        minutes = 0;
        addOneHour(); // If minutes overflow, increment hours
    }
}

// Function to add seconds to the clocks
void addOneSecond() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        addOneMinute(); // If seconds overflow, increment minutes
    }
}

// Function to display menu and get user's choice
int getUserChoice(int n) {
    int choice;
    do {
        cout << "\n********** Menu **********" << endl;
        cout << "1 - Add One Hour" << endl;
        cout << "2 - Add One Minute" << endl;
        cout << "3 - Add One Second" << endl;
        cout << "4 - Exit Program" << endl;
        cout << "*************************" << endl;
        cout << "Enter your choice (1-" << n << "): ";
        cin >> choice;

        // Validate that the choice is between 1 and n
        if (choice < 1 || choice > n) {
            cout << "Invalid choice! Please enter a number between 1 and " << n << "." << endl;
        }

    } while (choice < 1 || choice > n); // Keep asking until a valid choice is entered

    return choice;
}

// Function to get initial time from the user
void inputTime() {
    cout << "Enter the initial time (12-hour format):" << endl;

    cout << "Enter hours (1-12): ";
    cin >> hour;
    while (hour < 1 || hour > 12) {
        cout << "Invalid hours. Please enter a value between 1 and 12: ";
        cin >> hour;
    }

    cout << "Enter minutes (0-59): ";
    cin >> minutes;
    while (minutes < 0 || minutes > 59) {
        cout << "Invalid minutes. Please enter a value between 0 and 59: ";
        cin >> minutes;
    }

    cout << "Enter seconds (0-59): ";
    cin >> seconds;
    while (seconds < 0 || seconds > 59) {
        cout << "Invalid seconds. Please enter a value between 0 and 59: ";
        cin >> seconds;
    }

    char period;
    cout << "Enter A for AM or P for PM: ";
    cin >> period;
    while (toupper(period) != 'A' && toupper(period) != 'P') {
        cout << "Invalid input. Please enter 'A' for AM or 'P' for PM: ";
        cin >> period;
    }
    isPM = toupper(period) == 'P'; // true if PM, false if AM
}

// Main function
void mainMenu() {
    // Get the initial time from the user
    inputTime();

    int choice;

    do {
        // Display both clocks
        displayClocks();

        // Get user choice
        choice = getUserChoice(4);

        // Process user choice
        switch (choice) {
        case 1:
            addOneHour();
            break;
        case 2:
            addOneMinute();
            break;
        case 3:
            addOneSecond();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
        }

    } while (choice != 4);

}
int main() {
    mainMenu();
    return 0;
}
