# 📘 **NOTES — Pattern 14: Number Diamond**

Print a diamond shape with sequential numbers, combining an upper pyramid and lower inverted pyramid.

---

## 🔹 **Pattern Structure**

```
        1
      1 2 3
    1 2 3 4 5
  1 2 3 4 5 6 7
1 2 3 4 5 6 7 8 9
  1 2 3 4 5 6 7
    1 2 3 4 5
      1 2 3
        1
```

For N = 5:

- Total rows: 2N - 1 = 9 rows
- Upper half: Rows 1 to N (expanding)
- Lower half: Rows N-1 to 1 (contracting)
- Each row is centered with spaces

---

## 🔹 **Approach**

### Idea

- Diamond = Upper pyramid + Lower inverted pyramid
- Upper half: Rows increase from 1 to N
- Lower half: Rows decrease from N-1 to 1
- Each row has leading spaces and sequential numbers

### Algorithm

1. **Upper half:** Loop i from 1 to N
   - Print (N-i) spaces
   - Print numbers 1 to (2i-1)
2. **Lower half:** Loop i from N-1 to 1
   - Print (N-i) spaces
   - Print numbers 1 to (2i-1)

### Code

```cpp
void pattern14(int N) {
    // Upper half
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    // Lower half
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= N - i; j++) {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

### Upper Half (i = 1 to 5)

```
Row 1 (i=1):
  Spaces: N-i = 4 → "        "
  Numbers: 2*1-1 = 1 → "1"
  Output: "        1"

Row 2 (i=2):
  Spaces: N-i = 3 → "      "
  Numbers: 2*2-1 = 3 → "1 2 3"
  Output: "      1 2 3"

Row 3 (i=3):
  Spaces: N-i = 2 → "    "
  Numbers: 2*3-1 = 5 → "1 2 3 4 5"
  Output: "    1 2 3 4 5"

Row 4 (i=4):
  Spaces: N-i = 1 → "  "
  Numbers: 2*4-1 = 7 → "1 2 3 4 5 6 7"
  Output: "  1 2 3 4 5 6 7"

Row 5 (i=5):
  Spaces: N-i = 0 → ""
  Numbers: 2*5-1 = 9 → "1 2 3 4 5 6 7 8 9"
  Output: "1 2 3 4 5 6 7 8 9"
```

### Lower Half (i = 4 to 1)

```
Row 6 (i=4):
  Spaces: N-i = 1 → "  "
  Numbers: 2*4-1 = 7 → "1 2 3 4 5 6 7"
  Output: "  1 2 3 4 5 6 7"

Row 7 (i=3):
  Spaces: N-i = 2 → "    "
  Numbers: 2*3-1 = 5 → "1 2 3 4 5"
  Output: "    1 2 3 4 5"

Row 8 (i=2):
  Spaces: N-i = 3 → "      "
  Numbers: 2*2-1 = 3 → "1 2 3"
  Output: "      1 2 3"

Row 9 (i=1):
  Spaces: N-i = 4 → "        "
  Numbers: 2*1-1 = 1 → "1"
  Output: "        1"
```

---

## 🔹 **Key Formulas**

**Total rows:** `2N - 1`

**For row i in upper half:**

- **Spaces:** `N - i`
- **Numbers:** `2i - 1`

**For row i in lower half:**

- **Spaces:** `N - i`
- **Numbers:** `2i - 1`

**Middle row (widest):** Row N with (2N-1) numbers

---

## 🔹 **Pattern Breakdown**

```
Row  | i value | Spaces | Numbers | Output
-----|---------|--------|---------|------------------
1    | 1       | 4      | 1       | "        1"
2    | 2       | 3      | 3       | "      1 2 3"
3    | 3       | 2      | 5       | "    1 2 3 4 5"
4    | 4       | 1      | 7       | "  1 2 3 4 5 6 7"
5    | 5       | 0      | 9       | "1 2 3 4 5 6 7 8 9" ← Middle
6    | 4       | 1      | 7       | "  1 2 3 4 5 6 7"
7    | 3       | 2      | 5       | "    1 2 3 4 5"
8    | 2       | 3      | 3       | "      1 2 3"
9    | 1       | 4      | 1       | "        1"
```

---

## 🔹 **Dry Run (N = 3)**

```
Upper half (i = 1 to 3):
i=1: 2 spaces + [1]           → "    1"
i=2: 1 space  + [1 2 3]       → "  1 2 3"
i=3: 0 spaces + [1 2 3 4 5]   → "1 2 3 4 5"

Lower half (i = 2 to 1):
i=2: 1 space  + [1 2 3]       → "  1 2 3"
i=1: 2 spaces + [1]           → "    1"

Output:
    1
  1 2 3
1 2 3 4 5
  1 2 3
    1
```

---

## 🔹 **Edge Cases**

### N = 1

```
1
```

### N = 2

```
  1
1 2 3
  1
```

### N = 0

```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Star Diamond

```cpp
// Replace numbers with stars
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) cout << "* ";
    cout << endl;
}
for (int i = N - 1; i >= 1; i--) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) cout << "* ";
    cout << endl;
}
```

### Variation 2: Hollow Diamond

```cpp
// Print only borders
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) {
        if (j == 1 || j == 2*i - 1)
            cout << j << " ";
        else
            cout << "  ";
    }
    cout << endl;
}
// Similar for lower half
```

### Variation 3: Continuous Numbers

```cpp
// Numbers don't reset each row
int num = 1;
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) {
        cout << num++ << " ";
    }
    cout << endl;
}
for (int i = N - 1; i >= 1; i--) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) {
        cout << num++ << " ";
    }
    cout << endl;
}
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)

- Upper half: N rows, each with up to (2N-1) operations
- Lower half: (N-1) rows, each with up to (2N-1) operations
- Total rows: 2N - 1
- Total operations: O(N²)

**Space Complexity:** O(1)

- Only loop variables
- No extra data structures

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total rows: `2N - 1`

Numbers per row (upper half):

```
Row 1: 1 number
Row 2: 3 numbers
Row 3: 5 numbers
...
Row N: (2N-1) numbers
```

Total numbers in upper half:

```
1 + 3 + 5 + ... + (2N-1) = N²
```

Total numbers in lower half:

```
(2N-3) + (2N-5) + ... + 1 = (N-1)²
```

Total numbers in diamond:

```
N² + (N-1)² = 2N² - 2N + 1

For N=5: 25 + 16 = 41 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Including Middle Row Twice

```cpp
// ❌ WRONG - Middle row appears twice
for (int i = 1; i <= N; i++) { ... }
for (int i = N; i >= 1; i--) { ... }  // Starts from N!

// ✅ CORRECT - Start from N-1
for (int i = 1; i <= N; i++) { ... }
for (int i = N - 1; i >= 1; i--) { ... }
```

### Mistake 2: Wrong Space Calculation

```cpp
// ❌ WRONG
for (int j = 1; j < N - i; j++)  // One space short

// ✅ CORRECT
for (int j = 1; j <= N - i; j++)
```

### Mistake 3: Wrong Number Count

```cpp
// ❌ WRONG
for (int j = 1; j <= i; j++)  // Not enough numbers

// ✅ CORRECT
for (int j = 1; j <= 2*i - 1; j++)  // Odd numbers: 1,3,5,7,9
```

---

## 🔹 **Understanding the Structure**

```
Diamond = Upper Pyramid + Lower Inverted Pyramid

Upper (expanding):
        1         ← 1 number
      1 2 3       ← 3 numbers
    1 2 3 4 5     ← 5 numbers

Lower (contracting):
      1 2 3       ← 3 numbers
        1         ← 1 number
```

**Key insight:** Lower half is mirror of upper half (excluding middle row)

---

## 🔹 **Step-by-Step Construction**

### For Upper Half (i = 1 to N):

1. Calculate spaces: N - i
2. Print spaces
3. Calculate numbers: 2i - 1
4. Print numbers 1 to (2i-1)
5. New line

### For Lower Half (i = N-1 to 1):

1. Calculate spaces: N - i
2. Print spaces
3. Calculate numbers: 2i - 1
4. Print numbers 1 to (2i-1)
5. New line

---

## 🔹 **Alternative Implementation**

Using a single loop with conditional logic:

```cpp
void pattern14(int N) {
    for (int i = 1; i <= 2*N - 1; i++) {
        int row = (i <= N) ? i : (2*N - i);

        // Spaces
        for (int j = 1; j <= N - row; j++) {
            cout << "  ";
        }

        // Numbers
        for (int j = 1; j <= 2*row - 1; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
}
```

**Explanation:**

- If i ≤ N: we're in upper half, use i
- If i > N: we're in lower half, use (2N - i) to mirror

---

## 🔹 **Visual Symmetry**

```
Row 1:  ████████1████████  ← 4 spaces each side
Row 2:  ██████1 2 3██████  ← 3 spaces each side
Row 3:  ████1 2 3 4 5████  ← 2 spaces each side
Row 4:  ██1 2 3 4 5 6 7██  ← 1 space each side
Row 5:  1 2 3 4 5 6 7 8 9  ← 0 spaces (widest)
Row 6:  ██1 2 3 4 5 6 7██  ← Mirror of row 4
Row 7:  ████1 2 3 4 5████  ← Mirror of row 3
Row 8:  ██████1 2 3██████  ← Mirror of row 2
Row 9:  ████████1████████  ← Mirror of row 1
```

---

## 🔹 **Practice Tips**

1. Draw the pattern on paper first
2. Identify upper and lower halves
3. Calculate spaces and numbers for each row
4. Verify the formula: 2i - 1 for numbers
5. Test with small N (like 3)
6. Check that middle row appears only once
7. Verify symmetry between upper and lower halves

---

## 🔹 **Related Patterns**

1. **Star Diamond:** Same structure with stars
2. **Hollow Diamond:** Only borders
3. **Inverted Diamond:** Starts wide, ends narrow
4. **Rotated Diamond:** 90-degree rotation

---

## 🔹 **Applications**

- Understanding complex pattern construction
- Combining multiple simple patterns
- Symmetry and mirroring concepts
- Interview questions on pattern printing
- Foundation for more complex 2D patterns

---

## 🔹 **Summary**

- **Pattern Type:** Diamond (upper + lower pyramid)
- **Total Rows:** 2N - 1
- **Key Formula:** Numbers per row = 2i - 1 (odd sequence)
- **Structure:** Two loops (upper and lower halves)
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Medium-Hard
- **Key Concept:** Combining patterns and avoiding duplication of middle row

---
