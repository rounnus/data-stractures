#ifndef MAX_HEAP_H
#define MAX_HEAP_H

 /**
	The below classes has been found in the book
	of data stractures.
	@book Data stractures, algorithms and applications in c++
*/


namespace ds_ex
{
#ifndef HEAP_EXCEPTIONS
#define HEAP_EXCEPTIONS

	class Out_Of_Bounds
	{
		public:
			Out_Of_Bounds() {}
	};

	class No_Mem
	{
		public:
			No_Mem() {}
	};
#endif
	
	template <class T>
	class Max_Heap
	{
		private:
			int current_size;
			int max_size;
			T *heap;

		public:
			Max_Heap(int mex_heap_size = 10);
			~Max_Heap() { delete[] heap; }
		
			int size() const { return current_size; }

			T max()
			{
				if (current_size == 0)
				{
					throw Out_Of_Bounds();
				}
				return heap[1];
			}

			Max_Heap<T>& insert_element(const T& x);
			Max_Heap<T>& delete_max(T& x);
			
			void initialize(T a[], int size, int array_size);
	};

	
	template <class T>
	Max_Heap<T>::Max_Heap(int max_heap_size)
	{
		max_size = max_heap_size;
		heap = new T[max_heap_size + 1];
		current_size = 0;
	}

	template <class T>
	Max_Heap<T>& Max_Heap<T>::insert_element(const T& x)
	{
		if (current_size == max_size) throw No_Mem();
	
		int i = ++current_size;
		while (i != 1 && x > heap[i/2])
		{
			heap[i] = heap[i/2];
			i /= 2;
		}

		heap[i] = x;
		return *this;
	}

	template <class T>
	Max_Heap<T>& Max_Heap<T>::delete_max(T& x)
	{
		if (current_size == 0)
			throw Out_Of_Bounds();

		x = heap[1]; // max element

		T y = heap[current_size --]; // last element.

		int i = 1;
		int ci = 2;

		while (ci <= current_size)
		{
			if (ci < current_size && heap[ci] < heap[ci + 1])
			{
				ci++;
			}
			if (y >= heap[ci]) break;

			heap[i] = heap[ci];
			i = ci;
			ci *= 2;;
		}

		heap[i] = y;

		return *this;
	}

	template <class T>
	void Max_Heap<T>::initialize(T a[], int size, int array_size)
	{
		delete[] heap;
		heap = a;
		current_size = size;
		max_size = array_size;

		for (int i = current_size / 2; i >= 1; i--)
		{
			T y = heap[i];

			int c = 2 * i;
			
			while (c <= current_size)
			{
				if (c < current_size && heap[c] < heap[c + 1])
				{
					c++;
				}

				if (y >= heap[c]) break;

				heap[c/2] = heap[c];
				c *= 2;
			}
				
			heap[c/2] = y;	
		}
	

	}
	
}


#endif
