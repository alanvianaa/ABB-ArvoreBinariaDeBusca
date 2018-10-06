/******************************************************************************
                           Arvore Binária de Busca
                           Algoritimo simples e sem frecura.
                           Por: Alan Viana
Função Inserir e Imprimir em pre-ordem, em ordem e em pós-Ordem
*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *dir;
    struct no *esq;
}NO;

NO *inserir(NO *raiz,NO *p){

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

int main()
{
    NO *raiz;
    raiz = NULL;
    NO *p;
    int valor[5]={3,6,8,2,10};
    for(int i=0;i<5;i++){
        p=(NO*) malloc(sizeof(NO)); 
        p->chave=valor[i];
        p->dir = NULL;
        p->esq = NULL;
        if(raiz == NULL) raiz = p;
        else inserir(raiz,p);
    }
    
    imprimeOrdem(raiz);
    
    return 0;
}
