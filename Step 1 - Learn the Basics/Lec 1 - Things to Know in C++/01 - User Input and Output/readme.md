# 📘 **01 – User Input and Output (C++ Basics Explained Clearly)**

## 🔹 **Introduction**

When you start learning C++, the first and most important concepts are:

- **How to take input**
- **How to print output**
- **Basic structure of a C++ program**

C++ uses **streams** for I/O:

- `cin` → takes input
- `cout` → prints output

Both come from the **iostream** library.

---

# 🔹 **Including Libraries**

Libraries allow us to use pre-written code.

```cpp
#include <iostream>   // for input/output
#include <math.h>     // for mathematical functions
```

Basic structure of a C++ program:

```cpp
#include <iostream>
int main() {
    // Your code here
    return 0;
}
```

---

# 🔹 **Output with cout**

To print something:

```cpp
#include <iostream>
int main() {
    std::cout << "Hey, World!";
    return 0;
}
```

### **Output**

```
Hey, World!
```

---

# 🔹 **Multiple Prints on the Same Line**

```cpp
std::cout << "Hey, World!";
std::cout << "Hey, World!";
```

### Output:

```
Hey, World!Hey, World!
```

---

# 🔹 **Printing on New Lines**

Use **`\n`** or **`std::endl`**:

```cpp
std::cout << "Hey, World!" << "\n";
std::cout << "Hey, World!";
```

### Output:

```
Hey, World!
Hey, World!
```

### Difference:

- `\n` → just adds a new line (fast)
- `std::endl` → new line + flushes buffer (slower)

---

# 🔹 **Using namespace std**

Without using namespace:

```cpp
std::cout << "Hello";
```

With namespace:

```cpp
using namespace std;
cout << "Hello";
```

✔ Makes code shorter
❌ Not recommended in large projects (naming conflicts)

---

# 🔹 **Taking User Input (cin)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    cout << "Value of x: " << x;
}
```

### Input:

```
10
```

### Output:

```
Value of x: 10
```

---

# 🔹 **Taking Multiple Inputs**

```cpp
int x, y;
cin >> x >> y;
cout << "Value of x: " << x << " and y: " << y;
```

### Input:

```
10 20
```

### Output:

```
Value of x: 10 and y: 20
```

---

# 🔹 **Shortcut: bits/stdc++.h**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
}
```

### ✔ Pros

- Includes almost all standard libraries
- Good for competitive programming

### ❌ Cons

- Slower compile time
- Not recommended in production code

---

# ⭐ Summary

| Concept                | Meaning                           |
| ---------------------- | --------------------------------- |
| `cout`                 | Prints output                     |
| `cin`                  | Takes input                       |
| `\n`                   | New line (fast)                   |
| `std::endl`            | New line + flush                  |
| `using namespace std;` | Removes need for `std::` prefix   |
| `bits/stdc++.h`        | Includes most libraries (CP only) |

---
