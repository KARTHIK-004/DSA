#include <bits/stdc++.h>
using namespace std;

// Pattern 8: Inverted Star Pyramid (Centered)
void pattern8(int N)
{
    // Loop for rows
    for (int i = 0; i < N; i++)
    {
        // Print leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * (N - i) - 1; j++)
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
    pattern8(N);
    return 0;
}

