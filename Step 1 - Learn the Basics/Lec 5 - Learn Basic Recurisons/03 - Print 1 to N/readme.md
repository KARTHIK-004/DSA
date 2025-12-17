# 📘 **NOTES — 03 Print 1 to N**

Print numbers from 1 to N using recursion.

We want to:
👉 **Print numbers from 1 to N in ascending order using recursion**

Example:
`n = 5` → Output: `1 2 3 4 5`

---

# 🔹 **Method 1 — Recursive Approach (Print After Recursive Call) ⭐**

### Idea

- Make recursive call first with n-1
- Then print n
- This ensures numbers are printed in ascending order

### Recursion Tree

```
print1ToN(5)
├── print1ToN(4)
│   ├── print1ToN(3)
│   │   ├── print1ToN(2)
│   │   │   ├── print1ToN(1)
│   │   │   │   ├── print1ToN(0) → Base case
│   │   │   │   └── Print 1
│   │   │   └── Print 2
│   │   └── Print 3
│   └── Print 4
└── Print 5

Output: 1 2 3 4 5
```

### Code

```cpp
void print1ToN(int n) {
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;
    
    // Recursive call first (to print in ascending order)
    print1ToN(n - 1);
    
    // Print after recursive call
    cout << n << " ";
}
```

### Workflow for n = 4

```
Call: print1ToN(4)
  ├── Call: print1ToN(3)
  │     ├── Call: print1ToN(2)
  │     │     ├── Call: print1ToN(1)
  │     │     │     ├── Call: print1ToN(0) → Return
  │     │     │     └── Print: 1
  │     │     └── Print: 2
  │     └── Print: 3
  └── Print: 4

Output: 1 2 3 4
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - recursion stack

---

# 🔹 **Method 2 — Recursive with Counter (i to n)**

```cpp
void print1ToN(int i, int n) {
    // Base case: when i exceeds n
    if (i > n)
        return;
    
    // Print current number
    cout << i << " ";
    
    // Recursive call with i+1
    print1ToN(i + 1, n);
}

// Call: print1ToN(1, 5)
```

This approach prints BEFORE the recursive call, making it more intuitive.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

# 🔹 **Method 3 — Iterative Approach**

```cpp
void print1ToNIterative(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Understanding Print Before vs After Recursive Call**

### Print BEFORE Recursive Call (Descending)

```cpp
void printNTo1(int n) {
    if (n == 0) return;
    cout << n << " ";      // Print first
    printNTo1(n - 1);      // Then recurse
}
// Output for n=5: 5 4 3 2 1
```

### Print AFTER Recursive Call (Ascending)

```cpp
void print1ToN(int n) {
    if (n == 0) return;
    print1ToN(n - 1);      // Recurse first
    cout << n << " ";      // Then print
}
// Output for n=5: 1 2 3 4 5
```

---

# 🔹 **Stack Visualization**

```
For n = 3:

Stack builds up (going down):
print1ToN(3) → Waits
print1ToN(2) → Waits
print1ToN(1) → Waits
print1ToN(0) → Returns

Stack unwinds (coming back up):
print1ToN(1) → Prints 1 → Returns
print1ToN(2) → Prints 2 → Returns
print1ToN(3) → Prints 3 → Returns

Output: 1 2 3
```

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (n == 0) return;`                 |
| **Recursive Case** | `print1ToN(n - 1);`                |
| **Action**      | Print n AFTER recursive call          |
| **Order**       | Ascending (1 to N)                    |

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | Nothing printed                       |
| `n = 1`            | `1`                                   |
| `n = 10`           | `1 2 3 4 5 6 7 8 9 10`                |
| Negative n         | Should add validation                 |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Recursive (Method 1)| **O(n)**       | **O(n)**   |
| Recursive (Method 2)| **O(n)**       | **O(n)**   |
| Iterative           | **O(n)**       | **O(1)**   |

---

# 🔹 **Key Concepts**

1. **Order Matters:** Print before vs after recursive call determines output order
2. **Stack Unwinding:** Numbers are printed while stack unwinds
3. **Backtracking Concept:** Go deep first, then process on the way back
4. **Two Approaches:** Counter-based (i to n) or countdown (n to 0)

---

# 🔹 **Related Problems**

- **Print N to 1:** Print before recursive call
- **Print Even Numbers:** Add condition `if (i % 2 == 0)`
- **Print Odd Numbers:** Add condition `if (i % 2 == 1)`

---

# 🔹 **Summary**

- Printing in ascending order requires printing AFTER recursive call
- Stack builds up completely before any printing happens
- Numbers are printed during stack unwinding
- Alternative: Use counter from 1 to n (more intuitive)
- Demonstrates the power of recursion in controlling execution order

---

