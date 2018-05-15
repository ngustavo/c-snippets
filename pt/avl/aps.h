#include "avl.h"

int hi;
char altura[1024];
Node *arvore = NULL;

void cabecalho();
int menu();
int menuExibir(int);
int menuInserir(int);
void exibir2D(Node*);
void subir(char);
void descer();
void aux2D(Node*);

void cabecalho(){
    puts("");
    puts("         d8888 8888888b.   .d8888b.       UniCarioca | Prof. Sergio Monteiro");
    puts("        d88888 888   Y88b d88P  Y88b      Estrutura de Dados | 331");
    puts("       d88P888 888    888 Y88b.           ");
    puts("      d88P 888 888   d88P  'Y888b.        + Gustavo Santana");
    puts("     d88P  888 8888888P'      'Y88b.      + Felipe Monsores");
    puts("    d88P   888 888              '888      + Clayton Santos");
    puts("   d8888888888 888        Y88b  d88P      ");
    puts("  d88P     888 888         'Y8888P'       ");
    puts("");
    puts(" ───────────┤ Arvores AVL ├──────────");
    puts("");
}

int menu() {
    int opcao, val, ordem = 0, chaves = 10;
    printf("\nEscolha uma opcao:\n\n");
    printf("1.Inserir           4.Em-Ordem              7.[BONUS] Exibir em 2D  \n");
    printf("2.Excluir           5.Pre-Ordem com []      8.[BONUS] Automatico    \n");
    printf("3.Automatico        6.Pos-Ordem             0.Sair                  \n");
    printf("\n>>>");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 0:
            return 0;
        case 1:
            printf("\nInsira a nova chave: ");
            scanf("%d", &val);
            arvore = inserirElemento(arvore, val);
            printf("\nChave %d inserida.\n", val);
            return 1;
        case 2:
            printf("\nInsira a chave a ser excluida: ");
            scanf("%d", &val);
            if(!excluirElemento(&arvore, val))
                printf("\nErro ao excluir %d.", val);
            printf("\nChave %d excluida.\n", val);
            return 1;
            
        case 3:
            printf("\nInserindo %d chaves aleatorias...\n", chaves);
            arvore = inserirAleatorios(arvore, chaves);
            printf("\nPre-Ordem com []:\n");
            preOrdem(arvore);
            printf("\n\nExcluindo a chave %d...\n", arvore->esq->chave);
            excluirElemento(&arvore, arvore->esq->chave);
            printf("\nPre-Ordem com []:\n");
            preOrdem(arvore);
            puts("");
            return 1;
        case 4:
            printf("\nEm-Ordem:\n");
            emOrdem(arvore);
            puts("");
            return 1;
        case 5:
            printf("\nPre-Ordem com []:\n");
            preOrdem(arvore);
            puts("");
            return 1;
        case 6:
            printf("\nPos-Ordem:\n");
            posOrdem(arvore);
            puts("");
            return 1;
        case 7:
            printf("\n[BONUS] Pre-Ordem em 2D:\n");
            exibir2D(arvore);
            puts("");
            return 1;
        case 8:
            printf("\nInserindo %d chaves aleatorias...\n", chaves);
            arvore = inserirAleatorios(arvore, chaves);
            printf("\n[BONUS] Pre-Ordem em 2D\n\n");
            exibir2D(arvore);
            printf("\n\nExcluindo a chave %d...\n", arvore->esq->chave);
            excluirElemento(&arvore, 28);
            printf("\n[BONUS] Pre-Ordem em 2D:\n\n");
            exibir2D(arvore);
            puts("");
            return 1;
        default:
            printf("\nOpcao Invalida!\n");
            return 1;
    }
}

// bonus

void exibir2D(Node* n){
    
    if(!n) return;
    
    printf("•%d\n", n->chave);
 
    if(n->esq){
        if(n->dir){
            printf("%s├───", altura);
            subir('|');
            exibir2D(n->esq);
            descer();
        }
        else {
            printf("%s└───", altura);
            subir(' ');
            exibir2D(n->esq);
            descer();
        }
    }
    if(n->dir){
        printf("%s└───", altura);
        subir(' ');
        exibir2D(n->dir);
        descer();
    }
}

void subir(char c){
    altura[hi++] = c;
    altura[hi++] = ' ';
    altura[hi++] = ' ';
    altura[hi++] = ' ';
    altura[hi] = 0;
}
 
void descer(){
    altura[hi -= 4] = 0;
}
