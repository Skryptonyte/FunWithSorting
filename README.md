
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


Built in C++ Sort : 944ms
Built in C++ Stable-Sort : 1110ms
Built in C Quick-Sort : 1635ms

Merge Sort : 2916ms

Merge Sort (with Insertion Sort, MINRUN=32): 1265ms
Merge Sort (with Insertion Sort, MINRUN=64): 1196ms

Merge Sort (with Binary Insertion Sort, MINRUN=32): 1405ms
Merge Sort (with Binary Insertion Sort, MINRUN=64): 1420ms

Merge Sort (with Shell Sort, using Ciura Sequence (till 57), MINRUN=64): 573ms
```