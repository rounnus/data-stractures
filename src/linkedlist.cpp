#include "linkedlist.h"


class Out_Of_Bounds 
{
	public:
		Out_Of_Bounds() {}
};


template <class T>
Chain<T>::~Chain()
{
	Node<T> *next;
	while (first)
	{
		next = first->next;
		delete first;
		first = next;
	}
}

template <class T>
int Chain<T>::length() const
{
	Node<T> *current = first;
	int len = 0;

	while (current)
	{
		len++;
		current = current->next;
	}
	return len;
}

template <class T>
bool Chain<T>::find(int k, T& x) const
{
	if (k < 1) return false;
	Node<T> *current = first;

	int index = 1;
	while (index < k && current)
	{
		current = current->next;
		index++;
	}

	if (current)
	{
		x = current->data;
		return true;
	}

	return false;
}

template <class T>
int Chain<T>::search(const T& x) const
{
	Node<T> *current = first;

	int index = 1;
	while (current && current->data != x)
	{
		current = current->next;
		index++;
	}

	if (current) return index;

	return 0;
}

template <class T>
void Chain<T>::output(std::ostream& out) const
{

	Node<T> *current;
	for (current = first; current;
	     current = current->next)
	{
		out << current->data << "  ";

	}
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{
	x.output(out);
	return out;
}


template <class T>
Chain<T>& Chain<T>::delete_element(int k, T& x)
{
	if (k < 1 || !first) throw Out_Of_Bounds();

	Node<T> *p = first;

	if (k == 1) first = first->next;
	else
	{
		Node<T> *q = first;
	    	for (int index = 1; index < k - 1 && q; index++)
		{
			q = q->next;
		}

		if (!q || !q->next)
			throw Out_Of_Bounds();

		p = q->next;	
		q->next = p->next;

	}	

	x = p->data;
	delete p;

	return *this;

}

template <class T>
Chain<T>& Chain<T>::insert_element(int k, const T& x)
{
	if (k < 0) throw Out_Of_Bounds();

	Node<T> *p = first;
	for (int index = 1; index < k && p; index++)
	{	
		p = p->next;
	}
	

	if (k > 0 && !p) throw Out_Of_Bounds();
	
	Node<T> *y = new Node<T>;
	y->data = x;

	if (k)
	{
		y->next = p->next;
		p->next = y;
	}
	else
	{
		y->next = first;
		first = y;
	}

	return *this;
}
