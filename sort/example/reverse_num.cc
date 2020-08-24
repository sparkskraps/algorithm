/**********************************************
 * calculate the reverse number of the array.**
 *********************************************/
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>

// #include "../comm/test_sort.hpp"
// #include "../merge_sort/merge_sort.hpp"
// using namespace test_sort;
// using namespace merge_sort;

static int reverseNum = 0;

void merge(int arr[], int iStart, int iMid, int iEnd)
{
	int count = (iEnd - iStart + 1);
	int *newArr = new int[count];
	int i = iStart;
	int j = iMid + 1;
	int right_sum = (iEnd - iMid);
	for(int k=iStart; k<=iEnd; k++)
	{
		if(i > iMid)
		{
			newArr[k-iStart] = arr[j++];
			continue;
		}
		if(j > iEnd)
		{
			newArr[k-iStart] = arr[i++];
			continue;
		}
		if(arr[i] <= arr[j])
		{
			newArr[k-iStart] = arr[i++];	
		}
		else
		{
			newArr[k-iStart] = arr[j++];
			reverseNum += (iMid-i+1);
		}
	}

	for(int i=iStart; i<=iEnd; i++)
	{
		arr[i] = newArr[i-iStart];
	}
	delete[] newArr;
}

void merge_sort(int array[], int iStart, int iEnd)
{
	if(iStart >= iEnd)
		return;

	int iMid = (iStart + iEnd)/2;	
	merge_sort(array, iStart, iMid);
	merge_sort(array, iMid+1, iEnd);
	merge(array, iStart, iMid, iEnd);
}

int main()
{
	int array[] = {5, 4, 1, 6, 7, 8, 2, 3};
	merge_sort(array, 0, 7);

	for(auto &value : array)
		std::cout << value << " ";
	std::cout << "\n";

	// value should be 13
	std::cout << "reverse number is : " << reverseNum << "\n";

	return 0;
}
