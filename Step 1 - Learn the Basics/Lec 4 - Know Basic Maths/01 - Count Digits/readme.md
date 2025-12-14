# 📘 **NOTES — 01 Count Digits**

Counting digits is one of the simplest but most important math operations in programming.
It is used in number theory, patterns, loops, recursion, digit problems, etc.

We want to find:
👉 **How many digits does a number have?**

Example:
`n = 12345` → output = `5`

---

# 🔹 **Method 1 — Using Loop (Divide by 10)**

(This is the most basic and important method)

### Idea

- Repeatedly divide the number by 10
- Each division removes the last digit
- Count how many times division happens until number becomes 0

### Example

`1234 → 123 → 12 → 1 → 0` → 4 digits

### Code

```cpp
int countDigits(int n) {
    int cnt = 0;

    while (n > 0) {
        n = n / 10;  // remove last digit
        cnt++;
    }

    return cnt;
}
```

---

# 🔹 **Method 2 — Using Logarithm (log10)**

(Faster, used in CP)

Formula:

```
digits = floor(log10(n)) + 1
```

### Code

```cpp
int countDigitsLog(int n) {
    return floor(log10(n)) + 1;
}
```

⚠ Works only when `n > 0`.

---

# 🔹 **Method 3 — Convert to String**

```cpp
int countDigitsString(int n) {
    string s = to_string(n);
    return s.length();
}
```

Easy but slower (uses memory + conversion).

---

# 🔹 **Special Cases**

| Input              | Digits                         |
| ------------------ | ------------------------------ |
| `0`                | **1**                          |
| Negative numbers   | Count digits of absolute value |
| Very large numbers | Prefer string method           |

---

# 🔹 **Full Example Workflow**

For number `n = 59021`:

```
59021 → 5902 → 590 → 59 → 5 → 0
Count = 5
```

---

# 🔹 **Time Complexity**

| Method              | Time           |
| ------------------- | -------------- |
| Loop (divide by 10) | **O(log₁₀ n)** |
| log10() method      | **O(1)**       |
| string method       | **O(digits)**  |

---

# 🔹 **Summary**

- Counting digits is a fundamental operation
- Loop method is easiest and universally asked in exams
- Logarithm method is fastest
- String method is simplest but slower

---
