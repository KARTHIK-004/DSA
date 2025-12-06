# 📘 **02 – Data Types**

# 🧩 **What Are Data Types?**

Data types tell the compiler **what kind of data** a variable will store.

Examples:

- Whole numbers
- Decimal numbers
- Characters
- True/False values
- Very large numbers
- Text (strings)

Choosing the correct data type is important for:

✔ Memory usage
✔ Speed
✔ Preventing overflow
✔ Accuracy

---

# 🧮 **Basic Data Types in C++**

| Data Type   | Size (approx) | Example Value     | Description                  |
| ----------- | ------------- | ----------------- | ---------------------------- |
| `int`       | 4 bytes       | 10, -5, 2000      | Normal integers              |
| `long long` | 8 bytes       | 1e12, 9876543210  | Very large integers          |
| `float`     | 4 bytes       | 3.14, 5.66        | Decimal (single precision)   |
| `double`    | 8 bytes       | 9.876543, 1.23456 | Decimal (double precision)   |
| `char`      | 1 byte        | 'A', 'z', '9'     | Stores a single character    |
| `bool`      | 1 byte        | true / false      | Logical values               |
| `string`    | dynamic       | "Hello World"     | Stores text (multiple chars) |

---

# 🔢 **Integer Types**

### **int**

```cpp
int age = 21;
```

Range: approx **−2 billion to +2 billion**

### **long long**

Used for very large values.

```cpp
long long population = 8000000000;
```

Range: approx **−9e18 to +9e18**

---

# 🔤 **Character Type**

```cpp
char grade = 'A';
```

- Always inside **single quotes**
- Stores exactly **one** character

---

# 🧵 **String (Multiple Characters)**

To store a full name:

```cpp
string name;
getline(cin, name);
```

`getline()` reads the **full line**, including spaces.

---

# 🔢 **Decimal Types**

### **float**

```cpp
float height = 5.8;
```

Precision: ~6 digits

### **double**

```cpp
double weight = 67.45;
```

Precision: ~15 digits
More accurate → recommended in most cases

Formatting decimals:

```cpp
cout << fixed << setprecision(2) << weight;
```

Output:

```
67.45
```

---

# 🔘 **Boolean Type**

```cpp
bool isStudent = true;
```

Input:

```
0 → false
1 → true
```

Output it as readable text:

```cpp
cout << (isStudent ? "true" : "false");
```

---

# 🎯 **Key Takeaways**

- `int` → normal whole numbers
- `long long` → very large numbers
- `char` → single letter
- `string` → text
- `float` vs `double` → double is more accurate
- `bool` → true/false
- `getline()` → reads full string
- Use `setprecision()` to format decimals

---
