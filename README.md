# Sorting Algorithms Project

## University: USTHB
**Faculty of Computer Science**  
**Course: Advanced Algorithms and Complexity**  

---

## 📌 Introduction

This project studies and compares different sorting algorithms:
- **Bubble Sort**
- **Gnome Sort**
- **Radix Sort**
- **Quick Sort**
- **Heap Sort**

Objectives:
- Implement and test sorting algorithms
- Analyze their complexities
- Compare their theoretical and experimental performance

---

## 📜 Implemented Algorithms

### 🔹 Bubble Sort
- Iterative method, swapping adjacent elements
- Complexity:
  - Best case: **O(n)**
  - Worst case: **O(n²)**

### 🔹 Gnome Sort
- Simple iterative sorting approach
- Complexity:
  - Best case: **O(n)**
  - Worst case: **O(n²)**

### 🔹 Radix Sort
- Sorts numbers by digit position
- Complexity: **O(d × n)**
- Stable: ✅ Yes

### 🔹 Quick Sort
- "Divide and Conquer" method
- Complexity:
  - Average: **O(n log n)**
  - Worst case: **O(n²)**

### 🔹 Heap Sort
- Uses a heap data structure
- Complexity: **O(n log n)**
- Stable: ❌ No

---

## 📊 Performance Analysis

Tests were conducted with arrays of sizes **1000, 5000, 10000, 20000, 50000** elements.

| Size (n) | Bubble Sort | Gnome Sort | Radix Sort | Quick Sort | Heap Sort |
|----------|------------|------------|------------|------------|------------|
| 1000     | 0.023 s    | 0.021 s    | 0.002 s    | 0.001 s    | 0.003 s    |
| 5000     | 0.578 s    | 0.532 s    | 0.009 s    | 0.007 s    | 0.018 s    |
| 10000    | 2.314 s    | 2.128 s    | 0.018 s    | 0.015 s    | 0.041 s    |

---

## 🏆 Conclusion

- **Bubble & Gnome Sort** are inefficient for large arrays (**O(n²)**).
- **Radix Sort** is best for integers (**O(d × n)**).
- **Quick Sort** is efficient in practice (**O(n log n)**).
- **Heap Sort** provides a performance guarantee (**O(n log n)**).

**Algorithm Choice Based on Context:**
✅ Small datasets: Bubble/Gnome Sort
✅ Large integer sets: Radix Sort
✅ General use: Quick Sort
✅ Guaranteed performance: Heap Sort

---

## 📂 Project Structure
```
📂 sorts_algo
 ├── 📄 main.c
 ├── 📄 bubble_sort.c
 ├── 📄 gnome_sort.c
 ├── 📄 radix_sort.c
 ├── 📄 quick_sort.c
 ├── 📄 heap_sort.c
 ├── 📄 README.md
```

---

## 🚀 How to Run
1. **Compile with GCC**:
   ```sh
   gcc main.c bubble_sort.c gnome_sort.c radix_sort.c quick_sort.c heap_sort.c -o sorts_algo
   ```
2. **Execute**:
   ```sh
   ./sorts_algo
   ```

---

## 📢 Note
This project is an academic work for the "Advanced Algorithms and Complexity" course. Performance may vary based on hardware.

🎯 **Happy Sorting!** 🎯

