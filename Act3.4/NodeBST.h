// =================================================================
//
// File: NodeBST.h
// Team: 2
// Author: Adrián Eugenio García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: David Emiliano Mireles Cárdenas - A01633729
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 24/10/2021
//
// =================================================================
#ifndef NODEBST_H
#define NODEBST_H

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class NodeBST
{
public:
	NodeBST(T data);
	NodeBST(T data, NodeBST<T> *left, NodeBST<T> *right);
	T getData() const;
	NodeBST<T> *getLeft() const;
	NodeBST<T> *getRight() const;
	void setData(T data);
	void setLeft(NodeBST<T> *left);
	void setRight(NodeBST<T> *right);

private:
	T data;
	NodeBST<T> *left;
	NodeBST<T> *right;
};

// =================================================================
// Constructor. Initializes the value of the node. The variables
// left and right a initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
NodeBST<T>::NodeBST(T val) : data(val), left(nullptr), right(nullptr)
{
}

// =================================================================
// Constructor. Initializes all instances variables.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
NodeBST<T>::NodeBST(T val, NodeBST<T> *lft, NodeBST<T> *rght) : data(val), left(lft), right(rght)
{
}

// =================================================================
// Gets the data stored in the node.
//
// returns data
// =================================================================
template <class T>
T NodeBST<T>::getData() const
{
	return data;
}

// =================================================================
// Gets the left child of the node.
//
// returns node, corresponding to the left child.
// =================================================================
template <class T>
NodeBST<T> *NodeBST<T>::getLeft() const
{
	return left;
}

// =================================================================
// Gets the right child of the node.
//
// returns node, corresponding to the right child.
// =================================================================
template <class T>
NodeBST<T> *NodeBST<T>::getRight() const
{
	return right;
}

// =================================================================
// Sets the data of the node to val.
//
// @param val, value to be stored in the node.
// =================================================================
template <class T>
void NodeBST<T>::setData(T val)
{
	data = val;
}

// =================================================================
// Sets the left child of the node to lft.
//
// @param lft, new left child of the node.
// =================================================================
template <class T>
void NodeBST<T>::setLeft(NodeBST<T> *lft)
{
	left = lft;
}

// =================================================================
// Sets the left child of the node to rght.
//
// @param rght, new right child of the node.
// =================================================================
template <class T>
void NodeBST<T>::setRight(NodeBST<T> *rght)
{
	right = rght;
}
#endif /* NODEBST_H */