#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    // Handle edge cases
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    // Check if divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Check for divisors up to square root of n
    for (int i = 5; i <= sqrt(n); i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    if (isPrime(n))
    {
        cout << n << " is a prime number" << endl;
    }
    else
    {
        cout << n << " is not a prime number" << endl;
    }

    return 0;
}

