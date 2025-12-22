#include <bits/stdc++.h>
using namespace std;

// Pattern 4: Row Number Triangle
void pattern4(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (row number repeated)
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern4(N);
    return 0;
}

