#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */
    char** tablero = GetTablero();

    // ### Gana X ###
    //Horizontal
    if (tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X') return GANO_X;
    else if (tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X') return GANO_X;
    else if (tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X') return GANO_X;
    //Vertical
    else if (tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X') return GANO_X;
    else if (tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X') return GANO_X;
    else if (tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X') return GANO_X;
    //Diagonal
    else if (tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X') return GANO_X;
    else if (tablero[2][0] == 'X' && tablero[1][1] == 'X' && tablero[0][2] == 'X') return GANO_X;

    // ### Gana O ###
    //Horizontal
    else if (tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O') return GANO_O;
    else if (tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O') return GANO_O;
    else if (tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O') return GANO_O;
    //Vertical
    else if (tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O') return GANO_O;
    else if (tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O') return GANO_O;
    else if (tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O') return GANO_O;
    //Diagonal
    else if (tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O') return GANO_O;
    else if (tablero[2][0] == 'O' && tablero[1][1] == 'O' && tablero[0][2] == 'O') return GANO_O;

    // ### Empate ###
    int todasLlenas = 1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (tablero[i][j] == '_') todasLlenas = 0;
        }
    }
    
    if (todasLlenas == 1) return EMPATE;

    return JUEGO_EN_CURSO;
}
