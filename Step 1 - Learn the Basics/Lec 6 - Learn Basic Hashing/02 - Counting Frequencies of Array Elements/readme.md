# 📘 **NOTES — 02 Counting Frequencies of Array Elements**

Count the frequency of each element in an array using hashing.

We want to:
👉 **Find how many times each element appears in the array**

Example:
`arr = [10, 5, 10, 15, 10, 5]` → `10: 3 times, 5: 2 times, 15: 1 time`

---

# 🔹 **Method 1 — Using Unordered Map ⭐ (Best for Most Cases)**

### Idea

- Use `unordered_map<int, int>` to store element → frequency
- Iterate through array and increment count for each element
- O(1) average time for each insertion

### Code

```cpp
void countFrequencies(int arr[], int n) {
    unordered_map<int, int> freq;
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Display
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }
}
```

### Hash Table Visualization

```
Array: [10, 5, 10, 15, 10, 5]

Building Hash Map:
Step 1: freq[10] = 1
Step 2: freq[5] = 1
Step 3: freq[10] = 2
Step 4: freq[15] = 1
Step 5: freq[10] = 3
Step 6: freq[5] = 2

Final Hash Map:
┌─────┬───────┐
│ Key │ Value │
├─────┼───────┤
│ 10  │   3   │
│  5  │   2   │
│ 15  │   1   │
└─────┴───────┘
```

### Workflow

```
Input: [10, 5, 10, 15, 10, 5]

Process:
arr[0] = 10 → freq[10]++ → freq[10] = 1
arr[1] = 5  → freq[5]++  → freq[5] = 1
arr[2] = 10 → freq[10]++ → freq[10] = 2
arr[3] = 15 → freq[15]++ → freq[15] = 1
arr[4] = 10 → freq[10]++ → freq[10] = 3
arr[5] = 5  → freq[5]++  → freq[5] = 2

Output:
10 appears 3 times
5 appears 2 times
15 appears 1 time
```

**Time Complexity:** O(n) - one pass through array
**Space Complexity:** O(k) - where k is number of unique elements

---

# 🔹 **Method 2 — Using Map (For Sorted Output)**

### Idea

- Use `map<int, int>` instead of `unordered_map`
- Automatically maintains sorted order by keys
- O(log n) time for each insertion

### Code

```cpp
void countFrequencies(int arr[], int n) {
    map<int, int> freq;
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Display (automatically sorted)
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }
}
```

### Example

```
Input: [10, 5, 10, 15, 10, 5]

Map (Red-Black Tree):
        10:3
       /    \
     5:2    15:1

Output (Sorted by Key):
5 -> 2
10 -> 3
15 -> 1
```

**Time Complexity:** O(n log k) - k unique elements
**Space Complexity:** O(k)

---

# 🔹 **Method 3 — Using Array (For Small Range)**

### Idea

- Use array as hash table when range is small
- Index represents the element, value represents frequency
- Direct indexing gives O(1) access

### Code

```cpp
void countFrequencies(int arr[], int n, int maxVal) {
    int hash[maxVal + 1] = {0};
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    
    // Display
    for (int i = 0; i <= maxVal; i++) {
        if (hash[i] > 0) {
            cout << i << " -> " << hash[i] << endl;
        }
    }
}
```

### Hash Array Visualization

```
Array: [5, 10, 5, 15, 10, 5]
Max Value: 15

Hash Array (Index 0 to 15):
Index:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
Freq:   0  0  0  0  0  3  0  0  0  0  2  0  0  0  0  1
                       ↑              ↑              ↑
                       |              |              |
                    5 appears      10 appears     15 appears
                    3 times        2 times        1 time
```

**Time Complexity:** O(n + maxVal)
**Space Complexity:** O(maxVal)

**⚠️ Limitation:** Only works for non-negative integers in small range

---

# 🔹 **Method 4 — Brute Force (Without Hashing)**

### Idea

- For each unique element, count occurrences by scanning array
- No extra space but very slow

### Code

```cpp
void countFrequencies(int arr[], int n) {
    bool visited[n] = {false};
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }
        
        cout << arr[i] << " -> " << count << endl;
    }
}
```

**Time Complexity:** O(n²)
**Space Complexity:** O(n)

**❌ Not recommended** - Use hashing instead!

---

# 🔹 **Comparison of Methods**

| Method         | Time       | Space    | Sorted? | Range      | Best For              |
| -------------- | ---------- | -------- | ------- | ---------- | --------------------- |
| Unordered Map  | O(n)       | O(k)     | No      | Any        | General purpose ⭐    |
| Map            | O(n log k) | O(k)     | Yes     | Any        | Sorted output needed  |
| Array          | O(n+max)   | O(max)   | Yes     | Small      | Small range integers  |
| Brute Force    | O(n²)      | O(n)     | No      | Any        | Never use ❌          |

k = number of unique elements

---

# 🔹 **Special Cases**

### **Case 1: All Elements Same**
```
Input: [5, 5, 5, 5, 5]
Output: 5 -> 5
```

### **Case 2: All Elements Unique**
```
Input: [1, 2, 3, 4, 5]
Output:
1 -> 1
2 -> 1
3 -> 1
4 -> 1
5 -> 1
```

### **Case 3: Empty Array**
```
Input: []
Output: (nothing)
```

### **Case 4: Single Element**
```
Input: [42]
Output: 42 -> 1
```

### **Case 5: Negative Numbers**
```
Input: [-5, 10, -5, 10]

✅ Map/Unordered Map: Works fine
❌ Array: Needs offset (hash[arr[i] + offset])
```

---

# 🔹 **Handling Negative Numbers with Array**

```cpp
void countFrequencies(int arr[], int n) {
    int minVal = *min_element(arr, arr + n);
    int maxVal = *max_element(arr, arr + n);
    int offset = -minVal;  // Make all indices positive
    int range = maxVal - minVal + 1;
    
    int hash[range] = {0};
    
    for (int i = 0; i < n; i++) {
        hash[arr[i] + offset]++;
    }
    
    for (int i = 0; i < range; i++) {
        if (hash[i] > 0) {
            cout << (i - offset) << " -> " << hash[i] << endl;
        }
    }
}
```

---

# 🔹 **Applications**

1. **Find Duplicates:** Elements with frequency > 1
2. **Find Unique Elements:** Elements with frequency = 1
3. **Most/Least Frequent Element:** Max/min frequency
4. **Mode of Array:** Element with highest frequency
5. **Check if All Unique:** All frequencies = 1
6. **Majority Element:** Element with frequency > n/2

---

# 🔹 **Key Concepts**

1. **Pre-processing:** Build frequency map in O(n)
2. **Space-Time Tradeoff:** Use O(k) space to get O(1) queries
3. **Choose Right Data Structure:** Array vs Map vs Unordered Map
4. **Unordered Map is Usually Best:** O(n) time, works for any range
5. **Map for Sorted Output:** When order matters

---

# 🔹 **Summary**

- **Unordered map** is best for most cases: O(n) time, O(k) space
- **Map** when sorted output needed: O(n log k) time
- **Array** for small range integers: O(n) time but O(max) space
- Hashing reduces frequency counting from O(n²) to O(n)
- Essential technique for many array problems

---

