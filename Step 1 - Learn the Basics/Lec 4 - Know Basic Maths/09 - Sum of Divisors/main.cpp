#include <iostream>
#include <cmath>
using namespace std;

int sumOfDivisors(int n)
{
    // Handle edge cases
    if (n <= 0)
        return 0;

    int sum = 0;

    // Find divisors up to square root
    for (int i = 1; i <= sqrt(n); i++)
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

    return sum;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    int sum = sumOfDivisors(n);

    cout << "Sum of divisors of " << n << " = " << sum << endl;

    return 0;
}

