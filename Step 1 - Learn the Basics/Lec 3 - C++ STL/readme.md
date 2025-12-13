# 📘 **C++ STL Containers**

---

# ⭐ 1. **PAIR**

### Syntax

```cpp
pair<int, int> p = {1, 2};
cout << p.first << p.second;
```

### Vector of pairs

```cpp
vector<pair<int,int>> vp = {{1,2}, {3,4}};
```

---

# ⭐ 2. **VECTOR**

### Key Points

✔ Dynamic array
✔ Random access ✔
✔ Fast push_back ✔
✔ Slow insert/erase in middle ❌

### Common operations

```cpp
vector<int> v;
v.push_back(10);
v.pop_back();
v.size();
v.clear();
v.erase(v.begin() + 2);
v.insert(v.begin(), 5);
```

### Iteration

```cpp
for (auto x : v) cout << x;
```

---

# ⭐ 3. **LIST (Doubly Linked List)**

✔ Fast insertion/deletion anywhere
✔ No random access (no `l[0]`)

### Common operations

```cpp
list<int> l;
l.push_front(10);
l.push_back(20);

l.pop_front();
l.pop_back();

l.insert(it, value);
l.erase(it);

l.sort();
l.reverse();
l.unique();
```

---

# ⭐ 4. **DEQUE (Double-Ended Queue)**

✔ Fast insertion at front & back
✔ Random access allowed

### Operations

```cpp
deque<int> dq;
dq.push_front(10);
dq.push_back(20);
dq.pop_front();
dq.pop_back();

dq.insert(dq.begin()+1, 15);
dq.erase(dq.begin());
```

---

# ⭐ 5. **STACK – LIFO**

✔ Only top accessible
✔ No iteration

### Operations

```cpp
stack<int> st;
st.push(10);
st.top();
st.pop();
st.size();
st.empty();
```

Time complexity → All **O(1)**

---

# ⭐ 6. **QUEUE – FIFO**

✔ First in, first out
✔ Only front/back accessible

### Operations

```cpp
queue<int> q;
q.push(10);
q.front();
q.back();
q.pop();
q.size();
q.empty();
```

Time complexity → All **O(1)**

---

# ⭐ 7. **PRIORITY QUEUE (HEAP)**

### Max-Heap (default)

```cpp
priority_queue<int> pq;
pq.push(10);
pq.top();
pq.pop();
```

### Min-Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Time complexity →
`push` / `pop`: **O(log n)**
`top`: **O(1)**

---

# ⭐ 8. **SET**

✔ Sorted
✔ Unique elements
✔ Tree-based (RB tree)

### Operations

```cpp
set<int> s;
s.insert(10);
s.erase(5);
s.find(10);
s.count(10);
s.lower_bound(10);
s.upper_bound(10);
```

Time complexity → **O(log n)**

---

# ⭐ 9. **MULTISET**

✔ Sorted
✔ Duplicates allowed
✔ Tree-based

### Operations

```cpp
multiset<int> ms;
ms.insert(10);
ms.erase(10);      // removes ALL 10s
auto it = ms.find(10);
ms.erase(it);      // removes one
ms.count(10);      // duplicates count
```

Time complexity → **O(log n)**

---

# ⭐ 10. **UNORDERED SET**

✔ Unique
✔ Unordered (hash table)
✔ Very fast average time

### Operations

```cpp
unordered_set<int> us;
us.insert(10);
us.erase(10);
us.find(10);
```

Average Time → **O(1)**
Worst Case → **O(n)**

---

# ⭐ 11. **MAP (Ordered Dictionary)**

✔ Key–value pairs
✔ Keys sorted
✔ Unique keys
✔ Tree-based (RB tree)

### Operations

```cpp
map<int,int> mp;
mp[1] = 100;
mp.insert({2, 200});

mp.find(1);
mp.erase(2);
mp.lower_bound(2);
mp.upper_bound(2);
```

Time complexity → **O(log n)**

---

# ⭐ 12. **UNORDERED MAP**

✔ Key–value pairs
✔ Not sorted
✔ Hash table
✔ Fast lookups

### Operations

```cpp
unordered_map<int,int> ump;
ump[1] = 100;
ump.insert({2,200});
ump.find(1);
ump.erase(2);
```

Average Time → **O(1)**
Worst Case → **O(n)**

---

# ⭐ COMPARISON TABLE (SUPER IMPORTANT FOR EXAMS)

| Container      | Ordered?    | Duplicates? | Access     | Implementation     | Avg Speed |
| -------------- | ----------- | ----------- | ---------- | ------------------ | --------- |
| vector         | No          | Yes         | Random     | Dynamic Array      | Fast      |
| list           | No          | Yes         | No random  | Doubly Linked List | Medium    |
| deque          | No          | Yes         | Random     | Segmented array    | Fast      |
| stack          | LIFO        | Yes         | Top only   | Deque              | Fast      |
| queue          | FIFO        | Yes         | Ends only  | Deque              | Fast      |
| priority_queue | By priority | Yes         | Top only   | Heap               | Fast      |
| set            | Yes         | No          | Iterators  | RB Tree            | Slow      |
| multiset       | Yes         | Yes         | Iterators  | RB Tree            | Slow      |
| unordered_set  | No          | No          | Iterators  | Hash Table         | Very Fast |
| map            | Yes         | No          | Key lookup | RB Tree            | Slow      |
| unordered_map  | No          | No          | Key lookup | Hash Table         | Very Fast |

---

# ⭐ Time Complexity Summary

| STL Container  | Insert         | Erase    | Search   | Notes               |
| -------------- | -------------- | -------- | -------- | ------------------- |
| vector         | O(1) amortized | O(n)     | O(1)     | Middle ops slow     |
| list           | O(1)           | O(1)     | O(n)     | No random access    |
| deque          | O(1)           | O(1)     | O(1)     | Fast both ends      |
| stack          | O(1)           | O(1)     | O(1)     | Top only            |
| queue          | O(1)           | O(1)     | O(1)     | Ends only           |
| priority_queue | O(log n)       | O(log n) | O(1)     | Always top priority |
| set            | O(log n)       | O(log n) | O(log n) | Sorted & unique     |
| multiset       | O(log n)       | O(log n) | O(log n) | Sorted, duplicates  |
| unordered_set  | O(1) avg       | O(1) avg | O(1) avg | Hash table          |
| map            | O(log n)       | O(log n) | O(log n) | Sorted dictionary   |
| unordered_map  | O(1) avg       | O(1) avg | O(1) avg | Fast dictionary     |

---

# 🎯 FINAL REVISION TIPS

✔ Use **vector** by default unless you need special behavior
✔ Use **set** or **map** when you need **sorted** behavior
✔ Use **unordered_set / unordered_map** when you need **fast lookups**
✔ Use **priority_queue** for max/min extraction
✔ Use **stack** for LIFO, **queue** for FIFO
✔ Remember: list has **no random access**

---
