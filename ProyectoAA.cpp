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

/*

Lista de Nodos:
Establecimientos
0 : Carniceria
1 : Gimnasio
2 : Biblioteca
3 : Tienda
4 : Papelería
5 : Super
6 : Hospital
7 : Nutriologo
8 : Escuela
9 : Farmacia
10: Tortilleria

Puertas de acceso
11: Puerta superior izquierda
12: Puerta superior derecha
13: Puerta inferior izquierda
14: Puerta inferior derecha

A partir del nodo 15 son casas, por lo que se puede extender 
al numero de casas que se requieran (recordar actualizar la 
matriz de adyacencia)

*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
#include "Dijkstra.h"           //algDijkstra

using namespace std;


#define CASAS 9
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
    printf("\33[0;44m                                                                                \n");
    printf("                                (1) Estudiante                                  \n");
    printf("                                (2) Ama de casa                                 \n");
    printf("                                (3) Medico                                      \n");
    printf("                                (4) Deportista                                  \n");
    printf("                                                                                \33[0;0m\n\n");
} 

void pregunta2()
{
    char xd;
    printf("\n\n\n ¿Deseas buscar otra casa?   (s/n) :   ");
    scanf("%c",&xd);
    if(xd=='n')
    {
        exit(1);
    }
}

int pregunta1()
{
    char Apartado;
    printf("\n\n\n ¿Deseas apartar esta casa?   (s/n) :  ");
    scanf("%c",&Apartado);
    if(Apartado=='s')
    {
        return 1;
    }
    else
    {
        return 0;
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
    int ocupados[CASAS];
    int ND=0;
    while(1){

        system("clear");
    
    int graph[V][V] =   {
                            {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0}, 
                            {0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 1, 0} 

                        };
        int Valores[V];
        //int ocupados[CASAS];
        int a,b,c,j=0,CasaM,menor;

    int opcion;
    MenuOcupaciones();

    printf("\33[0;43m                                                                                \n");
    printf("  Elige la opcion que se acople mas a tus necesisdades:                        ");
    scanf("%i",&opcion);
    printf("                                                                                \33[0;0m\n\n");
    fflushh();

    switch (opcion)
    {
    case 1:
        // Code para el Estudiante
        //Establecimiento1 = Escuela      = 8
        //Establecimiento2 = Biiblioteca  = 2
        //Establecimiento3 = Papeleria    = 4
        
        for(int i=0 ; i<CASAS ; i++)
        {
            a = dijkstra(graph,i+15,8);
            b = dijkstra(graph,i+15,2);
            c = dijkstra(graph,i+15,4);
            Valores[i]= (a+b+c)/3;
            for(int k=0;k<CASAS;k++)
                if (i+15 == ocupados[k])
                {
                    Valores[i]=50714;
                }
        }
        menor = Valores[0];
        for (int i = 1; i < CASAS; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i+15;
            }
    	}
            printf("\33[0;46m                                                                                \n");
            printf("  La mejor casa disponible para ti es la numero %i con recorrido promedio de %im  \n",CasaM-14,menor);
            printf("Recorre de la casa %i  hasta la Escuela:         %im                             ",CasaM-14,dijkstra(graph,CasaM,8));
            printf("\nRecorre de la casa %i  hasta la Biblioteca:      %im                             ",CasaM-14,dijkstra(graph,CasaM,2));
            printf("\nRecorre de la casa %i  hasta la Papeleria:       %im                             ",CasaM-14,dijkstra(graph,CasaM,4));
            printf("\n                                                                                \33[0;0m\n\n");
                if(pregunta1()==1)
                {
                    ocupados[ND]=CasaM;
                    ND=ND+1;
                    printf("\33[0;42m     Se aparto la casa #%i     \33[0;0m",CasaM);
                }
                fflushh();
                pregunta2();
        break;
    case 2:
        // Code para el Ama de casa
        //Establecimiento1 = Super        = 5
        //Establecimiento2 = Carniceria   = 0
        //Establecimiento3 = Tienda       = 3
        for(int i=0 ; i<CASAS ; i++)
        {
            a = dijkstra(graph,i+15,5);
            b = dijkstra(graph,i+15,0);
            c = dijkstra(graph,i+15,3);
            Valores[i]= (a+b+c)/3;
            for(int k=0;k<CASAS;k++)
                if (i+15 == ocupados[k])
                {
                    Valores[i]=50714;
                }
        }
        menor = Valores[0];
        for (int i = 1; i < CASAS; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i+15;
            }
    	}
            printf("\33[0;46m                                                                                \n");
            printf("  La mejor casa disponible para ti es la numero %i con recorrido promedio de %im \n",CasaM-14,menor);
            printf("Recorre de la casa %i  hasta el SuperMercado:     %im                            ",CasaM-14,dijkstra(graph,CasaM,5));
            printf("\nRecorre de la casa %i  hasta la Carniceria:       %im                             ",CasaM-14,dijkstra(graph,CasaM,0));
            printf("\nRecorre de la casa %i  hasta la Tienda:           %im                             ",CasaM-14,dijkstra(graph,CasaM,3));
            printf("\n                                                                                \33[0;0m\n\n");
                if(pregunta1()==1)
                {
                    ocupados[ND]=CasaM;
                    ND=ND+1;
                    printf("\33[0;42m     Se aparto la casa #%i     \33[0;0m",CasaM);
                }
                fflushh();
                pregunta2();
        break;
    case 3:
        // Code para el Medico
        //Establecimiento1 = Hospital     = 6
        //Establecimiento2 = Farmacia     = 9
        //Establecimiento3 = Super        = 5
        for(int i=0 ; i<CASAS ; i++)
        {
            a = dijkstra(graph,i+15,6);
            b = dijkstra(graph,i+15,9);
            c = dijkstra(graph,i+15,5);
            Valores[i]= (a+b+c)/3;
            for(int k=0;k<CASAS;k++)
                if (i+15 == ocupados[k])
                {
                    Valores[i]=50714;
                }
        }
        menor = Valores[0];
        for (int i = 1; i < CASAS; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i+15;
            }
    	}
            printf("\33[0;46m                                                                                \n");
            printf("  La mejor casa disponible para ti es la numero %i con recorrido promedio de %im \n",CasaM-14,menor);
            printf("Recorre de la casa %i  hasta el Hospital:         %im                             ",CasaM-14,dijkstra(graph,CasaM,6));
            printf("\nRecorre de la casa %i  hasta la Farmacia:         %im                             ",CasaM-14,dijkstra(graph,CasaM,9));
            printf("\nRecorre de la casa %i  hasta el SuperMercado:     %im                             ",CasaM-14,dijkstra(graph,CasaM,5));
            printf("\n                                                                                \33[0;0m\n\n");
                if(pregunta1()==1)
                {
                    ocupados[ND]=CasaM;
                    ND=ND+1;
                    printf("\33[0;42m     Se aparto la casa #%i     \33[0;0m",CasaM);
                }
                fflushh();
                pregunta2();
        break;
    case 4:
        // Code para el Deportista 
        //Establecimiento1 = Gimnasio     = 1
        //Establecimiento2 = Carniceria   = 0
        //Establecimiento3 = Nutriologo   = 7
        for(int i=0 ; i<CASAS ; i++)
        {
            a = dijkstra(graph,i+15,1);
            b = dijkstra(graph,i+15,0);
            c = dijkstra(graph,i+15,7);
            Valores[i]= (a+b+c)/3;
            for(int k=0;k<CASAS;k++)
                if (i+15 == ocupados[k])
                {
                    Valores[i]=50714;
                }
        }
        menor = Valores[0];
        for (int i = 1; i < CASAS; ++i)
	    {
	    	if (Valores[i] < menor)
            {
                menor = Valores[i];
                CasaM=i+15;
            }
    	}
            printf("\33[0;46m                                                                                \n");
            printf("  La mejor casa disponible para ti es la numero %i con recorrido promedio de %im  \n",CasaM-14,menor);
            printf("Recorre de la casa %i  hasta el Gimnasio:         %im                             ",CasaM-14,dijkstra(graph,CasaM,1));
            printf("\nRecorre de la casa %i  hasta la Carniceria:       %im                           ",CasaM-14,dijkstra(graph,CasaM,0));
            printf("\nRecorre de la casa %i  hasta el Nutriologo:       %im                             ",CasaM-14,dijkstra(graph,CasaM,7));
            printf("\n                                                                                \33[0;0m\n\n");
                if(pregunta1()==1)
                {
                    ocupados[ND]=CasaM;
                    ND=ND+1;
                    printf("\33[0;42m     Se aparto la casa #%i     \33[0;0m",CasaM);
                }
                fflushh();
                pregunta2();
        break;
    
    default:
        printf("\33[0;31m Opcion no definida en el menu \33[0;0m \n");
        break;
    }
    }
    printf(" %i \n", ocupados[0]);
    return 0;
}
