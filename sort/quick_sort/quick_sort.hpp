#ifndef QUICK_SORT_H
#define QUICK_SORT_H

namespace quick_sort{

	template <typename T>
	int partition(T arr[], int iStart, int iEnd)
	{
		T tmpValue = arr[iStart];
		int tailIndex = iEnd;
		int i=0;
		for(i=iStart+1; i<=tailIndex; i++)	
		{
			while(i<=tailIndex && arr[i] > tmpValue)	
			{
				std::swap(arr[i], arr[tailIndex]);
				tailIndex--;
			}
		}

		arr[iStart] = arr[tailIndex];
		arr[tailIndex] = tmpValue;

		return tailIndex;
	}

	template <typename T>
	void quick_sort(T arr[], int iStart, int iEnd)
	{
		if(iStart >= iEnd)
			return;

		int iMid = partition(arr, iStart, iEnd);
		quick_sort(arr, iStart, iMid-1);
		quick_sort(arr, iMid+1, iEnd);
	}

	template <typename T>
	void quickSort(T arr[], int n)
	{
		quick_sort(arr, 0, n-1);
	}
};

#if 0
int main()
{
	int n=6;
	int arr[n] = {5, 4, 1, 7, 8, 8};
	quickSort(arr, n);
	for(int i=0; i<n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";



	return 0;
}
#endif
#endif


