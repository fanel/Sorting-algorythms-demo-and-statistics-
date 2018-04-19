#include <iostream>
#include "dni.hpp"
#include "ordenacion.hpp"
using namespace std;

int main (void) {
	cout << "\tPrograma de ordenación\n\tDemostración de funcionamiento\n\nInsertar valores de ejecución\n\nTamaño de secuencia: ";
	int tam;
	cin >> tam;
	while ((tam < 1) || (tam > 25)){
		cout << "\nEl tamaño de secuencia debe estar comprendido entre 1 y 25\nNuevo valor: ";
		cin >> tam;
	}
	
	dni* banco = new dni [tam];
	
	cout << "\nNúmero de algoritmo:\n\t1) Inserción\n\t2) Intercambio (burbuja)\n\t3) Heapsort\n\t4) Quicksort\n\t5) Shellsort";
	
	int alg;
	cin >> alg;
	while ((alg < 1) || (alg > 5)){
		cout << "\nEl número debe estar comprendido entre 1 y 5\nNuevo valor: ";
		cin >> tam;
	}
	
	switch (alg){
		case 1:Insercion (banco, tam);break;
		case 2:Interburbuja (banco, tam);break;
		case 3:Hsort (banco, tam);break;
		case 4:Qsort (banco, tam);break;
		case 5:
			float alf = -1;
			while((alf <= 0)||(alf >= 1)){
				cout << "\nIntroduce valor entre 0 y 1 para alfa: ";
				cin >> alf;
			}
			Shsort (banco, tam,alf);break;
	}
	
	
}
