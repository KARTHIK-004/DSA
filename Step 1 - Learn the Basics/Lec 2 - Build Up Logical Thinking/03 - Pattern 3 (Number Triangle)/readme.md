# 📘 **NOTES — Pattern 3: Sequential Number Triangle**

Print a right triangle where each row contains sequential numbers starting from 1.

---

## 🔹 **Pattern Structure**

```
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
```

For N = 5:
- Row 1: [1]
- Row 2: [1, 2]
- Row 3: [1, 2, 3]
- Row 4: [1, 2, 3, 4]
- Row 5: [1, 2, 3, 4, 5]

Each row starts from 1 and goes up to the row number!

---

## 🔹 **Approach**

### Idea

- Similar to Pattern 2 (star triangle), but print numbers instead of stars
- Each row i contains numbers from 1 to i
- Inner loop variable j represents the number to print

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. Inner loop: Print numbers from 1 to i (j from 1 to i)
3. Print j in each iteration
4. Move to next line after each row

### Code

```cpp
void pattern3(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (numbers in each row)
        for (int j = 1; j <= i; j++)
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
  - j=1: Print 1
  - Output: 1

Row 2 (i=2):
  - j=1: Print 1
  - j=2: Print 2
  - Output: 1 2

Row 3 (i=3):
  - j=1: Print 1
  - j=2: Print 2
  - j=3: Print 3
  - Output: 1 2 3

Row 4 (i=4):
  - j=1,2,3,4: Print 1 2 3 4
  - Output: 1 2 3 4

Row 5 (i=5):
  - j=1,2,3,4,5: Print 1 2 3 4 5
  - Output: 1 2 3 4 5
```

---

## 🔹 **Key Concept**

**Print j, not i:** The inner loop variable j represents the actual number to print.

```cpp
for (int j = 1; j <= i; j++) {
    cout << j << " ";  // ← Print j (column number)
}
```

**vs. Pattern 4 (Row Number Repeated):**
```cpp
for (int j = 1; j <= i; j++) {
    cout << i << " ";  // ← Print i (row number)
}
```

---

## 🔹 **Dry Run (N = 4)**

```
i=1: j=1       → Print 1
i=2: j=1,2     → Print 1 2
i=3: j=1,2,3   → Print 1 2 3
i=4: j=1,2,3,4 → Print 1 2 3 4

Output:
1 
1 2 
1 2 3 
1 2 3 4 
```

---

## 🔹 **Edge Cases**

### N = 1
```
1 
```

### N = 2
```
1 
1 2 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Start from Different Number
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 5; j < 5 + i; j++) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=3:
// 5
// 5 6
// 5 6 7
```

### Variation 2: Even Numbers Only
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << j * 2 << " ";
    }
    cout << endl;
}

// Output for N=4:
// 2
// 2 4
// 2 4 6
// 2 4 6 8
```

### Variation 3: Reverse Order (Descending)
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = i; j >= 1; j--) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=4:
// 1
// 2 1
// 3 2 1
// 4 3 2 1
```

### Variation 4: Alphabet Triangle
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << (char)('A' + j - 1) << " ";
    }
    cout << endl;
}

// Output for N=4:
// A
// A B
// A B C
// A B C D
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loop: i iterations for each row
- Total: 1 + 2 + 3 + ... + N = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- Only loop variables
- No extra data structures

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
1 + 2 + 3 + ... + N = N(N+1)/2

For N=5: 5×6/2 = 15 numbers
For N=10: 10×11/2 = 55 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Printing i Instead of j
```cpp
// ❌ WRONG - Prints row number
for (int j = 1; j <= i; j++) {
    cout << i << " ";  // This gives Pattern 4!
}

// ✅ CORRECT - Prints column number
for (int j = 1; j <= i; j++) {
    cout << j << " ";
}
```

### Mistake 2: Starting from 0
```cpp
// ❌ WRONG - Starts from 0
for (int j = 0; j < i; j++) {
    cout << j << " ";  // Prints 0 1 2...
}

// ✅ CORRECT - Starts from 1
for (int j = 1; j <= i; j++) {
    cout << j << " ";
}
```

### Mistake 3: Wrong Loop Condition
```cpp
// ❌ WRONG - Prints one extra number
for (int j = 1; j <= i + 1; j++)

// ✅ CORRECT
for (int j = 1; j <= i; j++)
```

---

## 🔹 **Comparison with Similar Patterns**

| Pattern | Row 3 Output | What to Print |
|---------|--------------|---------------|
| Pattern 2 (Stars) | `* * *` | Stars |
| Pattern 3 (Sequential) | `1 2 3` | Column number (j) |
| Pattern 4 (Row Number) | `3 3 3` | Row number (i) |

---

## 🔹 **Understanding i vs j**

```cpp
for (int i = 1; i <= N; i++) {      // i = row number
    for (int j = 1; j <= i; j++) {  // j = column number
        cout << j << " ";           // Print j for sequential
    }
}
```

- **i:** Which row we're on (1 to N)
- **j:** Which column/position in the row (1 to i)
- **Print j:** Gives sequential numbers
- **Print i:** Gives repeated row number

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Start inner loop** from j = 1
2. **Continue while** j ≤ i
3. **Print** j followed by space
4. **Increment** j
5. **After inner loop ends,** print newline

---

## 🔹 **Visual Representation**

```
Row 1: 1
Row 2: 1 2
Row 3: 1 2 3
Row 4: 1 2 3 4
Row 5: 1 2 3 4 5

Pattern: Each row contains numbers from 1 to row_number
```

---

## 🔹 **Practice Tips**

1. Understand the difference between printing i and j
2. Trace both loop variables through iterations
3. Compare with Pattern 2 (stars) and Pattern 4 (row numbers)
4. Try variations (even numbers, alphabets, reverse)
5. Calculate total numbers before running
6. Verify each row has correct count of numbers

---

## 🔹 **Related Patterns**

1. **Pattern 2:** Star triangle (same structure, different output)
2. **Pattern 4:** Row number repeated
3. **Reverse Sequential:** Numbers in descending order
4. **Alphabet Triangle:** Letters instead of numbers

---

## 🔹 **Summary**

- **Pattern Type:** Right triangle with sequential numbers
- **Key Feature:** Each row starts from 1
- **Critical Concept:** Print j (column number), not i (row number)
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Learning:** Understanding loop variables and what to print

---

