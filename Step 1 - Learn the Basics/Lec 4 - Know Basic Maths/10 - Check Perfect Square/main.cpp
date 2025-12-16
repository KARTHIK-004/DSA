#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n)
{
    // Negative numbers cannot be perfect squares
    if (n < 0)
        return false;

    // 0 and 1 are perfect squares
    if (n == 0 || n == 1)
        return true;

    // Find the square root
    int sqrtN = sqrt(n);

    // Check if square of sqrtN equals n
    return (sqrtN * sqrtN == n);
}

int main()
{

    int n;
    cout << "Enter a number: \n";
    cin >> n;

    if (isPerfectSquare(n))
    {
        int sqrtN = sqrt(n);
        cout << n << " is a perfect square (sqrt = " << sqrtN << ")" << endl;
    }
    else
    {
        cout << n << " is not a perfect square" << endl;
    }

    return 0;
}

