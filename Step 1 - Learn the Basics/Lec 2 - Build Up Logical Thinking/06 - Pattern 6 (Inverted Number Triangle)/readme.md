# 📘 **NOTES — Pattern 6: Inverted Number Triangle**

Print an inverted right triangle with sequential numbers, decreasing count each row.

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
- Row 1: [1, 2, 3, 4, 5] (5 numbers)
- Row 2: [1, 2, 3, 4] (4 numbers)
- Row 3: [1, 2, 3] (3 numbers)
- Row 4: [1, 2] (2 numbers)
- Row 5: [1] (1 number)

Each row starts from 1, count decreases!

---

## 🔹 **Approach**

### Idea

- Combination of Pattern 5 (inverted) and Pattern 3 (sequential numbers)
- Each row has (N - i + 1) numbers
- Numbers always start from 1

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. Inner loop: Print numbers from 1 to (N - i + 1)
3. Move to next line after each row

### Code

```cpp
void pattern6(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (numbers decrease each row)
        for (int j = 1; j <= N - i + 1; j++)
        {
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
  - Numbers: N - i + 1 = 5 - 1 + 1 = 5
  - Print: 1 2 3 4 5

Row 2 (i=2):
  - Numbers: N - i + 1 = 5 - 2 + 1 = 4
  - Print: 1 2 3 4

Row 3 (i=3):
  - Numbers: N - i + 1 = 5 - 3 + 1 = 3
  - Print: 1 2 3

Row 4 (i=4):
  - Numbers: N - i + 1 = 5 - 4 + 1 = 2
  - Print: 1 2

Row 5 (i=5):
  - Numbers: N - i + 1 = 5 - 5 + 1 = 1
  - Print: 1
```

---

## 🔹 **Key Formula**

**Numbers in row i:** `N - i + 1`

```
Row 1: N - 1 + 1 = N numbers
Row 2: N - 2 + 1 = N-1 numbers
Row 3: N - 3 + 1 = N-2 numbers
...
Row N: N - N + 1 = 1 number
```

---

## 🔹 **Dry Run (N = 4)**

```
i=1: j=1 to 4 → Print 1 2 3 4
i=2: j=1 to 3 → Print 1 2 3
i=3: j=1 to 2 → Print 1 2
i=4: j=1 to 1 → Print 1

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
for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=4:
// 1 2 3 4
// 2 3 4
// 3 4
// 4
```

### Variation 2: Descending Numbers
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = N - i + 1; j >= 1; j--) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=4:
// 4 3 2 1
// 3 2 1
// 2 1
// 1
```

### Variation 3: Alphabet Pattern
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i + 1; j++) {
        cout << (char)('A' + j - 1) << " ";
    }
    cout << endl;
}

// Output for N=4:
// A B C D
// A B C
// A B
// A
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loop: (N-i+1) iterations
- Total: N + (N-1) + ... + 1 = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
N + (N-1) + (N-2) + ... + 1 = N(N+1)/2

For N=5: 5+4+3+2+1 = 15 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Wrong Formula
```cpp
// ❌ WRONG - Missing +1
for (int j = 1; j <= N - i; j++)

// ✅ CORRECT
for (int j = 1; j <= N - i + 1; j++)
```

### Mistake 2: Printing i Instead of j
```cpp
// ❌ WRONG - Prints row number
cout << i << " ";

// ✅ CORRECT - Prints sequential
cout << j << " ";
```

### Mistake 3: Starting from 0
```cpp
// ❌ WRONG - Starts from 0
for (int j = 0; j < N - i + 1; j++) {
    cout << j << " ";  // Prints 0 1 2...
}

// ✅ CORRECT - Starts from 1
for (int j = 1; j <= N - i + 1; j++) {
    cout << j << " ";
}
```

---

## 🔹 **Comparison with Related Patterns**

| Pattern | Row 1 | Row 2 | Row 3 | Direction |
|---------|-------|-------|-------|-----------|
| Pattern 3 | `1` | `1 2` | `1 2 3` | Increasing |
| Pattern 5 | `* * * * *` | `* * * *` | `* * *` | Decreasing |
| Pattern 6 | `1 2 3 4 5` | `1 2 3 4` | `1 2 3` | Decreasing |

---

## 🔹 **Understanding the Formula**

```cpp
for (int i = 1; i <= N; i++) {
    // Row i has (N - i + 1) numbers
    // i=1: N-1+1 = N
    // i=2: N-2+1 = N-1
    // i=N: N-N+1 = 1
    
    for (int j = 1; j <= N - i + 1; j++) {
        cout << j << " ";  // Print 1, 2, 3, ...
    }
}
```

---

## 🔹 **Alternative Implementation**

```cpp
// Using 0-based indexing
for (int i = 0; i < N; i++) {
    for (int j = 1; j <= N - i; j++) {
        cout << j << " ";
    }
    cout << endl;
}
```

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Calculate count:** N - i + 1
2. **Print numbers 1 to count**
3. **Move to next line**

---

## 🔹 **Visual Representation**

```
Row 1: 1 2 3 4 5  ← N numbers
Row 2: 1 2 3 4    ← N-1 numbers
Row 3: 1 2 3      ← N-2 numbers
Row 4: 1 2        ← N-3 numbers
Row 5: 1          ← 1 number

Pattern: Sequential numbers, decreasing count
```

---

## 🔹 **Practice Tips**

1. Understand N - i + 1 formula
2. Compare with Pattern 3 and Pattern 5
3. Verify first and last rows
4. Try with small N values
5. Practice variations

---

## 🔹 **Related Patterns**

1. **Pattern 3:** Increasing sequential triangle
2. **Pattern 5:** Inverted star triangle
3. **Descending Numbers:** Reverse order
4. **Alphabet Inverted:** Letters instead

---

## 🔹 **Summary**

- **Pattern Type:** Inverted number triangle
- **Key Feature:** Sequential numbers, decreasing count
- **Critical Formula:** N - i + 1 numbers per row
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Learning:** Combining inverted structure with sequential numbers

---

