
# Intro sorts

This mini project aims at benchmarking many variations of introsort.

Currently, it tests the following

* The C and C++ built in sorting functions
* Merge sort and QuickSort, both optimized to switch to another algorithm below minrun threshold
  * Typically uses insertion sort, since they are the fastest with smaller array sizes.
* Insertion Sort Variants: Vanilla, Binary Insertion and Shell Sort (using Ciura sequence).
* Benchmark size hardcoded at 10M.

# Compilation

`gcc *.cpp -O3 -march=native`

# Personal Result

Tested on a Ryzen 4900HS running Windows 10.

```
Built in C++ Sort : 927ms
Built in C++ Stable-Sort : 1112ms
Built in C Quick-Sort : 1643ms

Merge Sort Implementations, MINRUN=64

Merge Sort : 2913ms
Merge Sort (Inplace: Insertion Sort): 1194ms
Merge Sort (Inplace: Binary Insertion Sort): 1418ms
Merge Sort (Inplace: Shell Sort, using Ciura Sequence (till 57)): 1354ms

Quick Sort Implementations, Partitioning used: Median of Three, MINRUN=64

Quick Sort: 1048ms
Quick Sort (Inplace: Insertion Sort): 958ms
```