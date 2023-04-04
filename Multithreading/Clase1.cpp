#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

using namespace std;

// Crear un proceso tenga un hijo y ese proceso hijo termine antes que el padre.
void ej1(){
	int pid = fork();
    if(pid == -1){
        printf("Fork Error.");
        exit(1);
    }
	if(pid == 0){
        printf("Hola, soy el hijo.");
	}else{
		printf("Hola, soy el padre.");
		wait(NULL);
	}
    exit(0);
}

// Hacer un proceso que cree 5 processo hijos y que esos hijos no tengan mas hijos.
void ej2(){
	for(int i=0 ; i<5; i++){
		int pid = fork();
        if(pid == -1){
            printf("Fork Error.");
            exit(1);
        }
        if(pid == 0){
            printf("Hola, soy el hijo numero: %d", i);
            exit(0);
        }
	}
	exit(0);
}

// Crear un programa de manera que el proceso padre, llamado 'Abraham', cree un proceso hijo llamado 'Homero'.
// El proceso 'Homero' creara 3 hijos llamados 'Bart' y 'Lisa' y 'Maggie'. 
// Cada proceso debe imprimir por pantalla el nombre asociado al mismo.
void ej3(){
	int pid = fork();
	if(pid == 0){
        printf("Homero");
		pid = fork();
		if(pid == 0){
            printf("Magie");
		}else{
			wait(NULL);
			pid = fork();
			if(pid == 0){
                printf("Bart");
			}else{
				wait(NULL);
				pid = fork();
				if(pid == 0){
                    printf("Lisa");
				}
			}
		}
	}else{
        printf("Abram");
		exit(0);
	}
}

// Informar por pantalla el pid del proceso
void ej4(){
	int pid = getpid();
    printf("El pid de este proceo es: %d", pid);
}

// Crear un programa que haga un arbol binario balanceado de procesos de altura n
void ej5(){
    int n = 3; // n es el parametro que se puede modificar a libertad
    int pid;
    for(int i = 0 ; i<n ; i++){
        pid = fork();
        if(pid != 0){
            pid = fork();
            if(pid != 0){
                if(i < n-1){
                    wait(NULL);
                    wait(NULL);
                }
                exit(0);   
            }
        }

    }
	
}

// Crear una hilera de procesos de largo n,
// donde una hilera quiere decir que el primer proceso crea un proceso hijo, ese hijo crea otro hijo, asi n veces.
// Nos queda un diagrama:   p1 -> p2 -> p3 -> ... -> pn
void ej6(){
    int n = 3;  // n es el parametro que se puede modificar a libertad
    for(int i ; i<n ; i++){
        int pid = fork();
        if(pid != 0){
            if(i < n-1){
                wait(NULL);    
            }
            exit(0);
        }
    }
}

// Crear n procesos se duerman durante 5 segundos, pero que antes de terminar el padre decida matarlos
void ej7(){
	int pid;
    int n = 3;
	vector<int> v;
	for(int i = 0 ; i<n ; i++){
		pid = fork();
		if(pid == 0){
			sleep(5);
			exit(0);	
		}else{
			v.push_back(pid);
		}
	}
	for(int i = 0 ; i<v.size() ; i++){
		kill(v[i], SIGKILL);
	}
}

// Crear un programa que dado un vector v de n posiciones, cree n proceso donde el i-esimo proceso imprime el i-esimo elemento del vector v
void ej8(){
    int pid;
    int n = 3;
	vector<int> v = {7, 8, 6};
    for(int i = 0 ; i<n ; i++){
        pid = fork();
        if(pid == 0){
            printf("La posicion %d, vector tiene el elemento: %d", i, v[i]);
            exit(0);
        }
    }
}



void main(){
    // Aca se pueden testear los ejercicios resueltos
    return 0;
}