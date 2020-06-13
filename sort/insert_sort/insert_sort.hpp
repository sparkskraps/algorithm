#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

namespace insert_sort{
	
	template <typename T>
	void insertSort(T arr[], int n)
	{
		int j=0;
		for(int i=1; i<n; i++)
		{
			T tmpValue = arr[i];
			for(j=i-1; j>=0 && arr[j] >= tmpValue; j--)
				arr[j+1] = arr[j];

			arr[j+1] = tmpValue;
		}
	}
};

#endif
