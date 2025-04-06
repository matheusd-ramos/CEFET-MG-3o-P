#include <stdio.h>

int mdc(int a, int b){
    if (a < b) {
        return mdc(b, a);
    }
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int main(){

    int x, y;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    printf("Resultado: %d\n", mdc(x, y));

    return 0;
}