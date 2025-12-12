#include <bits/stdc++.h>
using namespace std;

void pattern2(int N)
{
    // Loop for rows
    for (int i = 0; i < N; i++)
    {
        // Loop for columns (stars in each row)
        for (int j = 0; j <= i; j++)
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
    pattern2(N);

    return 0;
}
