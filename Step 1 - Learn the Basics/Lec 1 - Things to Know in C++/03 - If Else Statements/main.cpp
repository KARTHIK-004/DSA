#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    // Check conditions using if-else statements
    if (x > 0)
    {
        // Executes when number is greater than zero
        cout << x << " is Positive";
    }
    else if (x < 0)
    {
        // Executes when number is less than zero
        cout << x << " is Negative";
    }
    else
    {
        // Executes when number is exactly zero
        cout << "The number is Zero";
    }

    return 0;
}