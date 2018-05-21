#include <stdio.h>

void menuOpcoes(){
	printf("\n   Demonstracao                Comando Completo            Geral");
	printf("\n    1. Selection Sort           4. Selection Sort           -1. Sair");
	printf("\n    2. Fibonacci Recursiva      5. Fibonacci Recursiva      -2. Menu");
	printf("\n    3. Fibonacci Iterativa      6. Fibonacci Iterativa");
	printf("\n\n");
}

// trocar duas variaveis de posicao por referencia
void trocar(int *a, int *b){
	int temp;
	temp = *b;
	*b   = *a;
	*a   = temp;
}

// ordenar um vetor por selecao
void ordenar(int vet[], int *t){ 
	int i, j, min;
	for(i = 0; i < *t-1; i++){
    	min = i; // assumir que o primeiro eh o menor
    	for (j = (i+1); j < *t; j++) {
       		if(vet[j] < vet[min])
				min = j; // se um dos outros elementos for menor, assumir como tal
    	}
    	if (i != min) {
    		trocar(&vet[i], &vet[min]); // trocar para a posicao correta
    	}
   	}
}

// fibonacci recursiva
int fibrec(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1; // se for 0 ou 1 retornar os primeiros
	else
		return fibrec(n-1)+fibrec(n-2);
	// senão, retornar a soma do fibonacci de seus antecessores
}

// fibonacci iterativa
int fibite(int n){
	
	int a, b, c, i;
	a = 0; b = 1; c = 1;
	
	for(i = 1; i < n; i++){ // o proximo eh a soma dos anteriores
		c = a + b;
		a = b;
		b = c;
	}
	
	if(n == 0)
		return a;
	if(n == 1)
		return b; // se for 0 ou 1, retornar 0 ou 1
	else
		return c;
}

int clean(){
    while (getchar()!='\n');
    return 1;
}

void selectionSort(int x){
	int tam, vetor[100] = {0}, i;
	
	printf("\n============= Selection Sort ============");
	
	if(x == 1){
		
		printf("\n Insira o tamanho da lista: ");
		scanf("%d", &tam);
	
		for(i = 0; i < tam; i++){
			printf("\n Insira o %d* numero: ", i+1);
			scanf("%d", &vetor[i]);
		}
		
	}else{
		
		tam = 5;
		printf("\n Insira o tamanho da lista: %d \n", tam);
		
		for(i = 0; i < tam; i++){
			vetor[i] = (i-5)*-10;
			printf("\n Insira o %d* numero: %d \n", i+1, vetor[i]);
		}
		
	}
	
	printf("\n Vetor original: ");
	
   	for(i = 0; i < tam; i++){
   		printf("%d ", vetor[i]);
	}
	
	ordenar(vetor, &tam);
	
	printf("\n Vetor ordenado: ");
	
	for(i = 0; i < tam; i++){
   		printf("%d ", vetor[i]);
	}
	
	printf("\n=========================================\n");
}

void fibonacciRecursiva(int x){
	
	int n, i;
	
	printf("\n========== Fibonacci Recursiva ==========");
	
	if(x == 1){
		printf("\n Insira o indice N: ");
		scanf("%d", &n);
		
		printf("\n ");
		for(i = 1; i < n; i++){
			printf("%d ", fibrec(i));
		}
	}else{
		n = 5;
		printf("\n Insira o indice N: %d", n);
		
		printf("\n\n ");
		for(i = 1; i < n; i++){
			printf("%d ", fibrec(i));
		}
	}
	
	printf("[%d]", fibrec(n));
	printf("\n=========================================\n");
}

void fibonacciIterativa(int x){
	
	int n, i;
	
	printf("\n========== Fibonacci Iterativa ==========");
	
	if(x == 1){
		printf("\n Insira o indice N: ");
		scanf("%d", &n);
		
		printf("\n ");
		for(i = 1; i < n; i++){
			printf("%d ", fibite(i));
		}
	}else{
		n = 9;
		printf("\n Insira o indice N: %d", n);
		
		printf("\n\n ");
		for(i = 1; i < n; i++){
			printf("%d ", fibite(i));
		}
	}
	
	printf("[%d]", fibite(n));
	printf("\n=========================================\n");
}

int main(){
	
	int k = 0;
    
	menuOpcoes(); // imprimir o menu de opcoes
	
	// ler um comando enquanto nao for -1
	
	do{
		printf(">>> ");
		scanf("%d", &k);
		
		switch(k){
			case 1:
				selectionSort(0); // ordenar demo
				break;
			case 2:
				fibonacciRecursiva(0); // fibonacci recursiva demo
				break;
			case 3:
				fibonacciIterativa(0); // fibonacci iterativa demo
				break;
			case 4:
				selectionSort(1); // ordenar completa
				break;
			case 5:
				fibonacciRecursiva(1); // fibonacci recursiva completa
				break;
			case 6:
				fibonacciIterativa(1); // fibonacci iterativa completa
				break;
			case -1:
				printf("\n Saindo... \n\n"); // sair
				break;
			case -2:
				menuOpcoes(); // imprimir o menu de opcoes
				break;
			default: printf("\n Opcao Invalida! Tente novamente!");
				break;
		}
		
	}while(k != -1 && clean());
	
	getchar();
	return 0;
}
