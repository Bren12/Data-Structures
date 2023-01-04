// =================================================================
//
// File: HashTable.h
// Equipo: 2
// Date: 26/11/2021
//
// =================================================================
#include <vector>
#include <iostream>
#include "LinkedList.h"
using namespace std;

/*
* Definition of the HashTable class
*/
template <class KeyType, class ValueType>
class HashTable {
	private:
		vector<LinkedList<KeyType, ValueType>> table;
		int storage;
		int size;

	public:
		HashTable(int);
		void insert(KeyType, ValueType, int);
		void erase(KeyType);
		KeyType get(ValueType, int);
		int getSize();
		string toString();
};

/*
* Constructor. Initializes the HashTable.
*
* @param max, size of the table.
*/
template <class KeyType, class ValueType>
HashTable<KeyType, ValueType>::HashTable(int max) {
	size = 0;
	storage = max;
	table.resize(max);
}

/*
* Agrega un nuevo elemento con la llave (key) y valor (value) dado, en el HashTable.
*
* @param key, llave a ser agregada en la tabla.
* @param value, valor de la llave a ser agregada en la tabla.
*/
template <class KeyType, class ValueType>
void HashTable<KeyType, ValueType>::insert(KeyType key, ValueType value, int pos) {
	// Se hashing y se agrega el nuevo elemento
	table[pos%storage].create(key,value);

	// Se incrementa el tamaño
	size++;
}

/*
* Erases the element with the given key value from the HashTable.
*
* @param key, key to be erased.
*/
template <class KeyType, class ValueType>
void HashTable<KeyType, ValueType>::erase(KeyType key) {
	// Hashing -> Residual Method
	int i = key%storage;
	
	// Se elimina el nuevo elemento
	table[i].clear(key);
	
	// Se decrementa el tamaño
	size--;
}

/*
* Returns the value associated to a certain key.
*
* @param key, key assocaited to a certain value.
*/
template <class KeyType, class ValueType>
KeyType HashTable<KeyType, ValueType>::get(ValueType value, int pos) {
	// Hashing -> Residual Method
	return table[pos%storage].get(value);
}

/*
* Returns the number of elements in the HashTable.
*/
template <class KeyType, class ValueType>
int HashTable<KeyType, ValueType>::getSize() {
	return size;
}

/*
* Returns the string representation of the HashTable.
*/
template <class KeyType, class ValueType>
string HashTable<KeyType, ValueType>::toString() {
	stringstream aux;
	Node<KeyType, ValueType> *p;

	for (int i = 0; i < storage; i++) {
		aux << table[i].toString() << endl;
	}

	return aux.str();
}