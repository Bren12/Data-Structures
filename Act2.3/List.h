// =================================================================
//
// File: main.cpp
// Author: Adrían García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: Eduardo de la Rosa Flores - A01039969 
// Date: 13/10/2021
//
// =================================================================
#ifndef LIST_H
#define LIST_H

#include <string>

template <class T>
class List;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
	private:
		Node(T);
		Node(T, Node<T> *);

		T data;
		Node<T> *next;

		friend class List<T>;
};

// =================================================================
// Constructor. Initializes the data of the node. The variable next
// is initialized to nullptr.
//
// @param val, stored data in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : data(val), next(nullptr) {}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored data in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *nxt) : data(val), next(nxt) {}




// =================================================================
// Definition of the List class
// =================================================================
template <class T>
class List {
	private:
		Node<T> *head;
		int size;

	public:
		List();
		~List();

		int length() const;
		void create(T);
		void create(T, int);
		T get(int) const;
		void clear();
		int indexOrder(T val);
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
List<T>::List() : head(nullptr), size(0) {}

// =================================================================
// Destructor. Removes all items from the list.
// =================================================================
template <class T>
List<T>::~List() {
	clear();
}

// =================================================================
// Adds an element at the start of the linked list. The element that
// was at the begining is shifted to the right.
//
// @param val, objeto que se desea agregar.
//
// Worst case complexity: O(1).
// =================================================================
template <class T>
void List<T>::create(T val) {
	head = new Node<T>(val,head);
	size++;
}

// =================================================================
// Adds an element in index (0 <= index <= size). The element that
// was in that position is shifted to the right.
//
// @param val, objeto que se desea agregar.
// @param index, posición en la que se desea insertar el objeto en la lista.
//
// Worst case complexity: O(n).
// =================================================================
template <class T>
void List<T>::create(T val, int index) {
	if (index == 0) {
		create(val);
	}
	else if (index > 0 && index <= size) {
		Node<T> *curr = head;
		for (int i = 1; i < index; i++) {
			curr = curr->next;
		}
		curr->next = new Node<T>(val,curr->next);
		size++;
	}
}

// =================================================================
// Agrega un elemento en la lista de forma ordenada y de manera ascendente,
// este método solo aplica para datos de tipo númerico.
//
// @param val, objeto que se desea agregar y ordenar en la lista.
// @returns la posición del elemento agregado en la lista.
//
// Worst case complexity: O(n^2).
// =================================================================
template <class T>
int List<T>::indexOrder(T val) {
	int acum = 0;
	Node<T> *curr = head;
	for (int i = 0; i < size; i++) {
		if (curr->data < val) {
			acum++;
		}
		curr = curr->next;
	}
	create(val,acum);
	return acum;
}

// =================================================================
// Returns the value of an item at the given position in the list.
//
// @param index, posición de la cual se desea saber el valor.
// @returns the value of an item at the given position in the list.
//
// Worst case complexity: O(n).
// =================================================================
template <class T>
T List<T>::get(int index) const {
	Node<T> *curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}

// =================================================================
// Removes all the items from the list.
//
// Worst case complexity: O(n).
// =================================================================
template <class T>
void List<T>::clear() {
	Node<T> *curr = head;
	while (size != 0) {
		head = head->next;
		delete curr;
		curr = head;
		size--;
	}
}

// =================================================================
// Returns the number of items in the list.
//
// @returns size, the number of items in the list.
//
// Worst case complexity: O(1).
// =================================================================
template <class T>
int List<T>::length() const {
	return size;
}

#endif /* LIST_H */