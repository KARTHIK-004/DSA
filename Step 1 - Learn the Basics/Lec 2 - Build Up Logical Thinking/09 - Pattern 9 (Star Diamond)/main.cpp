#include <bits/stdc++.h>
using namespace std;

// Pattern 9: Star Diamond
void pattern9(int N)
{
    // Upper half (pyramid)
    for (int i = 0; i < N; i++)
    {
        // Print leading spaces
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half (inverted pyramid)
    for (int i = 0; i < N - 1; i++)
    {
        // Print leading spaces
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * (N - i - 1) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern9(N);
    return 0;
}

