# 📘 **NOTES — 06 Check for Prime**

A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

We want to find:
👉 **Is the given number a prime number?**

Example:
`n = 17` → Prime ✓ (divisors: 1, 17)
`n = 12` → Not Prime ✗ (divisors: 1, 2, 3, 4, 6, 12)

---

# 🔹 **Method 1 — Brute Force (Check All Numbers)**

### Idea

- Check if any number from 2 to n-1 divides n
- If yes, it's not prime
- If no divisor found, it's prime

### Code

```cpp
bool isPrimeBrute(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}
```

**Time Complexity:** O(n)

---

# 🔹 **Method 2 — Optimized (Check Till √n) ⭐**

(This is the most efficient basic method)

### Idea

- If n has a divisor greater than √n, it must also have a divisor smaller than √n
- So we only need to check till √n

### Example

```
n = 36, √36 = 6
Check: 2, 3, 4, 5, 6
36 % 2 = 0 → Not Prime ✗

n = 17, √17 ≈ 4.12
Check: 2, 3, 4
17 % 2 = 1, 17 % 3 = 2, 17 % 4 = 1
No divisor found → Prime ✓
```

### Code

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(n); i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}
```

**Time Complexity:** O(√n)

---

# 🔹 **Why Check i and i+2 with Step 6?**

All primes > 3 are of the form `6k ± 1`

```
Numbers: 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
         ✗  ✓  ✓  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✓  ✗  ✗  ✗  ✓  ✗  ✗  ✗  ✗  ✗  ✓  ✗

Pattern: 6k-1, 6k+1 (5, 7), (11, 13), (17, 19), (23, 25✗), (29, 31)
```

So we check: 5, 7, 11, 13, 17, 19, 23, 25, 29, 31...
This is done by: i = 5, i+2 = 7, then i = 11, i+2 = 13, etc.

---

# 🔹 **Special Cases**

| Input              | Result                                |
| ------------------ | ------------------------------------- |
| `0, 1`             | **false** (not prime by definition)   |
| `2`                | **true** (only even prime)            |
| `3`                | **true**                              |
| Negative numbers   | **false**                             |
| `17`               | **true**                              |
| `100`              | **false** (divisible by 2)            |

---

# 🔹 **First 20 Prime Numbers**

```
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71
```

---

# 🔹 **Full Example Workflow**

For number `n = 29`:

```
Step 1: n > 1 ✓
Step 2: n != 2 and n != 3
Step 3: 29 % 2 = 1 (not divisible by 2)
        29 % 3 = 2 (not divisible by 3)
Step 4: √29 ≈ 5.38
        Check i = 5: 29 % 5 = 4 ✓
        Check i+2 = 7: 29 % 7 = 1 ✓
        i = 11 > √29, stop
Step 5: No divisor found → Prime ✓
```

For number `n = 91`:

```
Step 1: n > 1 ✓
Step 2: n != 2 and n != 3
Step 3: 91 % 2 = 1, 91 % 3 = 1
Step 4: √91 ≈ 9.54
        Check i = 5: 91 % 5 = 1 ✓
        Check i+2 = 7: 91 % 7 = 0 ✗
Step 5: Divisor found (7) → Not Prime ✗
```

---

# 🔹 **Time Complexity**

| Method              | Time           | Space  |
| ------------------- | -------------- | ------ |
| Brute Force         | **O(n)**       | **O(1)** |
| Optimized (√n)      | **O(√n)**      | **O(1)** |
| 6k±1 Optimization   | **O(√n/3)**    | **O(1)** |

---

# 🔹 **Summary**

- Prime numbers have exactly 2 divisors: 1 and itself
- Only check divisors up to √n for efficiency
- 2 is the only even prime number
- All primes > 3 are of form 6k ± 1
- Time complexity is O(√n)

---

