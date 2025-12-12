#include <iostream>
#include <queue>
using namespace std;

void explainQueue()
{

    // ---------------- Creating a queue ----------------
    queue<int> q;

    // ---------------- push() ----------------
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front after pushes: " << q.front() << "\n"; // 10
    cout << "Back after pushes: " << q.back() << "\n";   // 30

    // ---------------- pop() ----------------
    q.pop();                                          // removes 10
    cout << "Front after pop: " << q.front() << "\n"; // 20

    // ---------------- size() ----------------
    cout << "Queue size: " << q.size() << "\n";

    // ---------------- empty() ----------------
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n\n";

    // ---------------- Queue with strings ----------------
    queue<string> names;
    names.push("Hello");
    names.push("World");
    names.push("Earth");

    cout << "String queue front: " << names.front() << "\n";
    cout << "String queue back: " << names.back() << "\n";

    names.pop(); // removes "Hello"
    cout << "After pop, new front: " << names.front() << "\n\n";

    // ---------------- Queue of pairs ----------------
    queue<pair<int, int>> qp;
    qp.push({1, 2});
    qp.push({3, 4});

    cout << "Queue of pairs front: ";
    cout << qp.front().first << ", " << qp.front().second << "\n";

    qp.pop(); // remove {1,2}

    cout << "After pop, new front pair: ";
    cout << qp.front().first << ", " << qp.front().second << "\n";
}

int main()
{
    explainQueue();
    return 0;
}
