#include <stdio.h>
#include <stdlib.h>

void ordenaVetor(int vetor[], int N, int *vetorOrdenado){
    for(int i=0; i<N; i++){
        vetorOrdenado[i] = vetor[i];
    }

    for(int i=N; i>=0; i--){
        for(int j=0; j<N; j++){
            if(vetorOrdenado[j] > vetorOrdenado[j+1]){
                int aux = vetorOrdenado[j+1];
                vetorOrdenado[j+1] = vetorOrdenado[j];
                vetorOrdenado[j] = aux;
            }
        }
    }
}

void simplificaVetor(int *vetorOrdenado, int **vetorSimplificado, int *tam, int N) {
    *vetorSimplificado = malloc(sizeof(int) * N); 
    *tam = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0 || vetorOrdenado[i] != vetorOrdenado[i - 1]) {
            (*vetorSimplificado)[*tam] = vetorOrdenado[i];
            (*tam)++;
        }
    }

    *vetorSimplificado = realloc(*vetorSimplificado, (*tam) * sizeof(int));
}

int contaSegmentos(int *vetorOrdenado, int N){
    int numSegmentos=0;
    for(int i=0; i<N; i++){
        if(vetorOrdenado[i] != vetorOrdenado[i+1])
            numSegmentos++;
    }
    return numSegmentos;
}

int buscaSegmentoDoNum(int *vetorSimplificado, int num, int tam){
    for(int i=0; i<tam; i++){
        if(vetorSimplificado[i] == num)
            return i+1;
    }
}

void criaVetorSegmentos(int vetor[], int *vetorSimplificado, int **vetorSegmentos, int tam, int N){
    *vetorSegmentos = malloc(N*sizeof(int));
    int tamVetorSegmentos = 0;

    for(int i=0; i<N; i++){
        if(i == 0 || vetor[i] != vetor[i-1]){
            (*vetorSegmentos)[tamVetorSegmentos] = buscaSegmentoDoNum(vetorSimplificado, vetor[i], tam);
            tamVetorSegmentos++;
        }
    }

    *vetorSegmentos = realloc(*vetorSegmentos, tamVetorSegmentos * sizeof(int));
}

void criaVetorNElementos(int vetor[], int **vetorNElementos, int N){
    *vetorNElementos = calloc(N, sizeof(int));
    int tamVetorNElementos=0;

    for(int i=1; i<N; i++){
        if(vetor[i] == vetor[i-1]){
            (*vetorNElementos)[tamVetorNElementos]++;
        } else
            tamVetorNElementos++;
    }

    *vetorNElementos = realloc(*vetorNElementos, tamVetorNElementos * sizeof(int));
}

void criaMatriz(int ***matriz, int *vetorSegmentos, int *vetorNElementos, int numSegmentos){
    *matriz = malloc(2 * sizeof(int*));
    
    for(int i = 0; i < 2; i++){
        (*matriz)[i] = malloc(numSegmentos * sizeof(int));
    }

    for(int i = 0; i < numSegmentos; i++){
        (*matriz)[0][i] = vetorSegmentos[i];
    }

    for(int i = 0; i < numSegmentos; i++){
        (*matriz)[1][i] = vetorNElementos[i];
    }
}

int main(){
    int N;
    scanf("%d", &N);

    int vetor[N];

    for(int i=0; i<N; i++){
        scanf("%d", &vetor[i]);
    }

    int *vetorOrdenado = malloc(N*sizeof(int));
    ordenaVetor(vetor, N, vetorOrdenado);

    int numSegmentos = contaSegmentos(vetor, N);
    int *tam = malloc(sizeof(int));
    int *vetorSimplificado, *vetorSegmentos, *vetorNElementos;
    int **matriz;

    simplificaVetor(vetorOrdenado, &vetorSimplificado, tam, N);
    criaVetorSegmentos(vetor, vetorSimplificado, &vetorSegmentos, *tam, N);
    criaVetorNElementos(vetor, &vetorNElementos, N);
    criaMatriz(&matriz, vetorSegmentos, vetorNElementos, numSegmentos);

    for(int i=0; i<numSegmentos; i++){
        if(i==numSegmentos-1){
            printf("%d", matriz[0][i]);
        } else
            printf("%d ", matriz[0][i]);
    }

    printf("\n");

    for(int i=0; i<numSegmentos; i++){
        if(i==numSegmentos-1){
            printf("%d", matriz[1][i] + 1);
        } else
            printf("%d ", matriz[1][i] + 1);
    }

    printf("\n");


    for(int i = 0; i < 2; i++){
        free(matriz[i]);
    }
    free(matriz);

    free(vetorOrdenado);
    free(vetorSimplificado);
    free(vetorSegmentos);
    free(vetorNElementos);
    free(tam);

    return 0;
}