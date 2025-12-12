#include <iostream>
#include <deque>
using namespace std;

void explainDeque()
{

    // ---------------- Creating deque ----------------
    deque<int> dq = {10, 20, 30};
    cout << "Initial deque: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // ---------------- push_front / push_back ----------------
    dq.push_front(5); // {5,10,20,30}
    dq.push_back(40); // {5,10,20,30,40}

    cout << "After push_front & push_back: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // ---------------- pop_front / pop_back ----------------
    dq.pop_front(); // remove 5
    dq.pop_back();  // remove 40

    cout << "After pop_front & pop_back: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // ---------------- Access elements ----------------
    cout << "Front element: " << dq.front() << "\n";
    cout << "Back element: " << dq.back() << "\n";
    cout << "Element at index 1 (dq[1]): " << dq[1] << "\n";

    // ---------------- Insert operations ----------------
    dq.insert(dq.begin() + 1, 15); // insert 15 at index 1
    cout << "After inserting 15 at index 1: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    dq.insert(dq.begin(), 3, 100); // insert 3 copies of 100 at front
    cout << "After inserting 100,100,100 at front: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // ---------------- Erase operations ----------------
    dq.erase(dq.begin() + 2); // erase element at index 2
    cout << "After erase at index 2: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    dq.erase(dq.begin(), dq.begin() + 2); // erase first 2 elements
    cout << "After erase first 2 elements: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // ---------------- Iterator Example ----------------
    cout << "Print using iterator: ";
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    // ---------------- Size, empty, clear ----------------
    cout << "dq.size(): " << dq.size() << "\n";
    dq.clear();
    cout << "dq.empty(): " << (dq.empty() ? "true" : "false") << "\n";
}

int main()
{
    explainDeque();
    return 0;
}
