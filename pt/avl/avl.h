#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
    int chave, altura;                                                  // AVL com chave e altura do tipo inteiro
    struct aux *esq, *dir;
} Node;

int maior(int, int);
int alturaArvore(Node*);
void preOrdem(Node*);                                                   // pré-ordem com colchetes
void emOrdem(Node*);
void posOrdem(Node*);
Node *buscaMenor(Node*);
Node *buscaMaior(Node*);
Node *criarNovoNode(int);
Node *rotacionarDireita(Node*);
Node *rotacionarEsquerda(Node*);
Node *rotacionarEsquerdaDireita(Node*);
Node *rotacionarDireitaEsquerda(Node*);
Node *inserirElemento(Node*, int);                                      // inserção
int excluirElemento(Node**, int);                                       // exclusão
Node *inserirAleatorios(Node*, int);

int maior(int a, int b){
    return a > b ? a : b;                                               // retorna o maior de dois números inteiros
}

int alturaArvore(Node *n){
    return n ? n->altura : 0;                                           // retorna a altura de uma árvore ou sub-árvore
}

void preOrdem(Node *n){
    if(!n) return;
    printf("%d[", n->chave);                                            // imprime uma árvore em pré-ordem com colchetes
    preOrdem(n->esq);
    preOrdem(n->dir);
    printf("]");
}

void emOrdem(Node *n){
    if(!n) return;
    preOrdem(n->esq);
    printf("%d", n->chave);                                             // imprime uma árvore em ordem
    preOrdem(n->dir);
}

void posOrdem(Node *n){
    if(!n) return;
    preOrdem(n->esq);
    preOrdem(n->dir);
    printf("%d", n->chave);                                             // imprime uma árvore em pós-ordem
}

Node *buscaMenor(Node *n){
    if(!n->esq) return n;                                               // retorna o menor elemento de uma árvore
    buscaMenor(n->esq);
}

Node *buscaMaior(Node *n){
    if(!n->dir) return n;                                               // retorna o maior elemento de uma árvore
    buscaMaior(n->dir);
}

Node *criarNovoNode(int novaChave){
    Node *n = (Node *)malloc(sizeof(Node));                             // cria o novo nó
    n->chave = novaChave;
    n->esq = n->dir = NULL;                                             // inicia com os valores padrão
    n->altura = 0;
    return n;
}

Node *rotacionarDireita(Node *n){
    Node *aux;
    aux = n->esq;
    n->esq = aux->dir;                                                  // faz a rotação trocando de lugar com a nova raiz
    aux->dir = n;
    int esquerda = alturaArvore(n->esq);                                // calcula a altura da esquerda e da direita
    int direita = alturaArvore(n->dir);
    n->altura = maior(esquerda, direita) + 1;                           // recalcula a altura da raiz anterior
    aux->altura = maior(esquerda, n->altura) + 1;                       // recalcula a altura da nova raiz
    return aux;
}

Node *rotacionarEsquerda(Node *n){
    Node *aux;
    aux = n->dir;
    n->dir = aux->esq;                                                  // faz a rotação trocando de lugar com a nova raiz
    aux->esq = n;
    int esquerda = alturaArvore(n->esq);                                // calcula a altura da esquerda e da direita
    int direita = alturaArvore(n->dir);
    n->altura = maior(esquerda, direita) + 1;                           // recalcula a altura da raiz anterior
    aux->altura = maior(direita, n->altura) + 1;                        // recalcula a altura da nova raiz
    return aux;
}

Node *rotacionarEsquerdaDireita(Node *n){
    n->esq = rotacionarEsquerda(n->esq);                                // rotaciona o filho esquerdo para a esquerda
    return rotacionarDireita(n);                                        // rotaciona a si mesmo para a direita
}

Node *rotacionarDireitaEsquerda(Node *n){
    n->dir = rotacionarDireita(n->dir);                                 // rotaciona o filho direito para a direita
    return rotacionarEsquerda(n);                                       // rotaciona a si mesmo para a esquerda
}

Node *inserirElemento(Node *n, int novaChave){
    if(!n)
        return criarNovoNode(novaChave);
    if(novaChave < n->chave){
        n->esq = inserirElemento(n->esq, novaChave);
        if(alturaArvore(n->esq) - alturaArvore(n->dir) == 2)            // se estiver desbalanceada, rotacione para a direita
            if(novaChave < n->esq->chave)
                n = rotacionarDireita(n);                               // direita simples se for menor que a do filho esquerdo
            else
                n = rotacionarEsquerdaDireita(n);                       // direita dupla se for maior
    } else if(novaChave > n->chave){
        n->dir = inserirElemento(n->dir, novaChave);
        if(alturaArvore(n->dir) - alturaArvore(n->esq) == 2)            // se estiver desbalanceada, rotacione para a esquerda
            if(novaChave > n->dir->chave)
                n = rotacionarEsquerda(n);                              // esquerda simples se for maior que a do filho direito
            else
                n = rotacionarDireitaEsquerda(n);                       // esquerda dupla se for menor
    }
    n->altura = maior(alturaArvore(n->esq), alturaArvore(n->dir)) + 1;  // recalcula a altura da raiz
    return n;
}

int excluirElemento(Node **n, int chave){
    if(!*n) return 0;
    int ret;
    if(chave < (*n)->chave){
        ret = excluirElemento(&(*n)->esq, chave);                       // se for menor, exclua na esquerda
        if(ret){
            if(alturaArvore((*n)->esq) - alturaArvore((*n)->dir) == 2){
                if(alturaArvore((*n)->dir->esq) <= alturaArvore((*n)->dir->dir))
                    (*n) = rotacionarEsquerda(*n);
                else
                    (*n) = rotacionarDireitaEsquerda(*n);               // se estiver desbalanceada, rotacione o filho direito
            }
        }
    } else if(chave > (*n)->chave) {
        ret = excluirElemento(&(*n)->dir, chave);                       // se for maior, exclua na direita
        if(ret){
            if(alturaArvore((*n)->dir) - alturaArvore((*n)->esq) == 2){
                if(alturaArvore((*n)->esq->dir) <= alturaArvore((*n)->esq->esq))
                    *n = rotacionarDireita(*n);
                else
                    *n = rotacionarEsquerdaDireita(*n);                 // se estiver desbalanceada, rotacione o filho esquerdo
            }
        }
    } else if(chave == (*n)->chave){                                    // se for igual, o elemento foi encontrado
        if(!(*n)->esq || !(*n)->dir){
            Node *anterior = *n;                                        // se um dos filhos for nulo, basta que o outro seja o pai
            if((*n)->esq)
                *n = (*n)->esq;
            else
                *n = (*n)->dir;
            free(anterior);
        } else {
            Node *aux = buscaMenor((*n)->dir);                          // se tiver dois filhos, o menor da direita será o novo pai
            (*n)->chave = aux->chave;
            excluirElemento(&(*n)->dir, (*n)->chave);
            if(alturaArvore((*n)->dir) - alturaArvore((*n)->esq) == 2){
                if(alturaArvore((*n)->esq->dir) <= alturaArvore((*n)->esq->esq))
                    *n = rotacionarDireita(*n);
                else
                    *n = rotacionarEsquerdaDireita(*n);                 // se estiver desbalanceada, rotacione o filho esquerdo
            }
        }
        return 1;
    }
    return ret;
}

Node *inserirAleatorios(Node *n, int x){
    if(!x) return n;
    n = inserirElemento(n, rand() % 99);                                // insere um elemento aleatório entre 0 e 98
    if(!n) inserirAleatorios(n, x);                                     // se a inserção falhou, tente novamente
    inserirAleatorios(n, x-1);
}
