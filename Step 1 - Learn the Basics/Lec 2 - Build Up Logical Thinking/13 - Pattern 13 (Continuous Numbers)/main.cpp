#include <bits/stdc++.h>
using namespace std;

// Pattern 13: Continuous Number Triangle
void pattern13(int N)
{
    int num = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern13(N);
    return 0;
}

