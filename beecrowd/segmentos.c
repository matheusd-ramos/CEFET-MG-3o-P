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

int defineSegmentos(int *vetorOrdenado, int N){
    int numSegmentos=0;
    for(int i=0; i<N; i++){
        if(vetorOrdenado[i] != vetorOrdenado[i+1])
            numSegmentos++;
    }
    return numSegmentos;
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

    printf("\n%d", defineSegmentos(vetorOrdenado, N));

    return 0;
}