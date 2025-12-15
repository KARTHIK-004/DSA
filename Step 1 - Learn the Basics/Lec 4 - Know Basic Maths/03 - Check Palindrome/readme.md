# 📘 **NOTES — 03 Check Palindrome**

A palindrome number is a number that remains the same when its digits are reversed.

We want to find:
👉 **Is the given number a palindrome?**

Example:
`n = 121` → output = `true` (reversed is also 121)
`n = 123` → output = `false` (reversed is 321)

---

# 🔹 **Method 1 — Reverse the Number and Compare**

(This is the most common and efficient method)

### Idea

- Reverse the entire number
- Compare the reversed number with the original
- If they are equal, it's a palindrome

### Example

```
Original: 121
Reversed: 121
121 == 121 → Palindrome ✓

Original: 123
Reversed: 321
123 != 321 → Not a Palindrome ✗
```

### Code

```cpp
bool isPalindrome(int n) {
    if (n < 0) return false;  // Negative numbers are not palindromes

    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return original == reversed;
}
```

---

# 🔹 **Method 2 — Using String Conversion**

```cpp
bool isPalindromeString(int n) {
    if (n < 0) return false;

    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());

    return s == rev;
}
```

Easy but uses extra space for string conversion.

---

# 🔹 **Special Cases**

| Input              | Result                       |
| ------------------ | ---------------------------- |
| `0`                | **true** (single digit)      |
| Negative numbers   | **false** (by convention)    |
| Single digit (1-9) | **true** (always palindrome) |
| `121`              | **true**                     |
| `1221`             | **true**                     |
| `123`              | **false**                    |

---

# 🔹 **Full Example Workflow**

For number `n = 12321`:

```
Step 1: original = 12321, reversed = 0
Step 2: digit = 1, reversed = 1, n = 1232
Step 3: digit = 2, reversed = 12, n = 123
Step 4: digit = 3, reversed = 123, n = 12
Step 5: digit = 2, reversed = 1232, n = 1
Step 6: digit = 1, reversed = 12321, n = 0

Compare: 12321 == 12321 → Palindrome ✓
```

---

# 🔹 **Time Complexity**

| Method              | Time           | Space         |
| ------------------- | -------------- | ------------- |
| Reverse and compare | **O(log₁₀ n)** | **O(1)**      |
| String method       | **O(digits)**  | **O(digits)** |

---

# 🔹 **Summary**

- A palindrome number reads the same forwards and backwards
- Reverse the number and compare with original
- Negative numbers are not palindromes
- Time complexity is O(log₁₀ n) where n is the number

---
