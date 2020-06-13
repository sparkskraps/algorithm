#ifndef SELECT_SORT_HPP
#define SELECT_SORT_HPP

namespace select_sort{
	
	template<typename T>
	void selectSort(T arr[], int n)
	{
		for(int i=0; i<n-1; i++)
		{
			int k = i;
			for(int j=i+1; j<n; j++)
			{
				if(arr[j] < arr[k])
					k = j;
			}
			if(k != i)
			{
				T tmp = arr[k];
				arr[k] = arr[i];
				arr[i] = tmp;
			}
		}
	}	
};

#endif
