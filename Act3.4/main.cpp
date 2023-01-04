// =================================================================
//
// File: main.cpp
// Team: 2
// Author: Adrián Eugenio García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: David Emiliano Mireles Cárdenas - A01633729
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 24/10/2021
//
// =================================================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "BST.h"
using namespace std;

int main() {
	// Un map para cada punto de entrada que guardarán los prefijos de los barcos.
	map<string, vector<string>> conteoRojo;
	map<string, vector<string>> conteoMedi;

	// Variable cantBarco de tipo entero que guardará la cantidad de barcos a teclear por el usuario
	int cantBarco;
	// Variables de tipo string que guardarán el formato de los barcos.
	string fecha, hora, pEntrada, ubi;

	// El usuario teclea la cantidad de barcos.
	cin >> cantBarco;

	BST rojo, medi;

	// Ciclo iterativo para los barcos a registrar
	for (int i = 0; i < cantBarco; i++) {
		cin >> fecha >> hora >> pEntrada >> ubi;

		// Si el punto de entrada es Mar Rojo, se agrega a uno de los maps
		if (pEntrada == "R") {
			conteoRojo[ubi.substr(0,3)].push_back(ubi);
		}
		// Si no, se agrega al otro.
		if (pEntrada == "M") {
			conteoMedi[ubi.substr(0,3)].push_back(ubi);
		}
	}

	// Inicializamos un iterador para poder recorrer el map
	cout << "Mar Rojo" << endl;
	map<string, vector<string>> :: iterator it;
	for (it = conteoRojo.begin(); it != conteoRojo.end(); it++) {
		// first es el prefix (key) y second es el vector correspondiente (contenido)
		rojo.add(it->second.size(),it->first);
	}
	rojo.print(2);

	// Inicializamos un iterador para poder recorrer el map
	cout << "\nMar Mediterraneo" << endl;
	map<string, vector<string>> :: iterator ite;
	for (ite = conteoMedi.begin(); ite != conteoMedi.end(); ite++) {
		// first es el prefix y second es el vector correspondiente
		medi.add(ite->second.size(),ite->first);
	}
	medi.print(2);
	cout << endl;
	
	return 0;
}
