#include <stdio.h>

void solucoes_otimas(){
    
}

int main(){

    int cap, N, pesoT = 0;
    scanf("%d\n%d", &cap, &N);

    int pesos[N], valores[N], escolhidos[N];

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



    return  0;
}