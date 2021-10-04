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
