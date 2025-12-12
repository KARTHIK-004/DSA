#include <iostream>
#include <stack>
using namespace std;

void explainStack()
{

    // ---------------- Creating a stack ----------------
    stack<int> st;

    // ---------------- push() ----------------
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top after pushes: " << st.top() << "\n"; // 30

    // ---------------- pop() ----------------
    st.pop();                                            // removes 30
    cout << "Stack top after pop: " << st.top() << "\n"; // 20

    // ---------------- size() ----------------
    cout << "Stack size: " << st.size() << "\n";

    // ---------------- empty() ----------------
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << "\n\n";

    // ---------------- Stack with string ----------------
    stack<string> names;
    names.push("Hello");
    names.push("World");
    names.push("Earth");

    cout << "String stack top: " << names.top() << "\n"; // Earth
    names.pop();
    cout << "After pop, new top: " << names.top() << "\n\n";

    // ---------------- Stack of pairs ----------------
    stack<pair<int, int>> sp;
    sp.push({1, 2});
    sp.push({3, 4});

    cout << "Stack of pairs top: ";
    cout << sp.top().first << ", " << sp.top().second << "\n";

    sp.pop();
    cout << "After pop, new top pair: ";
    cout << sp.top().first << ", " << sp.top().second << "\n";
}

int main()
{
    explainStack();
    return 0;
}
