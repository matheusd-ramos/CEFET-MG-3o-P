#include <stdio.h>

int Digitos(int N){
    if(N >= 10){
        return 1 + Digitos(N/10);
    }
    return 1;
}

int main(){

    int N, result;

    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    result = Digitos(N);

    printf("Resultado: %d\n", result);

    return 0;
}

