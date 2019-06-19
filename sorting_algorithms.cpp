#include "bst.h"
#include <algorithm>

void print_vector( std::vector<int> vec )
{
	for( int i = 0; i < vec.size(); ++i )
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void bubble_sort( std::vector<int> vec )
{
	if( vec.size() < 2 )
	{
		return vec;
	}

	for( int i = 0; i < vec.size() - 1; ++i )
	{
		if( vec[i] < vec[i+1] )
		{
			std::swap( vec[i], vec[i+1] );
		}
	}
}
		

int main()
{
	std::vector<int> unsorted;

	print_vector( unsorted );
	bubble_sort(unsorted );
	print_vector( unsorted );

	return 0;
}
