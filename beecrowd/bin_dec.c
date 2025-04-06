#include <stdio.h>

void dec2bin(int dec){
    if(dec/2 != 0)
        dec2bin(dec/2);
    printf("%d", dec%2);
}

int main(){

    int x;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    printf("Resultado: ");
    dec2bin(x);
    printf("\n");

    return 0;
}