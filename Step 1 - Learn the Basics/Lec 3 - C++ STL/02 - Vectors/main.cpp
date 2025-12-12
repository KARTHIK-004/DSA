#include <iostream>
#include <vector>
#include <utility> // pair
using namespace std;

int main()
{
    // Basic vector and push_back
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(12);
    v.push_back(23);

    cout << "Initial v (index loop): ";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";

    cout << "Print using range-for (auto): ";
    for (auto x : v)
        cout << x << " ";
    cout << "\n";

    cout << "Print using iterator (begin->end): ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Print using reverse iterator (rbegin->rend): ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";
    cout << "\n\n";

    // Erase single element (erase at index 1)
    // v = {10, 20, 12, 23}
    v.erase(v.begin() + 1); // removes 20
    cout << "After erase(v.begin()+1): ";
    for (auto x : v)
        cout << x << " ";
    cout << "\n";

    // Erase a range (erase indices 1..2 exclusive of end)
    // First ensure vector has enough elements
    v = {10, 20, 12, 23, 35}; // reset to demo
    // remove elements at indices 2 and 3 -> use begin()+2, begin()+4 (end exclusive)
    v.erase(v.begin() + 2, v.begin() + 4); // removes 12 and 23
    cout << "After erase(v.begin()+2, v.begin()+4): ";
    for (auto x : v)
        cout << x << " ";
    cout << "\n\n";

    // Insert operations
    vector<int> v_ins = {100, 100};
    cout << "v_ins start: ";
    for (auto x : v_ins)
        cout << x << " ";
    cout << "\n";

    v_ins.insert(v_ins.begin(), 300); // insert single at front -> {300,100,100}
    cout << "After insert(v_ins.begin(), 300): ";
    for (auto x : v_ins)
        cout << x << " ";
    cout << "\n";

    v_ins.insert(v_ins.begin() + 1, 2, 10); // insert two copies of 10 at pos 1
    cout << "After insert(... +1, 2, 10): ";
    for (auto x : v_ins)
        cout << x << " ";
    cout << "\n";

    vector<int> copyVec(2, 50); // {50, 50}
    v_ins.insert(v_ins.begin(), copyVec.begin(), copyVec.end());
    cout << "After inserting copyVec at begin: ";
    for (auto x : v_ins)
        cout << x << " ";
    cout << "\n\n";

    // pop_back, size, empty
    cout << "v_ins size before pop_back: " << v_ins.size() << "\n";
    v_ins.pop_back();
    cout << "After pop_back: ";
    for (auto x : v_ins)
        cout << x << " ";
    cout << "\n";
    cout << "Is v_ins empty()? " << (v_ins.empty() ? "yes" : "no") << "\n\n";

    // Erase example with comments
    vector<int> v3 = {10, 20, 30, 40, 50};
    cout << "v3 before erase: ";
    for (auto x : v3)
        cout << x << " ";
    cout << "\n";
    v3.erase(v3.begin() + 2); // remove 30
    cout << "v3 after erase at index 2: ";
    for (auto x : v3)
        cout << x << " ";
    cout << "\n\n";

    // Copying vectors (copy constructor and assignment)
    vector<int> vA = {1, 2, 3};
    vector<int> vB(vA); // copy constructor
    vector<int> vC;
    vC = vA; // assignment
    cout << "vA: ";
    for (auto x : vA)
        cout << x << " ";
    cout << "\nvB (copy constructor): ";
    for (auto x : vB)
        cout << x << " ";
    cout << "\nvC (assignment): ";
    for (auto x : vC)
        cout << x << " ";
    cout << "\n\n";

    // swap and clear
    vector<int> v1 = {10, 20};
    vector<int> v2 = {30, 40};
    cout << "Before swap v1: ";
    for (auto x : v1)
        cout << x << " ";
    cout << "  v2: ";
    for (auto x : v2)
        cout << x << " ";
    cout << "\n";
    v1.swap(v2);
    cout << "After swap v1: ";
    for (auto x : v1)
        cout << x << " ";
    cout << "  v2: ";
    for (auto x : v2)
        cout << x << " ";
    cout << "\n";
    v2.clear();
    cout << "After clear, v2.empty()? " << (v2.empty() ? "yes" : "no") << "\n\n";

    // Vector of pairs
    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.push_back(make_pair(3, 4));
    vp.emplace_back(5, 6); // in-place construct
    cout << "Vector of pairs:\n";
    for (auto &p : vp)
    {
        cout << p.first << ", " << p.second << "\n";
    }
    cout << "\n";

    // Access pair inside array-like vector
    cout << "Access vp[1].second = " << vp[1].second << "\n\n";

    return 0;
}
