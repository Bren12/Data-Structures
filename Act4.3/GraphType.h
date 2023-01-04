// =========================================================
// File: GraphType.h
// Equipo: 2
// Author: Adrián Eugenio García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: David Emiliano Mireles Cárdenas - A01633729
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 23/11/2021
// =========================================================
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
using namespace std;

/************************************************************/
/************************ GraphType *************************/
/************************************************************/
template <class VertexType, class EdgeType>
class GraphType {
    public:
        void addVertex(VertexType);
        void removeVertex(VertexType);
        void addEdge(VertexType, VertexType, EdgeType);
        void removeEdge(VertexType, VertexType);

        int getSize();
        int getIndex(VertexType);
        vector<VertexType> getVertices();
        void getAdjacents(VertexType vertex, queue<VertexType> &);

        bool searchPath(VertexType, VertexType);
        void topologicalSort(stack<VertexType> &);
        bool isCyclic();

		int MNP(VertexType, int);

    protected:
        int size;
        vector<VertexType> vertices;
        vector<vector<EdgeType>> edges;
        bool DFS(VertexType, VertexType);
        bool BFS(VertexType, VertexType);
        bool DFS(VertexType, vector<int> &);
        void DFS(VertexType, vector<bool> &, stack<VertexType> &);

		// void MNPsearch(VertexType, int, vector<VertexType> &);
		void MNPsearch(VertexType origin, int mnp, map<VertexType, bool> &alcanzables, int &cont);
};

/*
* Add a vertex to the graph.
*
* @param vertex, vertex to be added
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::addVertex(VertexType vertex) {
    // Para que no se repitan los vértices en el grafo
	int index = getIndex(vertex);

	// Si no se encontro el vértice, se agrega al grafo
	if (index == -1) {
		vertices[size++] = vertex;

		for (int i = 0; i < size; i++) {
			edges[i][size] = 0;
			edges[size][i] = 0;
		}
	}
	
}

/*
* Remove a vertex from the graph.
*
* @param vertex, vertex to be deleted.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::removeVertex(VertexType vertex) {
    int index = getIndex(vertex);
    VertexType nulo;

    if (index != -1) {
    	// Borra el vertex del vector de vértices
    	for (int i = index; i < size - 1; i++) {
	       vertices[i] = vertices[i + 1];
	    }
	    // Vacía el vertex repetido
	    vertices[size-1] = nulo;

	    // Borra el vertex la matriz de edges
	    for (int i = index; i < size - 1; i++) {
	    	edges[i] = edges[i+1];
	    }

	    // Borra los arcos del vertex de la matriz de edges
	    for (int i = 0; i < size - 1; i++) {
		    for (int j = index; j < size - 1; j++){
		        edges[i][j] = edges[i][j+1];
		    }
		    // Vacía el arco repetido
		    edges[i][size-1] = NULL;
	    }

	    // Vacía el vertex repetido de la matriz de edges
	    for (int i = 0; i < size; i++) {
	    	edges[size-1][i] = NULL;
		}

	    size--;
	}
}

/*
* Add an edge to the graph.
*
* @param fromVertex, vertex from  which the edge points from.
* @param toVertex, vertex to  which the edge points towards.
* @param value, value of the edge.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::addEdge(VertexType fromVertex, VertexType toVertex, EdgeType value) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    edges[row][col] = value;
	edges[col][row] = value;
}

/*
* Remove an edge from the graph.
*
* @param fromVertex, vertex from  which the edge points from.
* @param toVertex, vertex to which the edge points towards.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::removeEdge(VertexType fromVertex, VertexType toVertex) {
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    edges[row][col] = 0;
}

/*
* Get the index of a vertex.
*
* @param vertex, vertex to be located.
* @return index of the vertex.
*/
template <class VertexType, class EdgeType>
int GraphType<VertexType, EdgeType>::getIndex(VertexType vertex) {
    for (int i = 0; i < size; i++)
    {
        if (vertices[i] == vertex)
        {
            return i;
        }
    }

    return -1;
}

/*
* Get the adjacent vertices of a vertex.
*
* @param vertex, vertex to be analyzed.
* @return queue of adjacent vertices.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::getAdjacents(VertexType vertex, queue<VertexType> &adjacents) {

    int fromIndex = getIndex(vertex);

    for (int toIndex = 0; toIndex < size; toIndex++)
    {
        if (edges[fromIndex][toIndex] != false && fromIndex != toIndex)
        {
            adjacents.push(vertices[toIndex]);
        }
    }
}

/*
* Get the vertices of the graph.
*
* @return vertices of the graph.
*/
template <class VertexType, class EdgeType>
vector<VertexType> GraphType<VertexType, EdgeType>::getVertices() {
    return vertices;
}

/*
* Get the size of the graph, the number of vertices.
*
* @return size of the graph.
*/
template <class VertexType, class EdgeType>
int GraphType<VertexType, EdgeType>::getSize() {
    return size;
}

/*
* Searches if a path exists between two vertices.
*
* @param startVertex, vertex to start the search from.
* @param endVertex, vertex to be arrived at.
* @return true if a path exists between the vertices, false otherwise.
*/
template <class VertexType, class EdgeType>
bool GraphType<VertexType, EdgeType>::searchPath(VertexType startVertex, VertexType endVertex) {
    if (DFS(startVertex,endVertex) || BFS(startVertex,endVertex)) {
        return true;
    }
    return false;
}

/*
* Topological sort of the graph.
*
* @param sort, stack containing the topological sort of the graph.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::topologicalSort(stack<VertexType> &sort) {
    // Vector para verificar si se visitaron los vértices
	vector<bool> visited(size, false);

	// Para recorrer todos los vértices del Grafo
	for (int i = 0; i < size; i++) {
		// Si no se ha visitado el vértice
		if (!visited[i]) {
			// Se pasa la lista sort (stack) para que se modifique
			DFS(vertices[i], visited, sort);
		}
	}
}

/*
* Checks if the directed graph is acyclic.
*
* @return true if the graph is acyclic, false otherwise.
*/
template <class VertexType, class EdgeType>
bool GraphType<VertexType, EdgeType>::isCyclic() {
    // Vector que colorea los vértices
	// 0 = blanco = no revisado
	// 1 = gris = revisando actualmente
	// 2 = negro = revisado
	vector<int> colors(size,0);

	// Para recorrer todos los vértices
	for (int i = 0; i < size; i++) {
		// Para verificar si ya se reviso
		if (colors[i] == 0) {
			// Se pasa la lista de colores pars que se modifique
			if (DFS(vertices[i],colors)) {
				// El Grafo es Ciclico
				return true;
			}
		}
	}
	// El Grafo es Aciclico
    return false;
}

/*
* Breadth first search for a path between to vertices.
*
* @param startVertex, vertex to start the search from.
* @param endVertex, vertex to be arrived at.
* @return true if a path exists between the vertices, false otherwise.
*/
template <class VertexType, class EdgeType>
bool GraphType<VertexType, EdgeType>::BFS(VertexType startVertex, VertexType endVertex) {
    queue<VertexType> searching; // Vertices a visitar
	queue<VertexType> adjacents; // Vertices adyacentes
	vector<bool> visited(size, false); // Vertices ya visitados

	VertexType vertex, neighbour;
	int index;

	searching.push(startVertex);

	while (!searching.empty()) {
		vertex = searching.front();
		searching.pop();

		if (vertex == endVertex) {
			return true;
		}
		else {
			index = getIndex(vertex);

			if (!visited[index]) {
				visited[index] = true;
				getAdjacents(vertex, adjacents);

				while (!adjacents.empty()) {
					neighbour = adjacents.front();
					adjacents.pop();
					index = getIndex(neighbour);

					if (!visited[index]) {
						searching.push(neighbour);
					}
				}
			}
		}
	}
    return false;
}

/*
* Depth first search for a path between to vertices.
*
* @param startVertex, vertex to start the search from.
* @param endVertex, vertex to be arrived at.
* @return true if a path exists between the vertices, false otherwise.
*/
template <class VertexType, class EdgeType>
bool GraphType<VertexType, EdgeType>::DFS(VertexType startVertex, VertexType endVertex) {
    stack<VertexType> searching; // Vértices a visitar
	queue<VertexType> adjacents; // Vértices adyacentes
	vector<bool> visited(size, false); // Vértices ya visitados

	VertexType vertex, neighbour;
	int index;

	searching.push(startVertex);

	while (!searching.empty()) {
		vertex = searching.top();
		searching.pop();

		if (vertex == endVertex) {
			return true;
		}
		else {
			index = getIndex(vertex);

			if (!visited[index]) {
				visited[index] = true;
				getAdjacents(vertex, adjacents);

				while (!adjacents.empty()) {
					neighbour = adjacents.front();
					adjacents.pop();
					index = getIndex(neighbour);

					if (!visited[index]) {
						searching.push(neighbour);
					}
				}
			}
		}
	}
    return false;
}

/*
* Depth first search for the topological sort of the graph.
*
* @param vertex, vertex to be searched.
* @param visited, boolean vector of visited vertices.
* @param sort, stack for the topological sort.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::DFS(VertexType vertex, vector<bool> &visited, stack<VertexType> &sort) {
    queue<VertexType> adjacents;
	VertexType neighbour;

	// Marcamos el vértice como visitado
    int index = getIndex(vertex);
	visited[index] = true;

	// Obtenemos los vértices adyacentes
	getAdjacents(vertex, adjacents);

	// Revisamos los adyacentes
	while(!adjacents.empty()) {

		// Obtenemos un adyacente
		neighbour = adjacents.front();
		// Lo quitamos del queue de vértices adyacentes a revisar
		adjacents.pop();
		// Obtenemos el índice del adyacente (neighbour)
		int indexNeighbour = getIndex(neighbour);

		// Si no hemos visitado antes ese vértice
		if (!visited[indexNeighbour]) {
			// Hacemos DFS sobre ese adyacente
			DFS(neighbour, visited, sort);
		}
	}

	// Añadimos el vértice a nuetro stack
	sort.push(vertex);
}

/*
* Depth first search for a cycle in the graph.
*
* @param vertex, vertex to start the search from.
* @param colors, vector of possible color to keep control of the non-visited (0),
*                currently in search (1), already visited (2) vertices.
* @return true if a cycle was found, false otherwise.
*/
template <class VertexType, class EdgeType>
bool GraphType<VertexType, EdgeType>::DFS(VertexType vertex, vector<int> &colors) {
    queue<VertexType> adjacents;
	VertexType neighbour;

	// Marcamos el vértice como gris
    int index = getIndex(vertex);
	colors[index] = 1;

	// Obtenemos los vértices adyacentes
	getAdjacents(vertices[index], adjacents);

	// Mientras tengamos adyacentes que revisar
	while (!adjacents.empty()) {
		// Revisamos un adyacente
		neighbour = adjacents.front();
		// Quitamos ese adyacente de los adyacentes por revisar
		adjacents.pop();
		// Obtenemos el índice del adyacente (neighbour)
		int neighbourIndex = getIndex(neighbour);

		if (colors[neighbourIndex] == 0) {
			// Si uno nos da verdadero, encontramos un ciclo
			if (DFS(neighbour,colors)) {
				return true;
			}
		}
		// Encontramos un ciclo, el adyacente esta en el camino de la búsqueda actual (CASO BASE)
		else if (colors[neighbourIndex] == 1) {
			return true;
		}
	}

	// Lo marcamos negro
	colors[index] = 2;
	// No se encontro un ciclo
    return false;
}

/*
* MNP que retorna la cantidad de puertos que no se pueden acceder desde el puerto de origen, teniendo en cuenta el mnp.
*
* @param origin, el puerto de origen.
* @param mnp, máximo número de puertos a recorrer.
* @return el número de puertos que no puede se pueden acceder.
*/
template <class VertexType, class EdgeType>
int GraphType<VertexType, EdgeType>::MNP(VertexType origin, int mnp) {

    // Creamos un map que nos ayudará a verificar si los puertos son alcanzables o inalcanzables
	map<VertexType, bool> alcanzables;
	int cont = 0;
	
    // Si el puerto existe, continuamos
	if (getIndex(origin) != -1) {
		// El map guarda todos los puertos y les
		// pone como valor falso: no son alcanzables
		for (int i = 0; i < size; i++) {
			alcanzables[vertices[i]] = false;
		}
		// Se aumenta el contador
		cont++;
		// El puerto de origen se marca como alcanzable
		alcanzables[origin] = true;
		// Se llama a un método para comenzar con la búsqueda
		MNPsearch(origin,mnp,alcanzables,cont);
	}
	
    // Retorna el total de puertos inalcanzables
	return size - cont;
}

/*
* MNP que retorna la cantidad de puertos que no se pueden acceder desde el puerto de origen, teniendo en cuenta el mnp.
*
* @param origin, el puerto de origen.
* @param mnp, máximo número de puertos a recorrer.
* @param alcanzables, map de puertos alcanzables e inalcanzables
* @param cont, cantidad de puertos alcanzables.
*/
template <class VertexType, class EdgeType>
void GraphType<VertexType, EdgeType>::MNPsearch(VertexType origin, int mnp, map<VertexType, bool> &alcanzables, int &cont) {
	
	// Para guardar los puertos adjacentes del puerto de origen
	queue<VertexType> adjacents;
	
    // Si el máximo número de puertos es diferente a 0,
    // significa que todavía se pueden visitar puertos.
	if (mnp != 0 && cont != alcanzables.size()) {
		
		// Auxiliar para guardar un puerto adyacente
		VertexType neighbour;
		
		// Obtenemos los vértices adyacentes
		getAdjacents(origin, adjacents);
	
        // Mientras el queue de adyacents no este vacío,
        // debemos checar si sus puertos son alcanzables.
		while (!adjacents.empty()) {
			
			// Revisamos un adyacente
			neighbour = adjacents.front();
			
			// Quitamos ese adyacente de los adyacentes por revisar
			adjacents.pop();

            // Si ese adyacente esta marcado como falso entra (no se ha visitado)
			if (!alcanzables[neighbour]) {
				// Se aumenta el contador de puertos alcanzables
				cont++;
				// Se cambia su valor a verdadero
				alcanzables[neighbour] = true;
			}
			
			// Recursividad y se decrementa el mnp
			MNPsearch(neighbour,mnp-1,alcanzables,cont);
		}
		
		// Si el queue de adjacents esta vacío, regresamos/terminamos
		return;
    }
    
    // Regresamos/terminamos
	return;
}
