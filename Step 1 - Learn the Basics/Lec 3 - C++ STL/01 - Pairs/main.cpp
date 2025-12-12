#include <iostream>
using namespace std;

// Pairs
void explainPair()
{

    // -------- Simple Pair --------
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;

    // -------- Nested Pair --------
    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    // -------- Array of Pairs --------
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second << endl; // accessing element
}

int main()
{
    explainPair();
    return 0;
}
