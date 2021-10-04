
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


Built in C++ Sort : 706ms
Built in C++ Stable-Sort : 914ms
Built in C Quick-Sort : 1019ms

Merge Sort : 2697ms

Merge Sort (with Insertion Sort, MINRUN=32): 1046ms
Merge Sort (with Insertion Sort, MINRUN=64): 959ms

Merge Sort (with Binary Insertion Sort, MINRUN=32): 1189ms
Merge Sort (with Binary Insertion Sort, MINRUN=64): 1186ms

Merge Sort (with Shell Sort, using Ciura Sequence (till 57), MINRUN=64): 544ms
```