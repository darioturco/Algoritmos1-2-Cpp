#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}

int main() {
    int opcion = 0;
    int corx, cory = 0;
    char texto[50];
    char tecla = 0;
    do {
        cout << "Seleccione una opcion: " << endl;
        cout << "1 = Getchar test." << endl;
        cout << "2 = Gotoxy." << endl;
        cout << "3 = nada" << endl;
        cout << "4 = Salir." << endl;
        cin >> opcion;
        system("CLS");
        switch (opcion) {
            case 1:
                cout << "Apreta 'q' para salir." << endl;
                do {
                    tecla = getch();
                    cout << "Se apreto: " << tecla << " / " << (int)tecla << endl;
                }while (tecla != 'q');
                break;
            case 2:
                cout << "Ingrese cordenadas en X: " << endl;
                cin >> corx;
                cout << "Ingrese cordenadas en Y: " << endl;
                cin >> cory;
                cout << "Ingrese texto a imprimir: " << endl;
                cin >> texto;
                gotoxy(corx, cory);
                cout << texto;
                getch();
                gotoxy(0,0);
                system("CLS");
                fflush(stdin);
                break;
            case 3:
                cout << "Nada" << endl;
                break;
            case 4:
                cout << "Adios." << endl;
                break;
            default:
                cout << "Opcion equivacada, intente denuevo." << endl;
        }

    } while(opcion != 4);
    return 0;
}
