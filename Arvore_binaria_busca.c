/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

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

void imprime(NO *raiz){
    
    if(raiz->esq != NULL) imprime(raiz->esq);
    printf("%d ",raiz->chave);
    if(raiz->dir != NULL) imprime(raiz->dir);
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
    
    imprime(raiz);
    
    return 0;
}
