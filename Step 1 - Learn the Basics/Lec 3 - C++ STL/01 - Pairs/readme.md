# 📘 **NOTES — 01 Pair (C++ STL)**

A **pair** in C++ is a simple container that stores **two values together**.
It comes from the `<utility>` header.

Pairs are useful when two related values must be treated as one unit.

---

# 🔹 **Why do we use pair?**

- To store two values as one object
- To return two values from a function
- To store key–value data
- Used in **vector of pairs**, **map**, **graphs**, etc.
- Very useful in competitive programming

---

# 🔹 **Syntax**

```cpp
pair<type1, type2> variableName;
```

Examples:

```cpp
pair<int, int> p1;
pair<int, string> p2;
pair<string, double> p3;
```

---

# 🔹 **Ways to Initialize a Pair**

### 1️⃣ Using `{}`

```cpp
pair<int, string> p = {1, "Hello"};
```

### 2️⃣ Using `make_pair()`

```cpp
pair<int, string> p = make_pair(5, "World");
```

### 3️⃣ Assign later

```cpp
pair<int, int> p;
p.first = 10;
p.second = 20;
```

---

# 🔹 **Accessing Elements of a Pair**

| Member   | Meaning      |
| -------- | ------------ |
| `first`  | First value  |
| `second` | Second value |

Example:

```cpp
p.first
p.second
```

---

# 🔹 **Nested Pair**

```cpp
pair<int, pair<int, int>> p = {1, {2, 3}};
```

Access:

- `p.first` → 1
- `p.second.first` → 2
- `p.second.second` → 3

---

# 🔹 **Pair Inside an Array**

Pairs can be stored inside an array:

```cpp
pair<int, int> arr[3];
```

### Filling the array:

```cpp
arr[0] = {1, 10};
arr[1] = {2, 20};
arr[2] = {3, 30};
```

---

# 🔹 **💡 Accessing Pair Elements in an Array**

To access `.first` and `.second` of each pair in the array:

```cpp
cout << arr[0].first;   // 1
cout << arr[0].second;  // 10

cout << arr[1].first;   // 2
cout << arr[1].second;  // 20
```

### Or using a loop:

```cpp
for (int i = 0; i < 3; i++) {
    cout << arr[i].first << " " << arr[i].second << endl;
}
```

This is very useful for:

- Coordinates list
- Roll number + marks
- Graph edges list
- Key-value pairs

---

# 🔹 **Common Uses of pair**

- Coordinate storage `(x, y)`
- Storing two related fields
- Edges in graph: `(u, v)`
- Returning 2 values from a function
- Used heavily with vectors: `vector<pair<int,int>>`

---

# 🔹 **Summary**

- Pair stores **2 values** (may be different types)
- Access with `.first` and `.second`
- Can store inside arrays and vectors
- Can be nested
- Very important STL concept

---
