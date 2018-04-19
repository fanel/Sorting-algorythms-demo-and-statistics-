#include <iostream>
#include "dni.hpp"
#include "ordenacion.hpp"
using namespace std;

int main (void) {
	cout << "\tPrograma de ordenación\n\tAnálisis estadístico\n\nInsertar valores de ejecución\n\nNúmero de secuencias: ";
	int num;
	cin >> num;
	while (num < 1){
		cout << "\nEl número de secuencias debe ser mayor a 0\nNuevo valor: ";
		cin >> num;
	}
	
	dni** banco1 = new dni* [num];
	dni** banco2 = new dni* [num];
	dni** banco3 = new dni* [num];
	dni** banco4 = new dni* [num];
	dni** banco5 = new dni* [num];
	
	cout << "\nTamaño de las secuencias: ";
	int tam;
	cin >> tam;
	while (tam < 1){
		cout << "\nEl tamaño de secuencia debe ser mayor a 0\nNuevo valor: ";
		cin >> tam;
	}
	
	cout << "\nIntroduce el valor alfa para shellsort: ";
			float alf;
			cin >> alf;
			while ((alf >= 1)||(alf <= 0)){
				cout << "\nEl valor alfa debe estar comprendido entre 0 y 1 sin incluirlos\nNuevo valor: ";
				cin >> alf;
			}
	
	
	for (int n = 0; n < num; n++) banco1 [n] = new dni [tam];
	for (int n = 0; n < num; n++) banco2 [n] = new dni [tam];
	for (int n = 0; n < num; n++) banco3 [n] = new dni [tam];
	for (int n = 0; n < num; n++) banco4 [n] = new dni [tam];
	for (int n = 0; n < num; n++) banco5 [n] = new dni [tam];
	
	int min, max, acum, actual;
	cout << endl << endl << "\t\t\tNúmero de comparaciones\n\t\t\tMínimo\tMedio\tMáximo\n";
	
	min = max = acum = Insercion (banco1 [0], tam);
	for (int n = 1; n < num; n++){
		actual = Insercion (banco1 [n], tam);
		if (actual > max) max = actual;
		if (actual < min) min = actual;
		acum += actual;
	}
	cout << "Inserción\t\t" << min << "\t" << max << "\t" << acum/num << endl;
	
	min = max = acum = Interburbuja (banco2 [0], tam);
	for (int n = 1; n < num; n++){
		actual = Interburbuja (banco2 [n], tam);
		if (actual > max) max = actual;
		if (actual < min) min = actual;
		acum += actual;
	}
	cout << "Intercambio (burbuja)\t" << min << "\t" << max << "\t" << acum/num << endl;
	
	min = max = acum = Hsort (banco3 [0], tam);
	for (int n = 1; n < num; n++){
		actual = Hsort (banco3 [n], tam);
		if (actual > max) max = actual;
		if (actual < min) min = actual;
		acum += actual;
	}
	cout << "Heapsort\t\t" << min << "\t" << max << "\t" << acum/num << endl;
	
	min = max = acum = Qsort (banco4 [0], tam);
	for (int n = 1; n < num; n++){
		actual = Qsort (banco4 [n], tam);
		if (actual > max) max = actual;
		if (actual < min) min = actual;
		acum += actual;
	}
	cout << "Quicksort\t\t" << min << "\t" << max << "\t" << acum/num << endl;
	
	min = max = acum = Shsort (banco5 [0], tam, alf);
	for (int n = 1; n < num; n++){
		actual = Shsort (banco5 [n], tam, alf);
		if (actual > max) max = actual;
		if (actual < min) min = actual;
		acum += actual;
	}
	cout << "Shellsort\t\t" << min << "\t" << max << "\t" << acum/num << endl;
}
