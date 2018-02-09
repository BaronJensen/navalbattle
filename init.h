#include <stdio.h>
#include <stdlib.h> 

#define  SIZE  10 //Tamaño del tablero SIZE*SIZE
#define BARCOS 2 //Cantidad de barcos permitido por jugador
#define LINUX 0 //Para jugar en linux o cualquier UNIX   (1), para jugar en windows(0)

short int TABLERO[SIZE*2][SIZE*2];
int  barco[] = {2,2,3,3,5,5};
char *ship_name[] = {"lancha", "portaaviones"};
int vida[2]= {4,4}; //vida por total de barcos




#include "batalla.h"
#include "mainloop.h"



