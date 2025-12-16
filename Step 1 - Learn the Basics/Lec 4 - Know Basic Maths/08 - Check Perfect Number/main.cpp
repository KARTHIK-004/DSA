#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectNumber(int n)
{
    // Perfect numbers are positive
    if (n <= 1)
        return false;

    int sum = 1; // 1 is always a divisor

    // Find divisors up to square root
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;

            // Add the corresponding divisor if it's different
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }

    return sum == n;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    if (isPerfectNumber(n))
    {
        cout << n << " is a perfect number" << endl;
    }
    else
    {
        cout << n << " is not a perfect number" << endl;
    }

    return 0;
}

