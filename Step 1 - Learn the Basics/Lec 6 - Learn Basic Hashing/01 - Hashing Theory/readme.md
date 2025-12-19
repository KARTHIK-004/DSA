# 📘 **NOTES — 01 Hashing Theory**

Introduction to hashing concepts, hash tables, hash maps, and hash functions.

---

# 🔹 **What is Hashing?**

**Hashing** is a technique to store and retrieve data in **O(1) average time** using a hash function that maps keys to indices in a data structure.

### **Key Concepts:**
- **Hash Function:** Converts a key into an index/hash code
- **Hash Table:** Data structure that stores key-value pairs
- **Hash Map:** Implementation of hash table (map/unordered_map in C++)
- **Collision:** When two keys map to the same index

---

# 🔹 **Why Use Hashing?**

### **Problem Without Hashing:**
```
Array: [10, 5, 10, 15, 10, 5]
Query: How many times does 10 appear?

Brute Force: Loop through array → O(n) per query
For q queries: O(n × q) time
```

### **Solution With Hashing:**
```
Pre-process: Count frequencies → O(n)
Query: Look up in hash table → O(1)
For q queries: O(n + q) time ✓
```

**Hashing reduces query time from O(n) to O(1)!**

---

# 🔹 **Types of Hashing**

## **1. Array-Based Hashing (Direct Address Table)**

Use when:
- Range of values is **small and known** (e.g., 0 to 10^6)
- Values are **non-negative integers**

### Example:
```cpp
int hash[100] = {0};  // For values 0-99

// Store frequency
for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
}

// Query in O(1)
cout << hash[5];  // Frequency of 5
```

### Hash Table Visualization:
```
Array: [1, 2, 1, 3, 2, 1]

Hash Table:
Index:  0  1  2  3  4  5 ...
Value:  0  3  2  1  0  0 ...
        ↑  ↑  ↑  ↑
        |  |  |  |
        |  |  |  3 appears 1 time
        |  |  2 appears 2 times
        |  1 appears 3 times
        0 appears 0 times
```

**Time:** O(1) for insert and query
**Space:** O(max_value)

---

## **2. Map-Based Hashing (Ordered)**

Use when:
- Range is **large or unknown**
- Need **sorted output**
- Values can be **any type** (int, string, etc.)

### Example:
```cpp
map<int, int> hashMap;

// Store frequency
for (int i = 0; i < n; i++) {
    hashMap[arr[i]]++;
}

// Query in O(log n)
cout << hashMap[5];  // Frequency of 5
```

**Implementation:** Red-Black Tree (balanced BST)
**Time:** O(log n) for insert and query
**Space:** O(unique_elements)

---

## **3. Unordered Map-Based Hashing (Fastest)**

Use when:
- Range is **large or unknown**
- **Don't need sorted output**
- Want **fastest performance**

### Example:
```cpp
unordered_map<int, int> hashMap;

// Store frequency
for (int i = 0; i < n; i++) {
    hashMap[arr[i]]++;
}

// Query in O(1) average
cout << hashMap[5];  // Frequency of 5
```

**Implementation:** Hash Table with chaining
**Time:** O(1) average for insert and query
**Space:** O(unique_elements)

---

# 🔹 **Hash Functions**

A hash function converts a key to an index:

### **For Integers:**
```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Example:
// key = 25, tableSize = 10
// hash = 25 % 10 = 5
```

### **For Strings:**
```cpp
int hashFunction(string key, int tableSize) {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % tableSize;
    }
    return hash;
}
```

**Good Hash Function Properties:**
1. **Deterministic:** Same key → same hash
2. **Uniform Distribution:** Minimizes collisions
3. **Fast to Compute:** O(1) or O(key_length)

---

# 🔹 **Collision Handling**

**Collision:** When two different keys map to the same index.

## **Method 1: Chaining (Separate Chaining)**

Store multiple elements at same index using a linked list.

```
Hash Table with Chaining:
Index 0: → NULL
Index 1: → [11] → [21] → NULL
Index 2: → [12] → NULL
Index 3: → [13] → [23] → NULL
```

**Pros:** Simple, handles any number of collisions
**Cons:** Extra space for pointers
**Used by:** `unordered_map` in C++

---

## **Method 2: Open Addressing**

Find another empty slot when collision occurs.

### **Linear Probing:**
```
If hash(key) is occupied, try:
hash(key) + 1
hash(key) + 2
hash(key) + 3
...until empty slot found
```

### **Quadratic Probing:**
```
If hash(key) is occupied, try:
hash(key) + 1²
hash(key) + 2²
hash(key) + 3²
```

**Pros:** No extra space for pointers
**Cons:** Clustering, table can fill up

---

# 🔹 **Comparison: Array vs Map vs Unordered Map**

| Feature              | Array Hash        | Map               | Unordered Map     |
| -------------------- | ----------------- | ----------------- | ----------------- |
| **Time (Insert)**    | O(1)              | O(log n)          | O(1) average      |
| **Time (Query)**     | O(1)              | O(log n)          | O(1) average      |
| **Space**            | O(max_value)      | O(unique)         | O(unique)         |
| **Range**            | Small, known      | Any               | Any               |
| **Sorted Output**    | No                | Yes               | No                |
| **Negative Values**  | No (needs offset) | Yes               | Yes               |
| **String Keys**      | No                | Yes               | Yes               |
| **Best For**         | Small range ints  | Sorted output     | Fast queries      |

---

# 🔹 **When to Use Which?**

### **Use Array Hashing When:**
✅ Values are in range [0, 10^6] or similar
✅ All values are non-negative integers
✅ Need fastest possible O(1) guaranteed time
✅ Memory is not a constraint

### **Use Map When:**
✅ Need sorted output by keys
✅ Range is large or unknown
✅ Working with strings or custom types
✅ Need guaranteed O(log n) time

### **Use Unordered Map When:**
✅ Range is large or unknown
✅ Don't need sorted output
✅ Want fastest average performance
✅ Working with any data type

---

# 🔹 **Common Hashing Problems**

1. **Frequency Counting:** Count occurrences of elements
2. **Finding Duplicates:** Check if element appears more than once
3. **Two Sum Problem:** Find pair with given sum
4. **Subarray with Given Sum:** Find subarray summing to target
5. **Longest Subarray:** Find longest subarray with property
6. **Anagram Grouping:** Group anagrams together

---

# 🔹 **Time & Space Complexity**

| Operation            | Array Hash | Map      | Unordered Map |
| -------------------- | ---------- | -------- | ------------- |
| Insert               | O(1)       | O(log n) | O(1) avg      |
| Search/Query         | O(1)       | O(log n) | O(1) avg      |
| Delete               | O(1)       | O(log n) | O(1) avg      |
| Iterate All          | O(range)   | O(n)     | O(n)          |
| Space                | O(range)   | O(n)     | O(n)          |

---

# 🔹 **Key Concepts**

1. **Pre-processing:** Build hash table once in O(n)
2. **Fast Queries:** Answer queries in O(1) or O(log n)
3. **Trade-off:** Use extra space to save time
4. **Collision Handling:** Chaining or open addressing
5. **Load Factor:** ratio of elements to table size (affects performance)

---

# 🔹 **Summary**

- Hashing provides **O(1) average time** for insert, search, delete
- **Array hashing:** Best for small range integers
- **Map:** Best when sorted output needed
- **Unordered map:** Best for general purpose hashing
- Hash functions map keys to indices
- Collisions handled by chaining or open addressing
- Essential for frequency counting and fast lookups

---

