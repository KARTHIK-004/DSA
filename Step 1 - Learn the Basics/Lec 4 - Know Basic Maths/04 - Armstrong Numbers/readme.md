# 📘 **NOTES — 04 Armstrong Numbers**

An Armstrong number (also called Narcissistic number) is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

We want to find:
👉 **Is the given number an Armstrong number?**

Example:
`n = 153` → `1³ + 5³ + 3³ = 1 + 125 + 27 = 153` → **Armstrong ✓**
`n = 9474` → `9⁴ + 4⁴ + 7⁴ + 4⁴ = 6561 + 256 + 2401 + 256 = 9474` → **Armstrong ✓**

---

# 🔹 **Method — Extract Digits and Calculate Sum**

### Idea

1. Count the number of digits in the number
2. Extract each digit
3. Raise each digit to the power of total digits
4. Sum all the powered digits
5. Compare with original number

### Example

```
n = 153 (3 digits)
1³ + 5³ + 3³ = 1 + 125 + 27 = 153
153 == 153 → Armstrong ✓

n = 123 (3 digits)
1³ + 2³ + 3³ = 1 + 8 + 27 = 36
36 != 123 → Not Armstrong ✗
```

### Code

```cpp
bool isArmstrong(int n) {
    if (n < 0) return false;
    
    int original = n;
    int sum = 0;
    
    // Count digits
    int digits = 0;
    int temp = n;
    while (temp > 0) {
        digits++;
        temp = temp / 10;
    }
    
    // Calculate sum of digits raised to power
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum = sum + pow(digit, digits);
        temp = temp / 10;
    }
    
    return original == sum;
}
```

---

# 🔹 **Common Armstrong Numbers**

| Digits | Armstrong Numbers                     |
| ------ | ------------------------------------- |
| 1      | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9          |
| 2      | None                                  |
| 3      | 153, 370, 371, 407                    |
| 4      | 1634, 8208, 9474                      |
| 5      | 54748, 92727, 93084                   |

---

# 🔹 **Special Cases**

| Input              | Result                                |
| ------------------ | ------------------------------------- |
| `0`                | **true** (0¹ = 0)                     |
| Single digit (1-9) | **true** (n¹ = n)                     |
| Negative numbers   | **false**                             |
| `153`              | **true**                              |
| `123`              | **false**                             |

---

# 🔹 **Full Example Workflow**

For number `n = 153`:

```
Step 1: Count digits = 3
Step 2: Extract and calculate:
        digit = 3 → 3³ = 27, sum = 27
        digit = 5 → 5³ = 125, sum = 152
        digit = 1 → 1³ = 1, sum = 153
Step 3: Compare: 153 == 153 → Armstrong ✓
```

For number `n = 9474`:

```
Step 1: Count digits = 4
Step 2: Extract and calculate:
        digit = 4 → 4⁴ = 256, sum = 256
        digit = 7 → 7⁴ = 2401, sum = 2657
        digit = 4 → 4⁴ = 256, sum = 2913
        digit = 9 → 9⁴ = 6561, sum = 9474
Step 3: Compare: 9474 == 9474 → Armstrong ✓
```

---

# 🔹 **Time Complexity**

| Operation           | Time           |
| ------------------- | -------------- |
| Count digits        | **O(log₁₀ n)** |
| Calculate sum       | **O(log₁₀ n)** |
| **Total**           | **O(log₁₀ n)** |

**Space Complexity:** O(1)

---

# 🔹 **Summary**

- Armstrong number equals sum of its digits raised to power of digit count
- All single-digit numbers are Armstrong numbers
- No 2-digit Armstrong numbers exist
- Time complexity is O(log₁₀ n)

---

