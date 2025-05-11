#include <stdio.h>

// Acha o maior valor de uma linha e salva seu índice (coluna, caixa)
int encontraMaiorValor(int linha, int N, int mat[][N], int* indice) {
    int maior_valor = mat[linha][0];
    *indice = 0;
    
    for(int i = 1; i < N; i++) {
        if(mat[linha][i] > maior_valor) {
            maior_valor = mat[linha][i];
            *indice = i;
        }
    }
    return maior_valor;
}

int main() {
    int N;
    scanf("%d", &N);

    int mat[N][N];
    int maior_soma = 0, soma = 0;
    int camada = 0, caixa = 0;

    // Preenche a matriz com 0
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mat[i][j] = 0;
        }
    }

    // Lê os elementos do teclado e salva na matriz (somente da diagonal principal para baixo)
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Pega o maior valor da ultima linha e realiza a soma com ele, adimitindo ser a maior
    // Depois faz isso com as outras linhas até achar uma que seja maior
    for(int linha = N-1; linha >= 0; linha--) {
        int indice_maior;
        soma = encontraMaiorValor(linha, N, mat, &indice_maior);

        for(int i = 0; i < linha; i++) {
            for(int j = 0; j <= i; j++) {
                soma += mat[i][j];
            }
        }

        if(soma > maior_soma) {
            maior_soma = soma;
            camada = linha + 1;
            caixa = indice_maior + 1;  
        }
    }

    printf("Resposta: camada %d, caixa %d.\n", camada, caixa);
    return 0;
}

