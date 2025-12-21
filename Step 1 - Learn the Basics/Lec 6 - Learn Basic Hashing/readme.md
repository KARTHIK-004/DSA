# 📚 **Lecture 6 — Learn Basic Hashing**

This lecture covers fundamental hashing concepts and techniques that enable O(1) average-time data retrieval and frequency counting.

---

## 📖 **Overview**

**Hashing** is a technique that uses a hash function to map keys to indices in a data structure, enabling extremely fast data access, insertion, and deletion operations.

### **Why Learn Hashing?**
- **Speed:** O(1) average time for search, insert, delete
- **Efficiency:** Reduces O(n) queries to O(1)
- **Versatility:** Works with any data type (int, string, custom objects)
- **Essential:** Foundation for many advanced algorithms

### **Real-World Applications:**
- Database indexing
- Caching systems
- Password storage
- Compiler symbol tables
- Network routing tables
- Blockchain technology

---

## 🗂️ **Problems Covered**

### **01 - Hashing Theory**
Introduction to hashing fundamentals and data structures.

**Key Concepts:**
- What is hashing and why use it
- Hash functions and hash tables
- Array-based vs Map-based hashing
- Collision handling (chaining, open addressing)
- When to use each hashing method

**Demonstrates:**
- Array hashing for small ranges
- Map for sorted output
- Unordered_map for fastest performance

**Time:** O(1) array, O(log n) map, O(1) avg unordered_map

---

### **02 - Counting Frequencies of Array Elements**
Count how many times each element appears in an array.

**Key Concepts:**
- Frequency counting using hash maps
- Pre-processing for fast queries
- Choosing right data structure
- Handling negative numbers

**Example:** `[10, 5, 10, 15, 10, 5]` → `10:3, 5:2, 15:1`

**Methods:**
1. Unordered_map: O(n) time, O(k) space ⭐
2. Map: O(n log k) time, sorted output
3. Array: O(n) time, O(max) space (small range)

**Time:** O(n) | **Space:** O(k) where k = unique elements

---

### **03 - Find Highest and Lowest Frequency Element**
Identify elements with maximum and minimum frequencies.

**Key Concepts:**
- Finding extremes in frequency distribution
- Handling ties (multiple elements with same frequency)
- Statistical analysis of arrays
- Mode and outlier detection

**Example:** `[10, 5, 10, 15, 10, 5]` → `Max: 10 (3 times), Min: 15 (1 time)`

**Approach:**
1. Build frequency map: O(n)
2. Find max/min frequencies: O(k)
3. Handle edge cases and ties

**Time:** O(n) | **Space:** O(k)

---

## 🔑 **Core Hashing Concepts**

### **1. Hash Function**
Converts a key into an index/hash code.

```cpp
// Simple hash for integers
int hash(int key, int tableSize) {
    return key % tableSize;
}

// Hash for strings
int hash(string key) {
    int h = 0;
    for (char c : key) {
        h = h * 31 + c;
    }
    return h;
}
```

**Properties of Good Hash Function:**
- Deterministic (same input → same output)
- Uniform distribution (minimizes collisions)
- Fast to compute

---

### **2. Hash Table**
Data structure that stores key-value pairs using hashing.

```
Hash Table Structure:
Index 0: → [key1, value1]
Index 1: → [key2, value2] → [key3, value3] (collision chain)
Index 2: → NULL
Index 3: → [key4, value4]
```

---

### **3. Collision Handling**

**Collision:** When two keys map to the same index.

#### **Method 1: Chaining (Separate Chaining)**
Store multiple elements at same index using linked list.

```
Index 0: → NULL
Index 1: → [11] → [21] → [31]
Index 2: → [12]
```

**Used by:** `unordered_map` in C++

#### **Method 2: Open Addressing**
Find next available slot when collision occurs.

**Linear Probing:** Try index+1, index+2, index+3...
**Quadratic Probing:** Try index+1², index+2², index+3²...

---

### **4. Load Factor**
Ratio of elements to table size.

```
Load Factor = Number of Elements / Table Size

Example: 8 elements in table of size 10
Load Factor = 8/10 = 0.8
```

**Impact:**
- Low load factor: Fast but wastes space
- High load factor: Saves space but more collisions
- Optimal: ~0.7 to 0.75

---

## 📊 **Hashing Data Structures Comparison**

| Feature              | Array Hash        | Map               | Unordered Map     |
| -------------------- | ----------------- | ----------------- | ----------------- |
| **Implementation**   | Direct indexing   | Red-Black Tree    | Hash Table        |
| **Insert Time**      | O(1)              | O(log n)          | O(1) average      |
| **Search Time**      | O(1)              | O(log n)          | O(1) average      |
| **Delete Time**      | O(1)              | O(log n)          | O(1) average      |
| **Space**            | O(max_value)      | O(n)              | O(n)              |
| **Ordered**          | By index          | Yes (by key)      | No                |
| **Range**            | Small, known      | Any               | Any               |
| **Negative Values**  | Needs offset      | Yes               | Yes               |
| **String Keys**      | No                | Yes               | Yes               |
| **Best For**         | Small int range   | Sorted output     | Fast queries ⭐   |

---

## 🎯 **When to Use Which?**

### **Use Array Hashing When:**
✅ Values in range [0, 10^6] or similar
✅ All non-negative integers
✅ Need guaranteed O(1) time
✅ Memory not a constraint

**Example:**
```cpp
int hash[1000001] = {0};
hash[arr[i]]++;
```

---

### **Use Map When:**
✅ Need sorted output by keys
✅ Range is large or unknown
✅ Working with strings/custom types
✅ Need guaranteed O(log n) time

**Example:**
```cpp
map<int, int> freq;
freq[arr[i]]++;
// Automatically sorted
```

---

### **Use Unordered Map When:**
✅ Range is large or unknown
✅ Don't need sorted output
✅ Want fastest average performance
✅ General purpose hashing

**Example:**
```cpp
unordered_map<int, int> freq;
freq[arr[i]]++;
// Fastest for most cases
```

---

## ⚡ **Time & Space Complexity Summary**

| Problem                    | Time       | Space    | Key Technique        |
| -------------------------- | ---------- | -------- | -------------------- |
| Hashing Theory             | O(1) avg   | O(n)     | Hash table basics    |
| Count Frequencies          | O(n)       | O(k)     | Frequency map        |
| Highest/Lowest Frequency   | O(n)       | O(k)     | Max/min tracking     |

k = number of unique elements

---

## 🔄 **Common Hashing Patterns**

### **Pattern 1: Frequency Counting**
```cpp
unordered_map<int, int> freq;
for (int x : arr) {
    freq[x]++;
}
```

### **Pattern 2: Existence Check**
```cpp
unordered_set<int> seen;
for (int x : arr) {
    if (seen.count(x)) {
        // Element exists
    }
    seen.insert(x);
}
```

### **Pattern 3: Two Sum Pattern**
```cpp
unordered_map<int, int> map;
for (int i = 0; i < n; i++) {
    int complement = target - arr[i];
    if (map.count(complement)) {
        // Found pair
    }
    map[arr[i]] = i;
}
```

### **Pattern 4: Grouping/Categorization**
```cpp
unordered_map<string, vector<string>> groups;
for (string s : words) {
    string key = getKey(s);  // e.g., sorted string
    groups[key].push_back(s);
}
```

---

## 🚨 **Common Pitfalls & Solutions**

### **1. Using Array for Large Range**
```cpp
// ❌ WRONG - Wastes memory
int hash[1000000000] = {0};  // 4GB of memory!

// ✅ CORRECT - Use map
unordered_map<int, int> hash;
```

### **2. Forgetting to Initialize**
```cpp
// ❌ WRONG
int hash[100];
hash[5]++;  // Undefined behavior!

// ✅ CORRECT
int hash[100] = {0};  // Initialize to 0
hash[5]++;
```

### **3. Not Handling Negative Numbers**
```cpp
// ❌ WRONG - Negative index
int hash[100];
hash[-5]++;  // Error!

// ✅ CORRECT - Use offset or map
unordered_map<int, int> hash;
hash[-5]++;
```

### **4. Choosing Wrong Data Structure**
```cpp
// ❌ WRONG - Using map when unordered_map is better
map<int, int> freq;  // O(log n) per operation

// ✅ CORRECT - Use unordered_map for speed
unordered_map<int, int> freq;  // O(1) average
```

---

## 💡 **Hashing Applications**

### **1. Frequency Problems**
- Count element occurrences
- Find duplicates
- Mode of array
- Majority element

### **2. Pair/Subset Problems**
- Two sum
- Three sum
- Subarray with given sum
- Longest subarray

### **3. String Problems**
- Anagram grouping
- First unique character
- Longest substring without repeating

### **4. Array Problems**
- Find missing number
- First repeating element
- Longest consecutive sequence

---

## 🧠 **Problem-Solving Approach**

### **Step 1: Identify if Hashing Helps**
Ask: "Do I need fast lookups or frequency counting?"

### **Step 2: Choose Data Structure**
- Small range integers → Array
- Need sorted → Map
- General case → Unordered_map

### **Step 3: Build Hash Table**
```cpp
unordered_map<int, int> hash;
for (int x : arr) {
    hash[x]++;
}
```

### **Step 4: Query/Process**
```cpp
for (auto [key, value] : hash) {
    // Process each unique element
}
```

---

## 🔗 **Connections to Other Topics**

- **Arrays:** Hashing optimizes array searching
- **Strings:** Character frequency, anagrams
- **Two Pointers:** Can combine with hashing
- **Sliding Window:** Use hash for window state
- **Graphs:** Adjacency list uses hashing
- **Dynamic Programming:** Memoization uses hashing

---

## 📈 **Performance Characteristics**

### **Best Case:**
- Array: O(1) guaranteed
- Unordered_map: O(1) average
- Map: O(log n) guaranteed

### **Average Case:**
- All methods perform well
- Unordered_map usually fastest

### **Worst Case:**
- Array: O(1) still
- Unordered_map: O(n) if many collisions
- Map: O(log n) guaranteed

---

## ✅ **Summary**

This lecture covers essential hashing concepts:

**Key Takeaways:**
- Hashing provides O(1) average time for lookups
- Three main approaches: array, map, unordered_map
- Unordered_map is best for most cases
- Map when sorted output needed
- Array for small range integers
- Collision handling is crucial
- Load factor affects performance

**Master These:**
1. When to use hashing vs other approaches
2. Choosing right hash data structure
3. Frequency counting pattern
4. Handling collisions
5. Space-time tradeoffs

---

## 📂 **Folder Structure**

Each problem folder contains:
- `main.cpp` - Complete C++ implementation with multiple methods
- `input.txt` - Sample test cases
- `output.txt` - Expected output
- `readme.md` - Theory, approaches, complexity analysis, visualizations

---

**Happy Learning! 🎓**

Master hashing and you'll solve array/string problems much faster with optimal time complexity!
