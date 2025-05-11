#include <stdio.h>

void decompor_rec(int N, int soma_atual, int ultimo, int particao[], int k) {
    if (soma_atual == N) {
        for (int i = 0; i < k; i++) {
            if (i > 0) printf(" + ");
            printf("%d", particao[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = ultimo; i >= 1; i--) {
        if (soma_atual + i <= N) {
            particao[k] = i;
            decompor_rec(N, soma_atual + i, i, particao, k + 1);
        }
    }
}

int main(){
    int N;

    scanf("%d", &N);
    int particao[N];
    printf("Decomposicao:\n");
    decompor_rec(N, 0, N, particao, 0);

    return 0;
}