#include <bits/stdc++.h>
using namespace std;

// Pattern 3: Number Triangle (Sequential)
void pattern3(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (numbers in each row)
        for (int j = 1; j <= i; j++)
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
    pattern3(N);
    return 0;
}

