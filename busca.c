#include<stdio.h>
#include<string.h>

typedef struct tipoAluno{
    char nome[50];
    int matricula;
    char curso[50];
} tipoAluno;

/*Função que recebe como parametro um vetor de alunos (tipoAluno) e um nome para busca. A função retorna -1 caso
o aluno buscado nao exista no vetor, e retornar a posição de ocorrência em caso contrário*/

/*void lerVetor(float vet[], unsigned tamanhoVetor){
    unsigned i;
    for(i=0;i<tamanhoVetor;i++){
        scanf("%f%*c", &vet[i]);
    }
}*/

int buscaSequencial(tipoAluno vetor[], unsigned tamanhoVetor, char chave[]){
    unsigned i;
    for(i=0;i<tamanhoVetor;i++){
        if(strcmp(vetor[i].nome, chave)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    tipoAluno alunos[7];
    char nome[40];
    int pos;

    strcpy(alunos[0].nome, "Jose Mateus");
    strcpy(alunos[1].nome, "Aderbal Lacerda");
    strcpy(alunos[2].nome, "Guilherme Ferreira");
    strcpy(alunos[3].nome, "Julio Costa");
    strcpy(alunos[4].nome, "Edleno Moura");
    strcpy(alunos[5].nome, "Felipe");
    strcpy(alunos[6].nome, "João Mateus");
    strcpy(alunos[0].curso, "Jose Mateus");
    strcpy(alunos[1].curso, "Aderbal Lacerda");
    strcpy(alunos[2].curso, "Guilherme Ferreira");
    strcpy(alunos[3].curso, "Julio Costa");
    strcpy(alunos[4].curso, "Edleno Moura");
    strcpy(alunos[5].curso, "Felipe");
    strcpy(alunos[6].curso, "João Mateus");
    for(int cont = 0; cont<7; cont++){
        alunos[cont].matricula = cont;
    }

    //lerVetor(vet1, tamanhoVetor);
    printf("Nome: ");
    scanf("%[^\n]%*c", nome);
    pos = buscaSequencial(alunos, 7, nome);
    if(pos != -1){
        printf("Curso: %s\n", alunos[pos].curso);
        printf("Matricula: %d\n", alunos[pos].matricula);
    }
    else{
        printf("Chave nao encontrada\n");
    }
}