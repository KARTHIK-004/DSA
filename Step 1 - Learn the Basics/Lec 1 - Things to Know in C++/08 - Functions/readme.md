# 📘 **NOTES — 08 Functions**

# 🟦 **1. What is a Function?**

A function is a reusable block of code that performs a specific task.

### Syntax

```cpp
returnType functionName(parameters) {
    // function body
}
```

Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

# 🔹 **Why do we need Functions?**

- Reduce code repetition
- Improve readability
- Divide large programs into smaller parts
- Easier debugging
- Reusable and organized code

---

---

# ----------------------------------------------------

# 🟢 **2. Types of Functions**

## 2️⃣.1 **Void Function**

A function that **does not return any value**.

```cpp
void greet() {
    cout << "Hello!";
}
```

➡ Used when you only want some action/output.

---

## 2️⃣.2 **Parameterized Function**

A function that **takes input values** (parameters).

```cpp
void display(int n) {
    cout << "Number: " << n;
}
```

➡ Input is passed from the caller.

---

## 2️⃣.3 **Non-Parameterized Function**

A function that **does not take inputs**.

```cpp
void show() {
    cout << "Welcome!";
}
```

➡ Useful when message/output is fixed.

---

## 2️⃣.4 **Function with Return Type**

A function that returns a value using `return`.

```cpp
int square(int x) {
    return x * x;
}
```

➡ Used for calculations or operations where result is needed.

---

# ----------------------------------------------------

# 🟣 **3. Why Use Functions?**

- Avoid repetition
- Make code readable
- Easy to debug
- Reusable
- Helps structure large programs

---

# ----------------------------------------------------

# 🟧 **4. Function Call Methods**

There are 2 main ways to pass data to functions:

---

# 🟦 **4.1 PASS BY VALUE**

### 🔹 What is it?

A **copy** of the variable is passed to the function.

➡ Original value does **not change**.

### Example:

```cpp
void change(int x) {
    x = 100;   // only local copy changes
}
```

### When to use?

✔ When original value should remain safe
✔ For read-only operations

---

# 🟩 **4.2 PASS BY REFERENCE**

### 🔹 What is it?

The **actual variable** is passed (using `&`).

➡ Original value **changes**.

### Example:

```cpp
void change(int &x) {
    x = 100;   // original variable changes
}
```

### When to use?

✔ When you want to modify real data
✔ For performance (no copying large data)

---

# ----------------------------------------------------

# 🟨 **5. Difference Between Pass by Value & Pass by Reference**

| Feature           | Pass by Value       | Pass by Reference |
| ----------------- | ------------------- | ----------------- |
| What is passed?   | Copy of variable    | Actual variable   |
| Original changes? | ❌ No               | ✔ Yes             |
| Safety            | Safer               | Risky if misused  |
| Speed             | Slower for big data | Faster            |
| Syntax            | `int x`             | `int &x`          |

---

# ----------------------------------------------------

# 🟫 **6. Types of Functions Summary Table**

| Type                     | Takes Parameters | Returns Value | Syntax Example          |
| ------------------------ | ---------------- | ------------- | ----------------------- |
| **Void**                 | Optional         | No            | `void show()`           |
| **Parameterized**        | Yes              | Optional      | `void display(int x)`   |
| **Non-Parameterized**    | No               | Optional      | `void greet()`          |
| **Return-Type Function** | Optional         | Yes           | `int add(int a, int b)` |

---

---

# ----------------------------------------------------

# 🔹 **Summary**

- Functions help break programs into smaller tasks
- Void = no return value
- Parameterized = takes inputs
- Non-parameterized = no inputs
- Pass by Value = original unchanged
- Pass by Reference = original changed

---
