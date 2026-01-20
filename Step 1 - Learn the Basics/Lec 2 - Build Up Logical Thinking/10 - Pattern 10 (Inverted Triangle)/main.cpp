#include <bits/stdc++.h>
using namespace std;

// Pattern 10: Inverted Right Triangle with Numbers
void pattern10(int N)
{
    for (int i = 1; i <= N; i++)
    {
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
    pattern10(N);
    return 0;
}

