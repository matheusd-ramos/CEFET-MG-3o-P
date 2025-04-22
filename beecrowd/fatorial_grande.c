#include <stdio.h>
#include <stdlib.h>

int* numPVet(int n) {
    int* v = calloc(6000, sizeof(int));
    
    if (v == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    int i = 0;
    while (n > 0) {
        v[i] = n % 10;
        n = n / 10;
        i++;
    }
    
    return v;
}

int* multVetPorEscalar(int vet[], int esc) {
    int* vresult = calloc(6000, sizeof(int));
    
    if (vresult == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    int tEnt = 0;
    
    for (int i = 0; i < 6000; i++) {
        vresult[i] = (vet[i] * esc + tEnt) % 10;
        tEnt = (vet[i] * esc + tEnt) / 10;
    }
    
    return vresult;
}

int* somaVetores(int v1[], int v2[]) {
    int* vresult = calloc(6000, sizeof(int));
    
    if (vresult == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    int tEnt = 0;
    
    for (int i = 0; i < 6000; i++) {
        vresult[i] = (v1[i] + v2[i] + tEnt) % 10;
        tEnt = (v1[i] + v2[i] + tEnt) / 10;
    }
    
    return vresult;
}

int* potencia10Vetor(int vet[], int exp) {
    int* vresult = calloc(6000, sizeof(int));
    
    if (vresult == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    for (int i = 0; i < 6000 - exp; i++) {
        vresult[i + exp] = vet[i];
    }
    
    return vresult;
}

int* multVetPorVet(int v1[], int v2[]) {
    int* vresult = calloc(6000, sizeof(int));
    
    if (vresult == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    int ultimoDigito = 0;
    for (int i = 5999; i >= 0; i--) {
        if (v2[i] != 0) {
            ultimoDigito = i;
            break;
        }
    }
    
    for (int i = 0; i <= ultimoDigito; i++) {
        if (v2[i] != 0) {
            int* soma = somaVetores(vresult, potencia10Vetor(multVetPorEscalar(v1, v2[i]), i));
            
            free(vresult);
            
            vresult = soma;
        }
    }
    
    return vresult;
}

void printaVetor(int vet[]) {
    int i = 5999;
    
    while (i >= 0 && vet[i] == 0) {
        i--;
    }
    
    if (i < 0) {
        printf("0");
        return;
    }
    
    while (i >= 0) {
        printf("%d", vet[i]);
        i--;
    }
}

int* fatorialGrande(int n) {
    int* resultado = calloc(6000, sizeof(int));
    
    if (resultado == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    resultado[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        int* num = numPVet(i);
        int* temp = multVetPorVet(resultado, num);
        
        free(resultado);
        free(num);
        
        resultado = temp;
    }
    
    return resultado;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    int* resultado = fatorialGrande(n);
    
    printf("Resultado: ");
    printaVetor(resultado);
    printf("\n");
    
    free(resultado);
    
    return 0;
}