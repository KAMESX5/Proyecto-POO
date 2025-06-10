#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
//#include <algorithm>

using namespace std;

const int TAMANO = 4;

struct Celda {
    char letra;
    int numero;
};

void inicializarCuadricula(Celda cuadricula[TAMANO][TAMANO]) {
    // Crear un arreglo con las letras a-h, cada una apareciendo 2 veces
    char letras[16];
    for (int i = 0; i < 8; ++i) {
        letras[i] = 'a' + i;
        letras[i+8] = 'a' + i;
    }

    // Mezclar las letras aleatoriamente
    srand(time(0));
    //random_shuffle(begin(letras), end(letras));

    // Llenar la cuadrícula con letras y números
    int contador = 1;
    for (int i = 0; i < TAMANO; ++i) {
        for (int j = 0; j < TAMANO; ++j) {
            cuadricula[i][j].letra = letras[i*TAMANO + j];
            cuadricula[i][j].numero = contador++;
        }
    }
}

void mostrarCuadriculaConBordes(Celda cuadricula[TAMANO][TAMANO]) {
    // Mostrar línea horizontal superior
    for (int j = 0; j < TAMANO; ++j) {
        cout << "+---------";
    }
    cout << "+" << endl;

    for (int i = 0; i < TAMANO; ++i) {
        // Mostrar fila de letras
        for (int j = 0; j < TAMANO; ++j) {
            cout << "|    " << cuadricula[i][j].letra << "    ";
        }
        cout << "|" << endl;

        // Mostrar fila de números
        for (int j = 0; j < TAMANO; ++j) {
            cout << "|   " << setw(2) << cuadricula[i][j].numero << "    ";
        }
        cout << "|" << endl;

        // Mostrar línea horizontal entre filas
        for (int j = 0; j < TAMANO; ++j) {
            cout << "+---------";
        }
        cout << "+" << endl;
    }
}

int main() {
    Celda cuadricula[TAMANO][TAMANO];

    // Inicializar la cuadrícula
    inicializarCuadricula(cuadricula);

    cout << "Cuadrícula 4x4 con letras aleatorias y números:" << endl << endl;
    mostrarCuadriculaConBordes(cuadricula);

    return 0;
}
