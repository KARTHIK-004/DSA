# 📘 **NOTES — Pattern 9: Star Diamond**

Print a diamond shape by combining Pattern 7 (pyramid) and Pattern 8 (inverted pyramid).

---

## 🔹 **Pattern Structure**

```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

For N = 5:
- Total rows: 2N - 1 = 9
- Upper half: Rows 1-5 (expanding pyramid)
- Lower half: Rows 6-9 (contracting inverted pyramid)

Complete diamond shape!

---

## 🔹 **Approach**

### Idea

- Diamond = Pattern 7 (upper) + Pattern 8 (lower, excluding first row)
- Upper half: Spaces decrease, stars increase
- Lower half: Spaces increase, stars decrease
- Avoid duplicating the middle row

### Algorithm

1. **Upper half:** Loop i from 0 to N-1
   - Print (N-i-1) spaces
   - Print (2i+1) stars
   
2. **Lower half:** Loop i from 0 to N-2
   - Print (i+1) spaces
   - Print 2*(N-i-1) - 1 stars

### Code

```cpp
void pattern9(int N)
{
    // Upper half (pyramid)
    for (int i = 0; i < N; i++)
    {
        // Print leading spaces
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half (inverted pyramid)
    for (int i = 0; i < N - 1; i++)
    {
        // Print leading spaces
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < 2 * (N - i - 1) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
```

---

## 🔹 **Workflow Example (N = 5)**

### Upper Half (i = 0 to 4)

```
Row 1 (i=0): 4 spaces + 1 star  → "    *"
Row 2 (i=1): 3 spaces + 3 stars → "   ***"
Row 3 (i=2): 2 spaces + 5 stars → "  *****"
Row 4 (i=3): 1 space  + 7 stars → " *******"
Row 5 (i=4): 0 spaces + 9 stars → "*********" ← Middle (widest)
```

### Lower Half (i = 0 to 3)

```
Row 6 (i=0): 1 space  + 7 stars → " *******"
Row 7 (i=1): 2 spaces + 5 stars → "  *****"
Row 8 (i=2): 3 spaces + 3 stars → "   ***"
Row 9 (i=3): 4 spaces + 1 star  → "    *"
```

---

## 🔹 **Key Formulas**

**Total rows:** `2N - 1`

**Upper half (i = 0 to N-1):**
- Spaces: `N - i - 1`
- Stars: `2*i + 1`

**Lower half (i = 0 to N-2):**
- Spaces: `i + 1`
- Stars: `2*(N - i - 1) - 1`

**Middle row:** Row N with (2N-1) stars

---

## 🔹 **Dry Run (N = 3)**

```
Upper half:
i=0: 2 spaces + 1 star → "  *"
i=1: 1 space  + 3 stars → " ***"
i=2: 0 spaces + 5 stars → "*****"

Lower half:
i=0: 1 space  + 3 stars → " ***"
i=1: 2 spaces + 1 star → "  *"

Output:
  *
 ***
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
 *
***
 *
```

### N = 0
```
(empty output)
```

---

## 🔹 **Variations**

### Variation 1: Hollow Diamond
```cpp
// Upper half
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-i-1; j++) cout << " ";
    for (int j = 0; j < 2*i+1; j++) {
        if (j == 0 || j == 2*i) cout << "*";
        else cout << " ";
    }
    cout << endl;
}
// Similar for lower half
```

### Variation 2: Number Diamond
```cpp
// Replace stars with numbers
for (int j = 0; j < 2*i+1; j++) {
    cout << j + 1;
}
```

### Variation 3: Alphabet Diamond
```cpp
// Use letters
for (int j = 0; j < 2*i+1; j++) {
    cout << (char)('A' + j);
}
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Upper half: N rows
- Lower half: N-1 rows
- Total rows: 2N-1
- Operations per row: O(N)
- Total: O(N²)

**Space Complexity:** O(1)
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total stars:
```
Upper: 1 + 3 + 5 + ... + (2N-1) = N²
Lower: (2N-3) + (2N-5) + ... + 1 = (N-1)²

Total: N² + (N-1)² = 2N² - 2N + 1

For N=5: 25 + 16 = 41 stars
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Including Middle Row Twice
```cpp
// ❌ WRONG - Middle row appears twice
for (int i = 0; i < N; i++) { ... }      // Upper
for (int i = 0; i < N; i++) { ... }      // Lower (starts from N!)

// ✅ CORRECT - Start lower from N-1
for (int i = 0; i < N; i++) { ... }      // Upper
for (int i = 0; i < N - 1; i++) { ... }  // Lower
```

### Mistake 2: Wrong Lower Half Formula
```cpp
// ❌ WRONG - Doesn't mirror upper half
for (int j = 0; j < 2*i + 1; j++)

// ✅ CORRECT - Mirrors upper half
for (int j = 0; j < 2*(N-i-1) - 1; j++)
```

### Mistake 3: Wrong Space Count in Lower
```cpp
// ❌ WRONG
for (int j = 0; j < i; j++)

// ✅ CORRECT
for (int j = 0; j < i + 1; j++)
```

---

## 🔹 **Understanding the Structure**

```
Diamond = Upper Pyramid + Lower Inverted Pyramid

Upper (Pattern 7):
    *         ← 1 star
   ***        ← 3 stars
  *****       ← 5 stars
 *******      ← 7 stars
*********     ← 9 stars (middle, appears once)

Lower (Pattern 8, excluding first row):
 *******      ← 7 stars
  *****       ← 5 stars
   ***        ← 3 stars
    *         ← 1 star
```

---

## 🔹 **Alternative Implementation**

Single loop with conditional:
```cpp
void pattern9(int N) {
    for (int i = 0; i < 2*N - 1; i++) {
        int stars = (i < N) ? (2*i + 1) : (2*(2*N - i - 2) + 1);
        int spaces = (i < N) ? (N - i - 1) : i - N + 1;
        
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 0; j < stars; j++) cout << "*";
        cout << endl;
    }
}
```

---

## 🔹 **Step-by-Step Construction**

### Upper Half (i = 0 to N-1):
1. Calculate spaces: N - i - 1
2. Print spaces
3. Calculate stars: 2*i + 1
4. Print stars
5. New line

### Lower Half (i = 0 to N-2):
1. Calculate spaces: i + 1
2. Print spaces
3. Calculate stars: 2*(N-i-1) - 1
4. Print stars
5. New line

---

## 🔹 **Visual Symmetry**

```
Row 1:     *      ← Mirror of Row 9
Row 2:    ***     ← Mirror of Row 8
Row 3:   *****    ← Mirror of Row 7
Row 4:  *******   ← Mirror of Row 6
Row 5: ********* ← Middle (widest)
Row 6:  *******   ← Mirror of Row 4
Row 7:   *****    ← Mirror of Row 3
Row 8:    ***     ← Mirror of Row 2
Row 9:     *      ← Mirror of Row 1
```

---

## 🔹 **Practice Tips**

1. Understand it's Pattern 7 + Pattern 8
2. Verify middle row appears only once
3. Check symmetry between upper and lower
4. Draw on paper first
5. Test with small N (like 3)
6. Try hollow variation

---

## 🔹 **Related Patterns**

1. **Pattern 7:** Upper half (pyramid)
2. **Pattern 8:** Lower half (inverted)
3. **Pattern 14:** Number diamond
4. **Hollow Diamond:** Only borders

---

## 🔹 **Summary**

- **Pattern Type:** Star diamond
- **Structure:** Pattern 7 + Pattern 8 (excluding middle duplicate)
- **Total Rows:** 2N - 1
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Medium
- **Key Learning:** Combining patterns and avoiding duplication

---

