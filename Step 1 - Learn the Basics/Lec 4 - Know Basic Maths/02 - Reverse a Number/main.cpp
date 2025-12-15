#include <iostream>
using namespace std;

int reverseNumber(int n)
{
    // Handle negative numbers
    bool isNegative = false;
    if (n < 0)
    {
        isNegative = true;
        n = -n;
    }

    int reversed = 0;

    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    // Restore negative sign if needed
    if (isNegative)
        reversed = -reversed;

    return reversed;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    int reversed = reverseNumber(n);

    cout << "Reversed number = " << reversed << endl;

    return 0;
}

