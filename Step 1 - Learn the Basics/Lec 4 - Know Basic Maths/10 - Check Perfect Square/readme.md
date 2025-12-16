# 📘 **NOTES — 10 Check Perfect Square**

A perfect square is a number that can be expressed as the product of an integer with itself.

We want to find:
👉 **Is the given number a perfect square?**

Example:
`n = 64` → 8 × 8 = 64 → **Perfect Square ✓**
`n = 50` → No integer × itself = 50 → **Not Perfect Square ✗**

---

# 🔹 **Method 1 — Using Square Root**

(This is the most common and efficient method)

### Idea

- Find the square root of the number
- Check if squaring the integer part gives back the original number
- If yes, it's a perfect square

### Code

```cpp
bool isPerfectSquare(int n) {
    if (n < 0) return false;
    if (n == 0 || n == 1) return true;

    int sqrtN = sqrt(n);

    return (sqrtN * sqrtN == n);
}
```

**Time Complexity:** O(1) - using built-in sqrt()

---

# 🔹 **Method 2 — Binary Search**

### Idea

- Search for the square root using binary search
- Check if mid × mid equals n

### Code

```cpp
bool isPerfectSquareBinary(int n) {
    if (n < 0) return false;
    if (n == 0 || n == 1) return true;

    long long left = 1, right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == n) {
            return true;
        } else if (square < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
```

**Time Complexity:** O(log n)

---

# 🔹 **Method 3 — Linear Search (Brute Force)**

```cpp
bool isPerfectSquareBrute(int n) {
    if (n < 0) return false;

    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return true;
        }
    }

    return false;
}
```

**Time Complexity:** O(√n)

---

# 🔹 **Perfect Squares (First 20)**

```
1, 4, 9, 16, 25, 36, 49, 64, 81, 100,
121, 144, 169, 196, 225, 256, 289, 324, 361, 400
```

| Number | Square Root |
| ------ | ----------- |
| 1      | 1           |
| 4      | 2           |
| 9      | 3           |
| 16     | 4           |
| 25     | 5           |
| 64     | 8           |
| 100    | 10          |
| 144    | 12          |

---

# 🔹 **Special Cases**

| Input            | Result            |
| ---------------- | ----------------- |
| `0`              | **true** (0 = 0²) |
| `1`              | **true** (1 = 1²) |
| Negative numbers | **false**         |
| `64`             | **true** (8²)     |
| `50`             | **false**         |

---

# 🔹 **Full Example Workflow**

For number `n = 144`:

```
Method 1 (Square Root):
Step 1: sqrtN = sqrt(144) = 12
Step 2: 12 × 12 = 144
Step 3: 144 == 144 → Perfect Square ✓
```

For number `n = 50`:

```
Method 1 (Square Root):
Step 1: sqrtN = sqrt(50) ≈ 7.07 → integer part = 7
Step 2: 7 × 7 = 49
Step 3: 49 != 50 → Not Perfect Square ✗
```

---

# 🔹 **Properties of Perfect Squares**

1. **Last Digit Pattern:**

   - Perfect squares can only end in: 0, 1, 4, 5, 6, 9
   - Cannot end in: 2, 3, 7, 8

2. **Sum of Odd Numbers:**

   - n² = 1 + 3 + 5 + ... + (2n-1)
   - Example: 4² = 1 + 3 + 5 + 7 = 16

3. **Difference Pattern:**
   - Difference between consecutive squares increases by 2
   - 1, 4, 9, 16, 25... (differences: 3, 5, 7, 9...)

---

# 🔹 **Quick Check Using Last Digit**

```cpp
bool canBePerfectSquare(int n) {
    int lastDigit = n % 10;
    // Perfect squares can only end in 0,1,4,5,6,9
    return (lastDigit == 0 || lastDigit == 1 || lastDigit == 4 ||
            lastDigit == 5 || lastDigit == 6 || lastDigit == 9);
}
```

This is a quick filter but not a complete check.

---

# 🔹 **Applications**

- Geometry problems (area calculations)
- Pythagorean triplets
- Number theory
- Optimization problems
- Checking if a number can form a square grid

---

# 🔹 **Related Problems**

**Find Square Root:**

```cpp
int findSquareRoot(int n) {
    return (int)sqrt(n);
}
```

**Check Perfect Cube:**

```cpp
bool isPerfectCube(int n) {
    int cubeRoot = round(cbrt(n));
    return (cubeRoot * cubeRoot * cubeRoot == n);
}
```

---

# 🔹 **Time Complexity**

| Method             | Time         | Space    |
| ------------------ | ------------ | -------- |
| Square Root (sqrt) | **O(1)**     | **O(1)** |
| Binary Search      | **O(log n)** | **O(1)** |
| Linear Search      | **O(√n)**    | **O(1)** |

---

# 🔹 **Summary**

- Perfect square is a number that equals some integer squared
- Use sqrt() function for O(1) solution
- Binary search provides O(log n) alternative
- Perfect squares can only end in 0, 1, 4, 5, 6, 9
- Common in geometry and number theory problems

---
