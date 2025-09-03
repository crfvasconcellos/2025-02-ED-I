#include "TStaticList.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 10
struct _list{
    int qty;//quantidade de elementos atualmente na lista
    int data[MAX];
};

bool TStaticList_is_empty(TStaticList* list){
    return list->qty == 0;
}
bool TStaticList_is_full(TStaticList* list){
    return list->qty == MAX;
}

TStaticList* TStaticList_create(){
//Vamos criar uma lista vazia
    TStaticList* nova = malloc(sizeof(TStaticList));
    if(nova != NULL){
        nova->qty = 0;
    }
    return nova;
}

bool TStaticList_insert_end(TStaticList* lista, int valor){
    if(lista!=NULL && !TStaticList_is_full(lista)){
        lista->data[lista->qty] = valor;
        lista->qty = lista->qty+1;
        return true;
    }
    return false;
}
bool TStaticList_insert_begin(TStaticList* lista, int valor){
    if (lista->qty == MAX)
    {
        return false;
    }

    for (int i = 0; i < lista->qty; i++)
    {
        lista->data[i+1]= lista->data[i];
    }

    lista->data[0] = valor;

    lista->qty++;

    return true;
    
    
    //TODO: Fazer a implementação usando a política de inserção do início
    //Olhe a documentação no arquivo .h e o slide 12 para referência
}
void TStaticList_print(TStaticList* lista){
    if(lista){
        if(TStaticList_is_empty(lista))
            puts("Lista vazia!");
        else{
            for(int i=0; i<lista->qty; i++)
                printf("[%d] ", lista->data[i]);
            putchar('\n');
        }
    }   
}
