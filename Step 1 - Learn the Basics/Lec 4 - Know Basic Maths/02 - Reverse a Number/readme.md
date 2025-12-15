# 📘 **NOTES — 02 Reverse a Number**

Reversing a number means reading its digits from right to left.

We want to find:
👉 **What is the reverse of a given number?**

Example:
`n = 12345` → output = `54321`
`n = 7800` → output = `87` (leading zeros are removed)

---

# 🔹 **Method 1 — Using Loop (Extract Digits)**

(This is the most common and important method)

### Idea

- Extract the last digit using modulo operator (%)
- Build the reversed number by multiplying by 10 and adding the digit
- Remove the last digit by dividing by 10
- Repeat until the number becomes 0

### Example

```
n = 1234
reversed = 0

Step 1: digit = 4, reversed = 0 * 10 + 4 = 4, n = 123
Step 2: digit = 3, reversed = 4 * 10 + 3 = 43, n = 12
Step 3: digit = 2, reversed = 43 * 10 + 2 = 432, n = 1
Step 4: digit = 1, reversed = 432 * 10 + 1 = 4321, n = 0

Result: 4321
```

### Code

```cpp
int reverseNumber(int n) {
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    
    int reversed = 0;
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }
    
    if (isNegative)
        reversed = -reversed;
    
    return reversed;
}
```

---

# 🔹 **Method 2 — Using String Conversion**

```cpp
int reverseNumberString(int n) {
    bool isNegative = (n < 0);
    string s = to_string(abs(n));
    reverse(s.begin(), s.end());
    
    int reversed = stoi(s);
    return isNegative ? -reversed : reversed;
}
```

Easy but uses extra space and string operations.

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| `0`                | **0**                                 |
| `123`              | **321**                               |
| `-456`             | **-654** (preserve sign)              |
| `7800`             | **87** (leading zeros removed)        |
| `1000`             | **1**                                 |

---

# 🔹 **Full Example Workflow**

For number `n = 59021`:

```
Step 1: digit = 1, reversed = 1, n = 5902
Step 2: digit = 2, reversed = 12, n = 590
Step 3: digit = 0, reversed = 120, n = 59
Step 4: digit = 9, reversed = 1209, n = 5
Step 5: digit = 5, reversed = 12095, n = 0

Result: 12095
```

---

# 🔹 **Overflow Consideration**

⚠ **Important:** When reversing large numbers, the result might overflow.

```cpp
// Check for overflow before multiplying
if (reversed > INT_MAX / 10) {
    return 0;  // or handle overflow
}
```

---

# 🔹 **Time Complexity**

| Method              | Time           | Space  |
| ------------------- | -------------- | ------ |
| Loop method         | **O(log₁₀ n)** | **O(1)** |
| String method       | **O(digits)**  | **O(digits)** |

---

# 🔹 **Applications**

- Checking palindrome numbers
- Number manipulation problems
- Digit-based algorithms
- Competitive programming

---

# 🔹 **Summary**

- Reversing a number is done by extracting digits from right to left
- Use modulo (%) to get last digit and division (/) to remove it
- Handle negative numbers by preserving the sign
- Time complexity is O(log₁₀ n)
- Watch out for integer overflow with large numbers

---

