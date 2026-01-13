# 📘 **NOTES — Pattern 8: Inverted Star Pyramid (Centered)**

Print a centered inverted pyramid of stars.

---

## 🔹 **Pattern Structure**

```
*********
 *******
  *****
   ***
    *
```

For N = 5:
- Row 1: 0 spaces + 9 stars
- Row 2: 1 space + 7 stars
- Row 3: 2 spaces + 5 stars
- Row 4: 3 spaces + 3 stars
- Row 5: 4 spaces + 1 star

Inverted centered pyramid!

---

## 🔹 **Approach**

### Idea

- Opposite of Pattern 7
- Spaces increase from 0 to (N-1)
- Stars decrease following odd sequence: (2N-1), (2N-3), ..., 1
- Formula for stars: 2*(N-i) - 1

### Algorithm

1. Outer loop: Iterate through rows (i from 0 to N-1)
2. First inner loop: Print i spaces
3. Second inner loop: Print 2*(N-i) - 1 stars
4. Move to next line

### Code

```cpp
void pattern8(int N)
{
    // Loop for rows
    for (int i = 0; i < N; i++)
    {
        // Print leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * (N - i) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Row 1 (i=0):
  - Spaces: i = 0
  - Stars: 2*(N-i) - 1 = 2*5 - 1 = 9
  - Output: "*********"

Row 2 (i=1):
  - Spaces: i = 1
  - Stars: 2*(5-1) - 1 = 7
  - Output: " *******"

Row 3 (i=2):
  - Spaces: 2, Stars: 5
  - Output: "  *****"

Row 4 (i=3):
  - Spaces: 3, Stars: 3
  - Output: "   ***"

Row 5 (i=4):
  - Spaces: 4, Stars: 1
  - Output: "    *"
```

---

## 🔹 **Key Formulas**

**Spaces in row i:** `i`

**Stars in row i:** `2*(N - i) - 1`

```
Row 0: 0 spaces, (2N-1) stars
Row 1: 1 space, (2N-3) stars
Row 2: 2 spaces, (2N-5) stars
...
Row N-1: (N-1) spaces, 1 star
```

---

## 🔹 **Dry Run (N = 4)**

```
i=0: 0 spaces + 7 stars → "*******"
i=1: 1 space  + 5 stars → " *****"
i=2: 2 spaces + 3 stars → "  ***"
i=3: 3 spaces + 1 star  → "   *"

Output:
*******
 *****
  ***
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
***
 *
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: With Spaces Between Stars
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) cout << " ";
    for (int j = 0; j < 2*(N-i) - 1; j++) cout << "* ";
    cout << endl;
}
```

### Variation 2: Hollow Inverted Pyramid
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) cout << " ";
    for (int j = 0; j < 2*(N-i) - 1; j++) {
        if (i == 0 || j == 0 || j == 2*(N-i) - 2)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;
}
```

### Variation 3: Number Inverted Pyramid
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) cout << " ";
    for (int j = 0; j < 2*(N-i) - 1; j++) cout << j + 1;
    cout << endl;
}
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loops: i + (2(N-i)-1) = 2N - i - 1 operations
- Total: O(N²)

**Space Complexity:** O(1)
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total stars:
```
(2N-1) + (2N-3) + ... + 1 = N²

For N=5: 9+7+5+3+1 = 25 stars
```

Same as Pattern 7, but inverted!

---

## 🔹 **Common Mistakes**

### Mistake 1: Wrong Star Formula
```cpp
// ❌ WRONG - Increases instead of decreases
for (int j = 0; j < 2*i + 1; j++)

// ✅ CORRECT - Decreases
for (int j = 0; j < 2*(N-i) - 1; j++)
```

### Mistake 2: Wrong Space Formula
```cpp
// ❌ WRONG - Decreases instead of increases
for (int j = 0; j < N - i - 1; j++)

// ✅ CORRECT - Increases
for (int j = 0; j < i; j++)
```

### Mistake 3: Off-by-One in Stars
```cpp
// ❌ WRONG - Even numbers
for (int j = 0; j < 2*(N-i); j++)

// ✅ CORRECT - Odd numbers
for (int j = 0; j < 2*(N-i) - 1; j++)
```

---

## 🔹 **Comparison with Pattern 7**

| Feature | Pattern 7 | Pattern 8 |
|---------|-----------|-----------|
| Direction | Expanding | Contracting |
| Row 1 | `    *` | `*********` |
| Row 2 | `   ***` | ` *******` |
| Row 3 | `  *****` | `  *****` |
| Row 4 | ` *******` | `   ***` |
| Row 5 | `*********` | `    *` |
| Spaces | N-i-1 | i |
| Stars | 2i+1 | 2(N-i)-1 |

---

## 🔹 **Understanding the Formula**

```cpp
for (int i = 0; i < N; i++) {
    // Spaces increase: 0, 1, 2, ..., N-1
    for (int j = 0; j < i; j++)
    
    // Stars decrease (odd): 2N-1, 2N-3, ..., 1
    for (int j = 0; j < 2*(N-i) - 1; j++)
}
```

**Star progression:**
- i=0: 2(N-0)-1 = 2N-1
- i=1: 2(N-1)-1 = 2N-3
- i=2: 2(N-2)-1 = 2N-5
- ...
- i=N-1: 2(1)-1 = 1

---

## 🔹 **Alternative Implementation**

Using 1-based indexing:
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) cout << " ";
    for (int j = 1; j <= 2*(N-i+1) - 1; j++) cout << "*";
    cout << endl;
}
```

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Calculate spaces:** i
2. **Print spaces**
3. **Calculate stars:** 2*(N-i) - 1
4. **Print stars**
5. **New line**

---

## 🔹 **Visual Breakdown**

```
N=5

Row 0: [*********] ← 0 spaces, 9 stars
Row 1: [ ******* ] ← 1 space, 7 stars
Row 2: [  *****  ] ← 2 spaces, 5 stars
Row 3: [   ***   ] ← 3 spaces, 3 stars
Row 4: [    *    ] ← 4 spaces, 1 star
```

---

## 🔹 **Practice Tips**

1. Compare with Pattern 7 (regular pyramid)
2. Understand 2*(N-i) - 1 formula
3. Verify first and last rows
4. Draw pattern on paper
5. Test with small N
6. Try combining with Pattern 7 for diamond

---

## 🔹 **Related Patterns**

1. **Pattern 7:** Regular star pyramid
2. **Pattern 9:** Star diamond (7 + 8)
3. **Hollow Inverted:** Only borders
4. **Number Inverted:** Numbers instead

---

## 🔹 **Summary**

- **Pattern Type:** Inverted centered pyramid
- **Key Formulas:** Spaces = i, Stars = 2(N-i)-1
- **Critical Concept:** Decreasing odd sequence
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Medium
- **Key Learning:** Inverting pyramid patterns

---

