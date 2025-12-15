# 📘 **NOTES — 05 GCD Or HCF**

GCD (Greatest Common Divisor) or HCF (Highest Common Factor) is the largest number that divides both given numbers.

We want to find:
👉 **What is the GCD of two numbers?**

Example:
`a = 20, b = 15` → GCD = `5`
`a = 12, b = 18` → GCD = `6`

---

# 🔹 **Method 1 — Euclidean Algorithm (Most Efficient)**

(This is the standard and most efficient method)

### Idea

- Repeatedly replace the larger number with the remainder of division
- Continue until one number becomes 0
- The non-zero number is the GCD

### Algorithm

```
while (a > 0 && b > 0):
    if a > b:
        a = a % b
    else:
        b = b % a

return (a == 0) ? b : a
```

### Example

```
GCD(20, 15):
20 % 15 = 5  → a = 5, b = 15
15 % 5 = 0   → a = 5, b = 0
GCD = 5 ✓
```

### Code

```cpp
int findGCD(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) return b;
    return a;
}
```

---

# 🔹 **Method 2 — Recursive Euclidean Algorithm**

```cpp
int findGCDRecursive(int a, int b) {
    if (b == 0) return a;
    return findGCDRecursive(b, a % b);
}
```

Elegant but uses recursion stack space.

---

# 🔹 **Method 3 — Brute Force (Check All Divisors)**

```cpp
int findGCDBrute(int a, int b) {
    int gcd = 1;
    int minNum = min(a, b);

    for (int i = 1; i <= minNum; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}
```

Simple but inefficient for large numbers.

---

# 🔹 **Special Cases**

| Input         | GCD                     |
| ------------- | ----------------------- |
| `GCD(0, n)`   | **n**                   |
| `GCD(n, n)`   | **n**                   |
| `GCD(1, n)`   | **1**                   |
| `GCD(12, 18)` | **6**                   |
| `GCD(17, 19)` | **1** (coprime numbers) |

---

# 🔹 **Full Example Workflow**

For numbers `a = 48, b = 18`:

```
Step 1: 48 > 18 → a = 48 % 18 = 12, b = 18
Step 2: 18 > 12 → b = 18 % 12 = 6, a = 12
Step 3: 12 > 6  → a = 12 % 6 = 0, b = 6
Step 4: a = 0   → GCD = 6 ✓
```

---

# 🔹 **LCM (Least Common Multiple) Relation**

```
LCM(a, b) = (a * b) / GCD(a, b)
```

Example:

```
a = 12, b = 18
GCD = 6
LCM = (12 * 18) / 6 = 36
```

---

# 🔹 **Time Complexity**

| Method              | Time                 | Space                |
| ------------------- | -------------------- | -------------------- |
| Euclidean Algorithm | **O(log(min(a,b)))** | **O(1)**             |
| Recursive Euclidean | **O(log(min(a,b)))** | **O(log(min(a,b)))** |
| Brute Force         | **O(min(a,b))**      | **O(1)**             |

---

# 🔹 **Summary**

- GCD is the largest number that divides both numbers
- Euclidean algorithm is the most efficient method
- Time complexity is O(log(min(a,b)))
- Can be used to calculate LCM efficiently

---
