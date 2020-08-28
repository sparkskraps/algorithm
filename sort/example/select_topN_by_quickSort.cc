/**********************************************
 * select Top N numbers from array.
 * ********************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>

#include "../comm/test_sort.hpp"

using namespace test_sort;

static int topN = 5;

int partition(int arr[], int iStart, int iEnd)
{
	int tmpValue = arr[iStart];
	int index = iStart + 1;
	int highIndex = iEnd;
	int smallIndex = iStart + 1;
	while(index <= highIndex)
	{
		if(arr[index] < tmpValue)
		{
			index++;	
		}
		else
		{
			std::swap(arr[highIndex], arr[index]);
			highIndex--;
		}
	}
	std::swap(arr[iStart], arr[index-1]);

	return index-1;
}

// select top n from arr[iStart, iEnd].
void quick_sort(int arr[], int iStart, int iEnd, int count)
{
	if(iStart > iEnd)
		return;
	int iMid = partition(arr, iStart, iEnd);
	if(count-iMid < topN)
		quick_sort(arr, iStart, iMid-1, count);
	else if(count-iMid > topN)
		quick_sort(arr, iMid+1, iEnd, count);
}

int main()
{
	// int arr[] = {5, 4, 1, 7, 8, 8, 2, 6, 3, 4};
	int count = 20;
	int *arr = generateRandom(count, 1, 50);
	quick_sort(arr, 0, count-1, count);

	for(int i=0; i<count; i++)
		std::cout << arr[i] << " ";
	std::cout << "\nresult:\n";
	for(int i=count-1; (topN--)>0; i--)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	delete[] arr;

	return 0;
}
