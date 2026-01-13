#include <bits/stdc++.h>
using namespace std;

// Pattern 6: Inverted Number Triangle
void pattern6(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (numbers decrease each row)
        for (int j = 1; j <= N - i + 1; j++)
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
    pattern6(N);
    return 0;
}

