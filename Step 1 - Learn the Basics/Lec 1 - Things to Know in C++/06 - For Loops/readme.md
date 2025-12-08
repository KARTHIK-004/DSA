# 📘 **NOTES — 06 For Loop**

## 🔹 What is a `for` loop?

A **for loop** is used when you want to repeat a task **a specific number of times**.
It is the most commonly used loop in C++.

---

## 🔹 Why do we use `for` loop?

- To print sequences (1 to 10, even numbers, tables)
- To take multiple inputs quickly
- To scan through arrays
- To run fixed number of repetitions
- To perform repeated calculations

---

## 🔹 Syntax

```cpp
for (initialization; condition; update) {
    // repeated statements
}
```

### Meaning:

- **initialization** → runs once at start
- **condition** → loop continues while true
- **update** → happens after every iteration

---

## 🔹 Example Breakdown

Example:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << i;
}
```

### Step-by-step:

1. `int i = 1` → loop starts
2. Check `i <= 5` → true
3. Print `i`
4. `i++` → increases i
5. Repeat until condition becomes false

---

## 🔹 Flow of For Loop

1. Initialization
2. Condition check
3. Execute loop body
4. Update step
5. Go back to condition

Loop stops when the condition becomes **false**.

---

## 🔹 Types of For Loops

### 1️⃣ Normal for loop

Used for simple counting tasks.

### 2️⃣ Reverse loop

Example: `for (int i = 10; i >= 1; i--)`

### 3️⃣ Step-based loop

Example: `for (int i = 0; i < 20; i += 2)`
(prints even numbers)

### 4️⃣ Loop through arrays

Example: `for (int i = 0; i < size; i++)`

---

## 🔹 Common Mistakes

❌ Forgetting update step → infinite loop
❌ Wrong condition → loop may never run
❌ Using wrong index when accessing arrays

---

## 🔹 Summary

- `for` loop repeats a block of code multiple times
- Best when number of repetitions is known
- Uses **initialization → condition → update** structure
- Widely used for counting, arrays, and patterns

---
