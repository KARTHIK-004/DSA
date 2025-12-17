# 📘 **NOTES — 05 Factorial of N**

Calculate the factorial of N using recursion.

We want to:
👉 **Find N! = N × (N-1) × (N-2) × ... × 2 × 1 using recursion**

Example:
`n = 5` → `5! = 5 × 4 × 3 × 2 × 1 = 120`

---

# 🔹 **Understanding Factorial**

**Factorial** of a non-negative integer n is the product of all positive integers less than or equal to n.

```
0! = 1 (by definition)
1! = 1
2! = 2 × 1 = 2
3! = 3 × 2 × 1 = 6
4! = 4 × 3 × 2 × 1 = 24
5! = 5 × 4 × 3 × 2 × 1 = 120
```

---

# 🔹 **Method 1 — Recursive Approach ⭐**

### Idea

- Factorial of n = n × factorial of (n-1)
- Base case: 0! = 1 and 1! = 1

### Mathematical Formula

```
factorial(n) = n × factorial(n-1)
factorial(0) = 1 (base case)
factorial(1) = 1 (base case)

Example:
factorial(5) = 5 × factorial(4)
             = 5 × (4 × factorial(3))
             = 5 × 4 × (3 × factorial(2))
             = 5 × 4 × 3 × (2 × factorial(1))
             = 5 × 4 × 3 × 2 × 1
             = 120
```

### Recursion Tree

```
factorial(5)
├── return 5 × factorial(4)
│              ├── return 4 × factorial(3)
│              │              ├── return 3 × factorial(2)
│              │              │              ├── return 2 × factorial(1)
│              │              │              │              └── return 1
│              │              │              └── return 2
│              │              └── return 6
│              └── return 24
└── return 120
```

### Code

```cpp
long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1)
        return 1;
    
    // Recursive case: n * factorial(n-1)
    return n * factorial(n - 1);
}
```

### Workflow for n = 4

```
factorial(4) = 4 × factorial(3)
             = 4 × (3 × factorial(2))
             = 4 × 3 × (2 × factorial(1))
             = 4 × 3 × 2 × 1
             = 24
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - recursion stack

---

# 🔹 **Method 2 — Iterative Approach**

```cpp
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Method 3 — Tail Recursive**

```cpp
long long factorialTail(int n, long long result) {
    // Base case
    if (n == 0 || n == 1)
        return result;
    
    // Tail recursive call
    return factorialTail(n - 1, n * result);
}

// Call: factorialTail(5, 1)
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - but can be optimized by compiler

---

# 🔹 **Stack Visualization**

```
For n = 4:

Stack builds:
factorial(4) → Waits for factorial(3)
factorial(3) → Waits for factorial(2)
factorial(2) → Waits for factorial(1)
factorial(1) → Returns 1

Stack unwinds with multiplication:
factorial(2) → Returns 2 × 1 = 2
factorial(3) → Returns 3 × 2 = 6
factorial(4) → Returns 4 × 6 = 24
```

---

# 🔹 **Factorial Values**

| n    | n!                                    |
| ---- | ------------------------------------- |
| 0    | 1                                     |
| 1    | 1                                     |
| 2    | 2                                     |
| 3    | 6                                     |
| 4    | 24                                    |
| 5    | 120                                   |
| 6    | 720                                   |
| 7    | 5,040                                 |
| 8    | 40,320                                |
| 9    | 362,880                               |
| 10   | 3,628,800                             |
| 20   | 2,432,902,008,176,640,000             |

⚠ **Note:** Factorial grows very fast! Use `long long` to avoid overflow.

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (n == 0 || n == 1) return 1;`     |
| **Recursive Case** | `return n * factorial(n - 1);`     |
| **Return Type** | `long long` (to handle large values)  |
| **Operation**   | Multiplication during unwinding       |

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | 1 (by definition)                     |
| `n = 1`            | 1                                     |
| `n = 5`            | 120                                   |
| Negative n         | Undefined (add validation)            |
| Large n (>20)      | Overflow (use BigInteger or modulo)   |

---

# 🔹 **Overflow Consideration**

```cpp
// For int (32-bit): max factorial is 12! = 479,001,600
// For long long (64-bit): max factorial is 20!

// To prevent overflow, use modulo:
long long factorialMod(int n, int mod) {
    if (n == 0 || n == 1)
        return 1;
    return (n * factorialMod(n - 1, mod)) % mod;
}
```

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Recursive           | **O(n)**       | **O(n)**   |
| Tail Recursive      | **O(n)**       | **O(n)***  |
| Iterative           | **O(n)**       | **O(1)**   |

*Can be O(1) with tail call optimization

---

# 🔹 **Applications**

1. **Permutations:** Number of ways to arrange n items = n!
2. **Combinations:** C(n,r) = n! / (r! × (n-r)!)
3. **Probability:** Many probability formulas use factorials
4. **Series Expansion:** Taylor series, e^x = Σ(x^n / n!)
5. **Derangements:** Counting problems in combinatorics

---

# 🔹 **Related Problems**

```cpp
// Permutation: nPr = n! / (n-r)!
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Combination: nCr = n! / (r! × (n-r)!)
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
```

---

# 🔹 **Key Concepts**

1. **Classic Recursion Example:** Factorial is the textbook example
2. **Exponential Growth:** Values grow extremely fast
3. **Data Type:** Use `long long` to handle larger values
4. **Tail Recursion:** Can be optimized by some compilers
5. **Overflow Risk:** Be careful with large n values

---

# 🔹 **Summary**

- Factorial is a classic recursion problem
- Base cases: 0! = 1 and 1! = 1
- Recursive formula: n! = n × (n-1)!
- Values grow exponentially - use `long long`
- Iterative approach is more space-efficient
- Important in combinatorics and probability

---

