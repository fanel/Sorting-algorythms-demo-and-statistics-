/////////////Inserción//////////////////////
template <class T>
int Insercion (T* vector, int size) {
	int i = 1, j, iteraciones = 0;
	T t;
	while (i < size){
		j = i - 1;
		while ((vector [j] > vector [i]) && (j >= 0)){
			iteraciones++;
			t = vector [j];
			vector [j] = vector [j + 1];
			vector [j + 1] = t;
			j--;
		}
		i++;
	}
	return iteraciones;
}
////////////////////////////////////////////

//////////Intercambio burbuja/////////////
template <class T>
int Interburbuja (T* vector, int size) {
	int par, ord = 0, camb = 1, iteraciones = 0;
	T t;
	while  (camb > 0) {
		par = size - 2;
		camb = 0;
		while (par >= ord) {
			iteraciones++;
			if (vector [par] > vector [par + 1]){
				t = vector [par];
				vector [par] = vector [par + 1];
				vector [par + 1] = t;
				camb++;
			}
			par--;
		}
		ord++;
	}
	return iteraciones;
}
////////////////////////////////////////////

//////////////////Heapsort/////////////////
template <class T>
int Hsort (T* vector, int size) {
	int i = 1, j, j2, desor = size, iteraciones = 0;
	T t;
	while (i <= desor){
		j2 = i;
		j = j2/2;
		while  ((j2 > 1) && (vector [j - 1] < vector [j2 - 1])){
			iteraciones++;
			t = vector [j - 1];
			vector [j - 1] = vector [j2 - 1];
			vector [j2 - 1] = t;
			j2 = j;
			j = j2/2;
		}
		i++;
	}
	
	
	while (desor > 1) {///////// o que 2
		desor--;
		t = vector [desor];
		vector [desor] = vector [0];
		vector [0] = t;
		i = 1;
		j = 0;
		while  ((i * 2) <= desor){
			iteraciones++;
			if (((i * 2 + 1) <= desor) && (vector [i * 2] <= vector [i * 2 - 1]) && (vector [i * 2] < vector [i - 1])){
				t = vector [i - 1];
				vector [i - 1] = vector [i * 2];
				vector [i * 2] = t;
				i = i * 2 + 1;
			} else if (vector [i * 2 - 1] < vector [i - 1]){
				t = vector [i - 1];
				vector [i - 1] = vector [i * 2 - 1];
				vector [i * 2 - 1] = t;
				i = i * 2;
			} else break;
		}
	}
	return iteraciones;
}
///////////////////////////////////////////////////////////

/////int iteraciones////////Quicksort/////////////////////
template <class T>
int Qsort(T* vector, int fin, int ini = 0) {
	int i = ini,  j = fin - 1, iteraciones = 0;
	T pivote = vector [(i + j)/2];
	T t;
	while (i < j) {
		while (vector [i] <= pivote) {
			i++;
			iteraciones++;
		}
		while (vector [j] >= pivote) {
			j--;
			iteraciones++;
		}
		if (!(i >= j)) {
			t = vector [i] ;
			vector [i] = vector [j] ;
			vector [j] = t ;
		}
	}
	if (ini < j) {
		iteraciones  += Qsort(vector, j, ini) ;
	}
	if (i < (fin - 1)) {
		iteraciones += Qsort(vector, fin, i + 1) ;
	}
	return (iteraciones);
}

///////////////////////////////////////////////////////////

//////////////////////Shellsort alfa///////////////////
template <class T>
int Shsort (T* vector, int size , float alfa) {
	int salto = size, elems, mayor, iteraciones = 0;
	T t;
	do {
		salto *= alfa;
		if (salto <= 1) salto = 1;
		elems = (size - 1) / salto;
		
		while (elems > 1){
			mayor = 0;
			for (int n = 1; n <= elems; n++){
				iteraciones++;
				if (vector [n] > vector [mayor])
					mayor = n;
			}
			if (mayor != elems){
				t = vector [mayor] ;
				vector [mayor] = vector [elems] ;
				vector [elems] = t ;
			}
			elems--;
		}
	} while (salto != 1);
	return iteraciones;
}
