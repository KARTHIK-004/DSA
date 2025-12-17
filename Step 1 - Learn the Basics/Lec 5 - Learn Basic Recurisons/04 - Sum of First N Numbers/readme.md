# 📘 **NOTES — 04 Sum of First N Numbers**

Calculate the sum of first N natural numbers using recursion.

We want to:
👉 **Find the sum: 1 + 2 + 3 + ... + N using recursion**

Example:
`n = 5` → `1 + 2 + 3 + 4 + 5 = 15`

---

# 🔹 **Method 1 — Recursive Approach ⭐**

### Idea

- Sum of first n numbers = n + sum of first (n-1) numbers
- Base case: sum of 0 numbers = 0

### Mathematical Formula

```
sum(n) = n + sum(n-1)
sum(0) = 0 (base case)

Example:
sum(5) = 5 + sum(4)
       = 5 + (4 + sum(3))
       = 5 + 4 + (3 + sum(2))
       = 5 + 4 + 3 + (2 + sum(1))
       = 5 + 4 + 3 + 2 + (1 + sum(0))
       = 5 + 4 + 3 + 2 + 1 + 0
       = 15
```

### Recursion Tree

```
sumOfN(5)
├── return 5 + sumOfN(4)
│            ├── return 4 + sumOfN(3)
│            │            ├── return 3 + sumOfN(2)
│            │            │            ├── return 2 + sumOfN(1)
│            │            │            │            ├── return 1 + sumOfN(0)
│            │            │            │            │            └── return 0
│            │            │            │            └── return 1
│            │            │            └── return 3
│            │            └── return 6
│            └── return 10
└── return 15
```

### Code

```cpp
int sumOfN(int n) {
    // Base case: sum of 0 numbers is 0
    if (n == 0)
        return 0;
    
    // Recursive case: n + sum of (n-1) numbers
    return n + sumOfN(n - 1);
}
```

### Workflow for n = 4

```
sumOfN(4) = 4 + sumOfN(3)
          = 4 + (3 + sumOfN(2))
          = 4 + 3 + (2 + sumOfN(1))
          = 4 + 3 + 2 + (1 + sumOfN(0))
          = 4 + 3 + 2 + 1 + 0
          = 10
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - recursion stack

---

# 🔹 **Method 2 — Parameterized Recursion**

Pass sum as a parameter:

```cpp
void sumOfN(int n, int sum) {
    // Base case
    if (n == 0) {
        cout << "Sum = " << sum << endl;
        return;
    }
    
    // Add current n to sum and recurse
    sumOfN(n - 1, sum + n);
}

// Call: sumOfN(5, 0)
```

This is **tail recursion** - recursive call is the last operation.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

# 🔹 **Method 3 — Iterative Approach**

```cpp
int sumOfNIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Method 4 — Mathematical Formula (Best)**

```cpp
int sumOfNFormula(int n) {
    return n * (n + 1) / 2;
}
```

**Time Complexity:** O(1)
**Space Complexity:** O(1)

This is the most efficient approach!

---

# 🔹 **Stack Visualization**

```
For n = 4:

Stack builds:
sumOfN(4) → Waits for sumOfN(3)
sumOfN(3) → Waits for sumOfN(2)
sumOfN(2) → Waits for sumOfN(1)
sumOfN(1) → Waits for sumOfN(0)
sumOfN(0) → Returns 0

Stack unwinds with calculations:
sumOfN(1) → Returns 1 + 0 = 1
sumOfN(2) → Returns 2 + 1 = 3
sumOfN(3) → Returns 3 + 3 = 6
sumOfN(4) → Returns 4 + 6 = 10
```

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (n == 0) return 0;`               |
| **Recursive Case** | `return n + sumOfN(n - 1);`        |
| **Return Type** | int (returns the sum)                 |
| **Accumulation**| Sum is built during stack unwinding   |

---

# 🔹 **Functional vs Parameterized Recursion**

### Functional Recursion (Method 1)
```cpp
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
```
- Returns value
- Calculation happens during unwinding

### Parameterized Recursion (Method 2)
```cpp
void sum(int n, int total) {
    if (n == 0) {
        cout << total;
        return;
    }
    sum(n - 1, total + n);
}
```
- Passes accumulated value as parameter
- Tail recursive (can be optimized by compiler)

---

# 🔹 **Examples**

| n    | Calculation                           | Sum    |
| ---- | ------------------------------------- | ------ |
| 1    | 1                                     | 1      |
| 5    | 1+2+3+4+5                             | 15     |
| 10   | 1+2+3+...+10                          | 55     |
| 100  | 1+2+3+...+100                         | 5050   |

Formula verification: n(n+1)/2
- n=5: 5×6/2 = 15 ✓
- n=10: 10×11/2 = 55 ✓

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | 0                                     |
| `n = 1`            | 1                                     |
| `n = 100`          | 5050                                  |
| Negative n         | Should add validation                 |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Functional Recursion| **O(n)**       | **O(n)**   |
| Parameterized Recursion | **O(n)** | **O(n)**   |
| Iterative           | **O(n)**       | **O(1)**   |
| Formula             | **O(1)**       | **O(1)**   |

---

# 🔹 **Key Concepts**

1. **Return Value:** Function returns a value (not void)
2. **Accumulation:** Sum is accumulated during stack unwinding
3. **Tail Recursion:** Parameterized version is tail recursive
4. **Mathematical Insight:** Formula approach is always best when available

---

# 🔹 **Summary**

- Demonstrates functional recursion (returning values)
- Sum is calculated during stack unwinding
- Alternative: parameterized recursion (tail recursive)
- Mathematical formula O(1) is most efficient
- Important pattern for many recursive problems

---

