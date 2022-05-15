#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class Node
{
	private:
		T data;
		Node<T> *next;
};

template <class T>
class Chain
{
	private:
		Node<T> *first;
	
	public:
		Chain() { first = 0; }
		~Chain();

		bool is_empty() const { return first == 0; }
		int length() const;
		bool find(int k, T& x) const;
		int search(const T& x) const;
		
		Chain<T>& delete_element(int k, T& x);
		Chain<T>& insert_element(int k, const T& x);
		
		void output(std::ostream& out) const;
};




#endif
