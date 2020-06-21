/*******************************
 * This is the test file for the 
 * sort algorithm(select sort, insert sort, etc)
 *******************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>

#include "./select_sort/select_sort.hpp"
#include "./comm/test_sort.hpp"
#include "./insert_sort/insert_sort.hpp"
#include "./quick_sort/quick_sort.hpp"
#include "./merge_sort/merge_sort.hpp"

using namespace select_sort;
using namespace test_sort;
using namespace insert_sort;
using namespace quick_sort;
using namespace merge_sort;

int main()
{	
	int count = 200000;
	int iStart = 1;
	int iEnd = 1000;
	// generate `count` numbers, the range is [`iStart`, `iEnd`].
	int *arr = generateRandom(count, iStart, iEnd);
	int *arr2 = copyArray(arr, count);

	// testSort("selection sort", selectSort<int>, arr, count);
	// testSort("insert sort", insertSort<int>, arr2, count);
	
	/**************************************************************
	 * The [merge, quickSort] are faster than [selection, insert].
	 * ***********************************************************/
	testSort("merge sort", mergeSort<int>, arr, count);
	// testSort("quick sort", quickSort<int>, arr, count);
	testSort("three-way quick sort", threeWayQuickSort<int>, arr2, count);

	delete[] arr;
	delete[] arr2;
	arr = nullptr;
	arr2 = nullptr;

	return 0;
}

