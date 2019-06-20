//#include "bst.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>
#include <cmath>

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
		
//A list of the sorting algorithms
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
			return;
		}
	}
}

//Insertion sort has a sorted partition and an unsorted partition
void insertion_sort( std::vector<int> &vec )
{
	int size = vec.size();
	int sorted_size = 1;

	//Breaking if the vector is 0 or 1 elements in size
	if( vec.size() < 2 )
		return;

	for( int i = 1; i < size; ++i )
	{
		int j = i;
		while( j > 0 && vec[j] < vec[j-1] )
		{
			std::swap( vec[j], vec[j-1] );
			--j;
		}
	}
}

//Selection sort: pick the max every time
void selection_sort( std::vector<int> &vec )
{
	int max = -1;
	int max_ind = -1;
	for( int outer = vec.size()-1; outer > 0; --outer )
	{
		for( int i = 0; i <= outer; ++i )
		{
			if( vec[i] > max )
			{
				max = vec[i];
				max_ind = i;
			}
		}
		//std::cout << "new max: " << max << "("<< vec[max_ind] << ", at " << max_ind << std::endl;
		//print_vector( vec );
		std::swap( vec[max_ind], vec[outer] );
		//print_vector( vec );
		max = -1;
		max_ind = -1;
	}
}


/* DIVIDE AND CONQUEROR */












/* TREE SORTING ALGOS */
void heapify( int i, std::vector<int> &t )
{
	//case where there are not enough children
	if( i*2 + 1 > t.size() )
		return;
	else
	{
		if( t[i] < t[i*2 + 1] )
		{
			std::cout << "swap " << t[i] << " & " << t[i*2+1] << std::endl;
			std::swap( t[i], t[i*2 + 1] );
		}
		if( i*2 + 2 > t.size() )
			return;
		else if( t[i] < t[i*2 + 2] )
		{
			std::cout << "swap " << t[i] << " & " << t[i*2+1] << std::endl;
			std::swap( t[i], t[i*2 + 1] );
		}
	}

}

void heapify_vector( std::vector<int> &t )
{
	for( int i = std::ceil( (t.size()-1) / 2 ); i >= 0; --i )
	{
		std::cout << "n: " << i << std::endl;
		heapify( i, t );
	}
}











int main()
{
	int size = 10;
	//std::cout << "Vector size? " << std::endl;
	//std::cin << size;
	std::vector<int> unsorted;
	//std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	generate_vector( unsorted, size );
	
	
	//Unsorted tree:


	print_vector( unsorted );
	//bubble_sort( unsorted ); //this is a dumb O(n^2) algorithm, doesn't stop if there are no swaps
	//insertion_sort( unsorted );
	//selection_sort( unsorted );
	//
	//Divide and conqueror sorts:
	//quick_sort( unsorted );
	//merge_sort( unsorted );
	
	//heap_sort( unsorted );
	//
	//tree_sort( unsorted );
	heapify_vector( unsorted );
	print_vector( unsorted );

	return 0;
}
