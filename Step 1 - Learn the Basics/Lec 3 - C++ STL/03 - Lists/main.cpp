#include <iostream>
#include <list>
using namespace std;

void explainList()
{

    // ------------ Creating a list ------------
    list<int> l = {10, 20, 30};

    cout << "Initial list: ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ push_front / push_back ------------
    l.push_front(5); // {5, 10, 20, 30}
    l.push_back(40); // {5, 10, 20, 30, 40}

    cout << "After push_front & push_back: ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ pop_front / pop_back ------------
    l.pop_front(); // removes 5
    l.pop_back();  // removes 40

    cout << "After pop_front & pop_back: ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ front / back ------------
    cout << "Front element: " << l.front() << "\n";
    cout << "Back element: " << l.back() << "\n";

    // ------------ Remove value (all occurrences) ------------
    l.push_back(15); // add another 15
    l.remove(15);    // removes all 15

    cout << "After remove(15): ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ Unique (removes consecutive duplicates) ------------
    l = {10, 10, 20, 20, 20, 30, 10, 10};
    l.unique(); // removes only consecutive duplicates

    cout << "After unique(): ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ sort() ------------
    l = {50, 10, 40, 20, 30};
    l.sort();

    cout << "After sort(): ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ reverse() ------------
    l.reverse();

    cout << "After reverse(): ";
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    // ------------ clear / empty ------------
    l.clear();
    cout << "After clear(), empty(): " << (l.empty() ? "List is empty" : "Not empty") << "\n";
}

int main()
{
    explainList();
    return 0;
}
