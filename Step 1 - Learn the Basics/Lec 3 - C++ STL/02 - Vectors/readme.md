# 📘 **NOTES — 02 Vector (C++ STL)**

A **vector** in C++ is a dynamic array provided by STL.
It automatically grows and shrinks in size and provides many useful functions for insertion, deletion, and traversal.

Vectors are defined in the **`<vector>`** header.

---

# 🔹 **Why use vector?**

✔ Dynamic size (unlike arrays)
✔ Easy insertion & deletion
✔ Random access using index
✔ Many built-in functions
✔ Ideal for competitive programming
✔ Works well with pairs and 2D structures

---

# 🔹 **Syntax**

```cpp
vector<type> variableName;
```

Examples:

```cpp
vector<int> v;
vector<string> names;
vector<pair<int, int>> vp;
```

---

# ----------------------------------------------------

# 🟦 **Basic Vector Operations**

## 1️⃣ Push elements

```cpp
v.push_back(10);
v.push_back(20);
```

## 2️⃣ Pop element

```cpp
v.pop_back();
```

## 3️⃣ Accessing Elements

```cpp
v[0];        // direct access
v.at(1);     // bounds-checked access
v.front();   // first element
v.back();    // last element
```

## 4️⃣ Size of Vector

```cpp
v.size();
```

---

# ----------------------------------------------------

# 🟩 **Iterating Through Vector**

### 🔸 Using index loop:

```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

### 🔸 Using range-based loop:

```cpp
for (int x : v) {
    cout << x << " ";
}
```

### 🔸 Using iterators (begin → end):

```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

### 🔸 Using reverse iterators (rbegin → rend):

```cpp
for (auto it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << " ";
}
```

`auto` simplifies iterator declaration.

---

# ----------------------------------------------------

# 🟧 **Vector Initialization**

### 1️⃣ Empty vector

```cpp
vector<int> v;
```

### 2️⃣ With size

```cpp
vector<int> v(5);   // {0,0,0,0,0}
```

### 3️⃣ With size + initial value

```cpp
vector<int> v(5, 10); // {10,10,10,10,10}
```

### 4️⃣ Copy another vector

```cpp
vector<int> v2(v);
```

---

# ----------------------------------------------------

# 🟥 **Erase Operations**

### 1️⃣ Remove one element

```cpp
v.erase(v.begin() + 1); // removes element at index 1
```

### 2️⃣ Remove a range

```cpp
v.erase(v.begin() + 2, v.begin() + 4);  
```

Removes indices **2 and 3**.
(End is exclusive.)

---

# ----------------------------------------------------

# 🟪 **Insert Operations**

### 1️⃣ Insert a single element

```cpp
v.insert(v.begin(), 300);
```

### 2️⃣ Insert multiple copies

```cpp
v.insert(v.begin() + 1, 2, 10);
```

### 3️⃣ Insert from another vector

```cpp
vector<int> copy(2, 50); // {50,50}
v.insert(v.begin(), copy.begin(), copy.end());
```

---

# ----------------------------------------------------

# 🟫 **Vector of Pairs**

```cpp
vector<pair<int, int>> vp;

vp.push_back({1, 2});
vp.push_back({3, 4});
```

Access:

```cpp
vp[i].first;
vp[i].second;
```

---

# ----------------------------------------------------

# 🟩 **2D Vector (Vector inside Vector)**

```cpp
vector<vector<int>> v2d;

v2d.push_back({1,2,3});
v2d.push_back({4,5});
```

---

# ----------------------------------------------------

# 🟨 **Other Useful Functions**

| Function       | Meaning                  |
| -------------- | ------------------------ |
| `v.size()`     | Number of elements       |
| `v.pop_back()` | Remove last element      |
| `v.clear()`    | Remove all elements      |
| `v.empty()`    | Check if vector is empty |
| `v.swap(v2)`   | Swap with another vector |

---

# ----------------------------------------------------

# 🟦 **Copying Vectors**

### 1️⃣ Copy constructor

```cpp
vector<int> v2(v);
```

### 2️⃣ Assignment

```cpp
vector<int> v2;
v2 = v;
```

---

# ----------------------------------------------------

# 🔹 **Summary**

* Vector = **dynamic array**
* Supports **grow/shrink automatically**
* Allows **fast access** and **flexible insertion/deletion**
* Iterators (`begin`, `end`, `rbegin`, `rend`) help in traversal
* `erase()`, `insert()`, `push_back()`, `pop_back()` are essential tools
* Supports **vector of pairs** and **2D vectors**
* Very powerful and used everywhere in STL & CP

---
!
