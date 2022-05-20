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


static inline void add_float_using_max(ds_ex::Max_Heap<float>& max_h)
{

	float f1;
	float f2;

	float sum;
	while (max_h.size() != 0)
	{
		// retrieve the first num to add.
		max_h.delete_max(f1);
		
		if (max_h.size() == 0) break;
		// retrieve the second num to add.
		max_h.delete_max(f2);
	
		// add the numbers.
		sum = f1 + f2;
		max_h.insert_element(sum);
	}

	std::cout << "The result of adding floats using max heap is: " << f1 << std::endl;
}

static inline void add_float_using_min(ds_ex::Min_Heap<float>& min_h)
{
	float f1;
	float f2;

	float sum;
	while (min_h.size() != 0)
	{
		// retrieve the first num to add.
		min_h.delete_min(f1);

		if (min_h.size() == 0) break;
		// retrieve the second num to add.
		min_h.delete_min(f2);
	
		// add the numbers.
		sum = f1 + f2;
		min_h.insert_element(sum);
	}

	std::cout << "The result of adding floats using min heap is: " << f1 << std::endl;


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

	add_float_using_min(min_heap);
	add_float_using_max(max_heap);

	return 0;
}
