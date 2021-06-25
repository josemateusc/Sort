#include<stdio.h>

void quickSort1(float v[], int inicio, int fim){
    int i, j;
    float pivot, tmp;

    //if(inicio < fim){
        //Particiona o vetor
        pivot = v[(inicio+fim)/2];
        i = inicio;
        j = fim;
        while(i <= j){
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if (i <= j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++;
                j--;
            }
        }
        if(inicio < j){quickSort1(v, inicio, j);}
        if(i < fim){quickSort1(v, i, fim);}
    //}
}

void quickSort(float v[], unsigned tamanhoVetor){
    if(tamanhoVetor>0){
        quickSort1(v, 0, tamanhoVetor-1);
    }
}

//QUICKSORT MAIS ROBUSTO
/*
void quickSort(float v[], int inicio, int fim){
    int i, j;
    float pivot, tmp;

    while(inicio < fim){
        //Particiona o vetor
        pivot = v[(inicio+fim)/2];
        i = inicio;
        j = fim;
        while(i <= j){
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if (i <= j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++;
                j--;
            }
        }
        if(j < meio){
            quickSort(v, inicio, j);
            inicio = i;
        }
        else{
            quicSort(v, i, fim);
            fim = j;
        }
    }
}


*/

//QUICKSORT SEGMENTADO E COM INSERTIONSORT
/*
#define limiarInsercao 60


void insertionSort(float v[], unsigned tamanhoVetor){
    int i, j;
    float pivot;
    //Passa o menor para 1a posicao
    j = 0;
    for(i=1; i < limiarInsercao; i++){
        if(v[i] < v[j]){
            j = i;
        }
    }
    pivot = v[j];
    v[j] = v[0];
    v[0] = pivot;

    //ordenacao por insercao
    for(i = 1; i < tamanhoVetor; i++){
        pivot = v[i];
        j = i-1;
        while(v[j] > pivot){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = pivot;
    }
}


void quickSortR(float v[], int inicio, int fim){
    int i, j;
    float pivot, tmp;

    if(fim-inicio > limiarInsercao){
        //Particiona o vetor
        pivot = v[(inicio+fim)/2];
        i = inicio;
        j = fim;
        while(i <= j){
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if (i <= j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++;
                j--;
            }
        }
        quickSortR(v, inicio, j);
        quickSortR(v, i, fim);
    }
}

void quickSort(float v[], unsigned tamanhoVetor){
    quickSortR(v, 0, tamanhoVetor-1);
    insertionSort(v,tamanhoVetor);
}
*/


int main(){
    float v[10] = {1.2,10.2,5.0,2.1,1.2,3.2,6.4,8.4,4.3,10.1};

    quickSort(v, 10);

    for(unsigned i = 0; i<10; i++){
        printf("%.1f ", v[i]);
    }
    printf("\n");
}