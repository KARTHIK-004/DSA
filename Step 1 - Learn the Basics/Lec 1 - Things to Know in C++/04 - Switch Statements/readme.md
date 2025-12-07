# 📘 **NOTES — 04 Switch Statement**

## 🔹 What is a `switch` statement?

`switch` is used when you want to **choose one option from many choices** based on a single variable.

It is an alternative to long **if–else-if ladders**.

---

## 🔹 Syntax

```cpp
switch (expression) {
    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    default:
        // runs when no case matches
}
```

---

# 🔹 Why do we need `switch`?

✔ Cleaner and easier than many `if-else` conditions
✔ Best for **menu-based** programs
✔ Best when comparing a variable with **constant values**
✔ Improves readability and performance

---

# 🔹 How `switch` works

1. The value of the expression is checked.
2. It matches one of the `case` labels.
3. The corresponding block executes.
4. `break` stops execution from going to the next case.
5. If no case matches → `default` runs.

---

# 🔹 Example 1 — Basic Switch

```cpp
int day = 3;

switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    case 4: cout << "Thursday"; break;
    case 5: cout << "Friday"; break;
    default: cout << "Weekend!";
}
```

---

# 🔹 Example 2 — Menu Selection

```cpp
int choice;
cout << "1. Start\n2. Stop\n3. Exit\n";
cin >> choice;

switch (choice) {
    case 1: cout << "Program Started"; break;
    case 2: cout << "Program Stopped"; break;
    case 3: cout << "Exiting..."; break;
    default: cout << "Invalid Option!";
}
```

---

# 🔹 Rules of `switch`

| Rule                | Description                                                     |
| ------------------- | --------------------------------------------------------------- |
| `switch` works with | int, char, enum, short, long (not float or string in basic C++) |
| `break`             | Prevents falling through next cases                             |
| `default`           | Optional but recommended                                        |
| Cases must be       | Constant values (not variables, not expressions)                |

---

# 🔹 Fall-through (Important Concept)

If `break` is **not used**, the execution continues to the next case.

Example:

```cpp
switch (x) {
    case 1:
        cout << "One";
    case 2:
        cout << "Two";  // runs even if x == 1
}
```

This is called **fall-through** and is usually avoided unless intentionally used.

---

# 🔹 Nested Switch

```cpp
switch (department) {
    case 1:
        switch (year) {
            case 1: cout << "CSE First Year"; break;
            case 2: cout << "CSE Second Year"; break;
        }
        break;

    case 2:
        cout << "ECE Department";
        break;
}
```

Used when decisions depend on **two levels**.

---

# 🔹 When to use if-else instead of switch?

Use **if-else** when:

- You need ranges
  (example: `marks >= 90 && marks <= 100`)
- You need complex conditions
  (example: `age > 18 && citizen == true`)
- You need floating point or strings (in basic C++)

Use **switch** when:

- There are fixed values
- Menu-driven programs
- Character-based choices
- Cleaner alternative to multiple if-else

---

# 🔹 Common Mistakes

### ❌ Missing `break`

Leads to executing multiple cases accidentally.

### ❌ Using non-constant case values

Cases must be **constant literals**.

### ❌ Using float or double in switch

Not allowed in standard C++.

---

# 🔹 Summary

- `switch` is used for **multiple fixed choices**.
- Cleaner than long `if-else` ladders.
- Works with **int/char/enum**.
- Use `break` to stop fall-through.
- Always include `default` for safety.

---
