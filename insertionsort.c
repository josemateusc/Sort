#include<stdio.h>

void insertionSort(float v[], unsigned tamanhoVetor){
    int i, j;
    float pivot;
    /*
    for(i=1; i<tamanhoVetor; i++){
        pivot = v[i];
        j = i-1;

        while((j>=0) && (v[j]>pivot)){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]= pivot;
    }
    */
    i = 1;
    while(i<tamanhoVetor){
        pivot = v[i];
        j = i-1;

        while((j>=0) && (v[j]>pivot)){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]= pivot;
        i++;
    }
}



int main(){
     float vet1[7]={10.2, 1.2, 30.5, 1.1, 50.4, 0.1, 5.0};
     insertionSort(vet1, 7);
     for(int i =0; i<7; i++){
         printf("%.1f, ", vet1[i]);
    }
    printf("\n");
}