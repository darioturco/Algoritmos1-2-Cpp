#include <iostream>
#include <math.h>

using namespace std;

// Funcion que incrementa un numero entero x en una unidad 
int f (int x ){
	return x +1;
}

// Funcion que suma dos numeros enteros a y b
int f2(int a, int b){
	return a+b;
}

// Funcion que en caso de que a sea mayor a b devuelve la suma entre a y b y en caso contrario, su producto
int f3(int a, int b){
	int res = 0;
	if(a > b){
		res = a+b;
	}else{
		res = a*b;
	}
	return res;
}

// Funcion que indica si un numero entero positivo es primo o no
bool esPrimo(int n){
	if(n < 1) return false;
	if(n == 1) return false;
	int inc = n % 2;
	for(int i = 2 + inc ; i <= sqrt(n) ; i += (1 + inc)){
		 if(n % i == 0) return false;
	}
	return true;
}

// Funcion que devuelve el i-esimo numero de la suicesion de fibonachi.
int fibRecursivo(int i){
	// Esta es una version naive recursiva sin usar programaci0on dinamica, solo con el objeticvo de resolver el enunciado
	if(i == 0) return 0;
	if(i == 1) return 1;
	return fibRecursivo(i-1) + fibRecursivo(i-2);
}

// Funcion que devuelve el i-esimo numero de la suicesion de fibonachi.
int fibIterativo(int n){
	// Esta es una version iterativa, la cual es eficiente que la anterior
	int aux = 0, fib1 = 0, fib2 = 1;
	for(int i = 0 ; i<n ; i++){
		aux = fib2;
		fib2 = fib1 + fib2;
		fib1 = aux;
	}
	return fib1;
}

// Devuelve la suma de los numeros impares desde 1 hasta n 
int sumaRecursiva(int n){ // (Version recursiva)
	if(n == 1) return 1;
	if(n%2 == 0) return sumaRecursiva(n-1);
	return sumaRecursiva(n-1) + n;
}

// Devuelve la suma de los numeros impares desde 1 hasta n 
int sumaIterativa(int n){ // (Version iterativa)
	int suma = 0;
	n += -((n+1)%2);
	while(n >= 1){
		suma += n;
		n += -2;
	}
	return suma;
}

// Obtiene la suma de los divisores de un numero entero llamado num
int divisoresRecursiva(int num, int original){ // (Version recursiva)
	if(num == 1) return 1;
	if(original%num == 0) return divisoresRecursiva(num-1, original) + num;
	return divisoresRecursiva(num-1, original);
}

// Obtiene la suma de los divisores de un numero entero llamado num
int divisoresIterativa(int num){ // (Version iterativa)
	int suma = 0;
	for(int i = 1 ; i<=num ; i++){
		if(num%i == 0) suma += i;
	}
	return suma;
}

// Funcion que devuelve el numero combinatoria entre n, k
int combinatorio(int n, int k){	
	// Esta es la version recursiva, pero se podria hacer una iterativa usand la formula cerrada del factorial
	if(n <= k) return 1;
	if(k <= 1) return n;
	return combinatorio(n-1, k) + combinatorio(n-1, k-1);
}

int main () {
	cout << "El resultado del ejercicio 1 es: " << f(10) << endl ;
	
	cout << "El resultado del ejercicio 2 es: " << f2(10, 10) << endl ;
	
	cout << "El resultado del ejercicio 3 es: " << f3(2, 5) << endl;
	
	cout << "El resultado del ejercicio 4 es: " << esPrimo(15) << endl;
	
	cout << "El resultado del ejercicio 5 rescursivo es: " << fibRecursivo(8) << endl;
	
	cout << "El resultado del ejercicio 5 iterativo es: " << fibIterativo(8) << endl;
	
	cout << "El resultado del ejercicio 6 rescursivo es: " << sumaRecursiva(9) << endl;
	
	cout << "El resultado del ejercicio 6 iterativo es: " << sumaIterativa(9) << endl;
	
	cout << "El resultado del ejercicio 7 rescursivo es: " << divisoresRecursiva(10, 10) << endl;
	
	cout << "El resultado del ejercicio 7 iterativo es: " << divisoresIterativa(10) << endl;
	
	cout << "El resultado del ejercicio 8 rescursivo es: " << combinatorio(5, 2) << endl;
	
	return 0;
}

