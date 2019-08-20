#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
const int size_x = 50, size_y = 22;
int time = 1;
int jug1 = 1, jug2 = 1, gol1 = 0, gol2 = 0;
int posx = 30, posy = 10;
int velx = 1, vely = 1, timx = 10, timy = 25;

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}
void rectangulo(){
    gotoxy(0,0);
    cout << "*";
    gotoxy(size_x,0);
    cout << "*";
    gotoxy(0,size_y);
    cout << "*";
    gotoxy(size_x,size_y);
    cout << "*";
    for(int i=1 ; i<size_x ; i++){
        gotoxy(i,0);
        cout << "-";
        gotoxy(i, size_y);
        cout << "-";
    }
}
void dibuja_jugador(int ejeX, int inicio){
    for(int i = 1 ; i<=size_y-1 ; i++){
        gotoxy(ejeX, i);
        cout << " ";
    }
    for(int i = inicio ; i<5+inicio ; i++){
        gotoxy(ejeX, i);
        cout << "|";
    }
}
int toca_jugador(int posicionX, int posicionY){
    for(int i = 0 ; i<5 ; i++){
        if((posicionX == 5 && posicionY == jug1+i) || (posicionX == (size_x-5) && posicionY == jug2+i)){
            return 1;
        }
    }
    return 0;
}
int gol(int posicion){
    int res = 0;
    if(posicion <= 1){
        res = 1;
    }
    if(posicion > size_x){
        res = 2;
    }
    return res;
}
void resetvel(){
    timx = rand()%15+7;
    timy = rand()%15+7;
}
int mostrador(){
    int result = 0;
    gotoxy(5, size_y+1);
    cout << "Jugador 1: " << gol1;
    gotoxy(32, size_y+1);
    cout << "Jugador 2: " << gol2;
    if(gol1 >= 5 || gol2 >= 5){
        result = 1;
    }
    return result;
}

int main() {
    int termina = 0, g = 0;
    char tecla;
    rectangulo();
    dibuja_jugador(5, jug1);
    dibuja_jugador(size_x-5, jug2);
    resetvel();
    mostrador();
    while (termina == 0){
        if(kbhit()){
            tecla = (char)getch();
            if(tecla == 'w' && jug1 > 1){
                jug1 -= 1;
                dibuja_jugador(5, jug1);
            }
            if(tecla == 's' && jug1 < size_y-5){
                jug1 += 1;
                dibuja_jugador(5, jug1);
            }
            if(tecla == 'i' && jug2 > 1){
                jug2 -= 1;
                dibuja_jugador(size_x-5, jug2);
            }
            if(tecla == 'k' && jug2 < size_y-5){
                jug2 += 1;
                dibuja_jugador(size_x-5, jug2);
            }
            if(tecla == 'q'){
                termina = 1;
            }
        }
        time += 1;
        if(time % timx == 0){
            gotoxy(posx, posy);
            cout << " ";
            posx += velx;
            if(toca_jugador(posx, posy) == 1){
                velx *= -1;
                posx += velx;
            }
            g = gol(posx);
            if(g != 0) {//si es gol
                if(g == 1){
                    gol2 += 1;//gol del jugador 1
                }else{
                    gol1 += 1;//gol del jugador 2
                }
                time = 1;
                posx = 30;
                posy = 10;
                velx *= -1;
                resetvel();
                termina = mostrador();
            }else{
                gotoxy(posx, posy);
                cout << "@";
            }
        }
        if(time % timy == 0){
            gotoxy(posx, posy);
            cout << " ";
            posy += vely;
            if(posy <= 0 || posy >= size_y){
                vely *= -1;
                posy += vely;
            }
            gotoxy(posx, posy);
            cout << "@";
        }
        Sleep(10);
    }
    return 0;
}
