# 📘 **NOTES — 10 Unordered Set (C++ STL)**

An **unordered_set** is a container that stores **unique elements** but **NOT in sorted order**.
It is implemented using **Hash Tables**, making operations extremely fast.

Defined in:

```cpp
#include <unordered_set>
```

---

# 🔹 **Key Properties of Unordered Set**

✔ Stores **unique** elements (duplicates NOT allowed)
✔ **No ordering** — elements appear in random order
✔ Uses **hashing → average O(1)** operations
✔ Faster than `set` for search/insert/delete
✔ Ideal when order does not matter

---

# 🔹 **Syntax**

```cpp
unordered_set<type> us;
```

Examples:

```cpp
unordered_set<int> us;
unordered_set<string> names;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

| Operation   | Meaning                     |
| ----------- | --------------------------- |
| `insert(x)` | Inserts x (unique only)     |
| `erase(x)`  | Removes value x             |
| `erase(it)` | Removes element at iterator |
| `find(x)`   | Finds x in O(1) average     |
| `count(x)`  | Returns 1 if exists, else 0 |
| `size()`    | Number of elements          |
| `empty()`   | Checks if empty             |
| `clear()`   | Removes all elements        |

---

# ----------------------------------------------------

# 🔹 **Inserting Elements**

```cpp
unordered_set<int> us;
us.insert(10);
us.insert(5);
us.insert(10);   // duplicate ignored
us.insert(20);
```

Result (UNORDERED):

```
20 5 10   ← may appear in any order
```

---

# 🔹 **Traversing Unordered Set**

```cpp
for (auto x : us)
    cout << x << " ";
```

⚠ Output order is NOT sorted.

---

# 🔹 **find()**

```cpp
if (us.find(10) != us.end())
    cout << "Found";
```

---

# 🔹 **count()**

```cpp
cout << us.count(10);  // 1 or 0
```

---

# 🔹 **erase()**

### Erase by value:

```cpp
us.erase(10);
```

### Erase by iterator:

```cpp
auto it = us.find(20);
us.erase(it);
```

---

# ----------------------------------------------------

# 🔹 **Bucket & Hash Information (Optional but useful)**

Since unordered_set uses hashing:

```cpp
us.bucket_count();    // number of hash buckets
us.load_factor();     // load factor = size / bucket_count
```

These help understand performance.

---

# ----------------------------------------------------

# 🔹 **Time Complexity**

| Operation           | Average  | Worst Case |
| ------------------- | -------- | ---------- |
| `insert(x)`         | **O(1)** | O(n)       |
| `erase(x)`          | **O(1)** | O(n)       |
| `find(x)`           | **O(1)** | O(n)       |
| Traversal           | **O(n)** | O(n)       |
| `size()`, `empty()` | **O(1)** | O(1)       |

⚠ Worst-case happens only if many values hash to the same bucket.

---

# ----------------------------------------------------

# 🔹 **Differences: set vs unordered_set**

| Feature       | set              | unordered_set    |
| ------------- | ---------------- | ---------------- |
| Order         | Sorted           | Unordered        |
| Duplicates    | ❌ No            | ❌ No            |
| Underlying DS | Red-Black Tree   | Hash Table       |
| Search Time   | O(log n)         | **O(1)** avg     |
| Best Use      | Need sorted data | Need fast search |

---

# ----------------------------------------------------

# 🔹 **Summary**

- unordered_set stores **unique, unordered** elements
- Very fast: average **O(1)** operations
- No duplicates and no sorting
- Best used when **search speed is more important than order**

---
