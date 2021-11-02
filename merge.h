#ifndef MERGE_H
#define MERGE_H

void mergeSortModified(int* array, int l, int r, int replaceFunc, int minrun, void (*func) (int*,int,int));
int medianOfThree(int* arr, int a, int b, int c);
void quickSort(int* arr, int l, int r, int replaceFunc, int minrun, void (*func)(int*,int,int));
#endif
