# 📘 **NOTES — 08 Check Perfect Number**

A perfect number is a positive integer that is equal to the sum of its proper divisors (divisors excluding the number itself).

We want to find:
👉 **Is the given number a perfect number?**

Example:
`n = 6` → Divisors: 1, 2, 3 → Sum = 1 + 2 + 3 = 6 → **Perfect ✓**
`n = 28` → Divisors: 1, 2, 4, 7, 14 → Sum = 1 + 2 + 4 + 7 + 14 = 28 → **Perfect ✓**

---

# 🔹 **Method 1 — Brute Force (Check All Divisors)**

### Idea

- Find all divisors from 1 to n-1
- Sum all the divisors
- Check if sum equals n

### Code

```cpp
bool isPerfectNumberBrute(int n) {
    if (n <= 1) return false;
    
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    
    return sum == n;
}
```

**Time Complexity:** O(n)

---

# 🔹 **Method 2 — Optimized (Check Till √n) ⭐**

(This is the most efficient method)

### Idea

- Divisors come in pairs: if `i` divides `n`, then `n/i` also divides `n`
- Check only till √n
- Don't include `n` itself in the sum

### Example

```
n = 28, √28 ≈ 5.29

i = 1 → divisors: 1 (don't add 28)
i = 2 → divisors: 2, 14
i = 3 → 28 % 3 != 0 (skip)
i = 4 → divisors: 4, 7
i = 5 → 28 % 5 != 0 (skip)

Sum = 1 + 2 + 14 + 4 + 7 = 28 ✓
```

### Code

```cpp
bool isPerfectNumber(int n) {
    if (n <= 1) return false;
    
    int sum = 1;  // 1 is always a divisor
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            
            // Add corresponding divisor if different from n
            if (i != n / i && n / i != n) {
                sum += n / i;
            }
        }
    }
    
    return sum == n;
}
```

**Time Complexity:** O(√n)

---

# 🔹 **First Few Perfect Numbers**

| Number | Divisors (excluding itself)           | Sum    |
| ------ | ------------------------------------- | ------ |
| **6**  | 1, 2, 3                               | 6      |
| **28** | 1, 2, 4, 7, 14                        | 28     |
| **496**| 1, 2, 4, 8, 16, 31, 62, 124, 248      | 496    |
| **8128**| Many divisors...                     | 8128   |

⚠ Perfect numbers are very rare! Only 51 perfect numbers are known.

---

# 🔹 **Special Cases**

| Input              | Result                                |
| ------------------ | ------------------------------------- |
| `1`                | **false** (sum of divisors = 0)       |
| `6`                | **true**                              |
| `28`               | **true**                              |
| `12`               | **false** (sum = 1+2+3+4+6 = 16)      |
| Negative numbers   | **false**                             |

---

# 🔹 **Full Example Workflow**

For number `n = 28`:

```
Step 1: sum = 1 (always include 1)
Step 2: Check i = 2
        28 % 2 = 0 → add 2 and 14
        sum = 1 + 2 + 14 = 17
Step 3: Check i = 3
        28 % 3 != 0 → skip
Step 4: Check i = 4
        28 % 4 = 0 → add 4 and 7
        sum = 17 + 4 + 7 = 28
Step 5: i = 5 > √28, stop
Step 6: sum == 28 → Perfect ✓
```

---

# 🔹 **Mathematical Property**

All even perfect numbers have the form:
```
2^(p-1) × (2^p - 1)
```
where both `p` and `2^p - 1` are prime numbers.

Examples:
- p = 2: 2¹ × (2² - 1) = 2 × 3 = 6
- p = 3: 2² × (2³ - 1) = 4 × 7 = 28
- p = 5: 2⁴ × (2⁵ - 1) = 16 × 31 = 496

---

# 🔹 **Time Complexity**

| Method              | Time           | Space  |
| ------------------- | -------------- | ------ |
| Brute Force         | **O(n)**       | **O(1)** |
| Optimized (√n)      | **O(√n)**      | **O(1)** |

---

# 🔹 **Summary**

- Perfect number equals sum of its proper divisors
- Only a few perfect numbers exist (6, 28, 496, 8128...)
- Use √n optimization to find divisors efficiently
- Time complexity is O(√n)
- All known perfect numbers are even

---

