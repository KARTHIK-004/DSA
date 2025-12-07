#include <iostream>
using namespace std;

int main()
{
    int choice;

    // Ask user to enter a number from 1 to 4
    cout << "Enter a number (1-4): ";

    cin >> choice; // taking user input

    /*
       Switch Statement:
       - Checks 'choice'
       - Executes the matching case
       - break prevents falling into next case
    */
    switch (choice)
    {
    case 1:
        cout << "You selected Option 1: Start Program";
        break;

    case 2:
        cout << "You selected Option 2: Settings";
        break;

    case 3:
        cout << "You selected Option 3: Help Menu";
        break;

    case 4:
        cout << "You selected Option 4: Exit Program";
        break;

    default:
        // Executes when none of the above cases match
        cout << "Invalid choice! Please enter a number between 1 and 4.";
    }

    return 0;
}
