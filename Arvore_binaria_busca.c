/******************************************************************************
                           Arvore Binária de Busca
                           Algoritimo simples e sem frecura.
                           Por: Alan Viana
Função Inserir e Imprimir em pre-ordem, em ordem e em pós-Ordem
e a função buscar
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *dir;
    struct no *esq;
}NO;

void inserir(NO *raiz,NO *p){

    if(p->chave > raiz->chave){ 
        if(raiz->dir == NULL) raiz->dir = p;
        else inserir(raiz->dir,p);
    }
    if(p->chave < raiz->chave){
        if(raiz->esq == NULL) raiz->esq = p;
        else inserir(raiz->esq,p);
    }
}
void imprimePreOrdem(NO *raiz){ 
    printf("%d ",raiz->chave);
    if(raiz->esq != NULL) imprime(raiz->esq);
    if(raiz->dir != NULL) imprime(raiz->dir);
}

void imprimeOrdem(NO *raiz){ 
    if(raiz->esq != NULL) imprime(raiz->esq);
    printf("%d ",raiz->chave);
    if(raiz->dir != NULL) imprime(raiz->dir);
}

void imprimePosOrdem(NO *raiz){ 
    if(raiz->esq != NULL) imprime(raiz->esq);
    if(raiz->dir != NULL) imprime(raiz->dir);
    printf("%d ",raiz->chave);
}

void buscar(NO *raiz, int chave){
    if(raiz->chave == chave) printf("Achou");
    if(chave > raiz->chave && raiz->dir != NULL) buscar(raiz->dir,chave);
    if(chave < raiz->chave && raiz->esq != NULL) buscar(raiz->esq,chave);
}

void init(NO* raiz){ // inicializa árvore -- nó raiz
    raiz = NULL;
}

int nula(NO* raiz){ // verifica se árvore está vazia
    if(raiz == NULL) 
        return 1; // true para nulo 
    else 
        return 0;
}

int main()
{
    NO *raiz;    
    NO *p;

    init(raiz);

    int valor[5]={3,6,8,2,10};
    for(int i=0;i<5;i++){
        p=(NO*) malloc(sizeof(NO)); 
        p->chave=valor[i];
        p->dir = NULL;
        p->esq = NULL;
        if(nula(raiz)) raiz = p;
        else inserir(raiz,p);
    }
    
    imprimeOrdem(raiz);
    
    return 0;
}
