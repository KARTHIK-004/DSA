#include <iostream>
#include <map>
using namespace std;

void explainMap()
{

    // ---------------- Creating a map ----------------
    map<int, int> mp;

    // ---------------- insert() ----------------
    mp[1] = 100; // insert using []
    mp[3] = 300;
    mp.insert({2, 200}); // insert using {}
    mp.insert(make_pair(4, 400));

    cout << "Map contents (sorted keys):\n";
    for (auto x : mp)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- Accessing elements ----------------
    cout << "mp[1] = " << mp[1] << "\n"; // prints 100

    // accessing non-existing key creates it with value=0
    cout << "mp[10] (created automatically) = " << mp[10] << "\n\n";

    // ---------------- find() ----------------
    if (mp.find(3) != mp.end())
        cout << "Key 3 found with value " << mp[3] << "\n";
    else
        cout << "Key 3 not found\n";

    if (mp.find(99) == mp.end())
        cout << "Key 99 not found\n\n";

    // ---------------- count() ----------------
    cout << "Does key 2 exist? count = " << mp.count(2) << "\n";
    cout << "Does key 50 exist? count = " << mp.count(50) << "\n\n";

    // ---------------- erase(value) ----------------
    mp.erase(4); // removes key 4

    cout << "After erase(4):\n";
    for (auto x : mp)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- erase(iterator) ----------------
    auto it = mp.begin();
    mp.erase(it); // removes first key (1)

    cout << "After erase(iterator to first element):\n";
    for (auto x : mp)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- erase(range) ----------------
    mp.clear();
    mp = {{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}};

    cout << "Map before erase range:\n";
    for (auto x : mp)
        cout << x.first << " -> " << x.second << "\n";

    mp.erase(mp.begin(), mp.find(4)); // removes keys < 4

    cout << "\nAfter erase range (<4 removed):\n";
    for (auto x : mp)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- lower_bound / upper_bound ----------------
    map<int, int> t = {{10, 100}, {20, 200}, {30, 300}};

    cout << "lower_bound(15): key = " << t.lower_bound(15)->first << "\n"; // 20
    cout << "upper_bound(20): key = " << t.upper_bound(20)->first << "\n"; // 30
    cout << "\n";

    // ---------------- size(), empty(), clear() ----------------
    cout << "t.size(): " << t.size() << "\n";
    cout << "t.empty(): " << (t.empty() ? "Yes" : "No") << "\n";

    t.clear();
    cout << "After clear(): " << (t.empty() ? "Empty" : "Not empty") << "\n";
}

int main()
{
    explainMap();
    return 0;
}
