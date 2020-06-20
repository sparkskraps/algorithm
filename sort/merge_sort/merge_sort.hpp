#ifndef MERGER_SORT_HPP
#define MERGER_SORT_HPP

namespace merge_sort{

	/***************************************
	 * Recursive Merge Sort
	 * ************************************/
	template <typename T>
	void merge(T arr[], int iStart, int iMid, int iEnd)
	{
		int i=iStart;
		int j=iMid+1;
		int k=0;
		int count = iEnd-iStart+1;
		T *newArr = new T[count];
		for(k=0; k<count; k++)
		{
			if(i > iMid)
			{
				newArr[k] = arr[j++];
				continue;
			}
			if(j > iEnd)
			{
				newArr[k] = arr[i++];
				continue;
			}

			// ensure the stability of sorting process
			if(arr[i] <= arr[j])
				newArr[k] = arr[i++];
			else
				newArr[k] = arr[j++];	
		}
		for(int k=0; k<count; k++)
			arr[k+iStart] = newArr[k];
	}

	template <typename T>
	void merge_sort(T arr[], int iStart, int iEnd)
	{
		if(iStart >= iEnd)
			return;
		// prevent `int value` overflow
		int iMid = iStart + (iEnd-iStart)/2;
		merge_sort<T>(arr, iStart, iMid);
		merge_sort<T>(arr, iMid+1, iEnd);
		merge<T>(arr, iStart, iMid, iEnd);
	}

	template <typename T>
	void mergeSort(T *arr, int n)
	{
		merge_sort(arr, 0, n-1);	
	}


	/***************************************
	 * Non-Recursive Merge Sort
	 * ************************************/
	template <typename T>
	void mergeSortFromBottom(T arr[], int n)
	{
		for(int iStep=0; iStep<n-1; iStep=2*iStep+1)
		{
			for(int i=0; i+iStep<n-1; i+=2*iStep+2)
			{
				int iEnd = (i+2*iStep+1 > n-1)?(n-1):(i+2*iStep+1);
				// std::cout << "iStep = " << iStep << " iStart = " << i << " iMid = " << i+iStep << " iEnd = " << iEnd << "\n";
				merge(arr, i, i+iStep, iEnd);		
			}
		}
	}
}

#endif

// Test
#if 0
int main()
{
	int n = 8;
	int arr[n] = {5,4,1,7,8,8,2,6};
	// mergeSort<int>(arr, n);
	mergeSortFromBottom<int>(arr, n);

	for(auto &v : arr)
		std::cout << v << " ";
	std::cout << "\n";

	return 0;
}

#endif
