#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    // ---------- WHILE LOOP ----------
    cout << "WHILE loop output:\n";

    while (x < 5) // FALSE condition → loop will NOT run
    {
        cout << x << " ";
        x++;
    }

    cout << "While loop did NOT run because condition was false.\n";

    // ---------- DO-WHILE LOOP ----------
    cout << "\nDO-WHILE loop output:\n";

    int y = 10;

    do
    {
        cout << y << " "; // runs at least ONCE
        y++;
    } while (y < 5); // condition false → loop stops

    cout << "\nDo-while loop ran ONCE even though condition was false.\n";

    return 0;
}
