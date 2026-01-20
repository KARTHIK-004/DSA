#include <bits/stdc++.h>
using namespace std;

// Pattern 14: Number Diamond
void pattern14(int N)
{
    // Upper half
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    // Lower half
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 1; j <= N - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
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
    pattern14(N);
    return 0;
}

