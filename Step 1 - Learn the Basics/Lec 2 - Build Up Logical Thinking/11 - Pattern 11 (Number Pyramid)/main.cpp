#include <bits/stdc++.h>
using namespace std;

// Pattern 11: Number Pyramid (Centered)
void pattern11(int N)
{
    for (int i = 1; i <= N; i++)
    {
        // Print leading spaces
        for (int j = 1; j <= N - i; j++)
        {
            cout << "  ";
        }
        // Print ascending numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        // Print descending numbers
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern11(N);
    return 0;
}

