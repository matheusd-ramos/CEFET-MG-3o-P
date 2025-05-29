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

int* simplificaVetor(int *vetorOrdenado, int N, int *tam) {
    int *vetorSimplificado = malloc(sizeof(int) * N); 
    *tam = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0 || vetorOrdenado[i] != vetorOrdenado[i - 1]) {
            vetorSimplificado[*tam] = vetorOrdenado[i];
            (*tam)++;
        }
    }

    vetorSimplificado = realloc(vetorSimplificado, (*tam) * sizeof(int));
    return vetorSimplificado;
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

int* criaVetorSegmentos(int vetor[], int *vetorSimplificado, int tam, int N){
    int *vetorSegmentos = malloc(N*sizeof(int));
    int tamVetorSegmentos = 1;

    for(int i=0; i<N-1; i++){
        if(vetor[i] != vetor[i+1]){
            vetorSegmentos[tamVetorSegmentos-1] = buscaSegmentoDoNum(vetorSimplificado, vetor[i], tam);
            tamVetorSegmentos++;
        }
    }

    vetorSegmentos = realloc(vetorSegmentos, tamVetorSegmentos * sizeof(int));
    return vetorSegmentos;
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

    for(int i=0; i<N; i++){
        printf("%d ", vetorOrdenado[i]);
    }

    printf("\n\n");

    int numSegmentos = contaSegmentos(vetor, N);

    int *tam = malloc(sizeof(int));

    int *vetorSimplificado = simplificaVetor(vetorOrdenado, N, tam);
    int *vetorSegmentos = criaVetorSegmentos(vetor, vetorSimplificado, tam, N);

    for(int i=0; i<*tam; i++){
        printf("%d ", vetorSimplificado[i]);
    }


    return 0;
}