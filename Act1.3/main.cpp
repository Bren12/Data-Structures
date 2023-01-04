// =================================================================
//
// File: main.cpp
// Team: 1
// Author: Adrían García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: Eduardo de la Rosa Flores - A01039969
// Date: 11/09/2021
//
// =================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =====================================================================================================
// Realiza el ordenamiento de los vectores de manera ascendente según la cantidad total de minutos.
//
// @param vect, un vector de elementos de tipo entero (vector de minutos).
// @param fecha, un vector de elementos de tipo string (vector del formato de fecha).
// @param hora, un vector de elementos de tipo string (vector del formato de hora).
// @param pEn, un vector de elementos de tipo char (vector del formato de punto de entrada).
// @param ubi, un vector de elementos de tipo string (vector del formato de identificador).
// =====================================================================================================
void seleccion(vector<int> &vect, vector<string> &fecha, vector<string> &hora, vector<char> &pEn, vector<string> &ubi) {

	for (int i = 0; i < vect.size(); i++) {
		int min = i;
		for (int j = i+1; j < vect.size(); j++) {
			if (vect[min] > vect[j]) {
				min = j;
			}
		}
		
		if (min != i) {
			swap(vect[i],vect[min]);
			swap(fecha[i],fecha[min]);
			swap(hora[i],hora[min]);
			swap(pEn[i],pEn[min]);
			swap(ubi[i],ubi[min]);
		}
	}
}


int main() {

	// Variables que guardarán la cantidad de barcos y el prefijo a buscar por el usuario.
	// Variable "pos" que contará la cantidad de barcos que cumple con el prefijo buscado.
	// Variable "dia" que guardará el total de días.
	int cantBarco, pos = 0, dia;
	char prefix[3];

	// Solicita al usuario la cantidad de barcos y el prefijo a buscar.
	cin >> cantBarco >> prefix;

	// Variables que guardará los datos que el usuario va a teclear.
	string fecha_aux, hora_aux, ubi_aux;
	char pEntrada_aux;

	// Vectores que guardarán el formato de los unicos barcos que cumplen con el prefijo solicitado.
	vector<string> fecha, hora, ubi;
	vector<char> pEntrada;

	// Vectores auxiliares que guardarán el formato de fecha y hora en enteros.
	// Vector hora_min_tot que guardará los minutos en total.
	vector<int> fecha_dia, fecha_mes, hora_min, hora_hora, hora_min_tot;

	// Un ciclo para que pida los datos de la cantidad de barcos que el usuario tecleo anteriormente.
	for(int i = 0; i < cantBarco; i++) {
		cin >> fecha_aux >> hora_aux >> pEntrada_aux >> ubi_aux;

		// Busca si los datos del barco tecleado por el usuario cumplen con el prefijo que se busca.
		if (ubi_aux[0] == prefix[0] && ubi_aux[1] == prefix[1] && ubi_aux[2] == prefix[2]) {

			// Inicializar la cuenta de días totales
			dia = 0;

			// Guarda el formato de los barcos que cumplen con el prefijo buscado
			fecha.push_back(fecha_aux);
			hora.push_back(hora_aux);
			pEntrada.push_back(pEntrada_aux);
			ubi.push_back(ubi_aux);

			// Convierte la fecha y hora a enteros
			fecha_dia.push_back(stoi(fecha[pos].substr(0,2)));
			fecha_mes.push_back(stoi(fecha[pos].substr(3,2)));
			hora_hora.push_back(stoi(hora[pos].substr(0,2)));
			hora_min.push_back(stoi(hora[pos].substr(3,2)));

			// Calcula el total de días
			if (fecha_mes[pos] != 1) {
				for (int j = 1; j < fecha_mes[pos]; j++) {
					if ((j%2 != 0 && j<8) || (j%2 != 0 && j>7)) {
						dia += 31;
					}
					else {
						if (j == 2) {
							dia += 28;
						}
						else {
							dia += 30;
						}
					}
				}
			}
			dia += fecha_dia[pos];

			// Convierte el total de días a minutos.
			hora_min_tot.push_back( (((dia - 1) * 24) + hora_hora[pos]) * 60 + hora_min[pos]);

			// Actualiza el contador de la cantidad de barcos con el prefijo buscado.
			pos++;
		}
	}

	// Ordenamiento por selección.
	seleccion(hora_min_tot,fecha,hora,pEntrada,ubi);

	// Despliega los barcos encontrados con el prefijo solicitado y ordenados por fecha y hora.
	for (int i = 0; i < fecha.size(); i++) {
		cout << fecha[i] << " " << hora[i] << " " << pEntrada[i] << " " << ubi[i] << endl;
	}

	return 0;
}