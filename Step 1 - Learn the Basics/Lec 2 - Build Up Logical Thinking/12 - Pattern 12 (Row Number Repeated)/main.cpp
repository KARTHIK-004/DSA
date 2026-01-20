#include <bits/stdc++.h>
using namespace std;

// Pattern 12: Number Triangle (Row Number Repeated)
void pattern12(int N)
{
    for (int i = 1; i <= N; i++)
    {
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
    pattern12(N);
    return 0;
}

