#include <iostream>
using namespace std;

int fibonacci(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter the position (n): \n";
    cin >> n;

    if (n < 0)
    {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 0;
    }

    int result = fibonacci(n);

    cout << "Fibonacci number at position " << n << " = " << result << endl;

    return 0;
}

