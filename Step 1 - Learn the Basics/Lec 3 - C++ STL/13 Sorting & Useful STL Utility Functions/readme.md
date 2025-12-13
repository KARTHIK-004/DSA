# 📘 **NOTES — 13 Sorting & Useful STL Utility Functions**

In C++, sorting and utility functions from `<algorithm>` give powerful tools for competitive programming and interviews.

Include:

```cpp
#include <algorithm>
```

---

# ⭐ 1️⃣ **Basic Sort**

Sorts in **ascending order (default)**.

### Array:

```cpp
sort(a, a + n);
```

### Vector:

```cpp
sort(v.begin(), v.end());
```

### Partial sort (sort only a range):

```cpp
sort(a + 2, a + 4);
```

---

# ⭐ 2️⃣ **Sort in Descending Order**

Using built-in comparator:

```cpp
sort(a, a + n, greater<int>());
```

Works for vectors too:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

---

# ⭐ 3️⃣ **Custom Comparator for Sorting Pairs**

Useful when sorting by multiple conditions.

### Example:

Sort by:

- **second element ascending**
- if second is equal → **first element descending**

```cpp
bool comp(pair<int,int> p1, pair<int,int> p2) {

    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    // second elements same → sort first in descending
    if (p1.first > p2.first) return true;

    return false;
}
```

### Using it:

```cpp
pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};

sort(a, a + 3, comp);
```

After sorting:

```
{2,1}, {4,1}, {1,2}
```

---

# ⭐ 4️⃣ **\_\_builtin_popcount / popcountll**

Counts **number of 1-bits** in the binary form of a number.

### For int:

```cpp
int num = 7;
int cnt = __builtin_popcount(num);
// 7 → 111 → 3 bits set
```

### For long long:

```cpp
long long num = 165786578687;
int cnt = __builtin_popcountll(num);
```

Extremely useful in bit manipulation problems.

---

# ⭐ 5️⃣ **next_permutation()**

Generates next lexicographical permutation.

### Example:

```cpp
string s = "123";

do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));
```

Output:

```
123
132
213
231
312
321
```

Notes:

- It modifies the string/vector directly.
- Returns `false` when the next permutation does NOT exist.

---

# ⭐ 6️⃣ **max_element() / min_element()**

Gives iterator to the max/min element.

### Array:

```cpp
int maxi = *max_element(a, a + n);
int mini = *min_element(a, a + n);
```

### Vector:

```cpp
int maxi = *max_element(v.begin(), v.end());
```

---

# ⭐ 7️⃣ **Important sort variations**

| Task                   | Code                                        |
| ---------------------- | ------------------------------------------- |
| Sort whole array       | `sort(a, a+n);`                             |
| Sort subarray          | `sort(a+L, a+R+1);`                         |
| Sort vector            | `sort(v.begin(), v.end());`                 |
| Reverse sort           | `sort(a, a+n, greater<int>());`             |
| Sort vector descending | `sort(v.begin(), v.end(), greater<int>());` |
| Custom pair sorting    | `sort(a, a+n, comp);`                       |
| Check if sorted        | `is_sorted(v.begin(), v.end());`            |

---

# ⭐ 8️⃣ **Why custom comparator is needed?**

Used for sorting by:

✔ Multiple conditions
✔ Sorting complex structures (pairs, structs)
✔ Sorting by custom rules (e.g., second element first, then first descending)

---

# ⭐ 9️⃣ **Time Complexity of sort()**

C++ uses **IntroSort** (hybrid of quicksort + heapsort + mergesort).

Time Complexity:

| Case    | Complexity     |
| ------- | -------------- |
| Best    | O(n)           |
| Average | **O(n log n)** |
| Worst   | O(n log n)     |

---

# ⭐ 🔟 **Summary**

- `sort()` is extremely powerful → default = ascending
- `greater<int>()` makes descending sort
- Custom comparator allows multi-condition sorting
- `__builtin_popcount()` counts bits → great for bit problems
- `next_permutation()` generates ordered permutations
- `max_element()` returns largest value in range
- Essential for competitive programming and interviews

---
