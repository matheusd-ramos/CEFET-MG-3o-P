#include <stdio.h>

int maiorValorDaLinha(int **mat, int i, int j){
    int maior_valor = mat[i][0];
    for(int k=1; k<j; k++){
        if(mat[i][k] > maior_valor)
            maior_valor = mat[i][k];
    }
    return maior_valor;
}

int main(){
    int N, maior_soma;

    scanf("%d", &N);

    int mat[N][N];

    // Preencher a matriz com 0
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            mat[i][j] = 0;
        }
    }

    // Coloca os elementos na matriz
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j>i)
                continue;
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    maior_soma = maiorValorDaLinha(mat, 2, N);

    printf("%d", maior_soma);
}