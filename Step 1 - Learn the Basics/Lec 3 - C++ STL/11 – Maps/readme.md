# 📘 **NOTES — 11 Map (C++ STL)**

A **map** is an associative container that stores elements as **key–value pairs** in **sorted order of keys**.
Each key is **unique**, and mapped to exactly one value.

Map is implemented using a **Red-Black Tree (balanced BST)**.

Defined in:

```cpp
#include <map>
```

---

# 🔹 **Key Properties of map**

✔ Stores data as **{key → value}**
✔ Keys are stored in **sorted order**
✔ Keys must be **unique**
✔ Fast operations using BST → **O(log n)**
✔ Allows access, insertion, deletion by key
✔ Very useful for counting, indexing, frequency maps, dictionaries

---

# 🔹 **Syntax**

```cpp
map<KeyType, ValueType> mp;
```

Examples:

```cpp
map<int, int> mp;                  // int → int
map<string, int> freq;             // string → count
map<char, string> code;            // char → string
```

---

# ----------------------------------------------------

# 🔹 **Inserting Key–Value Pairs**

### Method 1: Using `operator[]`

```cpp
mp[1] = 100;
mp[3] = 300;
```

### Method 2: Using `insert()`

```cpp
mp.insert({2, 200});
```

### Method 3: Using `make_pair()`

```cpp
mp.insert(make_pair(4, 400));
```

All are valid.

---

# ----------------------------------------------------

# 🔹 **Accessing Values**

```cpp
cout << mp[1];      // prints 100
```

⚠ IMPORTANT
If `mp[key]` does not exist, it will **create the key with value = 0**.

Example:

```cpp
cout << mp[10];   // creates key 10 with value 0
```

To avoid accidental insertion, use `find()`.

---

# 🔹 **find()**

```cpp
if (mp.find(3) != mp.end())
    cout << "3 exists\n";
```

If key not found:

```cpp
if (mp.find(8) == mp.end())
    cout << "8 not found\n";
```

---

# ----------------------------------------------------

# 🔹 **Traversing a Map**

### 1️⃣ Range-based loop

```cpp
for (auto x : mp)
    cout << x.first << " -> " << x.second << "\n";
```

### 2️⃣ Iterator loop

```cpp
for (auto it = mp.begin(); it != mp.end(); it++)
    cout << it->first << " " << it->second << "\n";
```

---

# ----------------------------------------------------

# 🔹 **erase()**

### Erase by key:

```cpp
mp.erase(3);
```

### Erase by iterator:

```cpp
auto it = mp.begin();
mp.erase(it);
```

### Erase a range:

```cpp
mp.erase(mp.begin(), mp.find(4));
```

(Deletes everything before key 4)

---

# ----------------------------------------------------

# 🔹 **count()**

Since keys are unique:

```cpp
mp.count(3);   // returns 0 or 1
```

---

# ----------------------------------------------------

# 🔹 **upper_bound() & lower_bound()**

### lower_bound(key)

First iterator **>= key**

### upper_bound(key)

First iterator **> key**

Example:

```cpp
mp = {{1,100}, {2,200}, {5,500}};
cout << mp.lower_bound(3)->first; // 5
cout << mp.upper_bound(2)->first; // 5
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
| Iteration           | **O(n)**     |
| `size()`, `empty()` | **O(1)**     |

Reason: Uses **Red-Black Tree (Balanced BST)**.

---

# ----------------------------------------------------

# 🔹 **Important Notes**

✔ Keys are always **sorted**
✔ No duplicate keys allowed
✔ Access using `[]` can create new elements
✔ Best for dictionaries, frequency maps, ordered lookups
✔ Use unordered_map for **faster**, but unsorted operations

---

# ----------------------------------------------------

# 🔹 **Summary**

- Map stores **unique keys** in **sorted order**
- Provides key → value access
- All main operations are **O(log n)**
- Useful for frequency counting, indexing, searching, and associative storage

---
