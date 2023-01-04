// =================================================================
//
// File: BST.h
// Team: 2
// Author: Adrián Eugenio García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: David Emiliano Mireles Cárdenas - A01633729
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 24/10/2021
//
// =================================================================
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;
#include "NodeBST.h"
#include <stack>
#include <queue>

// =================================================================
// Definition of the Binary Search Tree class
// =================================================================
class BST
{
public:
    BST();
    ~BST();
    bool search(int data);
    void add(int data, string pref);
    void remove(int data);
    void print(int recorrido);
    int size();
    int getLevel(int data);
    void ancestors(int data);
    int height();

private:
    NodeBST<int> *root;
    NodeBST<string> *rootPrefix;
    int howManyChildren(NodeBST<int> *node);
    int succesor(NodeBST<int> *node);
    int predecesor(NodeBST<int> *node);
    void preOrder(NodeBST<int> *node);
    void inOrder(NodeBST<int> *node, NodeBST<string> *nodeP);
    void postOrder(NodeBST<int> *node);
    void levelByLevel(NodeBST<int> *node);
    void clear(NodeBST<int> *node);
    int sizeHelper(NodeBST<int> *node);
    int hightHelper(NodeBST<int> *node);
};

// =================================================================
// Constructor. Initializes the root to nullptr.
//
// =================================================================
BST::BST()
{
    root = nullptr;
}

// =================================================================
// Destructor. Deletes the nodes contained in the BST.
//
// =================================================================
BST::~BST()
{
    clear(root);
    root = nullptr;
}

// =================================================================
// Elimina todos los nodos del árbol.
//
// @param r, el nodo a eliminar.
// =================================================================
void BST::clear(NodeBST<int> *r)
{
    if (r != nullptr)
    {
        clear(r->getLeft());
        clear(r->getRight());
        delete r;
    }
}

// =================================================================
// Finds the correct successor of a node within the BST.
//
// @param r, el nodo a determinar el correcto sucesor.
// returns the successor node of a node.
// =================================================================
int BST::succesor(NodeBST<int> *r)
{
    NodeBST<int> *curr = r->getRight();
    while (curr->getLeft() != nullptr)
    {
        curr = curr->getLeft();
    }
    return curr->getData();
}

// =================================================================
// Finds the predecessor of a node within the BST.
//
// @param r, el nodo a determinar el correcto predecesor.
// returns the predecessor node of a node.
// =================================================================
int BST::predecesor(NodeBST<int> *r)
{
    NodeBST<int> *curr = r->getLeft();
    while (curr->getRight() != nullptr)
    {
        curr = curr->getRight();
    }
    return curr->getData();
}

// =================================================================
// Search for an element within the BST.
//
// @param data, the searched element.
// returns True, if the element is in the BST. False, otherwise.
// =================================================================
bool BST::search(int data)
{
    NodeBST<int> *curr = root;

    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            return true;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    return false;
}

// =================================================================
// Add an element within the bst.
//
// @param data, the element to be inserted.
// =================================================================
void BST::add(int data, string pref) {

    if (data >= 10) {
        NodeBST<int> *curr = root;
        NodeBST<int> *father = nullptr;
        NodeBST<string> *currP = rootPrefix;
        NodeBST<string> *fatherP = nullptr;

        while (curr != nullptr) {
            father = curr;
            fatherP = currP;
            currP = (curr->getData() > data) ? currP->getLeft() : currP->getRight();
            curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        }

        if (father == nullptr) {
            root = new NodeBST<int>(data);
            rootPrefix = new NodeBST<string>(pref);
        }
        else {
            (father->getData() > data) ? father->setLeft(new NodeBST<int>(data)) : father->setRight(new NodeBST<int>(data));
            (father->getData() > data) ? fatherP->setLeft(new NodeBST<string>(pref)) : fatherP->setRight(new NodeBST<string>(pref));
        }
    }
    
}

// =================================================================
// Remove an element, putting a succesor node in its place.
//
// @param data, the element to be removed.
// =================================================================
void BST::remove(int data)
{
    NodeBST<int> *curr = root;
    NodeBST<int> *father = nullptr;

    while (curr != nullptr && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr)
    {
        return;
    }

    int children = howManyChildren(curr);

    switch (children)
    {
    case 0:
        if (father == nullptr)
        {
            root = nullptr;
        }
        else
        {
            if (data < father->getData())
            {
                father->setLeft(nullptr);
            }
            else
            {
                father->setRight(nullptr);
            }
        }
        delete curr;
        break;
    case 1:
        if (father == nullptr)
        {
            if (curr->getLeft() != nullptr)
            {
                root = curr->getLeft();
            }
            else
            {
                root = curr->getRight();
            }
        }
        else
        {
            if (father->getData() > data)
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setLeft(curr->getLeft());
                }
                else
                {
                    father->setLeft(curr->getRight());
                }
            }
            else
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setRight(curr->getLeft());
                }
                else
                {
                    father->setRight(curr->getRight());
                }
            }
        }
        delete curr;
        break;
    case 2:
        int succ = succesor(curr);
        remove(succ);
        curr->setData(succ);
        break;
    }
}

// =================================================================
// Gets the number of children of a given node.
//
// @param node, the node to determine the number of children.
// =================================================================
int BST::howManyChildren(NodeBST<int> *node)
{
    int children = 0;

    if (node->getLeft() != nullptr)
    {
        children++;
    }
    if (node->getRight() != nullptr)
    {
        children++;
    }
    return children;
}

// =================================================================
// Print the elements from the bst in preorder, inorder, or
// postorder.
//
// @param recorrido, type of traversal:
//          1 - preOrder
//          2 - inOrder
//          3 - postOrder
//          4 - levelByLevel
// =================================================================
void BST::print(int recorrido)
{
    switch (recorrido)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root, rootPrefix);
        break;
    case 3:
        postOrder(root);
        break;
    case 4:
        levelByLevel(root);
        break;
    }
}

// =================================================================
// Print the tree in preorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::preOrder(NodeBST<int> *node)
{
    if (node != nullptr)
    {
        cout << node->getData() << " ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

// =================================================================
// Print the tree in inorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::inOrder(NodeBST<int> *node, NodeBST<string> *nodeP) {
    if (node != nullptr) {
        inOrder(node->getRight(), nodeP->getRight());
        cout << nodeP->getData() << " ";
        cout << node->getData() << endl;
        inOrder(node->getLeft(), nodeP->getLeft());
    }
}

// =================================================================
// Print the tree in postorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::postOrder(NodeBST<int> *node)
{
    if (node != nullptr)
    {
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getData() << " ";
    }
}

// =================================================================
// Gets the number of nodes in the BST.
//
// returns size of the BST.
// =================================================================
int BST::size()
{
    return sizeHelper(root);
}

// =================================================================
// Gets the number of nodes descendants of a node in the BST.
//
// @param node, el nodo a determinar el número de descendientes.
// returns the number of descendats of a node.
// =================================================================
int BST::sizeHelper(NodeBST<int> *node)
{
    if (node != nullptr)
    {
        return 1 + sizeHelper(node->getLeft()) + sizeHelper(node->getRight());
    }
    else
    {
        return 0;
    }
}

// =================================================================
// Print the tree level by level.
//
// @param node, the node to be traversed.
//
// Worst case complexity: O(n), porque recorre el árbol "n" veces, ya que depende del número de elementos en él.
// =================================================================
void BST::levelByLevel(NodeBST<int> *node) {
    /*
    Meter el nodo raiz a una fila.
    Mientras la fila no se vacie:
    - Sacar un nodo de nuestra fila y lo procesamos
    - Meter a la fila los hijos del nodo procesado (si existen los hijos)
    */

   // Queue -> first in, first out.
   queue<NodeBST<int>*> fila;
   // Empiezamos desde la raíz.
   fila.push(root);

   // Mientras la fila no este vacia.
   // Imprimimos nuestra fila.
   while (!fila.empty()) {
       // Imprime el primer elemento ingresado en la fila.
       cout << fila.front()->getData();

       // Si el lado izquierdo de la raíz actual no esta vacio.
       if (fila.front()->getLeft() != nullptr) {
           // Se agrega a la fila el lado izquierdo de la raíz.
           fila.push(fila.front()->getLeft());
       }
       // Si el lado derecho de la raíz actual no esta vacio.
       if (fila.front()->getRight() != nullptr) {
           // Se agrega a la fila el lado derecho de la raíz.
           fila.push(fila.front()->getRight());
       }

       // Se elimina el primer elemento ingresado en la fila.
       fila.pop();

       // Para llevar un control de espacios.
       // Si la fila esta vacia, no imprimir el espacio.
       if (!fila.empty()) {
            cout << " ";
        }
   }
}

// =================================================================
// Gets the height of the BST.
//
// returns the height of the BST.
// Worst case complexity: O(n), porque llama a un método que tiene esta complejidad.
// =================================================================
int BST::height() {
    return hightHelper(root);
}

// =================================================================
// Prints the ancestros of a node in the BST.
//
// @param data, el valor del nodo a saber sus ancestros.
//
// Worst case complexity: O(height), porque recorre el árbol dependiendo del número de niveles en él.
// =================================================================
void BST::ancestors(int data) {
    // Stack -> last in, first out.
    stack<int> pila;
    // Empezamos desde la raíz.
    NodeBST<int> *curr = root;

    // Vamos revisando que haya nodos descendientes.
    // Mientras no sea nulo.
    while (curr != nullptr) {
        // Revisamos que el dato que estamos buscando este guardado en curr.
        if (curr->getData() == data) {

            // Mientras la pila no este vacia.
            // Imprimimos nuestra pila.
            while (!pila.empty()) {
                // Imprime el último elemento ingresado en la pila.
                cout << pila.top();

                // Elimina el último elemento ingresado en la pila.
                pila.pop();

                // Para llevar un control de espacios.
                // Si la pila esta vacia, no imprimir el espacio.
                if (!pila.empty()) {
                    cout << " ";
                }
            }

            // Nos regresamos.
            return;
        }

        // Vamos metiendo a la pila.
        pila.push(curr->getData());
        // Avanzamos depedendiendo del dato con respecto al nodo actual.
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
}

// =================================================================
// Gets the level of a value in the BST.
//
// @param data, el valor del nodo a saber el nivel en el que se encuentra.
// returns the level at which the given data is stored, or -1
//         if the data was not found.
//
// Worst case complexity: O(height), porque recorre el árbol dependiendo del número de niveles en él.
// =================================================================
int BST::getLevel(int data) {
    // Tenemos que contar el número de ancestros.
    int contNivel = 0;
    // Empezamos desde la raíz.
    NodeBST<int> *curr = root;

    // Vamos revisando que haya nodos descendientes.
    while (curr != nullptr) {
        // Si encontramos nuestro dato regresamos contNivel.
        if (curr->getData() == data) {
            return contNivel;
        }
        // Si no, aumentamos contNivel++ y avanzamos depedendiendo del dato con respecto al nodo actual.
        else {
            contNivel++;
            curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        }
        
    }

    // Si no encontramos el dato.
    return -1;
}

// =================================================================
// Obtiene el número de niveles del árbol.
//
// @param node, el nodo a determinar su número máximo de niveles.
// retorna el número máximo de niveles en el árbol.
//
// Worst case complexity: O(n), porque recorre el árbol "n" veces, ya que depende del número de elementos en él.
// =================================================================
int BST::hightHelper(NodeBST<int> *node) {
    // Vamos revisando que haya nodos descendientes.
    if (node != nullptr) {
        // Nos cuenta la altura del sub-árbol izquierdo.
        int izq = hightHelper(node->getLeft()) + 1;
        // Nos cuenta la altura del sub-árbol derecho.
        int der = hightHelper(node->getRight()) + 1;
        // Máximo(izquierda, derecha) + 1;
        return 1 + (izq > der) ? izq : der;
    }
    else {
        return 0;
    }
}

#endif /* BST_H */