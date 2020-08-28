#include <memory.h>

#include <iostream>
#include <algorithm>

template <typename T>
class MaxHeap
{
	public:
		MaxHeap(int capacity)
			:m_capacity(capacity),
			m_size(0)
		{
			m_arr = new T[m_capacity];
		}

		~MaxHeap()
		{
			if(m_arr != NULL)
			{
				delete[] m_arr;
			}
		}

		void add_to_heap(T arr[], int n)
		{
			if(n >= m_capacity)
			{
				m_arr = (T *)realloc(m_arr, sizeof(T)*(n*2));
				memset(m_arr+m_capacity, 0, sizeof(T)*(n*2-m_capacity));
				m_capacity = 2*n;
			}
			for(int i=0; i<n; i++)
				m_arr[++m_size] = arr[i];
			heapify();
		}

		T get_max_element()
		{
			T tmpValue = m_arr[1];
			m_arr[1] = m_arr[m_size--];
			shift_down(1);

			return tmpValue;
		}

	protected:
		void heapify()
		{
			for(int i=m_size/2; i>=1; i--)	
				shift_down(i);
		}

		void shift_down(int index)
		{
			T tmpValue = m_arr[index];
			int k = 0; 
			while((k=2*index) <= m_size)
			{
				if(k+1 <= m_size && m_arr[k+1] > m_arr[k])
					k += 1;
				if(m_arr[k] < tmpValue)
					break;
				m_arr[index] = m_arr[k];
				index = k;
			}
			m_arr[index] = tmpValue;
		}

	private:
		T *m_arr;
		int m_size;
		int m_capacity;
};

int main()
{
	MaxHeap<int> maxHeap(20);
	int topN = 3;
	int count = 10;
	int arr[count] = {12,15,4,1,78,8,2,3,6,0};

	maxHeap.add_to_heap(arr, count);

	for(int i=0; i<topN; i++)
	{
		int maxElement = maxHeap.get_max_element();
		std::cout << maxElement << " ";
	}
	std::cout << "\n";
}
