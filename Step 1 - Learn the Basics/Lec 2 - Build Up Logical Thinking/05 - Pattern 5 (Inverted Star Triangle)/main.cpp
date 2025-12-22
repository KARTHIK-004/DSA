#include <bits/stdc++.h>
using namespace std;

// Pattern 5: Inverted Star Triangle
void pattern5(int N)
{
    // Loop for rows
    for (int i = 0; i < N; i++)
    {
        // Loop for columns (stars decrease each row)
        for (int j = 0; j < N - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern5(N);
    return 0;
}

