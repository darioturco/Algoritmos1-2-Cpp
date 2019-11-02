#include <iostream>
#include <math.h>

using namespace std;

int f (int x ){
	return x +1;
}

int f2(int a, int b){
	return a+b;
}

int f3(int a, int b){
	int res = 0;
	if(a > b){
		res = a+b;
	}else{
		res = a*b;
	}
	return res;
}

bool esPrimo(int n){
	if(n == 1) return false;
	int inc = n % 2;
	for(int i = 2 + inc ; i <= sqrt(n) ; i += (1 + inc)){
		 if(n % i == 0) return false;
	}
	return true;
}

int fibRecursivo(int i){
	if(i == 0) return 0;
	if(i == 1) return 1;
	return fibRecursivo(i-1) + fibRecursivo(i-2);
}

int fibIterativo(int n){
	int aux = 0, fib1 = 0, fib2 = 1;
	for(int i = 0 ; i<n ; i++){
		aux = fib2;
		fib2 = fib1 + fib2;
		fib1 = aux;
	}
	return fib1;
}

int sumaRecursiva(int n){
	if(n == 1) return 1;
	if(n%2 == 0) return sumaRecursiva(n-1);
	return sumaRecursiva(n-1) + n;
}

int sumaIterativa(int n){
	int suma = 0;
	n += -((n+1)%2);
	while(n >= 1){
		suma += n;
		n += -2;
	}
	return suma;
}

int divisoresRecursiva(int num, int original){
	if(num == 1) return 1;
	if(original%num == 0) return divisoresRecursiva(num-1, original) + num;
	return divisoresRecursiva(num-1, original);
}

int divisoresIterativa(int num){
	int suma = 0;
	for(int i = 1 ; i<=num ; i++){
		if(num%i == 0) suma += i;
	}
	return suma;
}

int combinatorioRecursivo(int n, int k){	
	if(n <= k) return 1;
	if(k <= 1) return n;
	return combinatorioRecursivo(n-1, k) + combinatorioRecursivo(n-1, k-1);
}

/*int combinatorioIterativo(int n, int k){
	// Usar funcion factorial
}*/

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
	
	cout << "El resultado del ejercicio 8 rescursivo es: " << combinatorioRecursivo(5, 2) << endl;
	
	//cout << "El resultado del ejercicio 8 iterativo es: " << divisoresIterativa(10) << endl;
	
	return 0;
}

