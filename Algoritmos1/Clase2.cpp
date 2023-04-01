#include <iostream>

using namespace std;

// Pedirle al usuario la nota de 10 estudiantes y calcular la suma de todas las notas junto con su promedio
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

// Ingresar la nota de n estudiantes y calcular la suma de todas las notas junto con su promedio
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

// Ingresar la nota de almenos 6 alumno e indicar si se puede aumentar la cantidad de plazas del curso.
// Esto sucede si la cantidad de aprobados es mayor al 66.6% de los inscriptos del curso
// Un alumno aprobado es uno cuya nota es 6 o mas.
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

// Hacer una funcion que pida un numero en binario digito por digito y lo transforme en decimal
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
	
	Ejercicio1();
	
	Ejercicio2();
	
	Ejercicio3();
	
	Ejercicio4();
	
	return 0;
}
