# 📘 **NOTES — 05 Stack (C++ STL)**

A **stack** is a container based on the **LIFO** principle:

👉 **L**ast **I**n → **F**irst **O**ut

The last inserted element is the first one removed.

Stacks are defined in:

```cpp
#include <stack>
```

---

# 🔹 **Why use stack?**

✔ Follows LIFO (Last-In-First-Out)
✔ Useful for:

- Reversing data
- Undo operations
- Expression evaluation (postfix/infix)
- Recursion internal working
- Backtracking algorithms
- DFS in graphs

✔ Simple but very powerful structure

---

# 🔹 **Syntax**

```cpp
stack<type> st;
```

Examples:

```cpp
stack<int> st;
stack<string> history;
stack<pair<int,int>> sp;
```

---

# ----------------------------------------------------

# 🔹 **Basic Stack Operations**

| Operation | Meaning                    |
| --------- | -------------------------- |
| `push(x)` | Insert element on top      |
| `pop()`   | Remove top element         |
| `top()`   | Access top element         |
| `size()`  | Returns number of elements |
| `empty()` | Checks if stack is empty   |

---

# ----------------------------------------------------

# 🔹 **push()**

Adds an element to the **top** of the stack.

```cpp
st.push(10);
st.push(20);
```

Stack (top at right):
`10 20`

---

# 🔹 **top()**

Returns the top element.

```cpp
cout << st.top();   // prints 20
```

---

# 🔹 **pop()**

Removes the top element.

```cpp
st.pop();
```

After pop:
`10`

⚠ **pop() does NOT return the removed element**.

---

# 🔹 **size()**

```cpp
cout << st.size();
```

---

# 🔹 **empty()**

```cpp
if (st.empty()) cout << "Stack is empty";
```

---

# ----------------------------------------------------

# 🔹 **Example Workflow**

```
push(5) → push(10) → push(15)

Stack (top at right): 5 10 15

top() → 15
pop() → removes 15
top() → 10
```

---

# ----------------------------------------------------

# 🔹 **Time Complexity of Stack Operations**

| Operation | Time Complexity |
| --------- | --------------- |
| `push(x)` | **O(1)**        |
| `pop()`   | **O(1)**        |
| `top()`   | **O(1)**        |
| `size()`  | **O(1)**        |
| `empty()` | **O(1)**        |

### 💡 Explanation:

A stack in STL internally uses a **deque** or **vector**, both of which provide constant-time operations for push/pop at the end.

So **all stack operations are O(1)**.

# ----------------------------------------------------

# 🔹 **Important Notes**

✔ You cannot access stack elements by index (`st[0]` ❌)
✔ Only the **top element** is accessible
✔ LIFO behavior is ideal for tasks needing history or backtracking

---

# ----------------------------------------------------

# 🔹 **Summary**

- Stack follows **LIFO**
- `push()`, `pop()`, `top()` are the main operations
- No direct indexing or iterating
- Used in recursion, expression evaluation, backtracking, DFS

---
