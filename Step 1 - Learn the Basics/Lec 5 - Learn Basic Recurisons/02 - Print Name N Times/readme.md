# 📘 **NOTES — 02 Print Name N Times**

Print a specific name N times using recursion.

We want to:
👉 **Print a given name N times using recursion**

Example:
`n = 4, name = "Raj"` → Print "Raj" 4 times

---

# 🔹 **Method 1 — Recursive Approach ⭐**

### Idea

- If n = 0, stop (base case)
- Print the name
- Call the function again with n-1

### Recursion Tree

```
printName(4, "Raj")
├── Print "Raj"
└── printName(3, "Raj")
    ├── Print "Raj"
    └── printName(2, "Raj")
        ├── Print "Raj"
        └── printName(1, "Raj")
            ├── Print "Raj"
            └── printName(0, "Raj") → Base case, return
```

### Code

```cpp
void printName(int n, string name) {
    // Base case: when n becomes 0, stop recursion
    if (n == 0)
        return;
    
    // Print the name
    cout << name << endl;
    
    // Recursive call with n-1
    printName(n - 1, name);
}
```

### Workflow for n = 3, name = "Alice"

```
Call 1: printName(3, "Alice") → Print "Alice" → Call printName(2, "Alice")
Call 2: printName(2, "Alice") → Print "Alice" → Call printName(1, "Alice")
Call 3: printName(1, "Alice") → Print "Alice" → Call printName(0, "Alice")
Call 4: printName(0, "Alice") → Base case reached → Return
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - due to recursion stack

---

# 🔹 **Method 2 — Iterative Approach**

```cpp
void printNameIterative(int n, string name) {
    for (int i = 0; i < n; i++) {
        cout << name << endl;
    }
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Variation: Print with Counter**

Print name with line numbers:

```cpp
void printNameWithCounter(int i, int n, string name) {
    // Base case
    if (i > n)
        return;
    
    // Print with counter
    cout << i << ". " << name << endl;
    
    // Recursive call
    printNameWithCounter(i + 1, n, name);
}

// Call: printNameWithCounter(1, 5, "Raj")
// Output:
// 1. Raj
// 2. Raj
// 3. Raj
// 4. Raj
// 5. Raj
```

---

# 🔹 **Stack Space Visualization**

```
For n = 4, name = "Raj":

Stack at maximum depth:
printName(4, "Raj")
printName(3, "Raj")
printName(2, "Raj")
printName(1, "Raj")
printName(0, "Raj") ← Returns

Then stack unwinds:
printName(4, "Raj")
printName(3, "Raj")
printName(2, "Raj")
printName(1, "Raj") ← Returns

... and so on
```

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (n == 0) return;`                 |
| **Recursive Case** | `printName(n - 1, name);`          |
| **Parameters**  | n (counter), name (string to print)   |

---

# 🔹 **Alternative Base Case**

You can also use `n == 1` as base case:

```cpp
void printName(int n, string name) {
    if (n == 1) {
        cout << name << endl;
        return;
    }
    
    cout << name << endl;
    printName(n - 1, name);
}
```

Both approaches work, but `n == 0` is more common.

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `n = 0`            | Nothing printed                       |
| `n = 1`            | Print name once                       |
| Empty string       | Print empty lines n times             |
| Negative n         | Should add validation                 |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Recursive           | **O(n)**       | **O(n)**   |
| Iterative           | **O(n)**       | **O(1)**   |

---

# 🔹 **Comparison with Problem 01**

| Aspect              | Problem 01                | Problem 02                |
| ------------------- | ------------------------- | ------------------------- |
| **Message**         | Fixed ("Hello World!")    | Variable (parameter)      |
| **Parameters**      | Only n                    | n and name                |
| **Flexibility**     | Less flexible             | More flexible             |

---

# 🔹 **Key Concepts**

1. **Parameterized Recursion:** Passing additional parameters (name)
2. **Same Structure:** Base case + recursive case pattern
3. **Stack Usage:** Each call stores both n and name on stack
4. **Flexibility:** Can print any string, not just hardcoded message

---

# 🔹 **Summary**

- Similar to Problem 01 but with parameterized input
- Demonstrates passing multiple parameters in recursion
- Base case prevents infinite recursion
- Recursive approach uses O(n) stack space
- Iterative approach is more space-efficient for this simple task

---

