# 📘 **NOTES — Pattern 4: Row Number Triangle**

Print a right triangle where each row contains the row number repeated.

---

## 🔹 **Pattern Structure**

```
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
```

For N = 5:
- Row 1: [1] (1 repeated 1 time)
- Row 2: [2, 2] (2 repeated 2 times)
- Row 3: [3, 3, 3] (3 repeated 3 times)
- Row 4: [4, 4, 4, 4] (4 repeated 4 times)
- Row 5: [5, 5, 5, 5, 5] (5 repeated 5 times)

Row number i is repeated i times!

---

## 🔹 **Approach**

### Idea

- Each row i prints the number i, repeated i times
- Outer loop (i) determines WHAT to print
- Inner loop (j) determines HOW MANY times to print

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. Inner loop: Repeat i times (j from 1 to i)
3. Print i in each iteration (not j!)
4. Move to next line after each row

### Code

```cpp
void pattern4(int N)
{
    // Loop for rows
    for (int i = 1; i <= N; i++)
    {
        // Loop for columns (row number repeated)
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";  // Print i, not j
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
  - j=1: Print 2
  - j=2: Print 2
  - Output: 2 2

Row 3 (i=3):
  - j=1,2,3: Print 3 (three times)
  - Output: 3 3 3

Row 4 (i=4):
  - j=1,2,3,4: Print 4 (four times)
  - Output: 4 4 4 4

Row 5 (i=5):
  - j=1,2,3,4,5: Print 5 (five times)
  - Output: 5 5 5 5 5
```

---

## 🔹 **Key Concept**

**Understanding i vs j:**

- **i (outer loop):** WHAT to print (the row number)
- **j (inner loop):** HOW MANY times to print (counter)

```cpp
for (int i = 1; i <= N; i++) {      // i = WHAT (row number)
    for (int j = 1; j <= i; j++) {  // j = HOW MANY (counter)
        cout << i << " ";           // Print i, not j!
    }
}
```

**This is the OPPOSITE of Pattern 3:**
- Pattern 3: Print j (sequential numbers)
- Pattern 4: Print i (repeated row number)

---

## 🔹 **Dry Run (N = 4)**

```
i=1: j runs 1 time  → Print 1 (once)      → "1"
i=2: j runs 2 times → Print 2 (twice)     → "2 2"
i=3: j runs 3 times → Print 3 (3 times)   → "3 3 3"
i=4: j runs 4 times → Print 4 (4 times)   → "4 4 4 4"

Output:
1 
2 2 
3 3 3 
4 4 4 4 
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
2 2 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Column Number Instead
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << j << " ";  // Print j instead of i
    }
    cout << endl;
}

// Output for N=3:
// 1
// 1 2
// 1 2 3
// (This is Pattern 3!)
```

### Variation 2: Reverse Row Numbers
```cpp
for (int i = N; i >= 1; i--) {
    for (int j = 1; j <= N - i + 1; j++) {
        cout << i << " ";
    }
    cout << endl;
}

// Output for N=4:
// 4
// 3 3
// 2 2 2
// 1 1 1 1
```

### Variation 3: Even Row Numbers Only
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << i * 2 << " ";
    }
    cout << endl;
}

// Output for N=4:
// 2
// 4 4
// 6 6 6
// 8 8 8 8
```

### Variation 4: Alphabet Pattern
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << (char)('A' + i - 1) << " ";
    }
    cout << endl;
}

// Output for N=4:
// A
// B B
// C C C
// D D D D
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

Same count as Pattern 3, but different values!

---

## 🔹 **Common Mistakes**

### Mistake 1: Printing j Instead of i
```cpp
// ❌ WRONG - Prints sequential numbers (Pattern 3)
for (int j = 1; j <= i; j++) {
    cout << j << " ";
}

// ✅ CORRECT - Prints row number
for (int j = 1; j <= i; j++) {
    cout << i << " ";
}
```

### Mistake 2: Using j as Loop Limit
```cpp
// ❌ WRONG - Infinite loop or wrong count
for (int j = 1; j <= j; j++)

// ✅ CORRECT - Use i as limit
for (int j = 1; j <= i; j++)
```

### Mistake 3: Starting from 0
```cpp
// ❌ WRONG - Prints 0 in first row
for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
        cout << i << " ";  // Prints 0, 1 1, 2 2 2...
    }
}

// ✅ CORRECT - Starts from 1
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << i << " ";
    }
}
```

---

## 🔹 **Comparison with Pattern 3**

| Feature | Pattern 3 | Pattern 4 |
|---------|-----------|-----------|
| What to print | j (column) | i (row) |
| Row 1 | `1` | `1` |
| Row 2 | `1 2` | `2 2` |
| Row 3 | `1 2 3` | `3 3 3` |
| Row 4 | `1 2 3 4` | `4 4 4 4` |
| Concept | Sequential | Repeated |

---

## 🔹 **Understanding the Roles**

```cpp
for (int i = 1; i <= N; i++) {
    // i tells us:
    // - Which row we're on
    // - What number to print
    // - How many times to print it
    
    for (int j = 1; j <= i; j++) {
        // j tells us:
        // - Which position in the row
        // - Acts as a counter
        // - We DON'T print j in this pattern
        
        cout << i << " ";  // Always print i
    }
}
```

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Outer loop sets i** (the number to print)
2. **Inner loop runs i times** (how many to print)
3. **Each iteration prints i** (not j)
4. **After inner loop,** print newline

---

## 🔹 **Visual Representation**

```
Row 1: 1           ← Print 1, once
Row 2: 2 2         ← Print 2, twice
Row 3: 3 3 3       ← Print 3, three times
Row 4: 4 4 4 4     ← Print 4, four times
Row 5: 5 5 5 5 5   ← Print 5, five times

Pattern: Row number repeated row_number times
```

---

## 🔹 **Practice Tips**

1. Clearly distinguish between i and j roles
2. Remember: i = WHAT, j = HOW MANY
3. Compare side-by-side with Pattern 3
4. Trace i and j values for each iteration
5. Try variations with different numbers
6. Understand why we print i, not j

---

## 🔹 **Related Patterns**

1. **Pattern 3:** Sequential numbers (prints j)
2. **Pattern 2:** Star triangle (same structure)
3. **Reverse Row Numbers:** Descending row numbers
4. **Alphabet Row Pattern:** Letters instead of numbers

---

## 🔹 **Summary**

- **Pattern Type:** Right triangle with repeated row numbers
- **Key Feature:** Row number i repeated i times
- **Critical Concept:** Print i (row), not j (column)
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Learning:** Understanding WHAT vs HOW MANY (i vs j)

---

