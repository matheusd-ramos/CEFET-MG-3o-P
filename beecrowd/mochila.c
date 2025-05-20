#include <stdio.h>

void solucao_otima(int peso[], int valor[], int cap, int N, int matriz[N+1][cap+1], int solucao[]){

    // Variáveis auxiliares 
    int x=0, y=0;

    // Zera a primeira linha e coluna
    for (int i = 0; i <= N; i++) 
        matriz[i][0] = 0;
    for (int j = 0; j <= cap; j++) 
        matriz[0][j] = 0;
    
    // Preenche a tabela
    for(int i=1; i <= N; i++){
        for(int j=1; j <= cap; j++){    // j é a capacidade atual
                
            if(peso[i-1] > j){
                matriz[i][j] = matriz[i-1][j];   
            } else{
                x = matriz[i-1][j-peso[i-1]] + valor[i-1];
                y = matriz[i-1][j];

                if(x > y){
                    matriz[i][j] = x;
                } else{
                    matriz[i][j] = y;
                }
            }
        }
    }

    // Retoma a matriz para definir a solução
    int j = cap;  
    for (int i = N; i >= 1; i--) {
        if (matriz[i][j] != matriz[i-1][j]) {  // Item foi incluído
            solucao[i-1] = 1;  // Marca como selecionado
            j -= peso[i-1];    // Reduz a capacidade restante
        } else {
            solucao[i-1] = 0;  // Item não foi incluído
        }
    }
}

void verifica_solucao(int escolhidos[], int solucao[], int N){
    for(int i=0; i<N; i++){
        if(escolhidos[i] != solucao[i]){
            printf("Solucao viavel mas nao otima.\n");
            return;
        }
    }
    printf("Solucao otima.\n");
}

int main(){

    int cap, N, pesoT = 0;

    scanf("%d\n%d", &cap, &N);

    int peso[N], valor[N], escolhidos[N], solucao[N];
    int matriz[N+1][cap+1];

    // Coleta os pesos
    for(int i = 0; i < N; i++){
        scanf("%d %d", &peso[i], &valor[i]);
    }

    // Coleta os itens escolhidos
    for(int i = 0; i < N; i++){
        scanf("%d", &escolhidos[i]);
        if(escolhidos[i] == 1){
            pesoT = pesoT + peso[i];
        } 
    }

    if(pesoT > cap){
        printf("Solucao inviavel.\n");
        return 0;
    }

    // Calcula a solução ótima
    solucao_otima(peso, valor, cap, N, matriz, solucao);

    // Printa o resultado
    verifica_solucao(escolhidos, solucao, N);

    return  0;
}