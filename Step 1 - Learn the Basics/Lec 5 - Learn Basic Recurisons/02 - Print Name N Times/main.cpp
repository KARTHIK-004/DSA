#include <iostream>
#include <string>
using namespace std;

void printName(int n, string name)
{
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;

    // Print the name
    cout << name << endl;

    // Recursive call with n-1
    printName(n - 1, name);
}

int main()
{
    int n;
    string name;

    cout << "Enter the number of times to print: \n";
    cin >> n;

    cout << "Enter the name: \n";
    cin >> name;

    printName(n, name);

    return 0;
}

