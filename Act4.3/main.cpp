// =================================================================
//
// File: main.cpp
// Equipo: 2
// Author: Adrián Eugenio García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: David Emiliano Mireles Cárdenas - A01633729
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 19/11/2021
//
// =================================================================
#include <iostream>
#include "unweightedGraph.h"

using namespace std;

int main()
{
	// Variable conexiones de tipo entero que guardará la cantidad de conexiones a teclear por el usuario
	int conexiones;
	// Variables de tipo string que guardarán los nombres de los puertos.
	string puerto1, puerto2;

	// Leer input
	cin >> conexiones;

	// Grafo no ponderado que guardará los puertos y sus conexiones
	unweightedGraph<string> Puertos(100);

	// Ciclo iterativo para los puertos a registrar
	for (int i = 0; i < conexiones; i++) {
		cin >> puerto1 >> puerto2;
		Puertos.addVertex(puerto1);
		Puertos.addVertex(puerto2);
		Puertos.addEdge(puerto1, puerto2);
	}

	// Variable casos de tipo entero para el total de consultas que se realizarán.
	// Variable mnp de tipo entero para el máximo número de puertos.
	int casos, mnp;
	// Variable puerto de tipo string para el puerto inicial.
	string puerto;

	// Leer input
	cin >> casos;

	for (int i = 0; i < casos; i++) {
		cin >> puerto >> mnp;
		cout << "Case " << i + 1 << ": " << Puertos.MNP(puerto,mnp) << " ports not reachable from port " << puerto << " with MNP = " << mnp << "." <<endl;
	}
	
	
	return 0;
}
