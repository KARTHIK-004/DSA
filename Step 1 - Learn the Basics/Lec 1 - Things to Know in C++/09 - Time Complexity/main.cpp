#include <iostream>
using namespace std;

// -------------------- O(1) --------------------
void constantTime()
{
    cout << "\nO(1) - Constant Time Example:\n";
    int a = 10, b = 20;
    cout << "Sum = " << (a + b) << endl; // One-step work
}

// -------------------- O(n) --------------------
void linearTime(int n)
{
    cout << "\nO(n) - Linear Time Example:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

// -------------------- O(n^2) --------------------
void quadraticTime(int n)
{
    cout << "\nO(n^2) - Quadratic Time Example:\n";
    for (int i = 0; i < n; i++)
    { // n times
        for (int j = 0; j < n; j++)
        { // n times
            cout << "* ";
        }
        cout << endl;
    }
}

// -------------------- O(log n) --------------------
void logarithmicTime(int n)
{
    cout << "\nO(log n) - Logarithmic Time Example:\n";
    int i = 1;
    while (i < n)
    {
        cout << i << " ";
        i *= 2; // grows exponentially → log n steps
    }
    cout << endl;
}

// -------------------- O(n log n) --------------------
void nlognTime(int n)
{
    cout << "\nO(n log n) - Linearithmic Time Example:\n";
    for (int i = 0; i < n; i++)
    { // n times
        int j = 1;
        while (j < n)
        { // log n times
            cout << "(" << i << "," << j << ") ";
            j *= 2;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    constantTime();
    linearTime(n);
    quadraticTime(n);
    logarithmicTime(n);
    nlognTime(n);

    return 0;
}
