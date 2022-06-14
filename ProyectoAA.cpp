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
#include "Dijkstra.h"           //algDijkstra

using namespace std;


//#define CASAS 8;
//#define V 10; //Define el número de nodos de tipo casa que usamos


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

void pregunta()
{
    char xd;
    printf("\n ¿Deseas buscar otra casa?   (s/n) \n");
    scanf("%c",&xd);
    if(xd=='n')
    {
        exit(1);
    }
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
    while(1){

        system("clear");
    
    int graph[V][V] =   {
                            {0, 1, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5}, 
                            {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0} 

                        };
        int Valores[V];
        int a,b,c,CasaM,menor;

    int opcion;
    MenuOcupaciones();

    printf("\33[0;32m  Elige la opcion que se acople mas a tus necesisdades:\t \33[0;0m");
    scanf("%i",&opcion);
    fflushh();

    switch (opcion)
    {
    case 1:
        // Code para el Estudiante
        /*
        Establecimiento1 = Escuela      = 20
        Establecimiento2 = Biiblioteca  = 14
        Establecimiento3 = Papeleria    = 16
        dijkstra(graph,0,8)
        */
        for(int i=0 ; i<9 ; i++)
        {
            a = dijkstra(graph,i,20);
            b = dijkstra(graph,i,14);
            c = dijkstra(graph,i,16);
            Valores[i]= a+b+c;
        }
        menor = Valores[0];
        for (int i = 1; i < /*sizeof(Valores) / sizeof(Valores[0])*/9; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i;
            }
    	}
        for (int i=0; i<9 ; i++)
            printf("%i \n",Valores[i]);
            printf("\n Mas corto %i en la casa %i \n",menor,CasaM);
            printf("\nTiene hasta la Escuela %i",dijkstra(graph,CasaM,20));
            printf("\nTiene hasta la Biblioteca %i",dijkstra(graph,CasaM,17));
            printf("\nTiene hasta la Papeleria %i",dijkstra(graph,CasaM,16));
        pregunta();
        break;
    case 2:
        // Code para el Ama de casa
        /*
        Establecimiento1 = Super        = 17
        Establecimiento2 = Carniceria   = 23
        Establecimiento3 = Tienda       = 15
        */
        for(int i=0 ; i<9 ; i++)
        {
            a = dijkstra(graph,i,17);
            b = dijkstra(graph,i,23);
            c = dijkstra(graph,i,15);
            Valores[i]= a+b+c;
        }
        menor = Valores[0];
        for (int i = 1; i < /*sizeof(Valores) / sizeof(Valores[0])*/9; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i;
            }
    	}
        for (int i=0; i<9 ; i++)
            printf("%i \n",Valores[i]);
        printf("\n Mas corto %i en la casa %i \n",menor,CasaM);
        printf("\nTiene hasta la Escuela %i",dijkstra(graph,CasaM,17));
        printf("\nTiene hasta la Biblioteca %i",dijkstra(graph,CasaM,23));
        printf("\nTiene hasta la Papeleria %i",dijkstra(graph,CasaM,15));
        break;
    case 3:
        // Code para el Medico
        
        
        /*
        Establecimiento1 = Hospital     = 18
        Establecimiento2 = Farmacia     = 21
        Establecimiento3 = Super        = 17
        */
        for(int i=0 ; i<9 ; i++)
        {
            a = dijkstra(graph,i,18);
            b = dijkstra(graph,i,21);
            c = dijkstra(graph,i,17);
            Valores[i]= a+b+c;
        }
        menor = Valores[0];
        for (int i = 1; i < /*sizeof(Valores) / sizeof(Valores[0])*/9; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i;
            }
    	}
        for (int i=0; i<9 ; i++)
            printf("%i \n",Valores[i]);
        printf("\n Mas corto %i en la casa %i \n",menor,CasaM);
        printf("\nTiene hasta la Escuela %i",dijkstra(graph,CasaM,18));
        printf("\nTiene hasta la Biblioteca %i",dijkstra(graph,CasaM,21));
        printf("\nTiene hasta la Papeleria %i",dijkstra(graph,CasaM,17));
        break;
    case 4:
        // Code para el Deportista 
        
        /*
        Establecimiento1 = Gimnasio     = 13
        Establecimiento2 = Carniceria   = 23
        Establecimiento3 = Nutriologo   = 19
        */
        for(int i=0 ; i<9 ; i++)
        {
            a = dijkstra(graph,i,13);
            b = dijkstra(graph,i,23);
            c = dijkstra(graph,i,19);
            Valores[i]= a+b+c;
        }
        menor = Valores[0];
        for (int i = 1; i < /*sizeof(Valores) / sizeof(Valores[0])*/9; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i;
            }
    	}
        for (int i=0; i<9 ; i++)
            printf("%i \n",Valores[i]);
        printf("\n Mas corto %i en la casa %i \n",menor,CasaM);
        printf("\nTiene hasta la Escuela %i",dijkstra(graph,CasaM,13));
        printf("\nTiene hasta la Biblioteca %i",dijkstra(graph,CasaM,23));
        printf("\nTiene hasta la Papeleria %i",dijkstra(graph,CasaM,19));
        break;
    
    default:
        printf("\33[0;31m Opcion no definida en el menu \33[0;0m \n");
        break;
    
    }
    }
    printf(" \n");
    return 0;
}
