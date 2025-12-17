#include <iostream>
using namespace std;

void printNTimes(int n)
{
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;

    // Print the message
    cout << "Hello World!" << endl;

    // Recursive call with n-1
    printNTimes(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number of times to print: \n";
    cin >> n;

    printNTimes(n);

    return 0;
}

