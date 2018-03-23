#include <stdio.h>
#include <stdlib.h>

typedef struct eno {
    int valor;
    struct eno *esq;
    struct eno *dir;
} No;

No *criar(int);
void inserir(No**,int);
void emOrdem(No*);
void preOrdem(No*);
void posOrdem(No*);
void imprimir(int);
int menu();
int maior(int,int);
int altura(No*);
int quantidade(No*);

No *raiz = NULL;

int main() {
    while(menu());
    return 0;
}

No *criar(int val){
    No *n = (No*)malloc(sizeof(No));
    n->valor = val;
    n->esq = n->dir = NULL;
    return n;
}

void inserir(No **raiz, int val){
    
    if(!*raiz){
        *raiz = criar(val);
        return;
    }
    
    if( val < (*raiz)->valor )
        inserir( &(*raiz)->esq, val );
    else
        inserir( &(*raiz)->dir, val );
}

void emOrdem(No *n){
    
    if(!n) return;
    
    emOrdem( n->esq );
    printf("%d ", n->valor );
    emOrdem( n->dir );
}

void preOrdem(No *n){
    
    if(!n) return;
    
    printf("%d ", n->valor );
    emOrdem( n->esq );
    emOrdem( n->dir );
}

void posOrdem(No *n){
    
    if(!n) return;
    
    emOrdem( n->esq );
    emOrdem( n->dir );
    printf("%d ", n->valor );
}

void imprimir(int i){
    switch(i){
        case 1:
            printf("\nEm Ordem: ");
            emOrdem(raiz);
            break;
        case 2:
            printf("\nPre Ordem: ");
            preOrdem(raiz);
            break;
        case 3:
            printf("\nPos Ordem: ");
            posOrdem(raiz);
            break;
        default:
            printf("\nOpcao Invalida!");
    }
}

int menu() {
    int opcao;
    printf("\n 0.sair  1.inserir  2.imprimir  3.altura  4.quantidade\n\n");
    scanf("%d", &opcao);
    int val;
    int ordem = 0;
    
    switch(opcao){
        case 0: return 0;
        case 1:
            printf("\nInsira o valor: ");
            scanf("%d", &val);
            inserir(&raiz, val);
            return 1;
        case 2:
            printf("\n 1.em ordem  2.pre ordem  3.pos ordem\n\n");
            scanf("%d", &ordem);
            imprimir(ordem);
            printf("\n");
            return 1;
        case 3:
            printf("\nAltura: %d \n", altura(raiz));
            return 1;
        case 4:
            printf("\nQuantidade: %d \n", quantidade(raiz));
            return 1;
        default:
            printf("\nOpcao Invalida!");
            return 1;
    }
}

int maior(int a, int b){
    return a > b ? a : b;
}

int altura(No *n){
    
    if(!n) return 0;
    
    int esquerda = altura( n->esq );
    int direita = altura( n->dir );
    return maior(esquerda, direita) + 1;
}

int quantidade(No *n){
    
    if(!n) return 0;
    
    int esquerda = quantidade( n->esq );
    int direita = quantidade( n->dir );
    return esquerda + direita + 1;
}
