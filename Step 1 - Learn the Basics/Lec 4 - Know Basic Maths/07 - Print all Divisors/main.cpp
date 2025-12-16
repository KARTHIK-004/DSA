#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n)
{
    cout << "Divisors of " << n << ": ";

    // Iterate only till square root of n
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";

            // Print the corresponding divisor if it's different
            if (i != n / i)
            {
                cout << n / i << " ";
            }
        }
    }

    cout << endl;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    printDivisors(n);

    return 0;
}

