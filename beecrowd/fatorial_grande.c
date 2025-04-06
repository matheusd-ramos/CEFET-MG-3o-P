#include <stdio.h>

void numToVet(int n, int vet[], int tam){
    for(int i=0; i<tam; i++){
        vet[i] = n%10;
        n = n/10;
    }
}

int main(){
    int n, vet[4];
    scanf("%d", &n);

    numToVet(n, vet, 4);

    for(int i=3; i >= 0; i--){
        printf("%d", vet[i]);
    }

    return 0;
}