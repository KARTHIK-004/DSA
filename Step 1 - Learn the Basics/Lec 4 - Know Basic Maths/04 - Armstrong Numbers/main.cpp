#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n)
{
    // Handle negative numbers
    if (n < 0)
        return false;

    int original = n;
    int sum = 0;

    // Count number of digits
    int digits = 0;
    int temp = n;
    while (temp > 0)
    {
        digits++;
        temp = temp / 10;
    }

    // Calculate sum of digits raised to power of number of digits
    temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum = sum + pow(digit, digits);
        temp = temp / 10;
    }

    return original == sum;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    if (isArmstrong(n))
    {
        cout << n << " is an Armstrong number" << endl;
    }
    else
    {
        cout << n << " is not an Armstrong number" << endl;
    }

    return 0;
}

