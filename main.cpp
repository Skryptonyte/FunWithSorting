#include <stdio.h>
#include "merge.h"
#include "insertion.h"
#include <random>

#include <chrono>
#include <iostream>
#include <algorithm>
#include <cstdlib>


#define SIZE 10000000

using namespace std;
using namespace std::chrono;

void regenerateArray(int* array, int n)
{
	// Use Mersenne Twister PRNG
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(0, 2147483647);
	for (int i = 0; i < n; i++)
	{
		array[i] = distr(generator);
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
	cout << "Merge Sort Implementations, MINRUN=64\n\n";
	cout << "Merge Sort : ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,0,0,NULL);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	regenerateArray(array,SIZE);

	cout << "Merge Sort (Inplace: Insertion Sort): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,insertionSort);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	regenerateArray(array,SIZE);

	cout << "Merge Sort (Inplace: Binary Insertion Sort): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,insertionSortBinary);
	stop = high_resolution_clock::now();
	
	verifyArray(array,SIZE);

	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;

	/////
	regenerateArray(array,SIZE);

	cout << "Merge Sort (Inplace: Shell Sort, using Ciura Sequence (till 57)): ";
	
	start = high_resolution_clock::now();
	mergeSortModified(array,0,SIZE-1,1,64,shellSort);
	stop = high_resolution_clock::now();

	verifyArray(array,SIZE);

	
	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	cout<<endl;
	/////
	regenerateArray(array,SIZE);

	cout << "Quick Sort Implementations, Partitioning used: Median of Three, MINRUN=64\n\n";

	cout << "Quick Sort: ";
	
	start = high_resolution_clock::now();
	quickSort(array,0,SIZE-1,0,0,NULL);
	stop = high_resolution_clock::now();

	verifyArray(array,SIZE);
	
	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;
	/////
	regenerateArray(array,SIZE);

	cout << "Quick Sort (Inplace: Insertion Sort): ";
	
	start = high_resolution_clock::now();
	quickSort(array,0,SIZE-1,1,64,insertionSort);

	stop = high_resolution_clock::now();

	verifyArray(array,SIZE);
	
	cout << duration_cast<milliseconds>(stop-start).count()<<"ms"<<endl;


}

