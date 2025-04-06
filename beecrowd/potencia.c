#include <stdio.h>

int mult(int base, int expoente){
    if(expoente > 0){
        return base * mult(base, expoente - 1);
    }
    return 1;
}

int main(){

    int n, x;
    
    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &x, &n);

    printf("Resultado: %d\n", mult(x, n));

    return 0;
}