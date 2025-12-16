# 📘 **NOTES — 09 Sum of Divisors**

The sum of divisors is the total of all numbers that divide a given number completely (including 1 and the number itself).

We want to find:
👉 **What is the sum of all divisors of a given number?**

Example:
`n = 12` → Divisors: 1, 2, 3, 4, 6, 12 → Sum = 28
`n = 6` → Divisors: 1, 2, 3, 6 → Sum = 12

---

# 🔹 **Method 1 — Brute Force (Check All Numbers)**

### Idea

- Check every number from 1 to n
- If it divides n, add it to sum

### Code

```cpp
int sumOfDivisorsBrute(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
```

**Time Complexity:** O(n)

---

# 🔹 **Method 2 — Optimized (Check Till √n) ⭐**

(This is the most efficient method)

### Idea

- Divisors come in pairs: if `i` divides `n`, then `n/i` also divides `n`
- Check only till √n
- Add both divisors in each iteration

### Example

```
n = 12, √12 ≈ 3.46

i = 1 → divisors: 1, 12 → sum = 1 + 12 = 13
i = 2 → divisors: 2, 6  → sum = 13 + 2 + 6 = 21
i = 3 → divisors: 3, 4  → sum = 21 + 3 + 4 = 28

Total sum = 28
```

### Code

```cpp
int sumOfDivisors(int n) {
    if (n <= 0) return 0;
    
    int sum = 0;
    
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            
            // Add corresponding divisor if different
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    
    return sum;
}
```

**Time Complexity:** O(√n)

---

# 🔹 **Examples**

| Number | Divisors                              | Sum    |
| ------ | ------------------------------------- | ------ |
| **1**  | 1                                     | 1      |
| **6**  | 1, 2, 3, 6                            | 12     |
| **12** | 1, 2, 3, 4, 6, 12                     | 28     |
| **28** | 1, 2, 4, 7, 14, 28                    | 56     |
| **36** | 1, 2, 3, 4, 6, 9, 12, 18, 36          | 91     |

---

# 🔹 **Special Cases**

| Input              | Sum                                   |
| ------------------ | ------------------------------------- |
| `1`                | **1**                                 |
| Prime number (7)   | **8** (1 + 7)                         |
| Perfect square (16)| **31** (1+2+4+8+16)                   |
| Perfect number (6) | **12** (sum = 2 × number)             |

---

# 🔹 **Full Example Workflow**

For number `n = 36`:

```
√36 = 6

i = 1: 36 % 1 = 0 → add 1 and 36 → sum = 37
i = 2: 36 % 2 = 0 → add 2 and 18 → sum = 57
i = 3: 36 % 3 = 0 → add 3 and 12 → sum = 72
i = 4: 36 % 4 = 0 → add 4 and 9  → sum = 85
i = 5: 36 % 5 = 1 → skip
i = 6: 36 % 6 = 0 → add 6 only (6 = 36/6) → sum = 91

Total sum = 91
```

---

# 🔹 **Mathematical Formula (For Prime Factorization)**

If `n = p₁^a₁ × p₂^a₂ × ... × pₖ^aₖ`, then:

```
Sum of divisors = [(p₁^(a₁+1) - 1)/(p₁ - 1)] × [(p₂^(a₂+1) - 1)/(p₂ - 1)] × ...
```

Example for n = 12 = 2² × 3¹:
```
Sum = [(2³ - 1)/(2 - 1)] × [(3² - 1)/(3 - 1)]
    = [7/1] × [8/2]
    = 7 × 4
    = 28 ✓
```

---

# 🔹 **Applications**

- Finding perfect numbers (sum of proper divisors = number)
- Finding abundant numbers (sum of proper divisors > number)
- Finding deficient numbers (sum of proper divisors < number)
- Number theory problems

---

# 🔹 **Related Concepts**

**Proper Divisors:** All divisors except the number itself
```cpp
int sumOfProperDivisors(int n) {
    return sumOfDivisors(n) - n;
}
```

**Perfect Number:** Sum of proper divisors = n
- Example: 6 → proper divisors sum = 1+2+3 = 6

**Abundant Number:** Sum of proper divisors > n
- Example: 12 → proper divisors sum = 1+2+3+4+6 = 16 > 12

**Deficient Number:** Sum of proper divisors < n
- Example: 8 → proper divisors sum = 1+2+4 = 7 < 8

---

# 🔹 **Time Complexity**

| Method              | Time           | Space  |
| ------------------- | -------------- | ------ |
| Brute Force         | **O(n)**       | **O(1)** |
| Optimized (√n)      | **O(√n)**      | **O(1)** |
| Prime Factorization | **O(√n)**      | **O(log n)** |

---

# 🔹 **Summary**

- Sum of divisors includes all numbers that divide n (including 1 and n)
- Use √n optimization for efficiency
- Divisors come in pairs (i, n/i)
- Time complexity is O(√n)
- Used in perfect number, abundant number problems

---

