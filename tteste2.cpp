/*Grafos - Algoritmo de Floyd-Warshall em C
*	Kelvin Salton do Prado - 2015
*	Complexidade: Teta de v�rtices ao cubo = Teta(n^3)
*
*	Encontra o caminho de todos para todos os v�rtices
*
*	Grafo com 5 v�rtices e 6 arestas
*
*			   6
*	(0)-----------------(1)
*	 |					 |
* 10 |					 | 2
*	 |		   1		 |
*	(2)-----------------(3)
*	  \					/
*	 3 \			   / 8
*		\			  /
*		 -----(4)-----			 
*
*	 Matriz de Dist�ncia
*	   0   1   2   3   4
*	0  0   6  10   -   -
*	1  6   0   -   2   -
*	2 10   -   0   1   3
*	3  -   2   1   0   8
*	4  -   -   3   8   0
*
* 	Para valores infinitos ser� considerado o valor: 4294967295
*
*/

#include <stdio.h>

#define nroVertices 5 // Define uma constante 5 que � a quantidade de v�rtices do grafo

// Algoritmo de Floyd-Warshall recebe como par�metro a matriz de dist�ncia e o n�mero de v�rtices
void FloydWarshall(unsigned long int matriz[nroVertices][nroVertices], int n){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			for(int z = 0; z < n; z++){
				if( matriz[y][z] > (matriz[y][x] + matriz[x][z]) )
					matriz[y][z] = matriz[y][x] + matriz[x][z];
			}	
		}	
	}
}

int main(){

	unsigned long int Matriz[nroVertices][nroVertices] = {{0,3,8, 4294967295, -4 },
														 { 4294967295,0, 4294967295, 1,7 },
														 {4294967295, 4,          0,4294967295,4294967295},
														 {2,4294967295,-5,0,4294967295},
														 { 4294967295, 4294967295,4294967295,6,0 }};

	FloydWarshall(Matriz, nroVertices);

	// Mostra a matriz com os valores atualizados
	printf("Matriz:\n");
	for (int i = 0; i < nroVertices; ++i){
		for (int e = 0; e < nroVertices; ++e){
			if( Matriz[i][e] < 10 )
				printf(" %lu ", Matriz[i][e]);
			else
				printf("%lu ", Matriz[i][e]);
		}
		printf("\n");
	}
	printf("\n");

	//printf("Total caminho mais curto do vertice 0 ao 4: %lu\n", Matriz[4][0]); // [destino] [origem]
	//printf("Total caminho mais curto do vertice 2 ao 0: %lu\n", Matriz[0][2]);
	//printf("Total caminho mais curto do vertice 4 ao 3: %lu\n\n", Matriz[3][4]);

	// Mostra todos os caminhos 
	printf("\n");
	for (int i = 0; i < nroVertices; ++i){
		for (int x = 0; x < nroVertices; ++x){
			printf("Menor distancia saindo do %d para chegar ao %d = %lu.\n", i, x, Matriz[x][i]);
		}
	}
	printf("\n\n");

	return 0;
}
