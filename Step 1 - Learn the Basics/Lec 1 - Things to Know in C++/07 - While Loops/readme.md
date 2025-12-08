# 📘 **NOTES — 07 While Loop**

# 🔹 **What is a Loop?**

A loop is used to **repeat a block of code** multiple times until a condition becomes false.

C++ provides three loops:

- `for`
- `while`
- `do-while`

This note explains **while** and **do-while**.

---

# ----------------------------------------------------

# 🟦 **WHILE LOOP**

## 🔹 What is a `while` loop?

A **while loop** repeats a statement **as long as** a condition remains true.
The condition is checked **before** the loop runs.

---

## 🔹 Syntax

```cpp
while (condition) {
    // repeated statements
}
```

---

## 🔹 How it works?

1. Check the condition
2. If true → execute loop body
3. Update the variable
4. Repeat
5. Stop when condition becomes false

---

## 🔹 Example (Print 1 to 5)

```cpp
int i = 1;

while (i <= 5) {
    cout << i << " ";
    i++;        // update step
}
```

---

## 🔹 When to use `while` loop?

- When number of iterations is **not known**
- When condition needs to be checked **before** execution
- Useful in menu systems, reading until user stops, file reading

---

# ----------------------------------------------------

# 🟩 **DO-WHILE LOOP**

## 🔹 What is a `do-while` loop?

A **do-while loop** always runs **at least once**,
because the condition is checked **after** the loop body.

---

## 🔹 Syntax

```cpp
do {
    // repeated statements
} while (condition);
```

⚠ Notice the semicolon `;` at the end.

---

## 🔹 How it works?

1. Run the loop body first
2. Check the condition
3. If true → repeat
4. If false → stop

---

## 🔹 Example (Print 1 to 5)

```cpp
int i = 1;

do {
    cout << i << " ";
    i++;
} while (i <= 5);
```

---

## 🔹 When to use `do-while` loop?

- When the loop must run **at least one time**
- Used in menu-driven programs ("Press 1 to continue")
- Useful when user input is required before checking condition

---

# ----------------------------------------------------

# 🔸 **Difference: While vs Do-While**

| Feature              | while loop          | do-while loop       |
| -------------------- | ------------------- | ------------------- |
| Condition checked    | Before loop starts  | After loop executes |
| Runs at least once?  | ❌ No               | ✔ Yes               |
| Used for             | Unknown repetitions | Must-run-once tasks |
| Syntax ends with `;` | ❌ No               | ✔ Yes               |

---

# ----------------------------------------------------

# 🔹 **Common Mistakes**

❌ Forgetting to update loop variable → infinite loop
❌ Missing semicolon in `do-while` → syntax error
❌ Using wrong condition → loop never runs

---

# ----------------------------------------------------

# 🔹 **Summary**

### **While Loop**

- Checks condition **before** running
- May run zero times
- Good for unknown iterations

### **Do-While Loop**

- Runs **at least once**
- Checks condition **after** execution
- Good for user-input-driven tasks

---
