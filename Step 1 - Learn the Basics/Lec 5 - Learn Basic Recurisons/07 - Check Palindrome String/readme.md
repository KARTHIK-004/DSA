# 📘 **NOTES — 07 Check Palindrome String**

Check if a string is a palindrome using recursion.

We want to:
👉 **Determine if a string reads the same forwards and backwards using recursion**

Example:
`"racecar"` → Palindrome ✓
`"hello"` → Not Palindrome ✗

---

# 🔹 **Understanding Palindrome**

A **palindrome** is a string that reads the same forwards and backwards.

**Examples:**
- Single character: `"a"` ✓
- Even length: `"abba"`, `"noon"` ✓
- Odd length: `"racecar"`, `"madam"` ✓
- Not palindrome: `"hello"`, `"world"` ✗

---

# 🔹 **Method 1 — Two Pointer Recursive Approach ⭐**

### Idea

- Compare characters at start and end positions
- If they don't match → not a palindrome
- If they match → recursively check remaining substring
- Base case: when start >= end (all characters matched)

### Recursion Tree

```
isPalindrome("racecar", 0, 6)
├── 'r' == 'r' ✓
└── isPalindrome("racecar", 1, 5)
    ├── 'a' == 'a' ✓
    └── isPalindrome("racecar", 2, 4)
        ├── 'c' == 'c' ✓
        └── isPalindrome("racecar", 3, 3)
            └── Base case (start >= end) → true
```

### Code

```cpp
bool isPalindrome(string str, int start, int end) {
    // Base case: if start >= end, string is palindrome
    if (start >= end)
        return true;
    
    // If characters don't match, not a palindrome
    if (str[start] != str[end])
        return false;
    
    // Recursive call with updated indices
    return isPalindrome(str, start + 1, end - 1);
}

// Call: isPalindrome(str, 0, str.length() - 1)
```

### Workflow for "madam"

```
Step 1: isPalindrome("madam", 0, 4)
        'm' == 'm' ✓ → Continue
        Call isPalindrome("madam", 1, 3)

Step 2: isPalindrome("madam", 1, 3)
        'a' == 'a' ✓ → Continue
        Call isPalindrome("madam", 2, 2)

Step 3: isPalindrome("madam", 2, 2)
        start == end → Base case → Return true

Result: true (Palindrome)
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - recursion stack

---

# 🔹 **Method 2 — Single Pointer Recursive**

```cpp
bool isPalindrome(string str, int i) {
    int n = str.length();
    
    // Base case: reached middle
    if (i >= n / 2)
        return true;
    
    // Check if characters match
    if (str[i] != str[n - i - 1])
        return false;
    
    // Recursive call
    return isPalindrome(str, i + 1);
}

// Call: isPalindrome(str, 0)
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

# 🔹 **Method 3 — Iterative Two Pointer**

```cpp
bool isPalindromeIterative(string str) {
    int start = 0, end = str.length() - 1;
    
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    
    return true;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

# 🔹 **Method 4 — Reverse and Compare**

```cpp
bool isPalindromeReverse(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - for reversed string

---

# 🔹 **Stack Visualization**

```
For str = "noon":

Stack builds:
isPalindrome("noon", 0, 3) → 'n' == 'n' ✓
isPalindrome("noon", 1, 2) → 'o' == 'o' ✓
isPalindrome("noon", 2, 1) → Base case (start > end) → true

Stack unwinds:
isPalindrome("noon", 1, 2) → Returns true
isPalindrome("noon", 0, 3) → Returns true

Result: true
```

---

# 🔹 **Base Case and Recursive Case**

| Component       | Description                           |
| --------------- | ------------------------------------- |
| **Base Case**   | `if (start >= end) return true;`      |
| **Check**       | `if (str[start] != str[end]) return false;` |
| **Recursive Case** | `return isPalindrome(str, start+1, end-1);` |
| **Return Type** | boolean                               |

---

# 🔹 **Examples**

| String         | Palindrome? | Explanation                   |
| -------------- | ----------- | ----------------------------- |
| `"racecar"`    | ✓ Yes       | Reads same both ways          |
| `"madam"`      | ✓ Yes       | Reads same both ways          |
| `"noon"`       | ✓ Yes       | Even length palindrome        |
| `"a"`          | ✓ Yes       | Single character              |
| `"ab"`         | ✗ No        | Different characters          |
| `"hello"`      | ✗ No        | Not symmetric                 |
| `""`           | ✓ Yes       | Empty string (by convention)  |

---

# 🔹 **Case Sensitivity**

The basic implementation is **case-sensitive**:

```cpp
isPalindrome("Racecar") → false ('R' != 'r')
```

To make it case-insensitive:

```cpp
bool isPalindromeCaseInsensitive(string str, int start, int end) {
    if (start >= end)
        return true;
    
    // Convert to lowercase for comparison
    if (tolower(str[start]) != tolower(str[end]))
        return false;
    
    return isPalindromeCaseInsensitive(str, start + 1, end - 1);
}
```

---

# 🔹 **Ignoring Spaces and Special Characters**

For real-world palindrome checking:

```cpp
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool isPalindromeAdvanced(string str, int start, int end) {
    if (start >= end)
        return true;
    
    // Skip non-alphanumeric characters
    if (!isAlphanumeric(str[start]))
        return isPalindromeAdvanced(str, start + 1, end);
    if (!isAlphanumeric(str[end]))
        return isPalindromeAdvanced(str, start, end - 1);
    
    // Compare (case-insensitive)
    if (tolower(str[start]) != tolower(str[end]))
        return false;
    
    return isPalindromeAdvanced(str, start + 1, end - 1);
}

// "A man, a plan, a canal: Panama" → true
```

---

# 🔹 **Special Cases**

| Input              | Output                                |
| ------------------ | ------------------------------------- |
| Empty string       | true (by convention)                  |
| Single character   | true                                  |
| Two same chars     | true ("aa")                           |
| Two diff chars     | false ("ab")                          |
| Spaces             | Depends on implementation             |

---

# 🔹 **Time & Space Complexity**

| Method              | Time           | Space      |
| ------------------- | -------------- | ---------- |
| Two Pointer Recursive | **O(n)**     | **O(n/2)** |
| Single Pointer Recursive | **O(n)**  | **O(n/2)** |
| Iterative           | **O(n)**       | **O(1)**   |
| Reverse & Compare   | **O(n)**       | **O(n)**   |

---

# 🔹 **Key Concepts**

1. **Symmetry Check:** Compare characters from both ends
2. **Early Termination:** Return false as soon as mismatch found
3. **Base Case:** When pointers meet, all characters matched
4. **Stack Depth:** Only n/2 recursive calls needed
5. **String Indexing:** Access characters using indices

---

# 🔹 **Related Problems**

- **Palindrome Number:** Check if integer is palindrome
- **Valid Palindrome:** Ignore non-alphanumeric characters
- **Longest Palindromic Substring:** Find longest palindrome in string
- **Palindrome Partitioning:** Split string into palindromic substrings

---

# 🔹 **Summary**

- Check if string reads same forwards and backwards
- Use two pointers from both ends
- Compare characters and move inward
- Base case: when pointers meet or cross
- Recursion depth is n/2
- Can extend to handle case-insensitivity and special characters
- Iterative approach is more space-efficient

---

