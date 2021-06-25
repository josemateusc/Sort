#include<stdio.h>

void selectionSort(float vetor[], unsigned tamanhoVetor){
    unsigned i, cont, posMenor;
    unsigned penultimo = tamanhoVetor-1;
    float tmp;
    for(i=0; i<penultimo; i++){
        posMenor = i;
        for(cont = i+1;cont<tamanhoVetor; cont++){
            if(vetor[cont]<vetor[posMenor]){
                posMenor = cont;
            }
        }
        tmp = vetor[i];
        vetor[i] = vetor[posMenor];
        vetor[posMenor] = tmp;
    }
}


int main(){
     float vet1[7]={10.2, 1.2, 30.5, 1.1, 50.4, 0.1, 5.0};
     selectionSort(vet1, 7);
     for(int i =0; i<7; i++){
         printf("%.1f, ", vet1[i]);
    }
    printf("\n");
}