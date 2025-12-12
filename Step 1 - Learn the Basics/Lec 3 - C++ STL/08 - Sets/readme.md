# 📘 **NOTES — 08 Set (C++ STL)**

A **set** in C++ is a container that stores **unique** elements in **sorted (ascending) order**.
It is implemented using a **balanced BST (Red-Black Tree)**.

Set is defined in:

```cpp
#include <set>
```

---

# 🔹 **Key Properties of set**

✔ Stores **unique** values (no duplicates)
✔ Elements are **always sorted**
✔ Supports fast operations (insert, erase, find)
✔ Uses **tree-based structure → O(log n)**
✔ Provides ordered traversal

---

# 🔹 **Syntax**

```cpp
set<type> s;
```

Examples:

```cpp
set<int> s;
set<string> names;
set<char> letters;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

| Operation       | Meaning                                     |
| --------------- | ------------------------------------------- |
| `insert(x)`     | Inserts x in sorted order                   |
| `erase(x)`      | Removes value x                             |
| `erase(it)`     | Removes element at iterator                 |
| `find(x)`       | Returns iterator to x (or end if not found) |
| `count(x)`      | Returns 1 if exists, else 0                 |
| `size()`        | Number of elements                          |
| `empty()`       | Checks if set is empty                      |
| `clear()`       | Removes all elements                        |
| `begin()/end()` | Iterators for traversal                     |

---

# ----------------------------------------------------

# 🔹 **Inserting Values**

```cpp
set<int> s;
s.insert(10);
s.insert(5);
s.insert(20);
s.insert(5);   // duplicate ignored
```

Result:

```
5 10 20
```

---

# 🔹 **Traversing a Set**

```cpp
for (auto x : s)
    cout << x << " ";
```

OR using iterators:

```cpp
for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
```

---

# 🔹 **find()**

```cpp
auto it = s.find(10);
if (it != s.end())
    cout << "Found";
```

If element does not exist:

```cpp
if (s.find(100) == s.end())
    cout << "Not found";
```

---

# 🔹 **erase()**

### 1️⃣ Erase by value

```cpp
s.erase(10);
```

### 2️⃣ Erase using iterator

```cpp
auto it = s.find(5);
s.erase(it);
```

### 3️⃣ Erase a range

```cpp
s.erase(s.begin(), s.find(20));
```

(Removes elements before 20)

---

# 🔹 **count()**

Since set stores unique values:

```cpp
s.count(10);   // returns 1 if exists, else 0
```

---

# 🔹 **upper_bound() & lower_bound()**

### `lower_bound(x)`

Returns iterator to **first element >= x**

### `upper_bound(x)`

Returns iterator to **first element > x**

Example:

```cpp
auto it = s.lower_bound(10);
auto it2 = s.upper_bound(10);
```

---

# ----------------------------------------------------

# 🔹 **Time Complexity**

| Operation           | Complexity   |
| ------------------- | ------------ |
| `insert(x)`         | **O(log n)** |
| `erase(x)`          | **O(log n)** |
| `find(x)`           | **O(log n)** |
| `count(x)`          | **O(log n)** |
| `size()`, `empty()` | **O(1)**     |
| Traversal           | **O(n)**     |

Why O(log n)?
Because set uses a **Red-Black Tree** internally.

---

# ----------------------------------------------------

# 🔹 **Important Notes**

✔ Set automatically removes duplicates
✔ Set always stores values in **sorted order**
✔ No indexing like `s[0]` (because not contiguous)
✔ Best used when you need **unique sorted data**

---

# ----------------------------------------------------

# 🔹 **Summary**

- Set stores **unique, sorted elements**
- All main operations take **O(log n)**
- Supports insertion, deletion, search efficiently
- Ideal when ordering & uniqueness are required

---
