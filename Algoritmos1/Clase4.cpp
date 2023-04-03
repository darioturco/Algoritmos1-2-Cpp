#include <iostream>
#include <vector>

using namespace std;

// Funcion que devuelve si existe un pico en el vector vec
// Un vector tiene un pico si existe un indice i cuyos elementos contiguos(i-1, i+1) son menores a vec[i]
bool pico(const vector<int>& vec){
	bool res = false;
	for(int i = 1; i<vec.size(); i++){
		res = res || (vec[i-1] < vec[i] && vec[i+1] < vec[i]);
	}
	return res;
}

// Funcion que devuelve el mayor comun divisor entre dos numeros enteros n y m
int mcd(int n, int m){
	int a = n, b = m;
	while(a % b != 0){
		int aux = a;
		a = a%b;
		b = aux;
	}
	return b;
}

// Funcion que indica el minimo elemento de un subvector de v, el cual esta determinado por los indices l y r
int minimo(const vector<int>& vec, int l, int r){
	int res = r;
	for(int i = r ; i>=l ; i--){
		if(vec[i] < vec[res]) res = i;
	}
	return res;
}

// Funcion que ordena un vector vec
void ordena(vector<int>& vec){
	int aux, min;
	for(int i = 0 ; i<vec.size()-1 ; i++){
		min = minimo(vec, i, vec.size()-1);
		aux = vec[i];
		vec[i] = vec[min];
		vec[min] = aux;
	}
}

int main(){
	return 0;
}
