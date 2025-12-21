# 📘 **NOTES — 03 Find Highest and Lowest Frequency Element**

Find the element with the highest and lowest frequency in an array.

We want to:
👉 **Identify which element appears most and least frequently**

Example:
`arr = [10, 5, 10, 15, 10, 5]` → `Highest: 10 (3 times), Lowest: 15 (1 time)`

---

# 🔹 **Method 1 — Using Unordered Map ⭐**

### Idea

1. Count frequencies using `unordered_map`
2. Iterate through map to find max and min frequencies
3. Track elements with those frequencies

### Code

```cpp
void findHighestLowest(int arr[], int n) {
    unordered_map<int, int> freq;
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Find max and min frequency
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElement, minElement;
    
    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElement = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }
    
    cout << "Highest: " << maxElement << " (" << maxFreq << " times)" << endl;
    cout << "Lowest: " << minElement << " (" << minFreq << " times)" << endl;
}
```

### Workflow

```
Input: [10, 5, 10, 15, 10, 5]

Step 1: Build Frequency Map
┌─────┬───────┐
│ Key │ Freq  │
├─────┼───────┤
│ 10  │   3   │ ← Maximum frequency
│  5  │   2   │
│ 15  │   1   │ ← Minimum frequency
└─────┴───────┘

Step 2: Find Max and Min
maxFreq = 3, maxElement = 10
minFreq = 1, minElement = 15

Output:
Highest Frequency: 10 (appears 3 times)
Lowest Frequency: 15 (appears 1 time)
```

**Time Complexity:** O(n) - one pass to count + one pass to find max/min
**Space Complexity:** O(k) - k unique elements

---

# 🔹 **Method 2 — Single Pass with Tracking**

### Idea

- Track max/min frequencies while building the frequency map
- Update max/min elements as we go

### Code

```cpp
void findHighestLowest(int arr[], int n) {
    unordered_map<int, int> freq;
    int maxFreq = 0, minFreq = INT_MAX;
    int maxElement = arr[0], minElement = arr[0];
    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        int currentFreq = freq[arr[i]];
        
        // Update max
        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
            maxElement = arr[i];
        }
        
        // Update min (after first occurrence)
        if (currentFreq == 1) {
            if (minFreq > 1 || i == 0) {
                minFreq = 1;
                minElement = arr[i];
            }
        }
    }
    
    // Final pass to confirm min (as frequencies change)
    for (auto it : freq) {
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(k)

---

# 🔹 **Method 3 — Using Map (Sorted)**

### Idea

- Use `map` to get sorted output
- Find max/min frequencies from sorted map

### Code

```cpp
void findHighestLowest(int arr[], int n) {
    map<int, int> freq;
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElement, minElement;
    
    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElement = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }
    
    cout << "Highest: " << maxElement << endl;
    cout << "Lowest: " << minElement << endl;
}
```

**Time Complexity:** O(n log k)
**Space Complexity:** O(k)

---

# 🔹 **Handling Ties (Multiple Elements with Same Frequency)**

### **Strategy 1: Return Smallest Element**

```cpp
for (auto it : freq) {
    if (it.second > maxFreq) {
        maxFreq = it.second;
        maxElement = it.first;
    } else if (it.second == maxFreq && it.first < maxElement) {
        maxElement = it.first;  // Choose smaller element
    }
}
```

### **Strategy 2: Return First Occurrence**

```cpp
// Track first occurrence
unordered_map<int, int> firstIndex;
for (int i = 0; i < n; i++) {
    if (firstIndex.find(arr[i]) == firstIndex.end()) {
        firstIndex[arr[i]] = i;
    }
}

// When comparing, use first occurrence
if (it.second == maxFreq && firstIndex[it.first] < firstIndex[maxElement]) {
    maxElement = it.first;
}
```

### **Strategy 3: Return All Elements**

```cpp
vector<int> maxElements, minElements;

for (auto it : freq) {
    if (it.second == maxFreq) {
        maxElements.push_back(it.first);
    }
    if (it.second == minFreq) {
        minElements.push_back(it.first);
    }
}
```

---

# 🔹 **Special Cases**

### **Case 1: All Elements Same Frequency**
```
Input: [1, 2, 3, 4, 5]
Frequencies: All are 1

Output:
Highest: 1 (or any element)
Lowest: 1 (or any element)
```

### **Case 2: All Elements Same**
```
Input: [5, 5, 5, 5]
Frequencies: 5 appears 4 times

Output:
Highest: 5 (4 times)
Lowest: 5 (4 times)
```

### **Case 3: Two Elements**
```
Input: [10, 20]
Frequencies: Both appear 1 time

Output:
Highest: 10 or 20 (both 1 time)
Lowest: 10 or 20 (both 1 time)
```

### **Case 4: Single Element**
```
Input: [42]
Frequencies: 42 appears 1 time

Output:
Highest: 42 (1 time)
Lowest: 42 (1 time)
```

### **Case 5: Multiple Max/Min**
```
Input: [1, 1, 2, 2, 3]
Frequencies: 1→2, 2→2, 3→1

Output:
Highest: 1 or 2 (both 2 times)
Lowest: 3 (1 time)
```

---

# 🔹 **Visualization Example**

```
Array: [10, 5, 10, 15, 10, 5, 10, 20, 5, 15]

Step 1: Count Frequencies
┌──────────┬──────────┐
│ Element  │ Frequency│
├──────────┼──────────┤
│   10     │    4     │ ← Maximum
│    5     │    3     │
│   15     │    2     │
│   20     │    1     │ ← Minimum
└──────────┴──────────┘

Step 2: Find Max/Min
Scan through map:
- 10: freq=4 → maxFreq=4, maxElement=10
- 5:  freq=3 → (no change)
- 15: freq=2 → (no change)
- 20: freq=1 → minFreq=1, minElement=20

Result:
Highest Frequency: 10 (appears 4 times)
Lowest Frequency: 20 (appears 1 time)
```

---

# 🔹 **Edge Cases to Handle**

```cpp
void findHighestLowest(int arr[], int n) {
    // Edge case: empty array
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    
    // Edge case: single element
    if (n == 1) {
        cout << "Highest: " << arr[0] << " (1 time)" << endl;
        cout << "Lowest: " << arr[0] << " (1 time)" << endl;
        return;
    }
    
    // Normal processing...
}
```

---

# 🔹 **Applications**

1. **Mode of Array:** Element with highest frequency
2. **Outlier Detection:** Elements with very low frequency
3. **Data Analysis:** Understanding distribution
4. **Majority Element:** Check if max frequency > n/2
5. **Unique Elements:** Elements with frequency = 1
6. **Load Balancing:** Identify over/under-utilized resources

---

# 🔹 **Related Problems**

### **Find All Elements with Max Frequency**
```cpp
vector<int> findAllMax(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    
    int maxFreq = 0;
    for (auto it : freq) maxFreq = max(maxFreq, it.second);
    
    vector<int> result;
    for (auto it : freq) {
        if (it.second == maxFreq) {
            result.push_back(it.first);
        }
    }
    return result;
}
```

### **Find Frequency Range**
```cpp
pair<int, int> frequencyRange(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    
    int maxF = INT_MIN, minF = INT_MAX;
    for (auto it : freq) {
        maxF = max(maxF, it.second);
        minF = min(minF, it.second);
    }
    return {minF, maxF};
}
```

---

# 🔹 **Time & Space Complexity**

| Method              | Time       | Space    | Notes                    |
| ------------------- | ---------- | -------- | ------------------------ |
| Unordered Map       | O(n)       | O(k)     | Best average case ⭐     |
| Map                 | O(n log k) | O(k)     | Sorted output            |
| Single Pass         | O(n)       | O(k)     | Optimized                |
| Brute Force         | O(n²)      | O(1)     | Not recommended ❌       |

k = number of unique elements

---

# 🔹 **Key Concepts**

1. **Two-Pass Approach:** Count frequencies, then find max/min
2. **Track While Building:** Update max/min during frequency counting
3. **Handle Ties:** Decide strategy for equal frequencies
4. **Edge Cases:** Empty, single element, all same frequency
5. **INT_MIN/INT_MAX:** Use for initial comparison values

---

# 🔹 **Summary**

- Use unordered_map for O(n) time complexity
- Two passes: one to count, one to find max/min
- Handle edge cases: empty array, single element, ties
- Can extend to find all elements with max/min frequency
- Essential for statistical analysis of arrays
- Foundation for mode, outlier detection, and distribution analysis

---

