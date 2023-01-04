// =================================================================
//
// File: main.cpp
// Team: 2
// Date: 26/11/2021
//
// =================================================================
#include <iostream>
#include <cstring>
#include "HashTable.h"
using namespace std;

int main() {
	// Objeto diccionario de tipo HashTable. 
	HashTable<int,string> diccionario(100);

	// Variable numPalabra de tipo int que guarda la cantidad de palabras a teclear.
	// Variable numDescrip de tipo int que guarda la cantidad de consultas a teclear.
	int numPalabra, numDescrip;

	// Leer input.
	cin >> numPalabra >> numDescrip;

	// Variable puesto de tipo string que guarda la palabra.
	// Variable dolar de tipo int que guarda el valor en dólares de la palabra.
	string puesto;
	int dolar;
	
	// Leer el input de puestos y su valor.
	for (int i = 0; i < numPalabra; i++) {

		// Leer input.
		cin >> puesto >> dolar;

		// Agregar al HashTable.
		diccionario.insert(dolar,puesto,puesto.size());
	}

	// Variable dolTotal de tipo entero que guarda la cantidad total de dólares.
	int dolarTotal;

	// Leer el input de palabras
	for(int i = 0; i < numDescrip; i++) {
		// Inicializar la cuenta de dolares total.
		dolarTotal = 0;
		do {
			// Leer input.
			cin >> puesto;

			// Acumular la suma de los valores en dolares de la palabra a buscar.
			dolarTotal += diccionario.get(puesto,puesto.size());

		} while (puesto != ".");

		// Desplegar en pantalla
		cout << dolarTotal << endl;
	}


	return 0;
}
