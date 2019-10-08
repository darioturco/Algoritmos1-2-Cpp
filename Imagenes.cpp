#include <iostream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<vector<int> > matriz;

void imprimeMatriz(vector<vector<int> > imagen){ // muesta imagen repesentado a un pixel apagado como '0' y a un pixel prendido con '1'
	//system("CLS"); // limpia la pantalla
	for(int i = 0 ; i<imagen.size() ; i++){
		for(int j = 0 ; j<imagen[0].size() ; j++){
			cout << imagen[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool expConProbaP(float p){
	bool res = (p*10000 > rand() % 10000) ? true : false;
	return res;
}

/*Generador de imagenes*/

vector<vector<int> > todosIguales(int num, int sizeX, int sizeY){// devuelve una imagen con todos sus elementos igual a num
	return vector<vector<int> >(sizeX, vector<int>(sizeY, num));
}

vector<vector<int> > elementoEstructurante(int size){// devuelve un elemento estructurante de tamaño size
	return vector<vector<int> > (size, vector<int>(size, 1));
}

void pintaAdjacencia4(vector<vector<int> > &imagen, float p, int x, int y){
	if(x-1 >= 0 && expConProbaP(p)){
		imagen[y][x-1] = 1;
		pintaAdjacencia4(imagen, p/1.5, x-1, y);
	}
	if(x+1 < imagen[0].size() && expConProbaP(p)){
		imagen[y][x+1] = 1;
		pintaAdjacencia4(imagen, p/1.5, x+1, y);
	}
	if(y-1 >= 0 && expConProbaP(p)){
		imagen[y-1][x] = 1;
		pintaAdjacencia4(imagen, p/1.5, x, y-1);
	}
	if(y+1 < imagen.size() && expConProbaP(p)){
		imagen[y+1][x] = 1;
		pintaAdjacencia4(imagen, p/1.5, x, y+1);
	}
}
vector<vector<int> > imagenRandomSeed(int sizeX, int sizeY, int seed, float p){// devuelve una imagen aleatoria de maximo 'seed' cantidad de regiones
	int x, y;
	vector<vector<int> > res(sizeY, vector<int>(sizeX, 0));
	for(int i = 0 ; i<seed ; i++){
		x = rand() % sizeX;
		y = rand() % sizeY;
		res[y][x] = 1;
		pintaAdjacencia4(res, p, x, y);
	}
	return res;
}

vector<vector<int> > imagenRandomTotal(int sizeX, int sizeY, float p){// devuelve una imagen totalmente aleatoria donde cada pixel tiene probabilidad p de esta activo
	vector<vector<int> > res(sizeY, vector<int>(sizeX, 0));
	for(int i = 0 ; i<sizeY ; i++){
		for(int j = 0 ; j<sizeX ; j++){
			if(expConProbaP(p)){
				res[i][j] = 1;
			}
		}
	}
	return res;
}

int main(){
	srand(time(NULL));// inicializa el generador de numero aleatorio
	imprimeMatriz(imagenRandomSeed(30, 20, 1, 1.1));
	//imprimeMatriz(imagenRandomTotal(25, 5, 0.5));
	system("PAUSE");
	return 0;
}
