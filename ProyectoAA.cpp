/*
PRUEBA UBUNTU
Primero definir las prioridades para un gready (como mochila)


Generar banderas para saber si se trata de casa o 
establecimiento, en caso de ser establecimiento, 
saber cual es y si esta disponible
Banderas:
(X)Esta ocupada ya
(X)Es casa
(X)Es establecimiento

El dijkstra debe retornar el valor del peso mas corto

*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
using namespace std;

#define CASAS 10; //Define el número de nodos de tipo casa que usamos


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
    printf("     (3) Medico          \n");
    printf("     (4) Deportista      \33[0;0m\n\n");
} 

/*

Prioridades: (usar solo las primeras 3 de cada uno)
Estudiante:     Escuela > Biblioteca > Papeleria > Hospital > Carniceria > Super > Tortilleria > Tienda > Farmacia > Nutriologo > Gimnasio
Ama de casa:    Super > Carniceria > Tienda > Tortilleria > Hospital > Farmacia > Biblioteca > Papeleria > Escuela > Gimnasio > Nutriologo
Medico:         Hospital > Farmacia > Super > Biblioteca > Papeleria > Tienda > Tortilleria > Carniceria >  Gimnasio > Nutriologo > Escuela
Deportista:     Gimnasio > Carniceria > Nutriologo > Super > Tienda > Tortilleria > Hospital > Farmacia > Papeleria > Biblioteca > Escuela 

*/

int main()
{
    int opcion;
    MenuOcupaciones();

    printf("\33[0;32m  Elige la opcion que se acople mas a tus necesisdades:\t \33[0;0m");
    scanf("%i",&opcion);
    fflushh();

    switch (opcion)
    {
    case 1:
        // Code para el Estudiante
        int Valores[CASAS];
        int menor;
        menor = numeros[0];
        /*
        Establecimiento1 = Escuela
        Establecimiento2 = Biiblioteca
        Establecimiento3 = Papeleria
        */
        for(i=0;i<CASAS;i++)
        {
            a = Dijkstra(Casa(i),Establecimiento(1));
            b = Dijkstra(Casa(i),Establecimiento(2));
            c = Dijkstra(Casa(i),Establecimiento(3));
            Valores[i]= a+b+c;
        }
        for (int i = 1; i < sizeof(Valores) / sizeof(Valores[0]); ++i)
	    {
	    	if (Valores[i] < menor) menor = Valores[i];
    	}
        break;
    case 2:
        // Code para el Ama de casa
        int Valores[CASAS];
        int menor;
        menor = numeros[0];
        /*
        Establecimiento1 = Super
        Establecimiento2 = Carniceria
        Establecimiento3 = Tienda
        */
        for(i=0;i<CASAS;i++)
        {
            a = Dijkstra(Casa(i),Establecimiento(1));
            b = Dijkstra(Casa(i),Establecimiento(2));
            c = Dijkstra(Casa(i),Establecimiento(3));
            Valores[i]= a+b+c;
        }
        for (int i = 1; i < sizeof(Valores) / sizeof(Valores[0]); ++i)
	    {
	    	if (Valores[i] < menor) menor = Valores[i];
    	}
        break;
    case 3:
        // Code para el Medico
        int Valores[CASAS];
        int menor;
        menor = numeros[0];
        /*
        Establecimiento1 = Hospital
        Establecimiento2 = Farmacia
        Establecimiento3 = Super
        */
        for(i=0;i<CASAS;i++)
        {
            a = Dijkstra(Casa(i),Establecimiento(1));
            b = Dijkstra(Casa(i),Establecimiento(2));
            c = Dijkstra(Casa(i),Establecimiento(3));
            Valores[i]= a+b+c;
        }
        for (int i = 1; i < sizeof(Valores) / sizeof(Valores[0]); ++i)
	    {
	    	if (Valores[i] < menor) menor = Valores[i];
    	}
        break;
    case 4:
        // Code para el Deportista 
        int Valores[CASAS];
        int menor;
        menor = numeros[0];
        /*
        Establecimiento1 = Gimnasio
        Establecimiento2 = Carniceria 
        Establecimiento3 = Nutriologo
        */
        for(i=0;i<CASAS;i++)
        {
            a = Dijkstra(Casa(i),Establecimiento(1));
            b = Dijkstra(Casa(i),Establecimiento(2));
            c = Dijkstra(Casa(i),Establecimiento(3));
            Valores[i]= a+b+c;
        }
        for (int i = 1; i < sizeof(Valores) / sizeof(Valores[0]); ++i)
	    {
	    	if (Valores[i] < menor) menor = Valores[i];
    	}
        break;
    
    default:
        printf("\33[0;31m Opcion no definida en el menu \33[0;0m \n");
        break;
    }

    printf(" \n");
    return 0;
}
