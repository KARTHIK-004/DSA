# 📘 **NOTES — Pattern 10: Inverted Right Triangle with Numbers**

Print an inverted right triangle where each row contains sequential numbers starting from 1.

---

## 🔹 **Pattern Structure**

```
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
```

For N = 5:
- Row 1: 5 numbers (1 to 5)
- Row 2: 4 numbers (1 to 4)
- Row 3: 3 numbers (1 to 3)
- Row 4: 2 numbers (1 to 2)
- Row 5: 1 number (1)

---

## 🔹 **Approach**

### Idea

- Each row i prints numbers from 1 to (N - i + 1)
- As row number increases, the count of numbers decreases
- Numbers always start from 1 in each row

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. Inner loop: Print numbers from 1 to (N - i + 1)
3. Move to next line after each row

### Code

```cpp
void pattern10(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Row 1 (i=1): 
  - Numbers to print: N - i + 1 = 5 - 1 + 1 = 5
  - j goes from 1 to 5
  - Output: 1 2 3 4 5

Row 2 (i=2):
  - Numbers to print: N - i + 1 = 5 - 2 + 1 = 4
  - j goes from 1 to 4
  - Output: 1 2 3 4

Row 3 (i=3):
  - Numbers to print: N - i + 1 = 5 - 3 + 1 = 3
  - j goes from 1 to 3
  - Output: 1 2 3

Row 4 (i=4):
  - Numbers to print: N - i + 1 = 5 - 4 + 1 = 2
  - j goes from 1 to 2
  - Output: 1 2

Row 5 (i=5):
  - Numbers to print: N - i + 1 = 5 - 5 + 1 = 1
  - j goes from 1 to 1
  - Output: 1
```

---

## 🔹 **Key Formula**

**Numbers per row:** `N - i + 1`

Where:
- N = total rows
- i = current row number

**Pattern:**
- Row 1: N numbers
- Row 2: N-1 numbers
- Row 3: N-2 numbers
- ...
- Row N: 1 number

---

## 🔹 **Dry Run (N = 4)**

```
i=1: j=1,2,3,4 → Print: 1 2 3 4
i=2: j=1,2,3   → Print: 1 2 3
i=3: j=1,2     → Print: 1 2
i=4: j=1       → Print: 1

Output:
1 2 3 4 
1 2 3 
1 2 
1 
```

---

## 🔹 **Edge Cases**

### N = 1
```
1 
```

### N = 2
```
1 2 
1 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Start from Row Number
```cpp
// Each row starts from i instead of 1
for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=5:
// 1 2 3 4 5
// 2 3 4 5
// 3 4 5
// 4 5
// 5
```

### Variation 2: Descending Numbers
```cpp
// Print numbers in descending order
for (int i = 1; i <= N; i++) {
    for (int j = N - i + 1; j >= 1; j--) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=5:
// 5 4 3 2 1
// 4 3 2 1
// 3 2 1
// 2 1
// 1
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop runs N times
- Inner loop runs (N-i+1) times for each i
- Total operations: N + (N-1) + (N-2) + ... + 1 = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- No extra data structures used
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
N + (N-1) + (N-2) + ... + 2 + 1
= N(N+1)/2

For N=5: 5+4+3+2+1 = 15 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Incorrect Loop Condition
```cpp
// ❌ WRONG
for (int j = 1; j < N - i + 1; j++)  // Misses last number

// ✅ CORRECT
for (int j = 1; j <= N - i + 1; j++)
```

### Mistake 2: Wrong Formula
```cpp
// ❌ WRONG
for (int j = 1; j <= N - i; j++)  // Off by one

// ✅ CORRECT
for (int j = 1; j <= N - i + 1; j++)
```

### Mistake 3: Printing Row Number Instead
```cpp
// ❌ WRONG - Prints row number
cout << i << " ";

// ✅ CORRECT - Prints column number
cout << j << " ";
```

---

## 🔹 **Related Patterns**

1. **Normal Triangle:** Rows increase instead of decrease
2. **Inverted Star Triangle:** Same structure with stars
3. **Right-Aligned Triangle:** Add leading spaces

---

## 🔹 **Practice Tips**

1. Start with small N (like 3) to understand the pattern
2. Calculate numbers per row for each i
3. Verify the formula: N - i + 1
4. Test edge cases (N=0, N=1)
5. Try variations (descending, different starting points)

---

## 🔹 **Summary**

- **Pattern Type:** Inverted right triangle
- **Key Formula:** Numbers per row = N - i + 1
- **Loop Structure:** Nested loops (rows × columns)
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Concept:** Understanding how to decrease elements per row

---

