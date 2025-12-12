# 📘 **NOTES — 04 Deque (C++ STL)**

A **deque** (Double-Ended Queue) is a container in C++ that allows **insertion and deletion from both ends** efficiently.

It is defined in:

```cpp
#include <deque>
```

Deque = Dynamic array + Doubly-ended operations.

---

# 🔹 **Why use deque?**

✔ Fast insertion at **front** and **back**
✔ Fast deletion at **front** and **back**
✔ Supports random access (like a vector)
✔ No fixed size
✔ Useful for sliding window problems, queues, and optimizations

---

# 🔹 **Syntax**

```cpp
deque<type> dq;
```

Examples:

```cpp
deque<int> d;
deque<string> names;
deque<pair<int,int>> dp;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

## 1️⃣ push_front()

```cpp
dq.push_front(10);   // insert at beginning
```

## 2️⃣ push_back()

```cpp
dq.push_back(20);    // insert at end
```

## 3️⃣ pop_front()

```cpp
dq.pop_front();      // remove from beginning
```

## 4️⃣ pop_back()

```cpp
dq.pop_back();       // remove from end
```

---

# ----------------------------------------------------

# 🔹 **Accessing Elements**

Deque supports **random access** like vector:

```cpp
dq[0];       // direct indexing
dq.at(1);    // bounds-checked access
dq.front();  // first element
dq.back();   // last element
```

---

# ----------------------------------------------------

# 🔹 **Iterating Through Deque**

### Using iterator:

```cpp
for (auto it = dq.begin(); it != dq.end(); it++) {
    cout << *it << " ";
}
```

### Using range-based loop:

```cpp
for (auto x : dq) {
    cout << x << " ";
}
```

---

# ----------------------------------------------------

# 🔹 **Insert & Erase**

### Insert at a specific index:

```cpp
dq.insert(dq.begin() + 1, 50);
```

### Insert multiple values:

```cpp
dq.insert(dq.begin(), 3, 100);  // inserts {100,100,100}
```

### Erase single element:

```cpp
dq.erase(dq.begin() + 2);
```

### Erase a range:

```cpp
dq.erase(dq.begin(), dq.begin() + 3);
```

---

# ----------------------------------------------------

# 🔹 **Useful Functions**

| Function              | Meaning                            |
| --------------------- | ---------------------------------- |
| `dq.size()`           | number of elements                 |
| `dq.empty()`          | checks if deque is empty           |
| `dq.clear()`          | deletes all elements               |
| `dq.swap(d2)`         | swaps with another deque           |
| `dq.assign(n, value)` | fills deque with n copies of value |

---

# ----------------------------------------------------

# 🔹 **Difference: Vector vs Deque vs List**

| Feature          | Vector     | Deque   | List         |
| ---------------- | ---------- | ------- | ------------ |
| Random access    | ✔ Yes      | ✔ Yes   | ❌ No        |
| Insert at back   | ✔ Fast     | ✔ Fast  | ✔ Fast       |
| Insert at front  | ❌ Slow    | ✔ Fast  | ✔ Fast       |
| Insert in middle | ❌ Slow    | ❌ Slow | ✔ Fast       |
| Memory layout    | Contiguous | Blocks  | Linked nodes |

---

# ----------------------------------------------------

# 🔹 **Summary**

- **deque** allows fast insertion & deletion at both ends
- Supports random access like vector
- More flexible than vector for front operations
- Not as efficient as list for deep middle insertions
- Common in problems requiring sliding windows, indexing + queue behavior

---
