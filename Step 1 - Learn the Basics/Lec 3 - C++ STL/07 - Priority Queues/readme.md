# 📘 **NOTES — 07 Priority Queue (C++ STL)**

A **priority_queue** is a special type of queue where elements are removed in order of **priority**, not FIFO.

By default, the **largest element has highest priority** → this is called a **Max-Heap**.

It is defined in:

```cpp
#include <queue>
```

---

# 🔹 **Why use priority queue?**

✔ Automatically keeps elements ordered by priority
✔ Efficient for:

- Finding maximum/minimum quickly
- Sorting-like operations
- Dijkstra’s algorithm (shortest path)
- Task scheduling
- Greedy algorithms
- Anytime you need the “largest” or “smallest” element frequently

✔ Offers **logarithmic time** insertion & deletion.

---

# 🔹 **Types of Priority Queues**

### 1️⃣ **Max-Heap (Default)**

Largest element comes out first.

```cpp
priority_queue<int> pq;
```

### 2️⃣ **Min-Heap**

Smallest element comes out first.

```cpp
priority_queue<int, vector<int>, greater<int>> pq_min;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

| Operation | Meaning                         |
| --------- | ------------------------------- |
| `push(x)` | Insert element with priority    |
| `pop()`   | Remove highest-priority element |
| `top()`   | Access highest-priority element |
| `size()`  | Number of elements              |
| `empty()` | Check if PQ is empty            |

---

# ----------------------------------------------------

# 🔹 **Max-Heap Example (Default)**

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(5);
pq.push(20);
pq.push(15);
```

Internally stored as a heap:

```
Top element → 20
```

Because **20 is the largest**.

---

# 🔹 **top()**

```cpp
cout << pq.top();   // prints the largest element
```

---

# 🔹 **pop()**

Removes the highest-priority element.

```cpp
pq.pop();   // removes the largest element
```

---

# 🔹 **Min-Heap Example**

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(10);
pq.push(5);
pq.push(20);
```

Here:

```
Top element → 5
```

Because **smallest element is given highest priority**.

---

# ----------------------------------------------------

# 🔹 **Priority Queue With Custom Data (Pair)**

Pairs are prioritized by:

1️⃣ First element
2️⃣ Then second element

Example:

```cpp
priority_queue<pair<int,int>> pq;
pq.push({2, 50});
pq.push({3, 10});
pq.push({3, 40});
```

Largest pair first → `{3, 40}`
(because 3 > 2, and 40 > 10)

---

# ----------------------------------------------------

# 🔹 **Time Complexity**

| Operation | Max-Heap     | Min-Heap     |
| --------- | ------------ | ------------ |
| `push()`  | **O(log n)** | **O(log n)** |
| `pop()`   | **O(log n)** | **O(log n)** |
| `top()`   | **O(1)**     | **O(1)**     |
| `size()`  | **O(1)**     | **O(1)**     |
| `empty()` | **O(1)**     | **O(1)**     |

### 💡 Why log(n)?

Priority queue uses a **binary heap**, so inserting or removing requires adjusting the heap → O(log n).

---

# ----------------------------------------------------

# 🔹 **Important Notes**

✔ PQ does **not** provide index access → `pq[0]` ❌
✔ PQ always keeps the **top element** as highest priority
✔ PQ is best when you need fast max/min extraction
✔ Internally uses **heap** for efficiency

---

# ----------------------------------------------------

# 🔹 **Summary**

- Priority Queue = Max-Heap (default)
- Min-Heap can be created with `greater<int>`
- Highest-priority element is always accessible at `top()`
- Insertion & deletion are **O(log n)**
- Ideal for graph algorithms, scheduling, greedy methods

---
