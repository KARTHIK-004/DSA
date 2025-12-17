# 📘 **NOTES — 06 Reverse an Array**

Reverse an array using recursion.

We want to:
👉 **Reverse the elements of an array using recursion**

Example:
`arr = [1, 2, 3, 4, 5]` → `[5, 4, 3, 2, 1]`

---

# 🔹 **Method 1 — Two Pointer Recursive Approach ⭐**

### Idea

- Use two pointers: start and end
- Swap elements at start and end
- Recursively call with start+1 and end-1
- Base case: when start >= end

### Recursion Tree

```
reverseArray([1,2,3,4,5], 0, 4)
├── Swap arr[0] and arr[4] → [5,2,3,4,1]
└── reverseArray([5,2,3,4,1], 1, 3)
    ├── Swap arr[1] and arr[3] → [5,4,3,2,1]
    └── reverseArray([5,4,3,2,1], 2, 2)
        └── Base case (start >= end) → Return
```

### Code

```cpp
void reverseArray(int arr[], int start, int end) {
    // Base case: when start >= end, array is reversed
    if (start >= end)
        return;
    
    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
    // Recursive call with updated indices
    reverseArray(arr, start + 1, end - 1);
}

// Call: reverseArray(arr, 0, n-1)
```

### Workflow for arr = [1, 2, 3, 4, 5]

```
Step 1: reverseArray(arr, 0, 4)
        Swap arr[0] ↔ arr[4] → [5, 2, 3, 4, 1]
        Call reverseArray(arr, 1, 3)

Step 2: reverseArray(arr, 1, 3)
        Swap arr[1] ↔ arr[3] → [5, 4, 3, 2, 1]
        Call reverseArray(arr, 2, 2)

Step 3: reverseArray(arr, 2, 2)
        start == end → Base case → Return

Result: [5, 4, 3, 2, 1]
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - recursion stack depth is n/2

---

# 🔹 **Method 2 — Single Pointer Recursive**

```cpp
void reverseArray(int arr[], int i, int n) {
    // Base case: reached middle
    if (i >= n / 2)
        return;
    
    // Swap arr[i] with arr[n-i-1]
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    
    // Recursive call
    reverseArray(arr, i + 1, n);
}

// Call: reverseArray(arr, 0, n)
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

# 🔹 **Method 3 — Iterative Two Pointer**

```cpp
void reverseArrayIterative(int arr[], int n) {
    int start = 0, end = n - 1;
    
    while (start < end) {
        // Swap
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Method 4 — Using STL**

```cpp
#include <algorithm>

void reverseArraySTL(int arr[], int n) {
    reverse(arr, arr + n);
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Stack Visualization**

```
For arr = [1, 2, 3, 4, 5]:

Stack builds:
reverseArray(arr, 0, 4) → Swap 1↔5 → [5,2,3,4,1]
reverseArray(arr, 1, 3) → Swap 2↔4 → [5,4,3,2,1]
reverseArray(arr, 2, 2) → Base case → Return

Stack unwinds:
reverseArray(arr, 1, 3) → Returns
reverseArray(arr, 0, 4) → Returns

Final: [5, 4, 3, 2, 1]
```

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (start >= end) return;`           |
| **Swap**        | Exchange arr[start] and arr[end]      |
| **Recursive Case** | `reverseArray(arr, start+1, end-1);` |
| **Parameters**  | Array, start index, end index         |

---

# 🔹 **Examples**

| Input Array        | Output Array                          |
| ------------------ | ------------------------------------- |
| `[1, 2, 3, 4, 5]`  | `[5, 4, 3, 2, 1]`                     |
| `[10, 20, 30]`     | `[30, 20, 10]`                        |
| `[1, 2]`           | `[2, 1]`                              |
| `[5]`              | `[5]` (single element)                |
| `[]`               | `[]` (empty array)                    |

---

# 🔹 **Even vs Odd Length Arrays**

### Even Length (n = 4)
```
[1, 2, 3, 4]
 ↓     ↓
Swap 1↔4 → [4, 2, 3, 1]
    ↓  ↓
Swap 2↔3 → [4, 3, 2, 1]
```

### Odd Length (n = 5)
```
[1, 2, 3, 4, 5]
 ↓        ↓
Swap 1↔5 → [5, 2, 3, 4, 1]
    ↓     ↓
Swap 2↔4 → [5, 4, 3, 2, 1]
       ↓
Middle element (3) stays in place
```

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| Empty array        | Empty array                           |
| Single element     | Same array                            |
| Two elements       | Swapped                               |
| Already reversed   | Original array                        |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Two Pointer Recursive | **O(n)**     | **O(n/2)** |
| Single Pointer Recursive | **O(n)**  | **O(n/2)** |
| Iterative           | **O(n)**       | **O(1)**   |
| STL reverse()       | **O(n)**       | **O(1)**   |

---

# 🔹 **In-Place Reversal**

All methods shown are **in-place** - they modify the original array without using extra space for another array.

```cpp
// NOT in-place (uses extra space):
int* reverseNotInPlace(int arr[], int n) {
    int* newArr = new int[n];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[n - 1 - i];
    }
    return newArr;
}
```

---

# 🔹 **Key Concepts**

1. **Two Pointer Technique:** Classic approach for array reversal
2. **In-Place Modification:** No extra array needed
3. **Symmetry:** Swap elements symmetrically from both ends
4. **Base Case:** When pointers meet or cross
5. **Stack Depth:** Only n/2 recursive calls needed

---

# 🔹 **Related Problems**

- **Reverse a String:** Same logic with char array
- **Palindrome Check:** Reverse and compare
- **Rotate Array:** Extension of reversal technique
- **Reverse Subarray:** Reverse only a portion

---

# 🔹 **Summary**

- Use two pointers from both ends of array
- Swap elements and move pointers inward
- Base case: when pointers meet or cross
- Recursion depth is n/2 (only half the array)
- Iterative approach is more space-efficient
- Demonstrates in-place array manipulation with recursion

---

