#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ---------------- Custom Comparator for Pair Sorting ----------------
bool comp(pair<int, int> p1, pair<int, int> p2)
{

    // Sort by second element (ascending)
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    // If second is same → sort first element in descending
    if (p1.first > p2.first)
        return true;

    return false;
}

void explainSort()
{

    // ---------------- Basic Sorting ----------------
    int a[] = {12, 5, 7, 1, 9};
    int n = 5;

    sort(a, a + n);

    cout << "Array after sort: ";
    for (int i : a)
        cout << i << " ";
    cout << "\n";

    // ---------------- Sort range only ----------------
    sort(a + 1, a + 4); // sort indices 1..3

    cout << "After sorting subrange [1..3]: ";
    for (int i : a)
        cout << i << " ";
    cout << "\n\n";

    // ---------------- Sort Vector ----------------
    vector<int> v = {10, 20, 30, 5, 15};
    sort(v.begin(), v.end());

    cout << "Vector sorted: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // ---------------- Descending Sort ----------------
    sort(v.begin(), v.end(), greater<int>());

    cout << "Vector sorted descending: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n\n";

    // ---------------- Sorting Pair Array using Comparator ----------------
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    int m = 3;

    sort(arr, arr + m, comp);

    cout << "Pair array sorted using comparator:\n";
    for (auto &p : arr)
        cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n\n";

    // ---------------- popcount / popcountll ----------------
    int num1 = 7; // 7 = 111 → 3 set bits
    cout << "popcount(7) = " << __builtin_popcount(num1) << "\n";

    long long num2 = 165786578687LL;
    cout << "popcountll(" << num2 << ") = " << __builtin_popcountll(num2) << "\n\n";

    // ---------------- next_permutation example ----------------
    string s = "123";

    cout << "All permutations of 123:\n";
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    cout << "\n";

    // ---------------- max_element & min_element ----------------
    int maxi = *max_element(a, a + n);
    int mini = *min_element(a, a + n);

    cout << "max_element in a: " << maxi << "\n";
    cout << "min_element in a: " << mini << "\n";
}

int main()
{
    explainSort();
    return 0;
}
