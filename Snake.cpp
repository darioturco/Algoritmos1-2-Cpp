#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
const int sizex = 62, sizey = 25, vel = 30;
int posx[100], posy[100];
int largo = 7, maximo = 100, direccion = 3, pun1 = 0, pun2 = 6;
int premx, premy;

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void limite(){
	int i = 0;
	for(i=0 ; i<largo ; i++){
		if(i < largo){
			posx[i] = 1+i;
			posy[i] = 1;
		}else{
			//posx[i] = 0;
			//posy[i] = 0;
		}
	}
	for(i=1 ;  i<sizex-1  ; i++){
		gotoxy(i, 0);
		cout << "-";
		gotoxy(i, sizey-1);
		cout << "-";
	}
	for(i=1 ; i<sizey-1 ; i++){
		gotoxy(0, i);
		cout << "|";
		gotoxy(sizex-1, i);
		cout << "|";
	}
}

void repremio(){
	premx = rand() % (sizex-2) +1;
	premy = rand() % (sizey-2) +1;
	gotoxy(premx, premy);
	cout << "@";
}

int seToca(int x, int y){
	int cont = 0;
	for(int j=0 ; j<maximo ; j++){
		if(posx[j] == x && posy[j] == y){
			cont++;
		}
	}
	return cont-1;
}

int serpiente(){
	int i = 0;
	for(i = 0 ; i<maximo ; i++){
		gotoxy(posx[i], posy[i]);
		cout << " ";
	}
	switch(direccion){
		case 0:
			posx[pun1] = posx[pun2];
			posy[pun1] = posy[pun2]-1;
			break;
		case 1:
			posx[pun1] = posx[pun2]-1;
			posy[pun1] = posy[pun2];
			break;
		case 2:
			posx[pun1] = posx[pun2];
			posy[pun1] = posy[pun2]+1;
			break;
		case 3:
			posx[pun1] = posx[pun2]+1;
			posy[pun1] = posy[pun2];
			break;
	}
	for(i = 0 ; i<maximo ; i++){
		gotoxy(posx[i], posy[i]);
		cout << "*";
	}
	if(posx[pun1] == 0 || posx[pun1] == sizex-1 || posy[pun1] == 0 || posy[pun1] == sizey-1 || seToca(posx[pun1], posy[pun1]) == 1){// if choca
		cout << "Fin del juego";
		return 1;
	}else{
		if(posx[pun1] == premx && posy[pun1] == premy){//if agarra un powerup
			repremio();
			largo++;
		}
	}
	pun2 = pun1;
	pun1++;
	if(pun1 > largo){
		pun1 = 0;
	}
	return 0;
}

int main (){
	int termina = 0;
	int tecla = 0;
	limite();
	repremio();
	while(termina == 0){
		termina = serpiente();
		if(kbhit()){
			tecla = (char)getch();
			switch(tecla){
				case 'w':
					direccion = 0;
					break;
				case 'a':
					direccion = 1;
					break;
				case 's':
					direccion = 2;
					break;
				case 'd':
					direccion = 3;
					break;
				case 'p':
					termina = 1;
					break;
			}
		}
		Sleep(vel);
	}
	return 0;
}
