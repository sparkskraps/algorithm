#ifndef HEAP_SORT
#define HEAP_SORT
// #include <iostream>
// #include <algorithm>
// #include <cassert>
// #include <memory.h>

namespace heap_sort{
	
	template <typename T>
	class MinHeap
	{
		public:
			MinHeap(int capacity)
				:m_capacity(capacity),
			    m_size(0)
			{
				m_arr = new T[m_capacity];
			}

			~MinHeap()
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
					m_arr = (T *)realloc(m_arr, sizeof(T)*(2*n));
					memset(m_arr + m_capacity, 0, sizeof(T)*(2*n-m_capacity));
				}
				for(int i=0; i<n; i++)
				{
					m_arr[++m_size] = arr[i];
				    shift_up(m_size);
				}
			}

			T get_min_element()
			{
				T minElement = m_arr[1];
				m_arr[1] = m_arr[m_size--];
				shift_down(1);

				return minElement;
			}

			void sort_heap()
			{
				for(int i=m_size/2; i>=1; i--)
				{
					shift_down(i, m_size);
				}
			}

			int size() const
			{
				return m_size;
			}

			void print_heap()
			{
				for(int i=1; i<=m_size; i++)
					std::cout << m_arr[i] << " ";
				std::cout << "\n";
			}

			void heapify()
			{
				sort_heap();
				int size = m_size;
				while(size > 1)
				{
					std::swap(m_arr[1], m_arr[size--]);	
					shift_down(1, size);
				}
			}

		protected:
			void shift_up(int index)
			{
				T tmpValue = m_arr[index];
				while(index >= 1)
				{
					int k = index/2;
					if(k >= 1 && m_arr[k] > tmpValue)
					{
						m_arr[index] = m_arr[k];
						index /= 2;
					}
					else
					{
						m_arr[index] = tmpValue;
						break;	
					}
				}
			}

			void shift_down(int index)
			{
				T tmpValue = m_arr[index];
				int k = 0; 
				while((k = 2*index) <= m_size)
				{
					if(k+1 <= m_size && m_arr[k+1] < m_arr[k])
						k += 1;
					if(m_arr[k] < tmpValue)
					{
						m_arr[index] = m_arr[k];
						index = k;
					}
					else
					{
						break;
					}
				}
				m_arr[index] = tmpValue;
			}

			void shift_down(int index, int size)
			{
				int tmpValue = m_arr[index];
				int k = 0;
				while((k=2*index) <= size)
				{
					if(k+1 <= size && m_arr[k+1] > m_arr[k])
						k += 1;
					if(m_arr[k] < tmpValue)
					{
						break;
					}
					else
					{
						m_arr[index] = m_arr[k];
						index = k;
					}
				}
				m_arr[index] = tmpValue;
			}
		private:
			T *m_arr;
			int m_capacity;
			int m_size;
	};

	template <typename T>
	void heapSort(T arr[], int n)
	{
		MinHeap<int> minHeap(n+1);
		minHeap.add_to_heap(arr, n);
		int k = 0;
		while(n-- > 0)
		{
			arr[k++] = minHeap.get_min_element(); 
		}
	}
};
#endif

#if 0
int main()
{
	heap_sort::MinHeap<int> minHeap(20);
	int count = 10;
	int arr[count] = {5,4,1,7,18,8,38,62,9,2};

	std::cout << "Befor sort:\n";
	for(auto v: arr)
		std::cout << v << " ";
	std::cout << "\n";

	std::cout << "After sort:\n";
	minHeap.add_to_heap(arr, count);
	std::cout << "Heap size is : " << minHeap.size() << "\n";
	// for(int i=0; i<count; i++)
	// {
	// 	int minValue = minHeap.get_min_element();
	// 	std::cout << minValue << " ";
	// }
	// std::cout << "\n";
	minHeap.heapify();
	minHeap.print_heap();
}
#endif
