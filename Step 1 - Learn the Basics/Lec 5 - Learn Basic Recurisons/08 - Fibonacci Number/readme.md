# 📘 **NOTES — 08 Fibonacci Number**

Calculate the Nth Fibonacci number using recursion.

We want to:
👉 **Find the Nth number in the Fibonacci sequence using recursion**

Example:
`n = 10` → `Fibonacci(10) = 55`

---

# 🔹 **Understanding Fibonacci Sequence**

The **Fibonacci sequence** is a series where each number is the sum of the two preceding ones.

```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n ≥ 2

Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...
```

---

# 🔹 **Method 1 — Simple Recursive Approach**

### Idea

- Base cases: F(0) = 0, F(1) = 1
- Recursive case: F(n) = F(n-1) + F(n-2)

### Recursion Tree for F(5)

```
                    fib(5)
                   /      \
              fib(4)      fib(3)
             /     \      /     \
        fib(3)   fib(2) fib(2) fib(1)
        /   \    /   \  /   \
    fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
    /   \
fib(1) fib(0)
```

Notice: Many subproblems are calculated multiple times!

### Code

```cpp
int fibonacci(int n) {
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Workflow for n = 5

```
fib(5) = fib(4) + fib(3)
       = (fib(3) + fib(2)) + (fib(2) + fib(1))
       = ((fib(2) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + 1)
       = (((1 + 0) + 1) + (1 + 0)) + ((1 + 0) + 1)
       = (2 + 1) + 2
       = 5
```

**Time Complexity:** O(2^n) - exponential! ⚠️
**Space Complexity:** O(n) - recursion stack depth

---

# 🔹 **Method 2 — Memoization (Top-Down DP) ⭐**

Store calculated values to avoid recalculation:

```cpp
int fibMemo(int n, int memo[]) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Check if already calculated
    if (memo[n] != -1)
        return memo[n];
    
    // Calculate and store
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

// Usage:
int memo[100];
fill(memo, memo + 100, -1);
int result = fibMemo(n, memo);
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - for memo array + recursion stack

---

# 🔹 **Method 3 — Iterative (Bottom-Up DP)**

```cpp
int fibIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev2 = 0, prev1 = 1;
    int current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Method 4 — Matrix Exponentiation**

For very large n, use matrix exponentiation:

```
[F(n+1)]   [1 1]^n   [1]
[F(n)  ] = [1 0]   × [0]
```

**Time Complexity:** O(log n)
**Space Complexity:** O(1)

---

# 🔹 **Fibonacci Sequence Values**

| n    | F(n)                                  |
| ---- | ------------------------------------- |
| 0    | 0                                     |
| 1    | 1                                     |
| 2    | 1                                     |
| 3    | 2                                     |
| 4    | 3                                     |
| 5    | 5                                     |
| 6    | 8                                     |
| 7    | 13                                    |
| 8    | 21                                    |
| 9    | 34                                    |
| 10   | 55                                    |
| 15   | 610                                   |
| 20   | 6,765                                 |
| 30   | 832,040                               |

---

# 🔹 **Problem with Simple Recursion**

### Redundant Calculations

For F(5), F(3) is calculated **2 times**, F(2) is calculated **3 times**!

```
Number of calls for each:
F(5): 1 time
F(4): 1 time
F(3): 2 times  ← Redundant!
F(2): 3 times  ← Redundant!
F(1): 5 times  ← Redundant!
F(0): 3 times  ← Redundant!

Total function calls: 15 for just F(5)!
```

This is why simple recursion is **exponential** O(2^n).

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case 1** | `if (n == 0) return 0;`               |
| **Base Case 2** | `if (n == 1) return 1;`               |
| **Recursive Case** | `return fib(n-1) + fib(n-2);`      |
| **Two Calls**   | Each call makes TWO recursive calls   |

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | 0                                     |
| `n = 1`            | 1                                     |
| `n = 2`            | 1                                     |
| Negative n         | Undefined (add validation)            |
| Large n (>40)      | Very slow with simple recursion       |

---

# 🔹 **Time & Space Complexity Comparison**

| Method              | Time           | Space      | Best For      |
| ------------------- | -------------- | ---------- | ------------- |
| Simple Recursion    | **O(2^n)**     | **O(n)**   | Learning only |
| Memoization         | **O(n)**       | **O(n)**   | Medium n      |
| Iterative           | **O(n)**       | **O(1)**   | Best overall  |
| Matrix Exponentiation | **O(log n)** | **O(1)**   | Very large n  |

---

# 🔹 **Why Simple Recursion is Slow**

```
For n = 40:
- Simple recursion: ~2^40 = 1,099,511,627,776 operations! 😱
- Memoization: ~40 operations ✓
- Iterative: ~40 operations ✓

Simple recursion for F(40) might take minutes!
Iterative/Memoization: milliseconds
```

---

# 🔹 **Golden Ratio Connection**

Fibonacci numbers are related to the **Golden Ratio** φ (phi):

```
φ = (1 + √5) / 2 ≈ 1.618

F(n) ≈ φ^n / √5

This gives us Binet's Formula:
F(n) = (φ^n - ψ^n) / √5
where ψ = (1 - √5) / 2
```

---

# 🔹 **Applications**

1. **Nature:** Flower petals, pine cones, tree branches
2. **Art:** Golden ratio in paintings and architecture
3. **Computer Science:** Algorithm analysis, data structures
4. **Mathematics:** Number theory, combinatorics
5. **Finance:** Fibonacci retracements in trading

---

# 🔹 **Key Concepts**

1. **Multiple Recursion:** Each call makes TWO recursive calls
2. **Exponential Growth:** Simple recursion is very inefficient
3. **Overlapping Subproblems:** Same values calculated repeatedly
4. **Memoization:** Cache results to avoid recalculation
5. **Classic DP Problem:** Perfect example for dynamic programming

---

# 🔹 **Summary**

- Fibonacci: F(n) = F(n-1) + F(n-2)
- Simple recursion is O(2^n) - very slow!
- Use memoization to reduce to O(n)
- Iterative approach is most efficient: O(n) time, O(1) space
- Classic example of why recursion needs optimization
- Demonstrates overlapping subproblems in dynamic programming

---

