/*******************
 * 1 2 8 9**********
 * 2 4 9 12*********
 * 4 7 10 13********
 * 6 8 11 15********
 * ****************/
#include <iostream>
#include <vector>

bool find_num_in_array()
{
	int n;
	std::cout << "Please input the array dimension : ";
	std::cin >> n;
	int value;
	std::vector<std::vector<int>> vec;
	std::vector<int> row_vec;
	for(int i=0; i<n; i++)
	{
		for(int i=0; i<n; i++)
		{
			std::cin >> value;
			row_vec.push_back(value);			
		}
		vec.push_back(row_vec);
		row_vec.clear();
	}
	int num;
	std::cout << "Input the number you want to find : ";
	std::cin >> num;

	int col = 0;
	int row = 0;
	for(col=0; col<n; col++)
	{
		if(num < vec[0][col])
			break;
		else if(num == vec[0][col])
		{
			return true;
		}
	}
	if(col == n)
	{
		for(int i=0; i<n; i++)
		{
			if(vec[i][n-1] == num)
				return true;
		}
		return false;
	}

	for(row=0; (col >= 0 && row<n); row++)
	{
		if(num < vec[row][col])
		{
			col--;
			row--;
			continue;
		}
		else if(num == vec[row][col])
		{
			return true;
		}
	}
	return false;
}

bool find_num(int *arr, int dimension, int value)
{
	bool ret = false;
	int row = 0;
	int col = dimension-1;
	int tmpValue;
	while(0 <= col && row < dimension)
	{
		int tmpValue = arr[dimension*row+col];
		if(tmpValue == value)
		{
			ret = true;
			break;
		}
		else if(tmpValue > value)
		{
			col--;
		}
		else
		{
			row++;
		}	
	}

	return ret;
}

int main()	
{
#if 0
	if(find_num_in_array())
		std::cout << "Find it\n";
	else
		std::cout << "Not find it\n";
#else
	int n;
	int value;
	int num;
	std::cout << "Please input the dimension of the array : ";
	std::cin >> n;
	int *arr = new int[n];
	for(int i=0; i<n*n; i++)
	{
		std::cin >> value;
		arr[i] = value;
	}
	std::cout << "Input the number you want to find : ";
	std::cin >> num;
	if(find_num(arr, n, num))
		std::cout << "Find it\n";
	else
		std::cout << "Not find it\n";
#endif
	return 0;
}

