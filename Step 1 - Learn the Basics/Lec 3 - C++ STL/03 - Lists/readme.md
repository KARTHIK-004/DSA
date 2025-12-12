# 📘 **NOTES — 03 List (C++ STL)**

A **list** in C++ is a _doubly linked list_ implemented by the STL `<list>` container.

Unlike vectors (dynamic arrays), a list allows **fast insertion and deletion anywhere** in the sequence, because it does **not** store elements in contiguous memory.

---

# 🔹 **Why use list?**

✔ Fast insertion & deletion at **beginning**, **middle**, or **end**
✔ Efficient for operations that require frequent modifications
✔ Allows constant-time complexity O(1) for insert/erase when given an iterator
✔ Supports both forward and backward traversal

---

# 🔹 **Header File**

```cpp
#include <list>
```

---

# 🔹 **Syntax**

```cpp
list<type> name;
```

Examples:

```cpp
list<int> l;
list<string> names;
list<pair<int, int>> lp;
```

---

# ----------------------------------------------------

# 🔹 **Basic Operations**

## 1️⃣ push_front() — Insert at beginning

```cpp
l.push_front(10);
```

## 2️⃣ push_back() — Insert at end

```cpp
l.push_back(20);
```

## 3️⃣ pop_front() — Remove first element

```cpp
l.pop_front();
```

## 4️⃣ pop_back() — Remove last element

```cpp
l.pop_back();
```

---

# ----------------------------------------------------

# 🔹 **Accessing Elements**

Unlike vectors, you **cannot** do `l[0]`.

You can only access elements through:

### 🔸 front()

```cpp
l.front();
```

### 🔸 back()

```cpp
l.back();
```

### 🔸 Iterators

```cpp
for (auto it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
}
```

---

# ----------------------------------------------------

# 🔹 **Insert & Erase**

Since list is a doubly linked list, insertions are fast.

### 1️⃣ Insert at position using iterator

```cpp
auto it = l.begin();
advance(it, 2);  // move iterator to index 2
l.insert(it, 50);
```

### 2️⃣ Erase element at iterator

```cpp
l.erase(it);
```

### 3️⃣ Erase a range

```cpp
l.erase(l.begin(), l.end());  // clears entire list
```

---

# ----------------------------------------------------

# 🔹 **Iterating Through List**

### 🔸 Using iterator

```cpp
for (auto it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
}
```

### 🔸 Using range-for loop

```cpp
for (auto x : l) {
    cout << x << " ";
}
```

---

# ----------------------------------------------------

# 🔹 **Other Useful Functions**

| Function          | Description                      |
| ----------------- | -------------------------------- |
| `l.size()`        | number of elements               |
| `l.clear()`       | removes all elements             |
| `l.empty()`       | checks if list is empty          |
| `l.reverse()`     | reverses the list                |
| `l.sort()`        | sorts elements (ascending)       |
| `l.remove(value)` | removes all occurrences of value |
| `l.unique()`      | removes consecutive duplicates   |

# 📌 **Examples for Each Function **

Let’s assume a list:

```cpp
list<int> l = {30, 10, 20, 20, 40};
```

---

## 1️⃣ `l.size()`

Returns number of elements.

```cpp
cout << l.size();     // Output: 5
```

---

## 2️⃣ `l.clear()`

Removes all elements.

```cpp
l.clear();
cout << l.size();     // Output: 0
```

---

## 3️⃣ `l.empty()`

Checks if list is empty.

```cpp
if (l.empty())
    cout << "List is empty";
else
    cout << "Not empty";
```

---

## 4️⃣ `l.reverse()`

Reverses the list.

Before:

```
30 10 20 20 40
```

After:

```cpp
l.reverse();
```

Result:

```
40 20 20 10 30
```

---

## 5️⃣ `l.sort()`

Sorts the list in ascending order.

Before:

```
30 10 20 20 40
```

After:

```cpp
l.sort();
```

Result:

```
10 20 20 30 40
```

---

## 6️⃣ `l.remove(value)`

Removes **all occurrences** of a value.

Before:

```
10 20 20 30 40
```

Run:

```cpp
l.remove(20);
```

After:

```
10 30 40
```

---

## 7️⃣ `l.unique()`

Removes **only consecutive duplicates**.

Example:

```cpp
list<int> l = {10, 10, 20, 20, 20, 30, 10, 10};
```

Run:

```cpp
l.unique();
```

Result:

```
10 20 30 10
```

👉 Note: The **two 10's at the end remain** because they were **not consecutive before sorting**.

---

# ----------------------------------------------------

# 🔹 **Difference: vector vs list**

| Feature                | vector       | list               |
| ---------------------- | ------------ | ------------------ |
| Memory                 | contiguous   | non-contiguous     |
| Insert/erase in middle | slow (O(n))  | fast (O(1))        |
| Random access          | ✔ yes (v[i]) | ❌ no              |
| Iteration speed        | faster       | slower             |
| Use case               | heavy access | heavy insert/erase |

---

# ----------------------------------------------------

# 🔹 **Summary**

- `list` is a **doubly linked list** from STL
- Supports fast insertion & deletion anywhere (O(1))
- No random access like vector
- Use iterators for traversal
- Supports functions like `sort(), reverse(), unique(), remove()`
- Best when modifications in the middle are frequent

---
