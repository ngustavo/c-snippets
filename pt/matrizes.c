#include <stdio.h>
#include <stdlib.h>

int **matriz(int ln, int cl);
int **preencher(int **m, int ln, int cl);

int main(){
	
	int i, j, linhas = 3, colunas = 3;
	int **mat = preencher(matriz(linhas, colunas), linhas, colunas);
	
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
			printf("\n [%i][%i]: %i ", i, j, mat[i][j]);
}

int **matriz(int ln, int cl){
	
	int i;
	int **m = (int **)malloc(ln * sizeof(int *));
	
	for(i = 0; i < ln; i++)
		m[i] = (int *)malloc(cl * sizeof(int));
	
	printf("\n O valor de i = %i ", i);
	return m;
}

int **preencher(int **m, int ln, int cl){
	
	int i, j;
	for(i = 0; i < ln; i++)
		for(j = 0; j < cl; j++){
			printf("\n [%i][%i]: ", i, j);
			scanf("%i", &m[i][j]);
		}
	
	printf("\n O valor de i = %i ", i);
	return m;
}


