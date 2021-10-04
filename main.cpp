#include <stdio.h>
#include "merge.h"
#include "insertion.h"
#include <random>

#include <chrono>
#include <iostream>
#include <algorithm>
#include <stdlib.h>


#define SIZE 10000000

using namespace std;
using namespace std::chrono;
void regenerateArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = rand();
	}
}

void verifyArray(int* array, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (array[i] > array[i+1])
		{
			cout << "SORT VERIFICATION FAILED" << endl;
			exit(1);
		}
	}
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
	
	int *array = new int[SIZE];

	cout << "Merge Sort Variant comparisons: \n\n" << endl;
	/////
	regenerateArray(array,SIZE);

	cout << "Built in C++ Sort : ";
	
	auto start = high_resolution_clock::now();
	sort(array,array+SIZE);
	auto stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	/////
	regenerateArray(array,SIZE);
	
	cout << "Built in C++ Stable-Sort : ";
	
	start = high_resolution_clock::now();
	stable_sort(array,array+SIZE);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	/////
	regenerateArray(array,SIZE);

	cout << "Built in C Quick-Sort : ";
	
	start = high_resolution_clock::now();
	qsort(array,SIZE,sizeof(int),cmpfunc);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	cout << endl;

	/////
	regenerateArray(array,SIZE);

	cout << "Merge Sort : ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,0,0,NULL);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	cout << endl;

	/////
	regenerateArray(array,SIZE);
	cout << "Merge Sort (with Insertion Sort, MINRUN=32): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,32,insertionSort);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	/////
	regenerateArray(array,SIZE);

	cout << "Merge Sort (with Insertion Sort, MINRUN=64): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,insertionSort);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	cout <<endl;

	/////
	regenerateArray(array,SIZE);

	cout << "Merge Sort (with Binary Insertion Sort, MINRUN=32): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,32,insertionSortBinary);
	stop = high_resolution_clock::now();

	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	regenerateArray(array,SIZE);

	cout << "Merge Sort (with Binary Insertion Sort, MINRUN=64): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,insertionSortBinary);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	cout << endl;

	regenerateArray(array,SIZE);

	cout << "Merge Sort (with Shell Sort, using Ciura Sequence (till 57), MINRUN=64): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,shellSort);
	stop = high_resolution_clock::now();

	verifyArray(array,SIZE);
	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	/*
	for (int i = 0; i < SIZE; i++)
	{
		cout<<array[i]<<endl;
	}
	*/
}

