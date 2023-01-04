// =================================================================
//
// File: main.cpp
// Author: Adrían García Lozano - A01721043
// Author: Brenda Elena Saucedo González - A00829855
// Author: Eduardo de la Rosa Flores - A01039969 
// Date: 13/10/2021
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include "List.h"
using namespace std;

int main() {

	// Variables que guardarán la cantidad de barcos y el prefijo a buscar por el usuario.
	// Variable "dia" que guardará el total de días.
	int cantBarco, dia;
	char prefix[3];

	// Solicita al usuario la cantidad de barcos y el prefijo a buscar.
	cin >> cantBarco >> prefix;

	// Variables que guardarán los datos que el usuario va a teclear.
	string fecha_aux, hora_aux, ubi_aux;
	char pEntrada_aux;

	// Listas encadenadas que guardarán el formato de los únicos barcos que cumplan con el prefijo solicitado.
	// Lista encadenada de tipo entero que guardará el tiempo total de la fecha y hora de los barcos.
	List<string> fecha, hora, ubi;
	List<char> pEntrada;
	List<int> tiempo_total;

	// Variables auxiliares que guardarán el formato de fecha y hora en enteros.
	// Variable de hora_min_tot que guardará los minutos en total.
	// Variable pos que guardará la posición de un determinado barco en la lista.
	int fecha_dia, fecha_mes, hora_min, hora_hora, hora_min_tot, pos;

	// Un ciclo para que pida los datos de la cantidad de barcos que el usuario tecleo anteriormente.
	for(int i = 0; i < cantBarco; i++) {
		cin >> fecha_aux >> hora_aux >> pEntrada_aux >> ubi_aux;
		//cout << fecha_aux << " " << hora_aux << " " << pEntrada_aux << " " << ubi_aux << endl; ////////////////////////////////

		// Busca si los datos del barco tecleado por el usuario cumplen con el prefijo que se busca.
		if (ubi_aux[0] == prefix[0] && ubi_aux[1] == prefix[1] && ubi_aux[2] == prefix[2]) {

			// Inicializar la cuenta de días totales
			dia = 0;

			// Convierte la fecha y hora a enteros
			fecha_dia = stoi(fecha_aux.substr(0,2));
			fecha_mes = stoi(fecha_aux.substr(3,2));
			hora_hora = stoi(hora_aux.substr(0,2));
			hora_min = stoi(hora_aux.substr(3,2));

			// Calcula el total de días
			if (fecha_mes != 1) {
				for (int j = 1; j < fecha_mes; j++) {
					if ((j%2 != 0 && j<8) || (j%2 != 0 && j>7)) {
						dia += 31;
					}
					else if (j == 2) {
						dia += 29;
					}
					else {
						dia += 30;
					}
				}
			}
			dia += fecha_dia;

			// Convierte el total de días a minutos.
			hora_min_tot = (((dia - 1) * 24) + hora_hora) * 60 + hora_min;

			// Guarda el formato de los barcos que cumplen con el prefijo buscado
			// y busca la posición en la que se guarda.
			pos = tiempo_total.indexOrder(hora_min_tot);
			fecha.create(fecha_aux, pos);
			hora.create(hora_aux, pos);
			pEntrada.create(pEntrada_aux, pos);
			ubi.create(ubi_aux, pos);
		}
	}

	// Variables que ayudarán a tener un control sobre el orden en que se debe de desplegar la información.
	int acum_mes, acum_m, acum_r, acum_entr;
	// Vector que guarda los meses.
	vector<string> mes{"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	// Vector que guarda los 2 puntos de entrada de los barcos.
	vector<char> entrada{'M','R'};
	
	// Despliega los barcos encontrados con el prefijo solicitado, y ordenados por fecha y hora.
	for (int i = 0; i < mes.size(); i++) {
		
		// Se inicializan los acumuladores.
		acum_mes = 0;
		acum_m = 0;
		acum_r = 0;

		// Cuenta cuantos barcos hay en cada punto de entrada en un mes en especifico.
		for (int j = 0; j < pEntrada.length(); j++) {
			if (pEntrada.get(j) == 'M' && stoi(fecha.get(j).substr(3,2)) == i+1) {
				acum_m++;
			}
			else if (stoi(fecha.get(j).substr(3,2)) == i+1) {
				acum_r++;
			}
		}

		// Un ciclo para desplegar la información en el orden del punto de entrada.
		for (int k = 0; k < entrada.size(); k++) {

			// Se inicializa el contador.
			acum_entr = 0;

			// Ciclo para desplegar el prefijo de los barcos.
			for(int j = 0; j < pEntrada.length(); j++) {
				// Verifica si el barco ingreso en un determinado mes.
				if (stoi(fecha.get(j).substr(3,2)) == i+1) {

					// Se actualiza el acumulador.
					if (acum_mes == 0) {
						cout << mes[i] << endl;
						acum_mes++;
					}

					// Se verifica si los barcos entraron por ninguno, uno o ambos 
					// puntos de entrada en determinado mes.
					// Despliega la información de los puntos de entrada en caso
					// de que exista mínimo un barco que cumpla con la condición.
					if (acum_entr == 0 && entrada[k] == 'M' && acum_m != 0) {
						cout << entrada[k] << " " << acum_m << ": ";
						acum_entr++;
					}
					else if (acum_entr == 0 && entrada[k] == 'R' && acum_r != 0) {
						cout << entrada[k] << " " << acum_r << ": ";
						acum_entr++;
					}
					
					// Si cumple con el punto de entrada que se busca,
					// despliega el prefijo en pantalla.
					if (pEntrada.get(j) == entrada[k]) {
						cout << ubi.get(j) << " ";
					}
				}
			}

			// Para llevar un control de los saltos de línea.
			if (acum_mes != 0 && acum_entr != 0) {
				cout << endl;
			}
		}
	}

	return 0;
}