#include <bits/stdc++.h>
using namespace std;

// Pattern 7: Star Pyramid (Centered)
void pattern7(int N)
{
    // Loop for rows
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
}

int main()
{
    int N;
    cin >> N;
    pattern7(N);
    return 0;
}

