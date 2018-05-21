#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 100

typedef struct eLista {
	int id;
	char nome[TAM];
	struct eLista *prox;
} tLista;

tLista *head;

void iniciar(){
    head = NULL;
}

void inserir(int id, char nome[TAM]){
	tLista *aux;
	aux = (tLista*)malloc(sizeof(tLista));
	aux->id = id;
    aux->nome = nome;
    //strncpy(aux->nome, nome, TAM);
    aux->prox = head;
	head = aux;
	puts("Elemento inserido na lista.");
}

void excluir(int id){
    tLista *aux, *h = head;
    while(h != NULL){
        if(h->id == id){
            if(h == head)
                head = h->prox;
            else
                aux->prox = h->prox;
            free(h);
            puts("Elemento excluído da lista.");
            return;
        }
        aux = h;
        h = h->prox;
    }
    puts("Elemento não encontrado na lista.");
}

void listar(){
	tLista *h = head;
	puts("");
	while(h != NULL){
		printf("[%d  %s]\n" , h->id, h->nome);
		h = h->prox;
	}
	puts("");
}

void apagar(){
    tLista *aux, *h = head;
    while(h != NULL){
        aux = h->prox;
        free(h);
        h = aux;
    }
    head = NULL;
	puts("Lista temporária zerada.");
}

void salvar(char *caminho, const char *modo){
    FILE *arquivo;
    tLista *h = head;
    arquivo = fopen(caminho, modo);
	while(h != NULL){
        fprintf(arquivo, "%d,%s\n", h->id, h->nome);
		h = h->prox;
	}
    fclose(arquivo);
    printf("Lista salva no arquivo \'%s\'.\n", caminho);
}

void recuperar(char *caminho){
    FILE *arquivo;
    tLista *h = head;
    char linha[TAM];
    char nome[TAM];
    int id;
    
    arquivo = fopen(caminho, "r");
    
    if(arquivo != NULL){
        apagar();
        
        while( fgets(linha, sizeof(linha), arquivo) ){
            tLista *aux = malloc(sizeof(tLista));
            sscanf(linha, "%d,%s", &id, nome);
            aux->id = id;
            strncpy(aux->nome, nome, TAM);
            aux->prox = NULL;

            if(head == NULL){
                h = head = aux;
            } else {
                h = h->prox = aux;
            }
        }
    }
    fclose(arquivo);
    printf("Lista recuperada do arquivo \'%s\'.\n", caminho);
    return;
}

void menu(){
    setlocale(LC_ALL, NULL);
	int id, opcao;
	char nome[TAM], arq[TAM];
	puts("\n =================================================================");
	puts(" ||                  Sistema de Salvar Listas 1.0               ||");
	puts(" =================================================================\n");
	iniciar();
	do {
	    puts("Escolha uma opção do menu: ");
		puts(" 1. Inserir Elemento        4. Salvar em Arquivo");
		puts(" 2. Excluir Elemento        5. Ler de Arquivo");
		puts(" 3. Consultar Lista         0. Sair\n");
		printf(">>> ");
		scanf("%i", &opcao);
		switch(opcao){
			case 1:
				printf("\nDigite a ID para inserir: ");
				scanf("%i", &id);
				printf("Digite o nome para inserir: ");
				scanf("%s", nome);
				inserir(id, nome);
				break;
			case 2:
				printf("\nDigite a ID para excluir: \n");
				scanf("%i", &id);
				excluir(id);
				break;
			case 3:
				listar();
				break;
			case 4:
				printf("\nDigite o nome do arquivo para salvar: \n");
				scanf("%s", arq);
				salvar(arq, "w");
				break;
			case 5:
				printf("\nDigite o nome do arquivo para ler: \n");
				scanf("%s", arq);
				recuperar(arq);
				break;
			case 0:
				printf("\nSaindo... \n");
		}
	} while(opcao != 0);
}

int main(){
    menu();
    return 0;
}
