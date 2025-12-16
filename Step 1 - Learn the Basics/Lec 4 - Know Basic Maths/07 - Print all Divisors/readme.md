# 📘 **NOTES — 07 Print all Divisors**

A divisor (or factor) of a number is a number that divides it completely without leaving a remainder.

We want to find:
👉 **What are all the divisors of a given number?**

Example:
`n = 36` → Divisors = `1, 2, 3, 4, 6, 9, 12, 18, 36`
`n = 12` → Divisors = `1, 2, 3, 4, 6, 12`

---

# 🔹 **Method 1 — Brute Force (Check All Numbers)**

### Idea

- Check every number from 1 to n
- If it divides n completely, it's a divisor

### Code

```cpp
void printDivisorsBrute(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}
```

**Time Complexity:** O(n)

---

# 🔹 **Method 2 — Optimized (Check Till √n) ⭐**

(This is the most efficient method)

### Idea

- Divisors come in pairs: if `i` divides `n`, then `n/i` also divides `n`
- We only need to check till √n
- For each divisor `i`, we also get `n/i`

### Example

```
n = 36, √36 = 6

i = 1 → divisors: 1, 36
i = 2 → divisors: 2, 18
i = 3 → divisors: 3, 12
i = 4 → divisors: 4, 9
i = 5 → 36 % 5 != 0 (skip)
i = 6 → divisors: 6 (only once, since 6 = 36/6)

All divisors: 1, 36, 2, 18, 3, 12, 4, 9, 6
```

### Code

```cpp
void printDivisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";

            // Print the corresponding divisor if different
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}
```

**Time Complexity:** O(√n)

---

# 🔹 **Method 3 — Sorted Divisors**

If you want divisors in sorted order:

```cpp
void printDivisorsSorted(int n) {
    vector<int> divisors;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        cout << d << " ";
    }
}
```

**Time Complexity:** O(√n + d log d), where d is number of divisors

---

# 🔹 **Special Cases**

| Input               | Divisors                       |
| ------------------- | ------------------------------ |
| `1`                 | **1**                          |
| Prime number (17)   | **1, 17** (only 2 divisors)    |
| Perfect square (16) | **1, 16, 2, 8, 4** (odd count) |
| `12`                | **1, 12, 2, 6, 3, 4**          |

---

# 🔹 **Full Example Workflow**

For number `n = 36`:

```
√36 = 6

i = 1: 36 % 1 = 0 → print 1, 36
i = 2: 36 % 2 = 0 → print 2, 18
i = 3: 36 % 3 = 0 → print 3, 12
i = 4: 36 % 4 = 0 → print 4, 9
i = 5: 36 % 5 = 1 → skip
i = 6: 36 % 6 = 0 → print 6 (only once)

Divisors: 1, 36, 2, 18, 3, 12, 4, 9, 6
```

---

# 🔹 **Count of Divisors**

If you only need to count divisors:

```cpp
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                count++;  // Perfect square case
            } else {
                count += 2;  // Both i and n/i
            }
        }
    }
    return count;
}
```

---

# 🔹 **Time Complexity**

| Method         | Time                | Space    |
| -------------- | ------------------- | -------- |
| Brute Force    | **O(n)**            | **O(1)** |
| Optimized (√n) | **O(√n)**           | **O(1)** |
| Sorted         | **O(√n + d log d)** | **O(d)** |

---

# 🔹 **Summary**

- Divisors come in pairs: (i, n/i)
- Only check till √n for optimization
- Time complexity reduces from O(n) to O(√n)
- For sorted output, store and sort the divisors

---
