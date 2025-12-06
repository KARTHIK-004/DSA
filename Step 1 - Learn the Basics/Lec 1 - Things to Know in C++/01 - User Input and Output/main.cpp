#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    int a, b;

    // read full name
    getline(cin, name);

    // read two integers
    cin >> a >> b;

    cout << "Hello, " << name << "!" << endl;
    cout << "The sum of " << a << " and " << b << " is: " << (a + b) << endl;

    return 0;
}
