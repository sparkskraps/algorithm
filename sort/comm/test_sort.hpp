#ifndef TEST_SORT_H
#define TEST_SORT_H

namespace test_sort{

	int *generateRandom(int n, int iStart, int iEnd)
	{
		int *pNewArr = new int[n];
		int range = iEnd - iStart + 1;
		srand(time(NULL));
		for(int i=0; i<n; i++)
			pNewArr[i] = iStart + rand()%range;	

		return pNewArr;
	}

	int *copyArray(int arr[], int n)
	{
		int *pNewArr = new int[n];
		for(int i=0; i<n; i++)
			pNewArr[i] = arr[i];

		return pNewArr;
	}

	bool isSorted(int arr[], int n)
	{
		for(int i=0; i<n-1; i++)
		{
			if(arr[i] <= arr[i+1])
				continue;
			return false;
		}

		return true;
	}

	template <typename T>
	void testSort(const std::string &sSortName, void (*sortFunc)(T arr[], int), int arr[], int n)
	{
		clock_t time = clock();
		sortFunc(arr, n);
		time = clock() - time;

		assert(isSorted(arr, n));
		std::cout << "The " << sSortName << " consume " << ((double)time/CLOCKS_PER_SEC) << " seconds.\n";
	}
};


#endif


