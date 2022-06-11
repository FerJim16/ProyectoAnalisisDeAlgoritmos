/*

Primero definir las prioridades para un gready (como mochila)


Generar banderas para saber si se trata de casa o 
establecimiento, en caso de ser establecimiento, 
saber cuál es y si está disponible

*/




#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
using namespace std;
void fflushh(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void MenuOcupaciones()//Imprime el menú de ocupaciones
{
    system("clear");
    printf("\33[0;44m     (1) Estudiante      \n");
    printf("     (2) Ama de casa     \n");
    printf("     (3) Médico          \n");
    printf("     (4) Trabajador      \n");
    printf("     (5) Deportista      \33[0;0m\n\n");
} 

/*
Prioridades:
Estudiante:Escuela > Biblioteca > Papeleria > Hospital > Carniceria > Super > Tortilleria > Tienda > Farmacia > Iglesia > Tlapaleria
Ama de casa:
Medico:
Trabajador:
Deportista:

*/

int main()
{
    int opcion;
    MenuOcupaciones();

    printf("\33[0;32m  Cúal se acopla más a tus necesisdades? \33[0;0m");
    scanf("%i",&opcion);
    fflushh();

    switch (opcion)
    {
    case 1:
        /* code */
        break;
    case 2:
        // Code desde super
        break;
    case 3:
        // Code desde el hospital
        break;
    case 4:
        //code desde el ¿?
        break;
    case 5:
        //Code desde el gym

        break;
    
    default:
        printf("\33[0;31m Valor no definido \33[0;0m \n");
        break;
    }

    printf(" \n");
    return 0;
}