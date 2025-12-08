#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ----- STRING -----
    string fullName;

    cout << "Enter your full name: ";
    getline(cin, fullName); // Reads full name with spaces

    // ----- ARRAY -----
    int numbers[5];

    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> numbers[i];
    }

    // ----- OUTPUT SECTION -----
    cout << "Full Name: " << fullName << endl;

    cout << "Numbers entered: ";
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
