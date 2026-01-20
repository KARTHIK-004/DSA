# 📘 **NOTES — Pattern 13: Continuous Number Triangle**

Print a right triangle with continuous sequential numbers that don't reset at each row.

---

## 🔹 **Pattern Structure**

```
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
```

For N = 5:
- Row 1: 1
- Row 2: 2, 3
- Row 3: 4, 5, 6
- Row 4: 7, 8, 9, 10
- Row 5: 11, 12, 13, 14, 15

Numbers continue sequentially across rows!

---

## 🔹 **Approach**

### Idea

- Use a counter variable that persists across rows
- Counter starts at 1 and increments with each number printed
- Unlike other patterns, the counter does NOT reset at each row

### Algorithm

1. Initialize counter `num = 1` before loops
2. Outer loop: Iterate through rows (i from 1 to N)
3. Inner loop: Print and increment num, j times (j from 1 to i)
4. Move to next line after each row

### Code

```cpp
void pattern13(int N) {
    int num = 1;  // Counter persists across rows
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;  // Increment after each print
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Initialize: num = 1

Row 1 (i=1):
  - j=1: Print 1, num becomes 2
  - Output: 1

Row 2 (i=2):
  - j=1: Print 2, num becomes 3
  - j=2: Print 3, num becomes 4
  - Output: 2 3

Row 3 (i=3):
  - j=1: Print 4, num becomes 5
  - j=2: Print 5, num becomes 6
  - j=3: Print 6, num becomes 7
  - Output: 4 5 6

Row 4 (i=4):
  - j=1: Print 7, num becomes 8
  - j=2: Print 8, num becomes 9
  - j=3: Print 9, num becomes 10
  - j=4: Print 10, num becomes 11
  - Output: 7 8 9 10

Row 5 (i=5):
  - j=1: Print 11, num becomes 12
  - j=2: Print 12, num becomes 13
  - j=3: Print 13, num becomes 14
  - j=4: Print 14, num becomes 15
  - j=5: Print 15, num becomes 16
  - Output: 11 12 13 14 15
```

---

## 🔹 **Key Concept**

**Persistent Counter:** The variable `num` is declared OUTSIDE the loops and maintains its value across all iterations.

```cpp
int num = 1;  // ← Declared here, persists across rows
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";  // Increments continuously
    }
}
```

**vs. Resetting Counter:**
```cpp
for (int i = 1; i <= N; i++) {
    int num = 1;  // ← Resets each row (WRONG for this pattern)
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";
    }
}
// Would produce: 1, 1 2, 1 2 3, ... (Pattern 1)
```

---

## 🔹 **Dry Run (N = 4)**

```
num = 1

i=1: j=1       → Print 1, num=2
i=2: j=1,2     → Print 2 3, num=4
i=3: j=1,2,3   → Print 4 5 6, num=7
i=4: j=1,2,3,4 → Print 7 8 9 10, num=11

Output:
1 
2 3 
4 5 6 
7 8 9 10 
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
2 3 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Start from Different Number
```cpp
int num = 10;  // Start from 10
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";
    }
    cout << endl;
}

// Output for N=3:
// 10
// 11 12
// 13 14 15
```

### Variation 2: Even Numbers Only
```cpp
int num = 2;  // Start from 2
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num << " ";
        num += 2;  // Increment by 2
    }
    cout << endl;
}

// Output for N=4:
// 2
// 4 6
// 8 10 12
// 14 16 18 20
```

### Variation 3: Fibonacci Sequence
```cpp
int a = 0, b = 1;
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}

// Output for N=4:
// 1
// 1 2
// 3 5 8
// 13 21 34 55
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loop: i iterations for each row
- Total: 1 + 2 + 3 + ... + N = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- Only one extra variable (num)
- Loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
1 + 2 + 3 + ... + N = N(N+1)/2

Last number printed = N(N+1)/2

For N=5: 
  Total numbers = 5×6/2 = 15
  Last number = 15

For N=10:
  Total numbers = 10×11/2 = 55
  Last number = 55
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Resetting Counter Each Row
```cpp
// ❌ WRONG - Counter resets
for (int i = 1; i <= N; i++) {
    int num = 1;  // Resets to 1 each row!
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";
    }
}

// ✅ CORRECT - Counter persists
int num = 1;  // Outside loops
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";
    }
}
```

### Mistake 2: Incrementing in Wrong Place
```cpp
// ❌ WRONG - Increments before printing
cout << ++num << " ";  // Skips 1

// ✅ CORRECT - Increments after printing
cout << num++ << " ";
```

### Mistake 3: Using j Instead of num
```cpp
// ❌ WRONG - Prints column number
cout << j << " ";

// ✅ CORRECT - Prints counter
cout << num << " ";
```

---

## 🔹 **Comparison with Similar Patterns**

| Pattern | Row 3 Output | Counter Behavior |
|---------|--------------|------------------|
| Continuous (13) | `4 5 6` | Persists across rows |
| Sequential (1) | `1 2 3` | Resets each row |
| Row repeated (12) | `3 3 3` | Uses row number |

---

## 🔹 **Understanding Counter Scope**

```cpp
// Scope visualization:
int num = 1;  // ← Scope: entire function
              //   Persists across all iterations

for (int i = 1; i <= N; i++) {  // ← i scope: outer loop
    
    for (int j = 1; j <= i; j++) {  // ← j scope: inner loop
        cout << num++ << " ";
        // num is accessible here and maintains value
    }
    // num still has its value here
}
// num still has final value here
```

---

## 🔹 **Step-by-Step Construction**

1. **Initialize counter** outside loops: `int num = 1`
2. **For each row i:**
   - Print i numbers
   - Each number is current value of num
   - Increment num after each print
3. **Counter never resets** - this is the key!

---

## 🔹 **Visual Representation**

```
Counter progression:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 10 → 11 → 12 → 13 → 14 → 15

Arranged in triangle:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

---

## 🔹 **Practice Tips**

1. Understand the difference between persistent and local variables
2. Trace the value of `num` through each iteration
3. Compare with patterns that reset each row
4. Try starting from different numbers
5. Experiment with different increment values
6. Calculate the last number before running

---

## 🔹 **Related Patterns**

1. **Sequential Triangle:** Resets to 1 each row
2. **Arithmetic Sequence:** Increment by constant (2, 3, etc.)
3. **Geometric Sequence:** Multiply by constant
4. **Custom Sequence:** Fibonacci, primes, squares

---

## 🔹 **Summary**

- **Pattern Type:** Right triangle with continuous numbers
- **Key Feature:** Counter persists across rows
- **Critical Concept:** Variable scope and persistence
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy-Medium
- **Key Learning:** Understanding when to reset vs persist variables

---

