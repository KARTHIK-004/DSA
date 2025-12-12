#include <iostream>
#include <unordered_set>
using namespace std;

void explainUnorderedSet()
{

    // ---------------- Creating an unordered set ----------------
    unordered_set<int> us;

    // ---------------- insert() ----------------
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(10); // duplicate ignored

    cout << "Unordered Set contents: ";
    for (auto x : us)
        cout << x << " ";
    cout << "\n\n"; // order is random

    // ---------------- find() ----------------
    if (us.find(10) != us.end())
        cout << "10 found in unordered set\n";
    else
        cout << "10 not found\n";

    if (us.find(100) == us.end())
        cout << "100 not found\n";

    cout << "\n";

    // ---------------- count() ----------------
    cout << "Does 20 exist? count = " << us.count(20) << "\n";   // 1
    cout << "Does 50 exist? count = " << us.count(50) << "\n\n"; // 0

    // ---------------- erase(value) ----------------
    us.erase(5);

    cout << "After erase(5): ";
    for (auto x : us)
        cout << x << " ";
    cout << "\n";

    // ---------------- erase(iterator) ----------------
    auto it = us.find(20);
    if (it != us.end())
        us.erase(it);

    cout << "After erase(iterator to 20): ";
    for (auto x : us)
        cout << x << " ";
    cout << "\n\n";

    // ---------------- size(), empty(), clear() ----------------
    cout << "Size: " << us.size() << "\n";
    cout << "Empty? " << (us.empty() ? "Yes" : "No") << "\n";

    us.clear();
    cout << "After clear(): " << (us.empty() ? "Empty" : "Not empty") << "\n";
}

int main()
{
    explainUnorderedSet();
    return 0;
}
