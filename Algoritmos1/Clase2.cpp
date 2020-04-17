#include <iostream>

using namespace std;

void Ejercicio1(){
	float suma = 0;
	int aux = 0;
	for(int i = 0 ; i<10 ; i++){
		cout << "Ingrese la nota del estudiante: ";
		cin >> aux;
		cout << endl;
		suma += aux;
	}
	cout << "La suma de las 10 notas es: " << suma << endl;
	cout << "El promedio de las 10 notas es: " << suma/10.0 << endl;
}

void Ejercicio2(){
	float suma = 0;
	float i = 0;
	int aux = 0;
	cout << "Ingrese -1 para terminar el ingreso de notas." << endl;
	while(aux != -1){
		cout << "Ingrese la nota del estudiante: ";
		cin >> aux;
		cout << endl;
		if(aux != -1){
			suma += aux;
			i++;
		}
	}
	cout << "La suma de todas las notas es: " << suma << endl;
	cout << "El promedio de todas las notas es: " << suma/i << endl;
}

void Ejercicio3(){
	float i = 0;
	float aprobados = 0;
	int aux = 0;
	cout << "Ingrese -1 para terminar el ingreso de notas." << endl;
	while(aux != -1){
		cout << "Ingrese la nota del estudiante: ";
		cin >> aux;
		cout << endl;
		if(aux != -1){
			if(aux > 6){
				aprobados++;	
			}
			i++;
		}
	}
	if(i < 6){
		cout << "Error. No puede haber tan pocos alumnos." << endl;
	}else{
		if(aprobados / i > 2.0/3.0){
			cout << "Se puede aumentar la cantidad de plazas del curso." << endl;
		}
	}
}

void Ejercicio4(){
	int suma = 0;
	int mult = 1;
	int aux = 0;
	cout << "Ingrese un numero distinto a 0 o 1 para terminar el ingreso de datos." << endl;
	while(aux == 0 || aux == 1){
		cout << "Ingrese un digito: ";
		cin >> aux;
		cout << endl;
		if(aux == 0 || aux == 1){
			suma += aux*mult;
			mult *= 2;	
		}
	}
	cout << "El numero ingresado, en decimal es: " << suma << endl;
}

int main () {
	
	//Ejercicio1();
	
	//Ejercicio2();
	
	Ejercicio3();
	
	//Ejercicio4();
	
	return 0;
}
