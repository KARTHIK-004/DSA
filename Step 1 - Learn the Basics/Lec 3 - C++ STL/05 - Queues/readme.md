# 📘 **NOTES — 06 Queue (C++ STL)**

A **queue** is a container based on the **FIFO** principle:

👉 **F**irst **I**n → **F**irst **O**ut

The first inserted element is the first one removed.

Queues are defined in:

```cpp
#include <queue>
```

---

# 🔹 **Why use queue?**

✔ Follows FIFO structure
✔ Useful for:

- Task scheduling
- BFS (Breadth-First Search) in graphs
- Processing requests in order
- Data buffering
- Producer-consumer problems

✔ Very simple and used everywhere in algorithms and OS concepts.

---

# 🔹 **Syntax**

```cpp
queue<type> q;
```

Examples:

```cpp
queue<int> q;
queue<string> names;
queue<pair<int,int>> qp;
```

---

# ----------------------------------------------------

# 🔹 **Basic Queue Operations**

| Operation | Meaning                           |
| --------- | --------------------------------- |
| `push(x)` | Insert element at the **back**    |
| `pop()`   | Remove element from the **front** |
| `front()` | Access the first element          |
| `back()`  | Access the last element           |
| `size()`  | Number of elements                |
| `empty()` | Checks if queue is empty          |

---

# ----------------------------------------------------

# 🔹 **push()**

Adds an element at the **end**.

```cpp
q.push(10);
q.push(20);
q.push(30);
```

Queue (front → back):
`10 20 30`

---

# 🔹 **front()**

Accesses the first element.

```cpp
cout << q.front();   // 10
```

---

# 🔹 **back()**

Accesses the last element.

```cpp
cout << q.back();    // 30
```

---

# 🔹 **pop()**

Removes the first element.

```cpp
q.pop();  // removes 10
```

Queue becomes:
`20 30`

⚠ **pop() does NOT return the removed element**.

---

# 🔹 **size()**

```cpp
cout << q.size();
```

---

# 🔹 **empty()**

```cpp
if (q.empty()) cout << "Queue is empty";
```

---

# ----------------------------------------------------

# 🔹 **Example Workflow**

```
push(5) → push(10) → push(15)

Queue (front → back): 5 10 15

front() → 5
back() → 15
pop() → removes 5
front() → 10
```

---

# ----------------------------------------------------

# 🔹 **Important Notes**

✔ Queue does **not** allow random access (no q[0])
✔ You cannot iterate normally because only front/back are accessible
✔ FIFO structure is ideal when order matters
✔ Used heavily in BFS, OS scheduling, and buffering applications

---

# ----------------------------------------------------

# 🔹 **Time Complexity of Queue Operations**

| Operation | Time Complexity |
| --------- | --------------- |
| `push(x)` | **O(1)**        |
| `pop()`   | **O(1)**        |
| `front()` | **O(1)**        |
| `back()`  | **O(1)**        |
| `size()`  | **O(1)**        |
| `empty()` | **O(1)**        |

### 💡 Explanation:

STL queue is built on **deque**, which supports constant-time insertion & removal at both ends.
Thus all queue operations work in **O(1)**.

---

# ----------------------------------------------------

# 🔹 **Summary**

- Queue follows **FIFO**
- Supports: `push`, `pop`, `front`, `back`, `size`, `empty`
- No indexing or iterating
- Used in BFS, scheduling, buffering
- All operations are **O(1)**

---
