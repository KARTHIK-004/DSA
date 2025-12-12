#include <iostream>
#include <queue>
using namespace std;

void explainPriorityQueue()
{

    // ---------------- MAX HEAP (default) ----------------
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Max-Heap top: " << pq.top() << "\n"; // 20

    pq.pop();                                           // removes 20
    cout << "After pop, new top: " << pq.top() << "\n"; // 15

    cout << "Size: " << pq.size() << "\n";
    cout << "Empty? " << (pq.empty() ? "Yes" : "No") << "\n\n";

    // ---------------- MIN HEAP ----------------
    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(10);
    minpq.push(5);
    minpq.push(20);
    minpq.push(15);

    cout << "Min-Heap top: " << minpq.top() << "\n"; // 5

    minpq.pop();                                             // removes 5
    cout << "After pop, new top: " << minpq.top() << "\n\n"; // 10

    // ---------------- Priority Queue of Pairs ----------------
    priority_queue<pair<int, int>> ppq;

    ppq.push({2, 50});
    ppq.push({3, 10});
    ppq.push({3, 40});

    cout << "Pair PQ top: ("
         << ppq.top().first << ", "
         << ppq.top().second << ")\n"; // (3, 40)

    ppq.pop();

    cout << "After pop, new top pair: ("
         << ppq.top().first << ", "
         << ppq.top().second << ")\n";
}

int main()
{
    explainPriorityQueue();
    return 0;
}
