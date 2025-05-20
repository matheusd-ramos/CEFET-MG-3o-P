#include <stdio.h>

void solucoes_otimas(int pesos[], int cap, int N, int ***matriz){
    
}

void criaMatriz(int cap, int N, int ***matriz){                 // Passar endereço da matriz como parâmetro

    *matriz = (int**)calloc(N+1, sizeof(int*));                // Aloca N+1 arrays de inteiros (linhas)

    for(int i=0; i<=N; i++){
        (*matriz)[i] = (int *)calloc(cap+1, sizeof(int));       // Aloca cap+1 espaços em cada array (colunas)
    }
}

int main(){

    int cap, N, pesoT = 0;
    int **matriz;

    scanf("%d\n%d", &cap, &N);

    int pesos[N], valores[N], escolhidos[N];
    criaMatriz(cap, N, &matriz);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &pesos[i], &valores[i]);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &escolhidos[i]);
        if(escolhidos[i] == 1){
            pesoT = pesoT + pesos[i];
        }
    }

    if(pesoT > cap){
        printf("Solucao inviavel.\n");
        return 0;
    }

    // Liberando a memória
    for (int i = 0; i <= N; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return  0;
}