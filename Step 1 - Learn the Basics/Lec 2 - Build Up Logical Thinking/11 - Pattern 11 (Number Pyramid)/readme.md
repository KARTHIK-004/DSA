# 📘 **NOTES — Pattern 11: Number Pyramid (Centered)**

Print a centered pyramid with palindrome numbers (ascending then descending).

---

## 🔹 **Pattern Structure**

```
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 
```

For N = 5:
- Row 1: 4 spaces + [1]
- Row 2: 3 spaces + [1 2 1]
- Row 3: 2 spaces + [1 2 3 2 1]
- Row 4: 1 space + [1 2 3 4 3 2 1]
- Row 5: 0 spaces + [1 2 3 4 5 4 3 2 1]

---

## 🔹 **Approach**

### Idea

- Each row has three parts:
  1. Leading spaces for centering
  2. Ascending numbers (1 to i)
  3. Descending numbers (i-1 to 1)
- Creates a symmetric palindrome pattern

### Algorithm

1. Outer loop: Iterate through rows (i from 1 to N)
2. First inner loop: Print (N - i) spaces
3. Second inner loop: Print ascending numbers (1 to i)
4. Third inner loop: Print descending numbers (i-1 to 1)
5. Move to next line

### Code

```cpp
void pattern11(int N) {
    for (int i = 1; i <= N; i++) {
        // Leading spaces
        for (int j = 1; j <= N - i; j++) {
            cout << "  ";
        }
        // Ascending numbers
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        // Descending numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5, Row 3)**

```
Row 3 (i=3):

Step 1: Print spaces
  - Spaces needed: N - i = 5 - 3 = 2
  - Print: "    " (2 double spaces)

Step 2: Print ascending numbers
  - j goes from 1 to 3
  - Print: "1 2 3 "

Step 3: Print descending numbers
  - j goes from 2 down to 1 (i-1 to 1)
  - Print: "2 1 "

Final output: "    1 2 3 2 1 "
```

---

## 🔹 **Pattern Breakdown**

```
Row 1: (N-1) spaces + [1] + []
       4 spaces + "1"
       
Row 2: (N-2) spaces + [1 2] + [1]
       3 spaces + "1 2" + "1"
       
Row 3: (N-3) spaces + [1 2 3] + [2 1]
       2 spaces + "1 2 3" + "2 1"
       
Row 4: (N-4) spaces + [1 2 3 4] + [3 2 1]
       1 space + "1 2 3 4" + "3 2 1"
       
Row 5: (N-5) spaces + [1 2 3 4 5] + [4 3 2 1]
       0 spaces + "1 2 3 4 5" + "4 3 2 1"
```

---

## 🔹 **Key Formulas**

**Spaces per row:** `N - i`

**Ascending numbers:** 1 to i (i numbers)

**Descending numbers:** (i-1) to 1 (i-1 numbers)

**Total numbers per row:** i + (i-1) = 2i - 1

**Total elements per row (including spaces):** (N-i) + (2i-1) = N + i - 1

---

## 🔹 **Dry Run (N = 4)**

```
i=1: 3 spaces + [1] + []           → "      1"
i=2: 2 spaces + [1 2] + [1]        → "    1 2 1"
i=3: 1 space  + [1 2 3] + [2 1]    → "  1 2 3 2 1"
i=4: 0 spaces + [1 2 3 4] + [3 2 1] → "1 2 3 4 3 2 1"

Output:
      1 
    1 2 1 
  1 2 3 2 1 
1 2 3 4 3 2 1 
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
1 2 1 
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Star Pyramid
```cpp
// Replace numbers with stars
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= 2*i - 1; j++) cout << "* ";
    cout << endl;
}
```

### Variation 2: Alphabet Pyramid
```cpp
// Use letters instead of numbers
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << "  ";
    for (int j = 1; j <= i; j++) cout << (char)('A' + j - 1) << " ";
    for (int j = i - 1; j >= 1; j--) cout << (char)('A' + j - 1) << " ";
    cout << endl;
}
```

### Variation 3: Continuous Numbers
```cpp
// Don't reset to 1 each row
int num = 1;
for (int i = 1; i <= N; i++) {
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
- Outer loop: N iterations
- Inner loops combined: (N-i) + i + (i-1) = N + 2i - 1 operations per row
- Total: Sum of (N + 2i - 1) for i=1 to N ≈ O(N²)

**Space Complexity:** O(1)
- Only loop variables used
- No extra data structures

---

## 🔹 **Mathematical Analysis**

Total numbers printed:
```
Row 1: 1 number
Row 2: 3 numbers
Row 3: 5 numbers
...
Row N: (2N-1) numbers

Total = 1 + 3 + 5 + ... + (2N-1)
      = N²

For N=5: 1+3+5+7+9 = 25 numbers
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Wrong Space Count
```cpp
// ❌ WRONG
for (int j = 1; j < N - i; j++)  // One space short

// ✅ CORRECT
for (int j = 1; j <= N - i; j++)
```

### Mistake 2: Descending Loop Error
```cpp
// ❌ WRONG - Starts from i
for (int j = i; j >= 1; j--)  // Prints center number twice

// ✅ CORRECT - Starts from i-1
for (int j = i - 1; j >= 1; j--)
```

### Mistake 3: Single Space Instead of Double
```cpp
// ❌ WRONG - Alignment issues
cout << " ";

// ✅ CORRECT - Proper alignment
cout << "  ";  // Two spaces for each position
```

---

## 🔹 **Understanding Symmetry**

The pattern is symmetric around the center:
```
    1 2 3 2 1
    ↑   ↑   ↑
    |   |   |
    |   |   Mirror of left side
    |   Center (peak)
    Ascending part
```

**Ascending:** 1, 2, 3
**Center:** 3 (printed once)
**Descending:** 2, 1 (mirror of ascending, excluding center)

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Calculate spaces:** N - i
2. **Print spaces:** Loop (N-i) times
3. **Print ascending:** 1, 2, 3, ..., i
4. **Print descending:** (i-1), (i-2), ..., 1
5. **New line**

---

## 🔹 **Practice Tips**

1. Draw the pattern on paper first
2. Count spaces and numbers for each row
3. Verify the palindrome property
4. Test with small N (like 3)
5. Check alignment carefully
6. Understand why descending starts from i-1

---

## 🔹 **Summary**

- **Pattern Type:** Centered pyramid with palindrome numbers
- **Key Components:** Spaces + ascending + descending
- **Symmetry:** Palindrome (reads same forwards and backwards)
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Medium
- **Key Concept:** Three-part row construction with symmetry

---

