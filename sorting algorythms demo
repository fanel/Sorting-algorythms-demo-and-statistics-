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
			cout << "\n";///////////////////////////////////
			for (int n = 0; n < size; n++)
				cout << vector[n] << " ";
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
				cout << "\n";///////////////////////////////
				for (int n = 0; n < size; n
