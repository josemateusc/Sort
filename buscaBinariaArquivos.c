#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

typedef struct tipoAluno{
    char nome[40];
    char pibic;
    char curso[40];
    float coeficienteRendimento;
    unsigned id;
} tipoAluno;

typedef struct tipoNo{
    tipoAluno dado;
    struct tipoNo *prox;    
} tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
    tipoNo *ult;  
} tipoLista;

unsigned long tamanhoArquivo(FILE *f){

    struct stat buf;
    fstat(fileno(f), &buf);
    return buf.st_size;
}

int buscarBinariaPorId(FILE *fp, unsigned chave, tipoAluno *al){
    long int inicio, fim, meio;
    inicio = 0;
    fim = (tamanhoArquivo(fp)/sizeof(tipoAluno))-1;

    while(inicio<=fim){
        meio = (inicio+fim)/2;
        fseek(fp,meio *sizeof(tipoAluno), SEEK_SET);
        fread(al,sizeof(tipoAluno), 1, fp);
        if(chave < al->id){
            fim = meio-1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

void mostra(tipoAluno al){
    printf("Nome: %s\n", al.nome);
    printf("Pibic: %d\n", al.pibic);
    printf("Curso: %s\n", al.curso);
    printf("Coeficiente: %.2f\n", al.coeficienteRendimento);
    printf("ID: %d\n", al.id);
}

int main(){
    tipoAluno al;
    FILE *fp;
    unsigned id=0;
    fp = fopen("ArquivoAlunos", "r");
    if(fp==NULL){
        exit(1);
    }
    while(id!=1000000000){
        printf("entre com um id: ");
        scanf("%u%*c", &id);
        if(buscarBinariaPorId(fp,id,&al)){
            printf("Encontrado:\n");
            mostra(al);
        }
        else{
            printf("Nao entcontrado no arquivo\n");
        }
    }
}