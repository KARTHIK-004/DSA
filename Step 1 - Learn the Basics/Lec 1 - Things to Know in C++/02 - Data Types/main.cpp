#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Variables of different data types
    string fullName;      // getline
    int age;              // 10^9
    long heightInMeters;  // 10^12
    long long population; // 10^18
    char grade;
    float height;
    double weight;
    bool isStudent;

    // Input section
    getline(cin, fullName); // read full name (with spaces)
    cin >> age;
    cin >> population;
    cin >> grade;
    cin >> height;
    cin >> weight;
    cin >> isStudent;

    // Output section
    cout << "Full Name (string): " << fullName << endl;
    cout << "Age (int): " << age << endl;
    cout << "Population (long long): " << population << endl;
    cout << "Grade (char): " << grade << endl;
    cout << "Height (float): " << height << endl;
    cout << "Weight (double): " << weight << endl;
    cout << "Is Student (bool): " << (isStudent ? "true" : "false") << endl;

    return 0;
}
