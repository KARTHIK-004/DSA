#include <iostream>
using namespace std;

void print1ToN(int n)
{
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;

    // Recursive call first (to print in ascending order)
    print1ToN(n - 1);

    // Print after recursive call
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter a number: \n";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": \n";
    print1ToN(n);
    cout << endl;

    return 0;
}

