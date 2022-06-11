/*

Primero definir las prioridades para un gready (como mochila)


Generar banderas para saber si se trata de casa o 
establecimiento, en caso de ser establecimiento, 
saber cuál es y si está disponible
Banderas:
(X)Está ocupada ya
(X)Es casa
(X)Es establecimiento

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
    printf("     (4) Deportista      \33[0;0m\n\n");
} 

/*

Prioridades: (usar solo las primeras 3)
Estudiante:     Escuela > Biblioteca > Papeleria > Hospital > Carniceria > Super > Tortilleria > Tienda > Farmacia > Iglesia > Tlapaleria
Ama de casa:    Super > Carniceria > Tienda > Tortilleria > Hospital > Farmacia > Biblioteca > Papelería > Escuela > Gimnasio > Nutriologo
Medico:         Hospital > Farmacia > Super > Biblioteca > Papeleria > Tienda > Tortilleria > Carnicería >  Gimnasio > Nutriologo > Escuela
Deportista:     Gimnasio > Carniceria > Nutriologo > Super > Tienda > Tortilleria > Hospital > Farmacia > Papeleria > Biblioteca > Escuela 

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
        // Code para el Estudiante
        break;
    case 2:
        // Code para el Ama de casa
        break;
    case 3:
        // Code para el Medico
        break;
    case 4:
        // Code para el Deportista 
        break;
    
    default:
        printf("\33[0;31m Valor no definido \33[0;0m \n");
        break;
    }

    printf(" \n");
    return 0;
}