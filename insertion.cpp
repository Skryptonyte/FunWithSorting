#include "insertion.h"
#include <iostream>
#include <algorithm>
using namespace std;


/* Binary Search function taken from GeeksForGeeks with slight modifications */

int binarySearch(int a[], int low, int high, int item)
{
    if (high <= low)
        return (item > a[low]) ?
                (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, mid + 1, high, item);
    return binarySearch(a, low, mid-1, item);
}

void insertionSortBinary(int* arr, int l, int r)
{
	for (int i = l+1; i <= r; i++)
	{
		int j = i-1;
		int value = arr[i];

		int pos = binarySearch(arr,l,j,value);
		//int pos = lower_bound(arr+l,arr+j,value);
		//std::cout<< l<<" " << j<<" "<<pos<<endl;
		for (j; j >= pos; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[pos] = value;
		//arr[j] = value;
	}
}

void shellSort(int* arr, int l, int r)
{
	 //cout << l << " " << r << endl;

	int gaps[] = {57,23,10,4,1};     // Ciura Gap Sequence
	for (int gapIndex = 0; gapIndex < 5; gapIndex++)
	{
		int gap = gaps[gapIndex];
		for (int i = l; i <= r; i++)
		{
			int j = i-gap;
			int value = arr[i];
			for (j; j >= l && arr[j] > value; j -= gap)
			{
				arr[j+gap] = arr[j];
			}
			arr[j+gap] = value;
			//arr[j] = value;
		}
	}
}


void insertionSort(int* arr, int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		int j = i-1;
		int value = arr[i];
		for (j; j >= l && arr[j] > value; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = value;
		//arr[j] = value;
	}
}
