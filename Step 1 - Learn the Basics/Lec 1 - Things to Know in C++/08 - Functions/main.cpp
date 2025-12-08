#include <iostream>
using namespace std;

// ---------- PARAMETERIZED + VOID ----------
void displayNumber(int x)
{
    cout << "You entered the number: " << x << endl;
}

// ---------- PASS BY VALUE ----------
void passByValue(int a)
{
    a = 100; // only local copy changes
    cout << "Inside passByValue(), a = " << a << endl;
}

// ---------- PASS BY REFERENCE ----------
void passByReference(int &b)
{
    b = 200; // original changes
    cout << "Inside passByReference(), b = " << b << endl;
}

int main()
{
    // ----- USER INPUT FOR PARAMETERIZED FUNCTION -----
    int num;
    cout << "\nEnter a number for parameterized function: ";
    cin >> num;
    displayNumber(num);

    // ----- USER INPUT FOR PASS BY VALUE -----
    int x;
    cout << "\nEnter a value for Pass by Value: ";
    cin >> x;

    cout << "Before passByValue(), x = " << x << endl;
    passByValue(x);
    cout << "After passByValue(), x = " << x << " (unchanged)\n";

    // ----- USER INPUT FOR PASS BY REFERENCE -----
    int y;
    cout << "\nEnter a value for Pass by Reference: ";
    cin >> y;

    cout << "Before passByReference(), y = " << y << endl;
    passByReference(y);
    cout << "After passByReference(), y = " << y << " (changed)\n";

    return 0;
}
