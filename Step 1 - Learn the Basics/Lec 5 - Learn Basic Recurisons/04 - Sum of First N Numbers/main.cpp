#include <iostream>
using namespace std;

int sumOfN(int n)
{
    // Base case: sum of 0 numbers is 0
    if (n == 0)
        return 0;

    // Recursive case: n + sum of (n-1) numbers
    return n + sumOfN(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: \n";
    cin >> n;

    int sum = sumOfN(n);

    cout << "Sum of first " << n << " numbers = " << sum << endl;

    return 0;
}

