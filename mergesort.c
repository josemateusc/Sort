#include<stdio.h>
#include<stdlib.h>

void intercala(float v1[], unsigned tamV1, float v2[], unsigned tamV2, float aux[]){
    unsigned i, j, k;
    i=0; 
    j=0; 
    k=0;

    while( (i < tamV1) && (j < tamV2) ){
        if(v1[i] < v2[j]){
            aux[k] = v1[i];
            i++;
        }
        else{
            aux[k] = v2[j];
            j++;
        }
        k++;
    }

    while( i < tamV1){
        aux[k] = v1[i];
        i++; k++;
    }
    while( j < tamV2){
        aux[k] = v2[j];
        j++; k++;
    }
    // Em todo lugar, k = i+j
}


void mergeSortR(float lista[], float aux[], unsigned inicio, unsigned fim){    
    unsigned meio;


    if(inicio < fim){
        meio = (inicio+fim)/2;
        mergeSortR(v, aux, inicio, meio);
        mergeSortR(v, aux, meio+1, fim);
        //Intercalacao
        unsigned i, j, k;
        i=inicio; 
        j=meio+1;
        k=inicio;

        while( (i <= meio) && (j <= fim) ){
            if(lista[i] < lista[j]){
                aux[k] = lista[i];
                i++;
            }
            else{
                aux[k] = lista[j];
                j++;
            }
            k++;
        }

        while( i <= meio){
            aux[k] = lista[i];
            i++; k++;
        }
        while( j <= fim){
            aux[k] = lista[j];
            j++; k++;
        }
        
        //Passando elementos
        for(k=inicio; k<=fim; k++){
            lista[k] = aux[k];
        }
    }
}

void mergeSort(float lista[], unsigned tamanhoVetor){
    float *vaux;
    vaux = (float*) malloc(sizeof(float)*tamanhoVetor);
    mergeSortR(v, vaux, 0, tamanhoVetor-1);
    free(vaux);
}


int main(){
    float v1[5]= {2.0, 1.5, 3.2, 5.4, 7.9};
    float v2[7]= {1.0, 2.2, 4.5, 5.3, 9.0, 10.0, 11.0};
    float aux[12];
    float lista[10] = {10.0, 11.2, 1.2, 1.3, 5.4, 4.2, 3.2, 14.5,0.5, 8.5};
    float aux[10];
    intercala(v1, 5, v2, 7, aux);
    for(int i=0; i<12; i++){
        printf("%.1f ", aux[i]);
    }
    printf("\n");

    //mergeSort(v, vaux, 0, 9);
    mergeSort(v,10);

    for(int i=0; i<10; i++){
        printf("%.1f ", lista[i]);
    }
    printf("\n");
}