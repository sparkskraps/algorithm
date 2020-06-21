#ifndef QUICK_SORT_H
#define QUICK_SORT_H
// #include <iostream>

namespace quick_sort{

	/********************************************
	 * one-way partition 
	 * *****************************************/
	template <typename T>
	int oneWayPartition(T arr[], int iStart, int iEnd)
	{
		T tmpValue = arr[iStart];
		int tailIndex = iEnd;
		for(int i=iStart+1; i<=tailIndex; i++)	
		{
			while(i<=tailIndex && arr[i] > tmpValue)	
			{
				std::swap(arr[i], arr[tailIndex]);
				tailIndex--;
			}
		}

		std::swap(arr[iStart], arr[tailIndex]);

		return tailIndex;
	}

	/********************************************
	 * two-way partition 
	 * *****************************************/
	template <typename T>
	int twoWayPartition(T arr[], int iStart, int iEnd)
	{
		T tmpValue = arr[iStart];
		int i=iStart+1;
		int j=iEnd;
		while(i <= j)
		{
			while(i<=j && arr[i] <= tmpValue)
				i++;
			while(j>=i && arr[j] >= tmpValue)
				j--;
			if(i >= j)
				break;
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
		std::swap(arr[j], arr[iStart]);
		
		return j;
	}

	template <typename T>
	void quick_sort(T arr[], int iStart, int iEnd)
	{
		if(iStart >= iEnd)
			return;

		// int iMid = oneWayPartition(arr, iStart, iEnd);
		int iMid = twoWayPartition(arr, iStart, iEnd);
		quick_sort(arr, iStart, iMid-1);
		quick_sort(arr, iMid+1, iEnd);
	}

	template <typename T>
	void quickSort(T arr[], int n)
	{
		quick_sort(arr, 0, n-1);
	}
};


/*****************************************
 * Three-way quick sort
 * **************************************/
template <typename T>
void fastSort(T arr[], int iStart, int iEnd)
{
	if(iStart >= iEnd)
		return;
	T tmpValue = arr[iStart];
	int i=iStart+1;
	int smallIndex = iStart;
	int bigIndex = iEnd;
	while(i<=bigIndex)
	{
		if(arr[i] < tmpValue)
		{
			std::swap(arr[i], arr[smallIndex]);
			i++;
			smallIndex++;
		}
		else if(arr[i] > tmpValue)
		{
			std::swap(arr[i], arr[bigIndex]);
			bigIndex--;
		}
		else
		{
			i++;
		}
	}
	fastSort(arr, iStart, smallIndex-1);
	fastSort(arr, bigIndex+1, iEnd);
}

template <typename T>
void threeWayQuickSort(T arr[], int n)
{
	fastSort(arr, 0, n-1);
}

#endif

#if 0
int main()
{
	using namespace quick_sort;
	int n=10;
	int arr[n] = {5, 4, 1, 7, 8, 9, 2, 6, 8, 0};
	// quickSort<int>(arr, n);
	threeWayQuickSort(arr, n);
	for(int i=0; i<n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	return 0;
}
#endif

