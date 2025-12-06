# 📘 **NOTES — 03 If Else Statement**

## 🔹 What is `if-else`?

`if-else` allows your program to **make decisions** based on conditions.

You check a condition → if it is **true**, one block runs
Otherwise → the **else** block runs.

---

## 🔹 Syntax

```cpp
if (condition) {
    // executes if condition is true
} else {
    // executes if condition is false
}
```

---

# 🔹 Why do we need `if-else`?

To make programs **smart**:

- Check age for voting
- Check marks for grade
- Validate login
- Categorize numbers
- Make menu-based programs

Programs without `if-else` cannot make decisions.

---

# 🔹 Types of Conditional Structures

## 1️⃣ Simple `if`

```cpp
if (temp > 30) {
    cout << "Hot day";
}
```

Runs only if condition is true.

---

## 2️⃣ `if-else`

```cpp
if (age >= 18) {
    cout << "Adult";
}
else {
    cout << "Minor";
}
```

Handles both true and false cases.

---

## 3️⃣ `if – else if – else`

Used for **multiple conditions**.

```cpp
if (marks >= 90) {
    cout << "Grade A";
}
else if (marks >= 75) {
    cout << "Grade B";
}
else if (marks >= 50) {
    cout << "Grade C";
}
else {
    cout << "Fail";
}
```

Only one block will execute — the first condition that becomes true.

---

## 4️⃣ Nested if-else

An `if` statement inside another `if`.

```cpp
if (age > 0) {
    if (age >= 18) {
        cout << "Adult";
    } else {
        cout << "Not an adult";
    }
}
else {
    cout << "Invalid age";
}
```

Used when decisions depend on **multiple layers**.

---

# 🔹 Comparisons Used in Conditions

| Operator | Meaning          |
| -------- | ---------------- |
| `==`     | Equal to         |
| `!=`     | Not equal        |
| `<`      | Less than        |
| `>`      | Greater than     |
| `<=`     | Less or equal    |
| `>=`     | Greater or equal |

---

# 🔹 Logical Operators

Used for combining conditions.

| Operator | Meaning |     |     |
| -------- | ------- | --- | --- |
| `&&`     | AND     |     |     |
| `        |         | `   | OR  |
| `!`      | NOT     |     |     |

### Example:

```cpp
if (age >= 18 && citizen == true) {
    cout << "Eligible to vote";
}
```

Both conditions must be true because of `&&`.

---

# 🔹 Real-Life Example — Checking Login

```cpp
if (username == "Karthik" && password == 1234) {
    cout << "Login Successful";
}
else {
    cout << "Incorrect credentials";
}
```

Shows how multiple conditions are combined.

---

# 🔹 Common Mistakes

### ❌ Using `=` instead of `==`

```cpp
if (x = 5)   // WRONG: this assigns 5 to x
```

Correct:

```cpp
if (x == 5)
```

---

### ❌ Forgetting braces

```cpp
if (x > 0)
    cout << "Positive";
    cout << "Done";  // executes always — WRONG
```

Always use braces `{}` for safety:

```cpp
if (x > 0) {
    cout << "Positive";
    cout << "Done";
}
```

---

# 🔹 Summary

- `if-else` allows decision-making in programs.
- Use it for conditions and multiple cases.
- Combine conditions with logical operators.
- Be careful with syntax and common mistakes.
