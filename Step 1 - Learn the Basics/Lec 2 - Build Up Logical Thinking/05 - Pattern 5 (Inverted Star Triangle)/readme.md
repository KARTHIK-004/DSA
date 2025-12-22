# 📘 **NOTES — Pattern 5: Inverted Star Triangle**

Print an inverted right triangle where stars decrease from N to 1.

---

## 🔹 **Pattern Structure**

```
* * * * * 
* * * * 
* * * 
* * 
* 
```

For N = 5:
- Row 1: 5 stars
- Row 2: 4 stars
- Row 3: 3 stars
- Row 4: 2 stars
- Row 5: 1 star

Stars decrease by 1 each row!

---

## 🔹 **Approach**

### Idea

- Opposite of Pattern 2 (which increases stars)
- Start with N stars, decrease to 1
- Each row i has (N - i) stars

### Algorithm

1. Outer loop: Iterate through rows (i from 0 to N-1)
2. Inner loop: Print (N - i) stars
3. Move to next line after each row

### Code

```cpp
void pattern5(int N)
{
    // Loop for rows
    for (int i = 0; i < N; i++)
    {
        // Loop for columns (stars decrease each row)
        for (int j = 0; j < N - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Row 1 (i=0):
  - Stars: N - i = 5 - 0 = 5
  - Print: * * * * *

Row 2 (i=1):
  - Stars: N - i = 5 - 1 = 4
  - Print: * * * *

Row 3 (i=2):
  - Stars: N - i = 5 - 2 = 3
  - Print: * * *

Row 4 (i=3):
  - Stars: N - i = 5 - 3 = 2
  - Print: * *

Row 5 (i=4):
  - Stars: N - i = 5 - 4 = 1
  - Print: *
```

---

## 🔹 **Key Formula**

**Stars in row i:** `N - i`

```
Row 0: N - 0 = N stars
Row 1: N - 1 stars
Row 2: N - 2 stars
...
Row N-1: N - (N-1) = 1 star
```

---

## 🔹 **Dry Run (N = 4)**

```
i=0: j runs from 0 to 3 (4 times) → * * * *
i=1: j runs from 0 to 2 (3 times) → * * *
i=2: j runs from 0 to 1 (2 times) → * *
i=3: j runs from 0 to 0 (1 time)  → *

Output:
* * * * 
* * * 
* * 
* 
```

---

## 🔹 **Edge Cases**

### N = 1
```
* 
```

### N = 2
```
* * 
* 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Numbers Instead of Stars
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i; j++) {
        cout << j + 1 << " ";
    }
    cout << endl;
}

// Output for N=4:
// 1 2 3 4
// 1 2 3
// 1 2
// 1
// (This is Pattern 6!)
```

### Variation 2: Start from 1 (Alternative Indexing)
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i + 1; j++) {
        cout << "* ";
    }
    cout << endl;
}

// Same output, different indexing
```

### Variation 3: Right-Aligned Inverted Triangle
```cpp
for (int i = 0; i < N; i++) {
    // Print leading spaces
    for (int j = 0; j < i; j++) {
        cout << "  ";
    }
    // Print stars
    for (int j = 0; j < N - i; j++) {
        cout << "* ";
    }
    cout << endl;
}

// Output for N=4:
// * * * *
//   * * *
//     * *
//       *
```

### Variation 4: Hollow Inverted Triangle
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i; j++) {
        if (i == 0 || j == 0 || j == N - i - 1) {
            cout << "* ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
}

// Output for N=5:
// * * * * *
// *     *
// *   *
// * *
// *
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loop: (N-i) iterations for each row
- Total: N + (N-1) + (N-2) + ... + 1 = N(N+1)/2 = O(N²)

**Space Complexity:** O(1)
- Only loop variables
- No extra data structures

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total stars printed:
```
N + (N-1) + (N-2) + ... + 1 = N(N+1)/2

For N=5: 5+4+3+2+1 = 15 stars
For N=10: 10+9+8+...+1 = 55 stars
```

Same count as Pattern 2, but in reverse order!

---

## 🔹 **Common Mistakes**

### Mistake 1: Wrong Formula
```cpp
// ❌ WRONG - Increases instead of decreases
for (int j = 0; j < i; j++)

// ✅ CORRECT - Decreases
for (int j = 0; j < N - i; j++)
```

### Mistake 2: Off-by-One Error
```cpp
// ❌ WRONG - Skips last row or adds extra
for (int j = 0; j < N - i - 1; j++)

// ✅ CORRECT
for (int j = 0; j < N - i; j++)
```

### Mistake 3: Starting from 1 with Wrong Formula
```cpp
// ❌ WRONG - Doesn't work with i starting from 1
for (int i = 1; i <= N; i++) {
    for (int j = 0; j < N - i; j++)  // Off by one!
}

// ✅ CORRECT - Adjust formula
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i + 1; j++)
}
```

---

## 🔹 **Comparison with Pattern 2**

| Feature | Pattern 2 | Pattern 5 |
|---------|-----------|-----------|
| Direction | Increasing | Decreasing |
| Row 1 | `*` | `* * * * *` |
| Row 2 | `* *` | `* * * *` |
| Row 3 | `* * *` | `* * *` |
| Row 4 | `* * * *` | `* *` |
| Row 5 | `* * * * *` | `*` |
| Formula | i+1 or j≤i | N-i |

---

## 🔹 **Understanding the Formula**

```cpp
for (int i = 0; i < N; i++) {
    // As i increases from 0 to N-1,
    // (N - i) decreases from N to 1
    
    for (int j = 0; j < N - i; j++) {
        // This loop runs (N-i) times
        cout << "* ";
    }
}
```

**Progression:**
- i=0: N-0 = N stars
- i=1: N-1 stars
- i=2: N-2 stars
- ...
- i=N-1: N-(N-1) = 1 star

---

## 🔹 **Alternative Implementations**

### Method 1: Start from N, Decrease
```cpp
for (int i = N; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

### Method 2: Use Subtraction
```cpp
for (int i = 0; i < N; i++) {
    for (int j = N; j > i; j--) {
        cout << "* ";
    }
    cout << endl;
}
```

All three methods produce the same output!

---

## 🔹 **Step-by-Step Construction**

For Row i (starting from 0):
1. **Calculate stars needed:** N - i
2. **Print that many stars**
3. **Move to next line**
4. **Repeat for next row**

---

## 🔹 **Visual Representation**

```
Row 0: * * * * *  ← N stars
Row 1: * * * *    ← N-1 stars
Row 2: * * *      ← N-2 stars
Row 3: * *        ← N-3 stars
Row 4: *          ← N-4 = 1 star

Pattern: Decreasing from N to 1
```

---

## 🔹 **Practice Tips**

1. Understand the N - i formula
2. Compare with Pattern 2 (increasing triangle)
3. Try different starting indices (0 vs 1)
4. Verify the formula for first and last rows
5. Practice with small N (like 3 or 4)
6. Try implementing with different loop styles

---

## 🔹 **Related Patterns**

1. **Pattern 2:** Increasing star triangle (opposite)
2. **Pattern 6:** Inverted number triangle
3. **Right-Aligned Inverted:** With leading spaces
4. **Hollow Inverted:** Only borders

---

## 🔹 **Summary**

- **Pattern Type:** Inverted right triangle
- **Key Feature:** Stars decrease from N to 1
- **Critical Formula:** N - i stars per row
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Easy
- **Key Learning:** Understanding decreasing patterns and N - i formula

---

