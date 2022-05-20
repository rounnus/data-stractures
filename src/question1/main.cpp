#include <random>
#include <functional>
#include <memory.h>

#include "linkedlist.h"


struct histogram_data
{
	int number;	// The number.
	int freq;	// The frequency of the number.
};


// Fills the list with random numbers.
static inline void fill_random(ds_ex::Chain<int>& list, size_t size)
{
	// Declare random engine.
	std::default_random_engine generator;
	std::uniform_int_distribution<int> data_element_distribution(0, 100);
	auto random_element = std::bind(data_element_distribution, generator);

	// for the size of the list, generate elements.
	for (int i = 0; i < size; i++)
	{
		list.insert_element(i, random_element());
	}
}


// prints all the numbers with the coresponded frequency.
static inline void print_histogram_list(ds_ex::Chain<struct histogram_data>& src)
{
	if (src.is_empty()) return;

	
	struct histogram_data tmp;
	memset(&tmp, 0x0, sizeof(tmp));

	std::cout << "N = Number, F = Frequency" << std::endl << std::endl;
	for (int i = 1; i < src.length() + 1; i++)
	{
		src.find(i, tmp);
		std::cout << "N: " << tmp.number << std::endl
			  << "F: " << tmp.freq   << std::endl << std::endl;
	}
}

/**
	Bubble sort implementetion
*/
template <class T>
static void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
static void bubble_sort(T a[], int n)
{
	for (int i = n; i > 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

// Checks if an number is already in records.
static inline bool is_in_records(struct histogram_data *recs, int number, 
				 size_t size)
{
	for (int i = 0; i < size; i++)
	{
		if (recs[i].number == number) 
		{
			// increase the number of times that number has appeared.
			recs[i].freq += 1;
			return true;
		} 
	}
	return false;
}


/**
	Find how many times a number apears in the src list and 
	save that info in dst list.
	@param src The list with the numbers
	@param dst The list where we store the number frequencies.
*/
static void number_frequency(ds_ex::Chain<int>& src, ds_ex::Chain<struct histogram_data>& dst,
			     size_t size)
{

	int retv_num;
	int *sorted_nums = new int[size];
	

	struct histogram_data *records;
	struct histogram_data tmp_data;
	size_t histogram_size = 0;
	

	for (int i = 1; i < size + 1; i++)
	{		
		// retrieve the number from L list.
		src.find(i, retv_num);
		sorted_nums[i - 1] = retv_num;
	}

	// sort numbers.
	bubble_sort(sorted_nums, size);

	// allocate space for records.
	records = new struct histogram_data[size];
	
	int c_el = 0;
	int c_rec = 0;

	while (c_el < size)
	{
		++c_el;
		if ((c_el - 1) == 0)
		{
			records[c_rec].number = sorted_nums[c_el - 1];
			records[c_rec].freq   = 1;
			++c_rec;
			continue;
		}

		if (is_in_records(records, sorted_nums[c_el - 1], size)) 
			continue;
	
		// configure new records.	
		records[c_rec].number = sorted_nums[c_el - 1];
		records[c_rec].freq   = 1;
		++c_rec;
	}

	// save records.
	for (int r = 0; r < c_rec; r++)
	{
		dst.insert_element(r, records[r]);
	}
	
	print_histogram_list(dst);
	delete[] records;
}


int main(int argc, char *argv[])
{
	// declare the lists.
	ds_ex::Chain<int> list_l; // The L list.
 	ds_ex::Chain<struct histogram_data> list_h; // Histogram list.

	// ask the user to give the number of elements for the list.
	int number_of_el;
	std::cout << "Give the number of elements for list L: ";
	std::cin >> number_of_el;
	std::cout << std::endl;

	// fill the list_l.
	fill_random(list_l, number_of_el);
	number_frequency(list_l, list_h, number_of_el);	

	return 0;
}
