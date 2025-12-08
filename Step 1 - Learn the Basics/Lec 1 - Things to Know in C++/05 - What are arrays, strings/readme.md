# 📘 **NOTES — 05 Arrays & Strings**

## 🔹 What are Arrays?

An **array** is a collection of elements of the **same data type**, stored in **continuous memory locations**.

Think of an array like a **row of boxes**, each box holding one value.

Example:
`int marks[5];` → creates 5 integer boxes.

---

## 🔹 Why do we use Arrays?

✔ To store multiple values using **one variable**
✔ Easy to access values using index
✔ Helps in storing lists (marks, prices, names, IDs)
✔ Used in loops, searching, sorting, matrices, etc.

---

## 🔹 Syntax

```cpp
dataType arrayName[size];
```

Example:

```cpp
int numbers[10];
float salary[5];
char letters[26];
```

---

# 🔹 Indexing in Arrays

Array index starts from **0**.

| Position    | Index |
| ----------- | ----- |
| 1st element | 0     |
| 2nd element | 1     |
| 3rd element | 2     |

Example:

```cpp
int a[3] = {10, 20, 30};

cout << a[0];  // 10
cout << a[1];  // 20
cout << a[2];  // 30
```

---

# 🔹 Input and Output of Arrays

```cpp
int marks[5];

for (int i = 0; i < 5; i++) {
    cin >> marks[i];
}
```

To print:

```cpp
for (int i = 0; i < 5; i++) {
    cout << marks[i] << " ";
}
```

---

# 🔹 Types of Arrays

### 1️⃣ One-Dimensional Array

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

### 2️⃣ Two-Dimensional Array (Matrix)

```cpp
int matrix[3][3];
```

Used to represent tables or grids.

---

# 🔹 Common Mistakes in Arrays

❌ Accessing index out of range
Example: `arr[10]` when size is 5 — invalid

❌ Forgetting size

❌ Using different data types in same array

---

---

# 📘 **STRINGS**

## 🔹 What is a String?

A **string** is a sequence of characters enclosed in **double quotes**.

Examples:

```cpp
"Hello"
"Karthik"
"1234"
```

In C++, strings are stored as **arrays of characters** with a `'\0'` (null character) at the end.

---

## 🔹 Declaring Strings

### 1️⃣ Using `char` array (old style)

```cpp
char name[20] = "Karthik";
```

### 2️⃣ Using `string` class (modern C++)

```cpp
string fullName = "Karthik Selvam";
```

👍 Recommended because it is easier and safer.

---

# 🔹 Input for Strings

### Using `cin`

Reads only one word:

```cpp
string name;
cin >> name;  // stops at space
```

### Using `getline()`

Reads full sentence:

```cpp
string fullName;
getline(cin, fullName);
```

---

# 🔹 Common String Operations

```cpp
string s = "Hello";

cout << s.length();    // length of string
cout << s[0];          // access first character
s += " World";         // concatenation
```

---

# 🔹 Strings vs Character Arrays

| Feature            | `string`   | `char[]`    |
| ------------------ | ---------- | ----------- |
| Easy to use        | ✔ Yes      | ❌ No        |
| Dynamic size       | ✔          | ❌ Fixed     |
| Built-in functions | ✔ Many     | ❌ Limited   |
| Used in modern C++ | ✔ Standard | ❌ Old style |

---

# 🔹 Real-Life Examples of Strings

✔ Names
✔ Email ID
✔ Passwords
✔ Messages
✔ File names

Everything written in text is stored as a **string**.

---

# 🔹 Summary

### **Arrays**

* Store multiple values of **same type**
* Access using index
* Used for lists, tables, matrices

### **Strings**

* Sequence of characters
* Easier with `string` class
* Useful for names, sentences, text processing

---
