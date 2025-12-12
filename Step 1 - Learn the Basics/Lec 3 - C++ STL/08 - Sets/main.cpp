#include <iostream>
#include <set>
using namespace std;

void explainSet()
{

    // ---------------- Creating a set ----------------
    set<int> s;

    // ---------------- insert() ----------------
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(5); // duplicate ignored

    cout << "Set after inserts (sorted & unique): ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n\n";

    // ---------------- find() ----------------
    auto it = s.find(10);
    if (it != s.end())
        cout << "10 found in set\n";
    else
        cout << "10 not found\n";

    // find non-existing element
    if (s.find(100) == s.end())
        cout << "100 not found\n";

    cout << "\n";

    // ---------------- erase(value) ----------------
    s.erase(5); // remove 5

    cout << "After erase(5): ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n";

    // ---------------- erase(iterator) ----------------
    it = s.find(20);
    if (it != s.end())
        s.erase(it);

    cout << "After erase(iterator to 20): ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n";

    // ---------------- erase(range) ----------------
    s.insert(1);
    s.insert(15);
    s.insert(25);

    // erase all elements < 15
    s.erase(s.begin(), s.lower_bound(15));

    cout << "After erase range (<15 removed): ";
    for (auto x : s)
        cout << x << " ";
    cout << "\n\n";

    // ---------------- count() ----------------
    cout << "Does 15 exist? (count): " << s.count(15) << "\n";
    cout << "Does 100 exist? (count): " << s.count(100) << "\n\n";

    // ---------------- lower_bound / upper_bound ----------------
    s = {10, 20, 30, 40, 50};

    cout << "lower_bound(25): " << *s.lower_bound(25) << "\n"; // >= 25 → 30
    cout << "upper_bound(30): " << *s.upper_bound(30) << "\n"; // > 30 → 40

    cout << "\n";

    // ---------------- size(), empty(), clear() ----------------
    cout << "Set size: " << s.size() << "\n";
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << "\n";

    s.clear();
    cout << "After clear(): " << (s.empty() ? "Set is empty" : "Not empty") << "\n";
}

int main()
{
    explainSet();
    return 0;
}
