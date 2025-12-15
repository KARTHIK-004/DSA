#include <iostream>
using namespace std;

int findGCD(int a, int b)
{
    // Euclidean Algorithm
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    if (a == 0)
        return b;
    return a;
}

int main()
{

    int a, b;
    cout << "Enter two numbers: \n";
    cin >> a >> b;

    int gcd = findGCD(a, b);

    cout << "GCD of " << a << " and " << b << " = " << gcd << endl;

    return 0;
}

