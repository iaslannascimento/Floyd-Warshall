//Autor Iaslan Nascimento
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define INF 999

	

int main(){
  	FILE *arq;
  	int v;
 	char aux[10];
 	
  // Abre um arquivo TEXTO para LEITURA
 	 arq = fopen("grafo1.txt", "rt");
  	if (arq == NULL)  {
   	  	printf("Problemas na abertura do arquivo\n");
  	}else{
  		printf("Arquivo carregado com Sucesso!\n\n");
  	}
	printf("Matriz Original:\n");

	fscanf(arq, "%d", &v); //pegando o tamanho da matriz
	int grafo[v][v]; // definindo a matriz
	int distancia[v][v];
	int i=0; // controlador das linhas
	while(!feof(arq)){
		for(int j=0; j<v; j++){
				fscanf(arq,"%s",aux); //Le  a linha e grava e em aux
				if(strcmp(aux,"INF")==0){
					grafo[i][j] = INF;					
				}else{
					grafo[i][j] = atoi(aux);
				}
		}
		i++;	
	}
	printf("----------------------------------------------\n");
 	 fclose(arq);
  //adicionando os valores do arquivo na matriz 
	for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				if (grafo[i][j] == INF){
					printf("%7s", "INF");	
				} 
				else{	
					printf("%7d",grafo[i][j]);
				}
			}
			printf("\n"); 
	}
	
	printf("--------------------------------------------\n");
	
//	printf(" --------------- \n");
//		for(int i=0; i<v; i++){
//			for(int j=0; j<v; j++){
//				printf(" %d ", grafo[i][j]);
//			}
//			printf("\n"); 
//	}
//	printf(" ---------------\n ");
	
		//aplicaçaõ do Algoritmo de FloydWarshall
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			for(int z = 0; z < v; z++){
				if( grafo[j][z] > (grafo[j][i] + grafo[i][z]) ){
					grafo[j][z] = grafo[j][i] + grafo[i][z];
					}
				}	
			}	
		}
	//detecção de caminhos negativos 
	int b;
	for (int i = 0; i < v; i++) {
        if (grafo[i][i] < 0){
        	
		}else{
			b = grafo[i][i];
		}
	}
	if (b < 0){
        	printf("Existem ciclos negativos\n");
		}else{
			printf("Nao existem ciclos negativos\n");
		}
		printf("--------------------------------------------\n");
	// Mostra a matriz com os valores atualizados
	
	printf("Matriz com os valores de distancia:\n\n");
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			if( grafo[i][j] < 10 )
				printf(" %d ", grafo[i][j]);
			else
				printf("%d ", grafo[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------------\n");
	printf("\n");
	

	//printf("Total caminho mais curto do vertice 0 ao 4: %lu\n", Matriz[4][0]); // [destino] [origem]
	//printf("Total caminho mais curto do vertice 2 ao 0: %lu\n", Matriz[0][2]);
	//printf("Total caminho mais curto do vertice 4 ao 3: %lu\n\n", Matriz[3][4]);

	// Mostra todos os caminhos 
	printf("\n");
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			printf("Menor distancia saindo do %d para chegar ao %d = %d.\n", i, j, grafo[j][i]);
		}
	}
	printf("\n\n");

	
    
}
