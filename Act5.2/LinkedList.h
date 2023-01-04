#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class KeyType, class ValueType>
class LinkedList;

/*
* Definition of the Node class
*/
template <class KeyType, class ValueType>
class Node {
    private:
        Node(KeyType, ValueType);
        Node(KeyType, ValueType, Node<KeyType, ValueType> *);

        KeyType key;
        ValueType value;
        Node<KeyType, ValueType> *next;

        friend class LinkedList<KeyType, ValueType>;
};

/*
* Constructor. Initializes the key of the node. The variable next
* is initialized to nullptr.
*
* @param key, key stored in the node.
* @param value, stored value in the node.
*/
template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node(KeyType key, ValueType value) : key(key), value(value), next(nullptr) {}

/*
* Constructor. Initializes both instance variables.
*
* @param key, key stored in the node.
* @param value, stored value in the node.
* @param next, the next node.
*/
template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node(KeyType key, ValueType value, Node *next) : key(key), value(value), next(next) {}

/*
* Definition of the LinkedList class
*/
template <class KeyType, class ValueType>
class LinkedList {
    private:
        Node<KeyType, ValueType> *head;
        int size;

    public:
        LinkedList();
        ~LinkedList();

        int length() const;
        bool empty() const;

        void create(KeyType, ValueType);
        KeyType get(ValueType) const;
        void clear(KeyType);
        void clear();

        string toString() const;
};

/*
* Constructor. Initializes both instance variables to zero.
*/
template <class KeyType, class ValueType>
LinkedList<KeyType, ValueType>::LinkedList() : head(nullptr), size(0) {}

/*
* Destructor. Removes all items from the LinkedList.
*/
template <class KeyType, class ValueType>
LinkedList<KeyType, ValueType>::~LinkedList() {
    clear();
}

/*
* Returns the number of items in the LinkedList.
*
* @returns size, the number of items in the LinkedList.
*/
template <class KeyType, class ValueType>
int LinkedList<KeyType, ValueType>::length() const {
    return size;
}

/*
* Returns true if the LinkedList is empty or false if not.
*
* @returns true if the LinkedList is empty, false otherwise.
*/
template <class KeyType, class ValueType>
bool LinkedList<KeyType, ValueType>::empty() const {
    return (head == nullptr);
}

/*
* Adds an element at the start of the linked LinkedList. The element that
* was at the begining is shifted to the right.
*/
template <class KeyType, class ValueType>
void LinkedList<KeyType, ValueType>::create(KeyType key, ValueType value) {
    head = new Node<KeyType, ValueType>(key, value, head);
    size++;
}

/*
* Returns the value of an item at the given position in the LinkedList.
*
* @returns the value of an item at the given position in the LinkedList.
*/
template <class KeyType, class ValueType>
KeyType LinkedList<KeyType, ValueType>::get(ValueType value) const {
    Node<KeyType, ValueType> *curr = head;

    while (curr != nullptr) {
    	if (curr->value == value) {
	    	return curr->key;
	}
        curr = curr->next;
    }
    
    return 0;
}

/*
* Removes all the items from the LinkedList.
*/
template <class KeyType, class ValueType>
void LinkedList<KeyType, ValueType>::clear() {
    Node<KeyType, ValueType> *curr, *aux;

    curr = head;
    while (curr != nullptr) {
        aux = curr->next;
        delete curr;
        curr = aux;
    }

    head = nullptr;
    size = 0;
}

/* 
* Deletes the element found in index (0 <= index <size).
*
* @returns the element that was at the index.
*/
template <class KeyType, class ValueType>
void LinkedList<KeyType, ValueType>::clear(KeyType key) {
    Node<KeyType, ValueType> *aux;

    if (head->key == key) {
        aux = head;
        head = head->next;
    }
    else {
        Node<KeyType, ValueType> *curr = head;
        while (curr->next != nullptr && curr->next->key != key)
        {
            curr = curr->next;
        }
        aux = curr->next;
        curr->next = aux->next;
    }

    delete aux;
    size--;
}

/*
* String representation of the elements in the LinkedList.
*
* @returns a string containing all the elements of the LinkedList.
*/
template <class KeyType, class ValueType>
string LinkedList<KeyType, ValueType>::toString() const {
    stringstream aux;
    Node<KeyType, ValueType> *p;

    p = head;
    aux << "[";
    while (p != nullptr) {
        aux << p->value;
        if (p->next != nullptr) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}
