/*
	Implementación del algoritmo de Kruskal
	Para detectar ciclos iremos utilizando algoritmo Union-Find que detecta
	ciclos en grafos no dirigidos.
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
using namespace std;

class Arista
{
	int vertice1, vertice2, peso;

public:

	Arista(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterVertice2()
	{
		return vertice2;
	}

	int obterPeso()
	{
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Arista& Arista2) const
	{
		return (peso < Arista2.peso);
	}
};

class Grafo
{
	int V; // número de vértices
	vector<Arista> Aristas; // vetor de Aristas

public:

	Grafo(int V)
	{
		this->V = V;
	}

	// función que agrega una Arista
	void adicionarArista(int v1, int v2, int peso)
	{
		Arista Arista(v1, v2, peso);
		Aristas.push_back(Arista);
	}

	// Función que busca o subconjunto de un elemento "i"
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// Función para unir dois subconjuntos en un único subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	/// Función que roda o algoritmo de Kruskal	
	void kruskal()
	{
		vector<Arista> arvore;
		int size_Aristas = Aristas.size();

		// ordena las Aristas por menor peso
		sort(Aristas.begin(), Aristas.end());

		// aloja memória para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos los subconjuntos como conjuntos de un único elemento
		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_Aristas; i++)
		{
			int v1 = buscar(subset, Aristas[i].obterVertice1());
			int v2 = buscar(subset, Aristas[i].obterVertice2());

			if(v1 != v2)
			{
				// se forman diferentes porque no forma ciclos, insertt un vector
				arvore.push_back(Aristas[i]);
				unir(subset, v1, v2); // hace la union
			}
		}

		int size_arvore = arvore.size();

		// muestra las aristas selecionadas con sus respectivos pesos  //imprime
		for(int i = 0; i < size_arvore; i++)
		{
			char v1 = 'A' + arvore[i].obterVertice1();
			char v2 = 'A' + arvore[i].obterVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
		}
	}
};

int main(int argc, char *argv[])
{
	Grafo g(7); // grafo
	
	// adiciona las Aristas
	g.adicionarArista(0, 1, 7);
	g.adicionarArista(0, 3, 5);
	g.adicionarArista(1, 2, 8);
	g.adicionarArista(1, 3, 9);
	g.adicionarArista(1, 4, 7);
	g.adicionarArista(2, 4, 5);
	g.adicionarArista(3, 4, 15);
	g.adicionarArista(3, 5, 6);
	g.adicionarArista(4, 5, 8);
	g.adicionarArista(4, 6, 9);
	g.adicionarArista(5, 6, 11);
	
	g.kruskal(); // roda o algoritmo de Kruskal
	
	return 0;
}