#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tipoDado{
    char nome[20];
    char unidade[20];
    float preco;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *prox;    
} tipoNo;

typedef struct tipoListaDeProdutos{
    char nome[60];
    tipoNo *prim;
} tipoListaDeProdutos;

// OPERAÇÔES

void criaLista(tipoListaDeProdutos *l, char nome[]){

    l->prim = NULL;
    strcpy(l->nome, nome);

}

void insereElemento(tipoListaDeProdutos *l, tipoDado *d){
    tipoNo * aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *d;
    aux->prox = l->prim;
    l->prim = aux;
}

void mostra(tipoListaDeProdutos *l){
    tipoNo * aux;

    aux = l->prim;

    printf("Lista do supermercado %s\n", l->nome);
    while (aux != NULL){
        printf("Produto: %s\n", aux->dado.nome);
        printf("Unidade: %s\n", aux->dado.unidade);
        printf("Preço: %.2f\n", aux->dado.preco);
        aux = aux->prox;
    }
    
}

void mostraDado(tipoDado *l){
    tipoNo * aux;
    printf("Produto: %s\n", aux->dado.nome);
    printf("Unidade: %s\n", aux->dado.unidade);
    printf("Preço: %.2f\n", aux->dado.preco);
    
}

tipoDado * busca(tipoListaDeProdutos *l, char *chave){
    tipoNo * aux;

    aux = l->prim;

    printf("Lista do supermercado %s\n", l->nome);
    while (aux != NULL){
        if( !strcmp(chave, aux->dado.nome)){ // strcmp(chave, aux->dado.nome) == 0
            return &(aux->dado);
        }
        aux = aux->prox;
    }
    return NULL;
}

int removeDado(tipoListaDeProdutos *l, char *chave){
    tipoNo *aux, *tmp;

    if(l->prim){
        //PRIMEIRO ELEMENTO
        if( !strcmp(chave, l->prim->dado.nome)){
            tmp = l->prim;
            l->prim = tmp->prox;
            free(tmp);
            return 1;
        }
        //DEMAIS ELEMENTOS
        aux = l->prim;
        while (aux ->prox){
            if( !strcmp(chave, aux->prox->dado.nome)){ // strcmp(chave, aux->dado.nome) == 0
                tmp = aux->prox;
                aux->prox = tmp->prox;
                free(tmp);
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

int main(){
    tipoListaDeProdutos lista1, lista2;
    tipoDado d;
    tipoDado *pDado;

    criaLista(&lista1, "DB");
    criaLista(&lista2, "Nova Era");

    strcpy(d.nome, "cebola");
    strcpy(d.unidade, "kg");
    d.preco = 4.99;
    insereElemento(&lista1, &d);

    strcpy(d.nome, "tomate");
    strcpy(d.unidade, "kg");
    d.preco = 9.99;
    insereElemento(&lista1, &d);

    strcpy(d.nome, "abacaxi");
    strcpy(d.unidade, "un");
    d.preco = 6.00;
    insereElemento(&lista1, &d);

    mostra(&lista1);

    printf("\n----------------------------\n");

    char nome[20];

    printf("Entre com a chave de busca: ");
    scanf("%[^\n]%*c", nome);
    pDado = busca(&lista1, nome);

    if(pDado){
        printf("\nEncontrado na Lista:");
        mostraDado(pDado);
    }
    else{
        printf("Nao encontrou!\n");
    }


    if(removeDado(&lista1, nome)){
        printf("\nRemovido com sucesso\n");
    }
    else{
        printf("\nNao removido\n");
    }

    mostra(&lista1);
}