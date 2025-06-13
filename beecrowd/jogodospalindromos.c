#include <stdio.h>
#include <stdlib.h>

#define max 1000

void contarLetras(int *qtdeLetras, char letras[], int numLetras){
    for(int i = 0; i < numLetras; i++){
        if(letras[i] >= 'a' && letras[i] <= 'z'){
            qtdeLetras[letras[i] - 'a']++;
        }
    }
}

int verificarPalindromo(int *qtdeLetras){
    int impares = 0;
    
    for(int i = 0; i < 26; i++){
        if(qtdeLetras[i] != 0){
            if(qtdeLetras[i] % 2 == 1){
                impares++;
            }
        }
    }

    if(impares == 0){
        return 0;
    }
    else{
        return impares - 1;
    }
}

int main(){
    char letras[max];
    int numLetras;

    while(scanf("%s", letras) != EOF){
        numLetras = 0;
        while(letras[numLetras] != '\0'){
            numLetras++;
        }

        int *qtdeLetras = calloc(26, sizeof(int));

        contarLetras(qtdeLetras, letras, numLetras);
        printf("%d\n", verificarPalindromo(qtdeLetras));

        free(qtdeLetras);
    }

    return 0;
}