# 📘 **NOTES — 12 Unordered Map (C++ STL)**

An **unordered_map** stores key–value pairs like `map`, **but without sorting**.
It uses **hash tables**, making operations extremely fast on average.

Defined in:

```cpp
#include <unordered_map>
```

---

# 🔹 **Key Properties of unordered_map**

✔ Stores data as **{key → value}**
✔ Keys are **NOT sorted** (random order)
✔ Much **faster** than map (average O(1))
✔ Keys must be **unique**
✔ Built using a **hash table**
✔ Best for lookup-heavy problems

---

# 🔹 **Syntax**

```cpp
unordered_map<KeyType, ValueType> ump;
```

Examples:

```cpp
unordered_map<int, int> ump;
unordered_map<string, int> freq;
unordered_map<char, string> dict;
```

---

# ----------------------------------------------------

# 🔹 **Inserting Elements**

### Method 1: Using `operator[]`

```cpp
ump[1] = 100;
ump[3] = 300;
```

### Method 2: Using `insert()`

```cpp
ump.insert({2, 200});
```

### Method 3: Using `make_pair()`

```cpp
ump.insert(make_pair(4, 400));
```

---

# ----------------------------------------------------

# 🔹 **Accessing Values**

```cpp
cout << ump[1];       // prints 100
```

⚠ IMPORTANT
If key doesn't exist, `ump[key]` **creates it with default value 0**.

To avoid accidental creation, use `find()`.

---

# 🔹 **find()**

```cpp
if (ump.find("Apple") != ump.end())
    cout << "Found Apple";
else
    cout << "Apple not found";
```

---

# 🔹 **count()**

```cpp
cout << ump.count(3);   // returns 0 or 1
```

---

# ----------------------------------------------------

# 🔹 **Traversal**

### Range-based loop

```cpp
for (auto x : ump)
    cout << x.first << " -> " << x.second << "\n";
```

### Iterator loop

```cpp
for (auto it = ump.begin(); it != ump.end(); it++)
    cout << it->first << " " << it->second << "\n";
```

⚠ Order is **NOT sorted** — hash table order.

---

# ----------------------------------------------------

# 🔹 **erase()**

### Erase by key:

```cpp
ump.erase(3);
```

### Erase by iterator:

```cpp
auto it = ump.begin();
ump.erase(it);
```

### Erase a range:

```cpp
ump.erase(ump.begin(), ump.end());
```

(Removes all elements)

---

# ----------------------------------------------------

# 🔹 **Time Complexity**

| Operation  | Average  | Worst Case |
| ---------- | -------- | ---------- |
| `insert()` | **O(1)** | O(n)       |
| `find()`   | **O(1)** | O(n)       |
| `erase()`  | **O(1)** | O(n)       |
| Traversal  | **O(n)** | O(n)       |

Worst case happens when many keys hash to the same bucket (rare).

---

# ----------------------------------------------------

# 🔹 map vs unordered_map

| Feature        | map            | unordered_map |
| -------------- | -------------- | ------------- |
| Order          | Sorted         | Unordered     |
| Speed          | O(log n)       | **O(1)** avg  |
| Implementation | Red-Black Tree | Hash Table    |
| Duplicate keys | ❌ No          | ❌ No         |
| Best Use       | Sorted data    | Fast lookups  |

---

# ----------------------------------------------------

# 🔹 **When to use unordered_map?**

Use when:

✔ You need **fast searching**
✔ Order does not matter
✔ Storing frequency counts
✔ Dictionaries, hash tables, lookups
✔ Competitive programming (most used map)

---

# ----------------------------------------------------

# 🔹 **Summary**

- unordered_map stores **unique key → value pairs** in **random order**
- Uses **hashing** → very fast O(1) average operations
- No duplicates, no sorting
- Best for lookups, frequency maps, dictionaries

---
