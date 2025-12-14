#include <iostream>
using namespace std;

int countDigits(int n)
{

    // Handle negative numbers
    if (n < 0)
        n = -n;

    // Special case
    if (n == 0)
        return 1;

    int cnt = 0;

    while (n > 0)
    {
        n = n / 10; // remove last digit
        cnt++;
    }

    return cnt;
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    int digits = countDigits(n);

    cout << "Number of digits = " << digits << endl;

    return 0;
}
