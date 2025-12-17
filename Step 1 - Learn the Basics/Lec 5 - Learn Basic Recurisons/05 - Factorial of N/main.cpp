#include <iostream>
using namespace std;

long long factorial(int n)
{
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
        return 1;

    // Recursive case: n * factorial(n-1)
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: \n";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    long long result = factorial(n);

    cout << "Factorial of " << n << " = " << result << endl;

    return 0;
}

