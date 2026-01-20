# 📘 **NOTES — Pattern 12: Row Number Repeated**

Print a right triangle where each row contains the row number repeated multiple times.

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
- Row 1: Print 1, one time
- Row 2: Print 2, two times
- Row 3: Print 3, three times
- Row 4: Print 4, four times
- Row 5: Print 5, five times

---

## 🔹 **Approach**

### Idea

- Row number i prints the number i, repeated i times
- Very simple pattern: outer loop value determines what to print
- Inner loop determines how many times to print

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. Inner loop: Print i, j times (j from 1 to i)
3. Move to next line after each row

### Code

```cpp
void pattern12(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Row 1 (i=1):
  - Print 1, one time
  - j goes from 1 to 1
  - Output: 1

Row 2 (i=2):
  - Print 2, two times
  - j goes from 1 to 2
  - Output: 2 2

Row 3 (i=3):
  - Print 3, three times
  - j goes from 1 to 3
  - Output: 3 3 3

Row 4 (i=4):
  - Print 4, four times
  - j goes from 1 to 4
  - Output: 4 4 4 4

Row 5 (i=5):
  - Print 5, five times
  - j goes from 1 to 5
  - Output: 5 5 5 5 5
```

---

## 🔹 **Key Formula**

**Number to print:** `i` (row number)

**Repetitions:** `i` times

**Pattern:**
- Row 1: 1 printed 1 time
- Row 2: 2 printed 2 times
- Row 3: 3 printed 3 times
- ...
- Row N: N printed N times

---

## 🔹 **Dry Run (N = 4)**

```
i=1, j=1:       Print 1 → Output: 1
i=2, j=1,2:     Print 2 2 → Output: 2 2
i=3, j=1,2,3:   Print 3 3 3 → Output: 3 3 3
i=4, j=1,2,3,4: Print 4 4 4 4 → Output: 4 4 4 4

Final Output:
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
// Print column number instead of row number
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << j << " ";
    }
    cout << endl;
}

// Output for N=5:
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
```

### Variation 2: Reverse Row Numbers
```cpp
// Print (N - i + 1) instead of i
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << (N - i + 1) << " ";
    }
    cout << endl;
}

// Output for N=5:
// 5
// 4 4
// 3 3 3
// 2 2 2 2
// 1 1 1 1 1
```

### Variation 3: Even Numbers Only
```cpp
// Print even row numbers
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << (2 * i) << " ";
    }
    cout << endl;
}

// Output for N=5:
// 2
// 4 4
// 6 6 6
// 8 8 8 8
// 10 10 10 10 10
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop runs N times
- Inner loop runs i times for each row
- Total operations: 1 + 2 + 3 + ... + N = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- No extra data structures
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
1 + 2 + 3 + ... + N = N(N+1)/2

For N=5: 1+2+3+4+5 = 15 numbers
For N=10: 10×11/2 = 55 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Printing j Instead of i
```cpp
// ❌ WRONG - Prints column number
cout << j << " ";

// ✅ CORRECT - Prints row number
cout << i << " ";
```

### Mistake 2: Wrong Loop Condition
```cpp
// ❌ WRONG - Off by one
for (int j = 1; j < i; j++)

// ✅ CORRECT
for (int j = 1; j <= i; j++)
```

### Mistake 3: Starting from 0
```cpp
// ❌ WRONG - Starts from 0
for (int i = 0; i < N; i++)

// ✅ CORRECT - Starts from 1
for (int i = 1; i <= N; i++)
```

---

## 🔹 **Comparison with Similar Patterns**

| Pattern | Row 3 Output | What Changes |
|---------|--------------|--------------|
| Row number repeated | `3 3 3` | Same number (i) |
| Sequential numbers | `1 2 3` | Different numbers (j) |
| Continuous numbers | `4 5 6` | Counter persists |

---

## 🔹 **Understanding the Logic**

```
Outer loop (i): Controls which row we're on
Inner loop (j): Controls how many times to print

Row i:
  - What to print: i
  - How many times: i
  
Example for i=3:
  j=1: Print 3
  j=2: Print 3
  j=3: Print 3
  Result: 3 3 3
```

---

## 🔹 **Step-by-Step Construction**

For each row i:
1. **Determine value:** Use i (row number)
2. **Determine count:** Use i (same as row number)
3. **Print:** Output i, i times
4. **New line**

---

## 🔹 **Visual Representation**

```
Row 1: i=1 → Print 1 × 1 time  → 1
Row 2: i=2 → Print 2 × 2 times → 2 2
Row 3: i=3 → Print 3 × 3 times → 3 3 3
Row 4: i=4 → Print 4 × 4 times → 4 4 4 4
Row 5: i=5 → Print 5 × 5 times → 5 5 5 5 5
```

---

## 🔹 **Practice Tips**

1. This is one of the simplest patterns
2. Focus on understanding i vs j
3. i determines WHAT to print
4. j determines HOW MANY times
5. Try variations to deepen understanding
6. Compare with Pattern 1 (sequential numbers)

---

## 🔹 **Related Patterns**

1. **Sequential Triangle:** Print j instead of i
2. **Inverted Triangle:** Start from N and decrease
3. **Star Triangle:** Replace numbers with stars
4. **Alphabet Triangle:** Use letters instead of numbers

---

## 🔹 **Applications**

- Understanding nested loops
- Differentiating between loop variables
- Foundation for more complex patterns
- Interview warm-up questions

---

## 🔹 **Summary**

- **Pattern Type:** Right triangle with repeated row numbers
- **Key Formula:** Print i, i times
- **Loop Structure:** Simple nested loops
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Concept:** Using outer loop variable in inner loop

---

