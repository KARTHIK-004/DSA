# 📘 **NOTES — 09 Multiset (C++ STL)**

A **multiset** is similar to a set, **but it allows duplicate elements**.
All elements are stored in **sorted order**, just like set.

It is implemented using a **Red-Black Tree (balanced BST)**.

Defined in:

```cpp
#include <set>
```

---

# 🔹 **Key Properties of Multiset**

✔ Elements are stored in **sorted (ascending) order**
✔ **Duplicates are allowed**
✔ Supports fast insertion, deletion, and searching
✔ Uses a tree structure → operations are **O(log n)**

---

# 🔹 **Syntax**

```cpp
multiset<type> ms;
```

Examples:

```cpp
multiset<int> ms;
multiset<string> words;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

| Operation       | Meaning                                 |
| --------------- | --------------------------------------- |
| `insert(x)`     | Inserts x (duplicates allowed)          |
| `erase(x)`      | Removes **all** occurrences of x        |
| `erase(it)`     | Removes only 1 element at iterator      |
| `find(x)`       | Returns iterator to one occurrence of x |
| `count(x)`      | Number of occurrences of x              |
| `size()`        | Number of elements                      |
| `empty()`       | Checks if multiset is empty             |
| `clear()`       | Removes all elements                    |
| `begin()/end()` | Iterators for traversal                 |

---

# ----------------------------------------------------

# 🔹 **Inserting Elements**

```cpp
multiset<int> ms;
ms.insert(10);
ms.insert(5);
ms.insert(10);   // duplicate allowed
ms.insert(20);
```

Result:

```
5 10 10 20
```

---

# 🔹 **Iterating Through Multiset**

```cpp
for (auto x : ms)
    cout << x << " ";
```

---

# 🔹 **find()**

```cpp
auto it = ms.find(10);
```

Returns an iterator to **one** occurrence of 10 (first one from left).

---

# 🔹 **count()**

```cpp
cout << ms.count(10);   // number of times 10 appears
```

Example output:

```
2
```

---

# ----------------------------------------------------

# 🔹 **erase()**

### 1️⃣ Erase ALL occurrences of a value

```cpp
ms.erase(10);   // removes both 10s
```

### 2️⃣ Erase ONLY one element using iterator

```cpp
auto it = ms.find(5);
ms.erase(it);   // removes only the element pointed by iterator
```

### 3️⃣ Erase a range

```cpp
ms.erase(ms.begin(), ms.find(20));
```

(Removes all elements before 20)

---

# ----------------------------------------------------

# 🔹 **lower_bound() & upper_bound()**

### `lower_bound(x)`

First element **>= x**

### `upper_bound(x)`

First element **> x**

Example:

```cpp
ms = {5, 10, 10, 20};

ms.lower_bound(10); // points to first 10
ms.upper_bound(10); // points to 20
```

---

# ----------------------------------------------------

# 🔹 **Time Complexity**

| Operation                  | Complexity   |
| -------------------------- | ------------ |
| `insert(x)`                | **O(log n)** |
| `erase(x)`                 | **O(log n)** |
| `find(x)`                  | **O(log n)** |
| `count(x)`                 | **O(log n)** |
| Traversal                  | **O(n)**     |
| `size(), empty(), clear()` | **O(1)**     |

Why?
Because multiset uses a **balanced BST (Red-Black Tree)**.

---

# ----------------------------------------------------

# 🔹 **Difference: Set vs Multiset**

| Feature             | Set             | Multiset        |
| ------------------- | --------------- | --------------- |
| Duplicates allowed? | ❌ No           | ✔ Yes           |
| Sorted?             | ✔ Yes           | ✔ Yes           |
| Storage             | Unique elements | Multiple copies |
| count(x) returns    | 0 or 1          | 0, 1, or many   |

---

# ----------------------------------------------------

# 🔹 **Summary**

- Multiset stores **sorted elements with duplicates**
- `insert()` always keeps order
- `erase(x)` removes all copies, `erase(it)` removes one
- Useful when frequency matters (e.g., counting, sliding window problems)
- All major operations are **O(log n)**

---
