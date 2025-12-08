# 📘 **NOTES — 09 Time Complexity (Basics & Rules)**

# 🟦 **What is a Time Complexity?**

Time Complexity tells us **how fast an algorithm grows** as the **input size (n)** increases.

We don’t count exact seconds, we count **steps** (operations).

---

## 🔹 Why Do We Need Time Complexity?

- To compare **two algorithms** for the same problem
- To understand how code behaves for **large inputs**
- To choose **efficient** algorithms in competitive exams / interviews
- To avoid programs that become **too slow** when `n` is big

Example:

- Algorithm A takes `n` steps
- Algorithm B takes `n²` steps

For small `n`, both are fine.
For large `n`, **n² becomes very slow**.

---

## 🔹 Big-O Notation (O-Notation)

Big-O gives the **upper bound** of time complexity.

We write:

- `O(f(n))` → Time grows **proportional to** `f(n)`

Examples:

- `O(1)` → constant time
- `O(n)` → linear time
- `O(n²)` → quadratic time

We mostly focus on **Big-O** in basics.

---

## 🔹 Common Time Complexities (From Best to Worst)

| Notation   | Name         | Example idea                                   |
| ---------- | ------------ | ---------------------------------------------- |
| O(1)       | Constant     | Accessing `arr[i]`                             |
| O(log n)   | Logarithmic  | Binary search                                  |
| O(n)       | Linear       | Loop from 1 to n                               |
| O(n log n) | Linearithmic | Efficient sorting (Merge sort, Quick sort avg) |
| O(n²)      | Quadratic    | Nested loops (i, j)                            |
| O(2ⁿ)      | Exponential  | Some recursive brute force                     |
| O(n!)      | Factorial    | Permutation generation (brute force)           |

---

# 🧠 BASIC RULES FOR TIME COMPLEXITY

These are **very important** when manually analysing code.

---

## 🔹 Rule 1: Ignore Constants

If time is:

- `T(n) = 3n` → `O(3n)` = **O(n)**
- `T(n) = 5n² + 2n + 10` → **O(n²)** (dominant term)

We only care about the **highest power of n**.

---

## 🔹 Rule 2: Add Complexities for Sequential Statements

If part A takes `O(f(n))` and part B takes `O(g(n))`:

- Total = `O(f(n) + g(n))`
- Final answer = **max(f(n), g(n))**

Example:

```cpp
for (int i = 0; i < n; i++) {
    // O(n)
}

for (int j = 0; j < n; j++) {
    // O(n)
}
```

Total = `O(n) + O(n)` = `O(2n)` = **O(n)**.

---

## 🔹 Rule 3: Multiply for Nested Loops

If a loop is inside another loop → we **multiply**.

Example:

```cpp
for (int i = 0; i < n; i++) {          // O(n)
    for (int j = 0; j < n; j++) {      // O(n)
        // constant work
    }
}
```

Total steps ≈ `n * n` → **O(n²)**.

Another example:

```cpp
for (int i = 0; i < n; i++) {          // O(n)
    for (int j = 0; j < 100; j++) {    // O(1) (100 is constant)
        // constant work
    }
}
```

Total ≈ `n * 100` → **O(n)**.

---

## 🔹 Rule 4: Conditionals (if-else)

For `if-else`, we consider the **worst-case branch**.

```cpp
if (condition) {
    // O(n)
} else {
    // O(1)
}
```

Time complexity = **O(n)** (worst possible branch).

---

## 🔹 Rule 5: Loops and `n`

Typical loop patterns:

### 1️⃣ Simple loop

```cpp
for (int i = 0; i < n; i++) {
    // constant
}
```

→ **O(n)**

### 2️⃣ Loop with step 2

```cpp
for (int i = 0; i < n; i += 2) {
    // constant
}
```

Runs ≈ n/2 times → **O(n)** (constants ignored)

### 3️⃣ Logarithmic loop

```cpp
for (int i = 1; i < n; i *= 2) {
    // constant
}
```

i = 1, 2, 4, 8, … up to n → **O(log n)**

---

## 🔹 Rule 6: Function Calls

If a function `f()` is **O(n)** and you call it:

- Once → O(n)
- k times → O(k \* n) → **O(n)** if k is constant

If a function is called **inside a loop**, multiply:

```cpp
for (int i = 0; i < n; i++) {
    f();   // f() is O(n)
}
```

Total = `n * O(n)` = **O(n²)**.

---

# 🔍 Small Examples (Concept Only)

### ✅ Example 1: Single Loop

```cpp
for (int i = 0; i < n; i++) {
    // constant work
}
```

→ **O(n)**.

---

### ✅ Example 2: Two Nested Loops

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // constant work
    }
}
```

→ **O(n²)** (n \* n).

---

### ✅ Example 3: Mixed Parts

```cpp
// Part 1
for (int i = 0; i < n; i++) {   // O(n)
    // constant
}

// Part 2
for (int j = 0; j < n*n; j++) { // O(n²)
    // constant
}
```

Total = `O(n) + O(n²)` = **O(n²)** (dominated by n²).

---

# 📝 Summary (Basics to Remember)

- Time complexity measures **growth of time with input size n**
- We use **Big-O** to express worst-case upper bound
- **Ignore constants**, keep highest power of n
- **Add** complexities for sequential code
- **Multiply** for nested loops
- **If-else** → take **worst-case** branch
- Common orders:
  `O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)`

---
