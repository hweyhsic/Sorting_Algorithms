//#include "bst.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>

void print_vector( std::vector<int> vec )
{
	for( int i = 0; i < vec.size(); ++i )
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void generate_vector( std::vector<int> &vec, int size )
{
	//creating random device
	std::random_device rand;
	std::mt19937 g(rand());

	for( int i = 0; i < size; ++i )
	{
		vec.push_back( i );
	}

	std::shuffle( vec.begin(), vec.end(), g );
}
		
void bubble_sort( std::vector<int> &vec )
{
	bool swapped = false;
	if( vec.size() < 2 )
	{
		return;
	}

	for( int outer = 0; outer < vec.size(); ++outer )
	{
		swapped = false;
		for( int i = 0; i < vec.size() - 1; ++i )
		{
			std::cout << "i: " << vec[i] << ", i+1: " << vec[i+1] << std::endl;
			if( vec[i] > vec[i+1] )
			{
				swapped = true;
				std::swap( vec[i], vec[i+1] );
			}
		}

		//This is to make it O(n) when sorted:
		if( swapped == false )
		{
			std::cout << "no more swaps to perform, it's sorted" << std::endl;
			return;
		}
	}
}
		

int main()
{
	int size = 10;
	//std::cout << "Vector size? " << std::endl;
	//std::cin << size;
	std::vector<int> unsorted;
	std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	generate_vector( unsorted, size );

	print_vector( unsorted );
	bubble_sort( unsorted ); //this is a dumb O(n^2) algorithm, doesn't stop if there are no swaps
	print_vector( unsorted );

	std::cout << "testing if it breaks early" << std::endl;
	print_vector( sorted );
	bubble_sort( sorted );

	return 0;
}
