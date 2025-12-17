# 📘 **NOTES — 01 Print Something N Times**

Print a message or statement N times using recursion.

We want to:
👉 **Print "Hello World!" (or any message) N times using recursion**

Example:
`n = 5` → Print "Hello World!" 5 times

---

# 🔹 **Understanding Recursion**

**Recursion** is a technique where a function calls itself to solve a problem by breaking it down into smaller subproblems.

Every recursive function has:
1. **Base Case:** Condition to stop recursion
2. **Recursive Case:** Function calls itself with modified parameters

---

# 🔹 **Method 1 — Recursive Approach ⭐**

### Idea

- If n = 0, stop (base case)
- Print the message
- Call the function again with n-1

### Recursion Tree

```
printNTimes(5)
├── Print "Hello World!"
└── printNTimes(4)
    ├── Print "Hello World!"
    └── printNTimes(3)
        ├── Print "Hello World!"
        └── printNTimes(2)
            ├── Print "Hello World!"
            └── printNTimes(1)
                ├── Print "Hello World!"
                └── printNTimes(0) → Base case, return
```

### Code

```cpp
void printNTimes(int n) {
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;
    
    // Print the message
    cout << "Hello World!" << endl;
    
    // Recursive call with n-1
    printNTimes(n - 1);
}
```

### Workflow for n = 3

```
Call 1: printNTimes(3) → Print "Hello World!" → Call printNTimes(2)
Call 2: printNTimes(2) → Print "Hello World!" → Call printNTimes(1)
Call 3: printNTimes(1) → Print "Hello World!" → Call printNTimes(0)
Call 4: printNTimes(0) → Base case reached → Return
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - due to recursion stack

---

# 🔹 **Method 2 — Iterative Approach**

```cpp
void printNTimesIterative(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Hello World!" << endl;
    }
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Stack Space Visualization**

When recursion happens, each function call is stored in the call stack:

```
For n = 3:

Stack grows:
printNTimes(3) ← Top
printNTimes(2)
printNTimes(1)
printNTimes(0) → Returns

Stack shrinks:
printNTimes(3)
printNTimes(2)
printNTimes(1) → Returns

printNTimes(3)
printNTimes(2) → Returns

printNTimes(3) → Returns
```

Maximum stack depth = n + 1

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (n == 0) return;`                 |
| **Recursive Case** | `printNTimes(n - 1);`              |
| **Action**      | Print message before recursive call   |

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | Nothing printed (base case)           |
| `n = 1`            | Print once                            |
| `n = 5`            | Print 5 times                         |
| Negative n         | Should handle (add check)             |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Recursive           | **O(n)**       | **O(n)**   |
| Iterative           | **O(n)**       | **O(1)**   |

**Note:** Recursive approach uses O(n) space due to call stack.

---

# 🔹 **Key Concepts**

1. **Recursion Stack:** Each function call is pushed onto the stack
2. **Base Case:** Essential to prevent infinite recursion
3. **Stack Overflow:** Can occur if n is very large (typically n > 10^5)
4. **Tail Recursion:** This is NOT tail recursive (action happens before recursive call)

---

# 🔹 **Summary**

- Recursion is a function calling itself
- Always need a base case to stop recursion
- Each recursive call uses stack space
- For simple printing, iterative is more efficient
- This problem demonstrates the basic structure of recursion

---

