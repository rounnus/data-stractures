#include <iostream>
#include <random>
#include <functional>
#include <stdlib.h>

#include "maxheap.h"
#include "minheap.h"

/**
	This function fills the two arrays
	with the same random float elements.
	@param max The array that is going to be the max heap.
	@param min The array that is going to be the min heap.
*/
static void fill_heaps_with_random(float max[], float min[],
				   size_t size)
{
	std::default_random_engine generator;	
	std::chi_squared_distribution<float> my_distribution(0.5);

	auto random_num = std::bind(my_distribution, generator);
	
	float curr_random;
	for (int i = 0; i < size; i++) {
		curr_random = random_num() * 10000.0;
		max[i] = curr_random;
		min[i] = curr_random;
	}
}


static inline void add_float_using_max()
{


}

static inline void add_float_using_min()
{


}


int main()
{
	// get the size of array from user.
	int n;
	std::cout << "Give the number of numbers: ";
	std::cin >> n;
	std::cout << std::endl;

	// The arrays that holds the numbers. ( before becomes heaps )
	float *max_array = new float[n];
	float *min_array = new float[n];

	// fill the arrays with random float numbers.
	fill_heaps_with_random(max_array, min_array, n);

	// convert arrays into max and min heaps.
	ds_ex::Max_Heap<float> max_heap;
	ds_ex::Min_Heap<float> min_heap;

	max_heap.initialize(max_array, n, n);
	min_heap.initialize(min_array, n, n);


	return 0;
}
