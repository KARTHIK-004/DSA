#include <iostream>
#include <unordered_map>
using namespace std;

void explainUnorderedMap()
{

    // ---------------- Creating unordered_map ----------------
    unordered_map<int, string> ump;

    // ---------------- insert() ----------------
    ump[1] = "One"; // using []
    ump[3] = "Three";

    ump.insert({2, "Two"}); // using {}
    ump.insert(make_pair(4, "Four"));

    cout << "Unordered Map contents (random order):\n";
    for (auto x : ump)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- Accessing elements ----------------
    cout << "ump[1] = " << ump[1] << "\n";

    // accessing non-existing key creates it with default value ""
    cout << "ump[10] (auto-created) = \"" << ump[10] << "\"\n\n";

    // ---------------- find() ----------------
    if (ump.find(3) != ump.end())
        cout << "Key 3 found with value: " << ump[3] << "\n";
    else
        cout << "Key 3 not found\n";

    if (ump.find(99) == ump.end())
        cout << "Key 99 not found\n\n";

    // ---------------- count() ----------------
    cout << "Does key 2 exist? count = " << ump.count(2) << "\n";
    cout << "Does key 50 exist? count = " << ump.count(50) << "\n\n";

    // ---------------- erase(key) ----------------
    ump.erase(4);

    cout << "After erase(4):\n";
    for (auto x : ump)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- erase(iterator) ----------------
    auto it = ump.begin();
    ump.erase(it); // removes any one key (unordered)

    cout << "After erase(iterator):\n";
    for (auto x : ump)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // ---------------- size(), empty(), clear() ----------------
    cout << "Size: " << ump.size() << "\n";
    cout << "Empty? " << (ump.empty() ? "Yes" : "No") << "\n";

    ump.clear();
    cout << "After clear(): " << (ump.empty() ? "Empty" : "Not empty") << "\n";
}

int main()
{
    explainUnorderedMap();
    return 0;
}
