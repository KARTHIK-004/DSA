# 📘 **NOTES — Pattern 7: Star Pyramid (Centered)**

Print a centered pyramid of stars.

---

## 🔹 **Pattern Structure**

```
    *
   ***
  *****
 *******
*********
```

For N = 5:
- Row 1: 4 spaces + 1 star
- Row 2: 3 spaces + 3 stars
- Row 3: 2 spaces + 5 stars
- Row 4: 1 space + 7 stars
- Row 5: 0 spaces + 9 stars

Centered pyramid with odd number of stars!

---

## 🔹 **Approach**

### Idea

- Each row has two parts: spaces (for centering) + stars
- Spaces decrease from (N-1) to 0
- Stars increase following odd sequence: 1, 3, 5, 7, 9...
- Formula for stars: 2*i + 1

### Algorithm

1. Outer loop: Iterate through rows (i from 0 to N-1)
2. First inner loop: Print (N - i - 1) spaces
3. Second inner loop: Print (2*i + 1) stars
4. Move to next line

### Code

```cpp
void pattern7(int N)
{
    // Loop for rows
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
}
```

---

## 🔹 **Workflow Example (N = 5)**

```
Row 1 (i=0):
  - Spaces: N - i - 1 = 5 - 0 - 1 = 4
  - Stars: 2*i + 1 = 2*0 + 1 = 1
  - Output: "    *"

Row 2 (i=1):
  - Spaces: N - i - 1 = 5 - 1 - 1 = 3
  - Stars: 2*i + 1 = 2*1 + 1 = 3
  - Output: "   ***"

Row 3 (i=2):
  - Spaces: 2, Stars: 5
  - Output: "  *****"

Row 4 (i=3):
  - Spaces: 1, Stars: 7
  - Output: " *******"

Row 5 (i=4):
  - Spaces: 0, Stars: 9
  - Output: "*********"
```

---

## 🔹 **Key Formulas**

**Spaces in row i:** `N - i - 1`

**Stars in row i:** `2*i + 1` (odd numbers)

```
Row 0: (N-1) spaces, 1 star
Row 1: (N-2) spaces, 3 stars
Row 2: (N-3) spaces, 5 stars
...
Row N-1: 0 spaces, (2N-1) stars
```

---

## 🔹 **Dry Run (N = 4)**

```
i=0: 3 spaces + 1 star  → "   *"
i=1: 2 spaces + 3 stars → "  ***"
i=2: 1 space  + 5 stars → " *****"
i=3: 0 spaces + 7 stars → "*******"

Output:
   *
  ***
 *****
*******
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
    for (int j = 0; j < N - i - 1; j++) cout << " ";
    for (int j = 0; j < 2 * i + 1; j++) cout << "* ";
    cout << endl;
}

// Output for N=3:
//   * 
//  * * * 
// * * * * * 
```

### Variation 2: Number Pyramid
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i - 1; j++) cout << " ";
    for (int j = 0; j < 2 * i + 1; j++) cout << j + 1;
    cout << endl;
}

// Output for N=3:
//   1
//  123
// 12345
```

### Variation 3: Hollow Pyramid
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i - 1; j++) cout << " ";
    for (int j = 0; j < 2 * i + 1; j++) {
        if (j == 0 || j == 2*i || i == N-1)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;
}

// Output for N=4:
//    *
//   * *
//  *   *
// *******
```

---

## 🔹 **Time & Space Complexity**

**Time Complexity:** O(N²)
- Outer loop: N iterations
- Inner loops: (N-i-1) + (2i+1) = N operations per row
- Total: O(N²)

**Space Complexity:** O(1)
- Only loop variables

**Auxiliary Space:** O(1)

---

## 🔹 **Mathematical Analysis**

Total characters (spaces + stars):
```
Each row: (N-i-1) + (2i+1) = N
Total rows: N
Total characters: N × N = N²

Total stars only:
1 + 3 + 5 + ... + (2N-1) = N²

For N=5: 1+3+5+7+9 = 25 stars
```

---

## 🔹 **Common Mistakes**

### Mistake 1: Wrong Space Formula
```cpp
// ❌ WRONG - Too many or too few spaces
for (int j = 0; j < N - i; j++)

// ✅ CORRECT
for (int j = 0; j < N - i - 1; j++)
```

### Mistake 2: Wrong Star Formula
```cpp
// ❌ WRONG - Even numbers
for (int j = 0; j < 2 * i; j++)

// ✅ CORRECT - Odd numbers
for (int j = 0; j < 2 * i + 1; j++)
```

### Mistake 3: Printing Space with Star
```cpp
// ❌ WRONG - Extra space after each star
cout << "* ";

// ✅ CORRECT - No space (for solid pyramid)
cout << "*";
```

---

## 🔹 **Understanding the Odd Sequence**

```
2*i + 1 generates odd numbers:
i=0: 2*0 + 1 = 1
i=1: 2*1 + 1 = 3
i=2: 2*2 + 1 = 5
i=3: 2*3 + 1 = 7
i=4: 2*4 + 1 = 9

This creates symmetric pyramid!
```

---

## 🔹 **Why This Formula Works**

```
For centering:
- Total width = 2N - 1 (last row)
- Row i has (2i+1) stars
- Spaces needed = (2N-1) - (2i+1) / 2
                = (2N - 2i - 2) / 2
                = N - i - 1
```

---

## 🔹 **Step-by-Step Construction**

For Row i:
1. **Calculate spaces:** N - i - 1
2. **Print spaces** (for centering)
3. **Calculate stars:** 2*i + 1
4. **Print stars**
5. **New line**

---

## 🔹 **Visual Breakdown**

```
N=5, Total width = 9

Row 0: [    *    ] ← 4 spaces, 1 star, 4 spaces
Row 1: [   ***   ] ← 3 spaces, 3 stars, 3 spaces
Row 2: [  *****  ] ← 2 spaces, 5 stars, 2 spaces
Row 3: [ ******* ] ← 1 space, 7 stars, 1 space
Row 4: [*********] ← 0 spaces, 9 stars, 0 spaces
```

---

## 🔹 **Alternative Implementation**

Using 1-based indexing:
```cpp
for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << " ";
    for (int j = 1; j <= 2*i - 1; j++) cout << "*";
    cout << endl;
}
```

---

## 🔹 **Practice Tips**

1. Understand the 2*i + 1 formula for odd numbers
2. Verify space calculation for centering
3. Draw the pattern on paper first
4. Test with small N (like 3)
5. Compare with Pattern 8 (inverted)
6. Try hollow variation

---

## 🔹 **Related Patterns**

1. **Pattern 8:** Inverted star pyramid
2. **Pattern 9:** Star diamond (7 + 8)
3. **Number Pyramid:** Pattern 11
4. **Hollow Pyramid:** Only borders

---

## 🔹 **Summary**

- **Pattern Type:** Centered star pyramid
- **Key Formulas:** Spaces = N-i-1, Stars = 2i+1
- **Critical Concept:** Odd sequence for symmetry
- **Complexity:** O(N²) time, O(1) space
- **Difficulty:** Medium
- **Key Learning:** Centering with spaces and odd number sequences

---

