
# Combined sorts

This mini project aims at benchmarking combinations of sorting algorithms.

Currently, it tests the following

* The C and C++ built in sorting functions
* Merge sort (top-down), modified to switch to another sorting algorithm at some minrun threshold
 * Typically uses insertion algorithms, since they are the fastest with smaller array sizes.
* Insertion algorithms: Vanilla, Binary Insertion and Shell Sort (using Ciura sequence).
* Benchmark size hardcoded at 10M.
# Compilation

`gcc *.cpp -O3 -march=native`

# Personal Result

Tested on a Ryzen 4900HS running Windows 10.

```
Merge Sort Variant comparisons:


Built in C++ Sort : 925ms
Built in C++ Stable-Sort : 1107ms
Built in C Quick-Sort : 1658ms

Merge Sort : 2955ms

Merge Sort (Inplace: Insertion Sort, MINRUN=32): 1268ms
Merge Sort (Inplace: Insertion Sort, MINRUN=64): 1204ms

Merge Sort (Inplace: Binary Insertion Sort, MINRUN=32): 1423ms
Merge Sort (Inplace: Binary Insertion Sort, MINRUN=64): 1415ms

Merge Sort (Inplace: Shell Sort, using Ciura Sequence (till 57), MINRUN=64): 1370ms

Quick Sort: 1114ms
Quick Sort (Inplace: Insertion Sort, MINRUN: 64): 1161ms
```