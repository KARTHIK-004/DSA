# 📚 **Lecture 4 — Know Basic Maths**

This lecture covers fundamental mathematical operations and number theory concepts that are essential for programming and competitive coding.

---

## 📖 **Overview**

Basic mathematics forms the foundation of many algorithms and problem-solving techniques. This section covers digit manipulation, number properties, divisibility, and optimization techniques that reduce time complexity from O(n) to O(√n) or O(log n).

---

## 🗂️ **Problems Covered**

### **01 - Count Digits**

Count the number of digits in a given number.

**Key Concepts:**

- Loop method: Divide by 10 repeatedly
- Logarithm method: `floor(log10(n)) + 1`
- String conversion method

**Time Complexity:** O(log₁₀ n)

**Example:** `12345` → `5 digits`

---

### **02 - Reverse a Number**

Reverse the digits of a number.

**Key Concepts:**

- Extract digits using modulo (%)
- Build reversed number by multiplying by 10
- Handle negative numbers and overflow

**Time Complexity:** O(log₁₀ n)

**Example:** `12345` → `54321`

---

### **03 - Check Palindrome**

Check if a number reads the same forwards and backwards.

**Key Concepts:**

- Reverse the number and compare
- No need to store all digits

**Time Complexity:** O(log₁₀ n)

**Example:** `121` → `Palindrome ✓`, `123` → `Not Palindrome ✗`

---

### **04 - Armstrong Numbers**

Check if a number equals the sum of its digits raised to the power of digit count.

**Key Concepts:**

- Count digits first
- Sum of (each digit)^(digit count)
- All single-digit numbers are Armstrong numbers

**Time Complexity:** O(log₁₀ n)

**Example:** `153` → `1³ + 5³ + 3³ = 153` ✓

**Common Armstrong Numbers:** 0-9, 153, 370, 371, 407, 1634, 8208, 9474

---

### **05 - GCD Or HCF**

Find the Greatest Common Divisor (GCD) or Highest Common Factor (HCF) of two numbers.

**Key Concepts:**

- Euclidean Algorithm (most efficient)
- Repeatedly replace larger number with remainder
- Can be implemented iteratively or recursively

**Time Complexity:** O(log(min(a,b)))

**Example:** `GCD(20, 15)` → `5`

**Formula:** `LCM(a, b) = (a × b) / GCD(a, b)`

---

### **06 - Check for Prime**

Check if a number is a prime number (divisible only by 1 and itself).

**Key Concepts:**

- Check divisors only up to √n
- 6k±1 optimization (all primes > 3 are of form 6k±1)
- 2 is the only even prime

**Time Complexity:** O(√n)

**Example:** `17` → `Prime ✓`, `12` → `Not Prime ✗`

**First Primes:** 2, 3, 5, 7, 11, 13, 17, 19, 23, 29...

---

### **07 - Print all Divisors**

Print all divisors (factors) of a given number.

**Key Concepts:**

- Divisors come in pairs: (i, n/i)
- Check only till √n
- For perfect squares, avoid counting √n twice

**Time Complexity:** O(√n)

**Example:** `36` → `1, 36, 2, 18, 3, 12, 4, 9, 6`

---

### **08 - Check Perfect Number**

Check if a number equals the sum of its proper divisors (excluding itself).

**Key Concepts:**

- Find all divisors except the number itself
- Sum them and compare with original number
- Perfect numbers are very rare

**Time Complexity:** O(√n)

**Example:** `28` → `1 + 2 + 4 + 7 + 14 = 28` ✓

**Perfect Numbers:** 6, 28, 496, 8128, 33550336...

---

### **09 - Sum of Divisors**

Calculate the sum of all divisors of a number (including 1 and the number itself).

**Key Concepts:**

- Similar to finding divisors, but sum them
- Use √n optimization
- Prime factorization formula available

**Time Complexity:** O(√n)

**Example:** `12` → `1 + 2 + 3 + 4 + 6 + 12 = 28`

**Applications:** Perfect numbers, abundant numbers, deficient numbers

---

### **10 - Check Perfect Square**

Check if a number is a perfect square (can be expressed as n²).

**Key Concepts:**

- Use sqrt() and check if squaring gives original number
- Binary search alternative
- Perfect squares can only end in 0, 1, 4, 5, 6, 9

**Time Complexity:** O(1) with sqrt(), O(log n) with binary search

**Example:** `64` → `8² = 64` ✓, `50` → `Not Perfect Square ✗`

**Perfect Squares:** 1, 4, 9, 16, 25, 36, 49, 64, 81, 100...

---

## 🔑 **Key Optimization Techniques**

### **1. √n Optimization**

When finding divisors or checking primality, only check up to √n because divisors come in pairs.

```cpp
for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
        // i and n/i are both divisors
    }
}
```

### **2. Euclidean Algorithm**

Efficiently find GCD using repeated modulo operations.

```cpp
while (a > 0 && b > 0) {
    if (a > b) a = a % b;
    else b = b % a;
}
```

### **3. Binary Exponentiation**

Calculate power in O(log n) instead of O(n).

```cpp
while (y > 0) {
    if (y % 2 == 1) result *= base;
    base *= base;
    y /= 2;
}
```

---

## 📊 **Time Complexity Summary**

| Problem           | Brute Force | Optimized        |
| ----------------- | ----------- | ---------------- |
| Count Digits      | O(log n)    | O(1) with log    |
| Reverse Number    | O(log n)    | O(log n)         |
| Check Palindrome  | O(log n)    | O(log n)         |
| Armstrong Numbers | O(log n)    | O(log n)         |
| GCD/HCF           | O(min(a,b)) | O(log min(a,b))  |
| Check Prime       | O(n)        | O(√n)            |
| Print Divisors    | O(n)        | O(√n)            |
| Perfect Number    | O(n)        | O(√n)            |
| Sum of Divisors   | O(n)        | O(√n)            |
| Perfect Square    | O(√n)       | O(1) or O(log n) |

---

## 🎯 **Common Patterns & Techniques**

### **Digit Manipulation**

```cpp
// Extract last digit
int lastDigit = n % 10;

// Remove last digit
n = n / 10;

// Build number from digits
result = result * 10 + digit;

// Count digits
int count = floor(log10(n)) + 1;
```

### **Divisor Finding**

```cpp
// Find all divisors efficiently
for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
        cout << i << " ";
        if (i != n/i) cout << n/i << " ";
    }
}
```

### **Prime Checking**

```cpp
// Optimized prime check
if (n <= 1) return false;
if (n == 2 || n == 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;

for (int i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i+2) == 0)
        return false;
}
return true;
```

---

## 💡 **Important Mathematical Properties**

### **Perfect Numbers**

- Sum of proper divisors equals the number
- Formula: 2^(p-1) × (2^p - 1) where both p and 2^p-1 are prime
- Only 51 perfect numbers are known

### **Prime Numbers**

- Only divisible by 1 and itself
- 2 is the only even prime
- All primes > 3 are of form 6k±1
- Infinite number of primes exist

### **GCD Properties**

- GCD(a, 0) = a
- GCD(a, b) = GCD(b, a % b)
- LCM(a, b) × GCD(a, b) = a × b

### **Armstrong Numbers**

- n-digit number where sum of nth powers of digits equals the number
- No 2-digit Armstrong numbers exist
- All single-digit numbers (0-9) are Armstrong numbers

---

## 🚀 **Applications in Programming**

1. **Cryptography:** Prime numbers, GCD, modular arithmetic
2. **Competitive Programming:** Fast I/O, optimization techniques
3. **Number Theory:** Divisibility, factorization, modular exponentiation
4. **Algorithm Design:** Time complexity optimization
5. **Data Validation:** Palindrome checking, digit manipulation

---

## 📝 **Practice Tips**

1. **Master the basics:** Understand digit extraction and manipulation thoroughly
2. **Optimize early:** Always think about √n optimization for divisor problems
3. **Handle edge cases:** Zero, negative numbers, single digits
4. **Use appropriate data types:** `long long` for large numbers to avoid overflow
5. **Test with examples:** Verify with small numbers first
6. **Understand time complexity:** Know when to use O(n) vs O(√n) vs O(log n)

---

## 🔗 **Connections to Other Topics**

- **Recursion:** GCD, power calculation
- **Arrays:** Sieve of Eratosthenes for multiple primes
- **Strings:** Number to string conversion
- **Bit Manipulation:** Fast power using binary representation
- **Dynamic Programming:** Digit DP problems
- **Modular Arithmetic:** Large number calculations

---

## ✅ **Summary**

This lecture covers essential mathematical operations that form the building blocks for:

- Number theory problems
- Optimization techniques
- Competitive programming
- Algorithm design

**Key Takeaways:**

- √n optimization reduces O(n) to O(√n) for divisor problems
- Euclidean algorithm is the fastest way to find GCD
- Binary exponentiation reduces power calculation from O(n) to O(log n)
- Understanding digit manipulation is crucial for many problems
- Always consider edge cases: 0, 1, negative numbers

---

## 📂 **Folder Structure**

Each problem folder contains:

- `main.cpp` - Complete C++ implementation
- `input.txt` - Sample test cases
- `output.txt` - Expected output
- `readme.md` - Detailed explanation, multiple methods, complexity analysis

---

**Happy Learning! 🎓**

Master these basic math concepts and you'll have a solid foundation for advanced algorithms and problem-solving!
