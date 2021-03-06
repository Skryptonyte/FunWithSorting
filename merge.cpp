#include "merge.h"
#include <iostream>
#include <unistd.h>
using namespace std;


void mergeSortModified(int* arr, int l, int r,int replaceFunc,int minrun, void (*func)(int*, int, int))
{
	//sleep(1);
	int size = r-l+1;

	if (size <= 1)
	{
		return;
	}
	else if (size <= minrun && replaceFunc)
	{
		func(arr,l,r);
		return;
	}
//	cout << l << " " << r <<" "<< endl;
	int midpoint = l +( (r-l)>>1);
//	cout<<midpoint<<endl;
	mergeSortModified(arr,l,midpoint,replaceFunc, minrun, func);
	mergeSortModified(arr,midpoint+1,r,replaceFunc, minrun, func);
	
	int lsize = midpoint-l+1, rsize = r - midpoint;
	int *rightArr = new int[rsize];
	int *leftArr = new int[lsize];
	
	for (int i = 0; i < lsize; i++) leftArr[i] = arr[l+i];
	for (int i = 0; i < rsize; i++) rightArr[i] = arr[midpoint+1+i];


	int rp=0,lp=0,p=l;
	

	while (lp < lsize && rp < rsize)
	{
		if (rightArr[rp] <= leftArr[lp])
		{
			arr[p] = rightArr[rp];
			rp++;
			p++;
		}
		else
		{
			arr[p] = leftArr[lp];
			lp++;
			p++;
		}

	}
	while (rp < rsize)
	{
		arr[p] = rightArr[rp];
		rp++;
		p++;
	}

	while (lp < lsize)
	{
		arr[p] = leftArr[lp];
		lp++;
		p++;
	}
	delete rightArr;
	delete leftArr;

}

int medianOfThree(int* arr, int a, int b, int c)
{
    // Compare each three number to find middle
    // number. Enter only if a > b
    if (arr[a] > arr[b])
    {
        if (arr[b] > arr[c])
            return b;
        else if (arr[a] > arr[c])
            return c;
        else
            return a;
    }
    else
    {
        // Decided a is not greater than b.
        if (arr[a] > arr[c])
            return a;
        else if (arr[b] > arr[c])
            return c;
        else
            return b;
    }

}

void quickSort(int* arr, int l, int r, int replaceFunc, int minrun, void (*func)(int*,int,int))
{
	// cout << l << " " << r << endl;
	
	int lowIndex = l;
	int size = r-l+1;

	if (size <=  1|| l <0 || r<0)
	{
		return;
	}
	else if (size <= minrun && replaceFunc)
	{
		func(arr,l,r);
		return;
	}

	int selectedPivot = medianOfThree(arr,l,l + (r-l)>>1,r);

	swap(arr[r],arr[selectedPivot]);

	for (int i = l; i <= r-1; i++)
	{
		if (arr[i] < arr[r])
		{
			swap(arr[i],arr[lowIndex]);

			lowIndex++;
		}
	}

	swap(arr[r],arr[lowIndex]);

	quickSort(arr,l,lowIndex-1,replaceFunc,minrun,func);
	quickSort(arr,lowIndex+1,r,replaceFunc,minrun,func);
}