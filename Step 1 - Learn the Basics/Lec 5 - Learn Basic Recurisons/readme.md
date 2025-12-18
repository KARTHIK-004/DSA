# 📚 **Lecture 5 — Learn Basic Recursion**

This lecture covers fundamental recursion concepts, techniques, and classic recursive problems that form the foundation for advanced algorithms.

---

## 📖 **Overview**

**Recursion** is a programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems. It's one of the most powerful and elegant problem-solving approaches in computer science.

### **Key Components of Recursion:**

1. **Base Case:** Condition to stop recursion (prevents infinite loops)
2. **Recursive Case:** Function calls itself with modified parameters
3. **Stack Space:** Each recursive call uses memory on the call stack

---

## 🗂️ **Problems Covered**

### **01 - Print Something N Times**

Print a message N times using recursion.

**Key Concepts:**

- Basic recursion structure
- Base case: n == 0
- Simple recursive call with n-1

**Example:** Print "Hello World!" 5 times

**Time:** O(n) | **Space:** O(n)

---

### **02 - Print Name N Times**

Print a specific name N times using recursion.

**Key Concepts:**

- Parameterized recursion
- Passing additional parameters (name)
- Same structure as Problem 01 but more flexible

**Example:** Print "Raj" 4 times

**Time:** O(n) | **Space:** O(n)

---

### **03 - Print 1 to N**

Print numbers from 1 to N in ascending order using recursion.

**Key Concepts:**

- Print AFTER recursive call for ascending order
- Stack unwinding concept
- Alternative: counter-based approach (i to n)

**Example:** Print 1 2 3 4 5 for n=5

**Time:** O(n) | **Space:** O(n)

**Important:** Print before vs after recursive call determines output order!

---

### **04 - Sum of First N Numbers**

Calculate sum of first N natural numbers using recursion.

**Key Concepts:**

- Functional recursion (returns value)
- Accumulation during stack unwinding
- Alternative: parameterized recursion (tail recursive)
- Mathematical formula: n(n+1)/2 is O(1)

**Example:** Sum(5) = 1+2+3+4+5 = 15

**Time:** O(n) | **Space:** O(n)

---

### **05 - Factorial of N**

Calculate factorial of N using recursion.

**Key Concepts:**

- Classic recursion example
- Base cases: 0! = 1, 1! = 1
- Exponential growth of values
- Use `long long` to prevent overflow

**Example:** 5! = 5×4×3×2×1 = 120

**Time:** O(n) | **Space:** O(n)

**Applications:** Permutations, combinations, probability

---

### **06 - Reverse an Array**

Reverse an array using recursion.

**Key Concepts:**

- Two-pointer technique with recursion
- In-place modification
- Swap elements from both ends
- Stack depth is only n/2

**Example:** [1,2,3,4,5] → [5,4,3,2,1]

**Time:** O(n) | **Space:** O(n/2)

---

### **07 - Check Palindrome String**

Check if a string is a palindrome using recursion.

**Key Concepts:**

- Two-pointer comparison
- Early termination on mismatch
- Symmetry checking
- Can extend to handle case-insensitivity

**Example:** "racecar" → Palindrome ✓

**Time:** O(n) | **Space:** O(n/2)

---

### **08 - Fibonacci Number**

Calculate the Nth Fibonacci number using recursion.

**Key Concepts:**

- Multiple recursion (two recursive calls)
- Overlapping subproblems
- Simple recursion is O(2^n) - very slow!
- Memoization reduces to O(n)
- Classic dynamic programming example

**Example:** F(10) = 55

**Time:** O(2^n) simple, O(n) with memoization | **Space:** O(n)

**Warning:** Simple recursion is exponential - use memoization or iteration!

---

## 🔑 **Core Recursion Concepts**

### **1. Base Case**

Every recursive function MUST have a base case to prevent infinite recursion.

```cpp
if (n == 0) return;  // Base case
```

### **2. Recursive Case**

The function calls itself with modified parameters, moving toward the base case.

```cpp
functionName(n - 1);  // Recursive call
```

### **3. Stack Space**

Each recursive call is stored on the call stack.

```
Maximum stack depth = Number of recursive calls
Space Complexity = O(depth)
```

### **4. Print Before vs After**

```cpp
// Print BEFORE → Descending order
void printDesc(int n) {
    if (n == 0) return;
    cout << n;        // Print first
    printDesc(n-1);   // Then recurse
}

// Print AFTER → Ascending order
void printAsc(int n) {
    if (n == 0) return;
    printAsc(n-1);    // Recurse first
    cout << n;        // Then print
}
```

---

## 📊 **Recursion Types**

### **1. Linear Recursion**

Function makes ONE recursive call.

```cpp
void print(int n) {
    if (n == 0) return;
    cout << n;
    print(n - 1);  // One call
}
```

### **2. Multiple Recursion**

Function makes MULTIPLE recursive calls.

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Two calls
}
```

### **3. Tail Recursion**

Recursive call is the LAST operation.

```cpp
void printTail(int n) {
    if (n == 0) return;
    cout << n;
    printTail(n - 1);  // Last operation
}
```

Can be optimized by compiler to iteration.

---

## ⚡ **Time & Space Complexity Summary**

| Problem            | Time   | Space  | Notes                |
| ------------------ | ------ | ------ | -------------------- |
| Print N Times      | O(n)   | O(n)   | Linear recursion     |
| Print Name N Times | O(n)   | O(n)   | Parameterized        |
| Print 1 to N       | O(n)   | O(n)   | Stack unwinding      |
| Sum of N Numbers   | O(n)   | O(n)   | Functional recursion |
| Factorial          | O(n)   | O(n)   | Classic example      |
| Reverse Array      | O(n)   | O(n/2) | Two pointers         |
| Palindrome String  | O(n)   | O(n/2) | Two pointers         |
| Fibonacci          | O(2^n) | O(n)   | Exponential! Use DP  |

---

## 🎯 **Common Recursion Patterns**

### **Pattern 1: Countdown (n to 0)**

```cpp
void countdown(int n) {
    if (n == 0) return;      // Base case
    cout << n << " ";        // Process
    countdown(n - 1);        // Recurse
}
```

### **Pattern 2: Count Up (0 to n)**

```cpp
void countup(int n) {
    if (n == 0) return;      // Base case
    countup(n - 1);          // Recurse first
    cout << n << " ";        // Process after
}
```

### **Pattern 3: Accumulator**

```cpp
int sum(int n, int acc) {
    if (n == 0) return acc;  // Base case returns accumulator
    return sum(n - 1, acc + n);  // Add to accumulator
}
```

### **Pattern 4: Two Pointers**

```cpp
void process(int arr[], int left, int right) {
    if (left >= right) return;  // Base case
    // Process arr[left] and arr[right]
    process(arr, left + 1, right - 1);  // Move inward
}
```

### **Pattern 5: Multiple Recursion**

```cpp
int multiRecurse(int n) {
    if (n <= 1) return n;    // Base case
    return multiRecurse(n-1) + multiRecurse(n-2);  // Multiple calls
}
```

---

## 🚨 **Common Pitfalls & Solutions**

### **1. Missing Base Case**

```cpp
// ❌ WRONG - Infinite recursion!
void wrong(int n) {
    cout << n;
    wrong(n - 1);  // Never stops!
}

// ✅ CORRECT
void correct(int n) {
    if (n == 0) return;  // Base case
    cout << n;
    correct(n - 1);
}
```

### **2. Stack Overflow**

```cpp
// For very large n (>10^5), recursion may cause stack overflow
// Solution: Use iteration or tail recursion
```

### **3. Inefficient Recursion**

```cpp
// ❌ Fibonacci without memoization: O(2^n)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Recalculates same values!
}

// ✅ With memoization: O(n)
int fibMemo(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}
```

---

## 💡 **When to Use Recursion**

### **Good Use Cases:**

✅ Tree/Graph traversal
✅ Divide and conquer algorithms (merge sort, quick sort)
✅ Backtracking problems (N-Queens, Sudoku)
✅ Mathematical problems (factorial, Fibonacci with memoization)
✅ Problems with recursive structure (nested data)

### **Avoid Recursion When:**

❌ Simple iteration is clearer
❌ Stack overflow risk (very large n)
❌ Performance critical (recursion has overhead)
❌ No overlapping subproblems benefit

---

## 🔄 **Recursion vs Iteration**

| Aspect             | Recursion                 | Iteration               |
| ------------------ | ------------------------- | ----------------------- |
| **Code**           | Often more elegant        | Sometimes more verbose  |
| **Space**          | O(n) stack space          | O(1) typically          |
| **Performance**    | Function call overhead    | Faster (no overhead)    |
| **Readability**    | Natural for some problems | Better for simple loops |
| **Stack Overflow** | Risk for large n          | No risk                 |

---

## 🧠 **Recursion Thinking Process**

1. **Identify the base case:** When should recursion stop?
2. **Define the recursive case:** How to break down the problem?
3. **Trust the recursion:** Assume smaller problem is solved
4. **Combine results:** How to use the result from smaller problem?

### **Example: Factorial**

```
1. Base case: 0! = 1, 1! = 1
2. Recursive case: n! = n × (n-1)!
3. Trust: Assume factorial(n-1) works
4. Combine: Multiply n with result
```

---

## 📈 **Recursion Tree Analysis**

Understanding recursion trees helps analyze time complexity:

### **Linear Recursion (Print N)**

```
print(5)
  └── print(4)
      └── print(3)
          └── print(2)
              └── print(1)
                  └── print(0)

Depth: n
Calls: n
Time: O(n)
```

### **Binary Recursion (Fibonacci)**

```
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   └── fib(1)
│   └── fib(2)
└── fib(3)
    ├── fib(2)
    └── fib(1)

Depth: n
Calls: 2^n (exponential!)
Time: O(2^n)
```

---

## 🎓 **Learning Path**

1. **Start Simple:** Print N times, countdown
2. **Understand Stack:** Visualize call stack
3. **Master Base Cases:** Practice identifying stopping conditions
4. **Print Before/After:** Understand execution order
5. **Return Values:** Functional recursion (sum, factorial)
6. **Two Pointers:** Array/string manipulation
7. **Multiple Recursion:** Fibonacci, tree problems
8. **Optimization:** Memoization, tail recursion

---

## 🔗 **Connections to Other Topics**

- **Dynamic Programming:** Recursion + Memoization
- **Backtracking:** Recursion with state exploration
- **Tree Traversal:** Inherently recursive
- **Divide and Conquer:** Merge sort, quick sort
- **Graph Algorithms:** DFS uses recursion
- **Mathematical Induction:** Similar logical structure

---

## ✅ **Summary**

This lecture covers essential recursion concepts:

**Key Takeaways:**

- Every recursion needs a base case
- Stack space is O(depth of recursion)
- Print before vs after determines order
- Functional recursion returns values
- Multiple recursion can be exponential
- Memoization optimizes overlapping subproblems
- Tail recursion can be optimized by compiler
- Recursion is powerful but has overhead

**Master These:**

1. Base case identification
2. Recursive case formulation
3. Stack space analysis
4. Time complexity calculation
5. When to use recursion vs iteration

---
