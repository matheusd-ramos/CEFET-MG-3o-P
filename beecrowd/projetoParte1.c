/*
LAED1 - Projeto (Parte I) - Busca por padrão em sequência
Aluno: Matheus de Araújo Ramos
Data: 13/06/2025
*/

#include <stdio.h>
#include <stdlib.h>

/* Fiz uma função para ler a entrada e, ao mesmo tempo, criar um vetor simplificado 
   (vetor com os números sem repetição e na mesma ordem) e retornar seu tamanho */
int lerEntrada(int N, int vetor[], int **vetSimp){
    // Alocando a memória no pior caso
    *vetSimp = (int*)malloc(N * sizeof(int));
    
    // Lendo o primeiro número para efeitos de comparação
    scanf("%d", &vetor[0]);
    int j = 0;
    (*vetSimp)[j] = vetor[0];
    
    for(int i = 1; i < N; i++){
        scanf("%d", &vetor[i]);
        
        // Se o número atual for diferente do anterior, adicionamos ao vetor simplificado
        if(vetor[i-1] != vetor[i]){
            j++;
            (*vetSimp)[j] = vetor[i];
        }
    }
    
    // Realocando para tamanho exato
    *vetSimp = (int*)realloc(*vetSimp, (j + 1) * sizeof(int));
    
    return j + 1; // Retorna o tamanho do vetor simplificado
}

void criarVetSeg(int tamVetSimp, int *vetSimp, int **vetSeg) {
    *vetSeg = (int*)malloc(tamVetSimp * sizeof(int));
    
    int *valoresUnicos = (int*)malloc(tamVetSimp * sizeof(int));
    int numUnicos = 0;
    
    // Coletar valores únicos 
    for (int i = 0; i < tamVetSimp; i++) {
        int encontrado = 0;
        for (int j = 0; j < numUnicos; j++) {
            if (valoresUnicos[j] == vetSimp[i]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            valoresUnicos[numUnicos] = vetSimp[i];
            numUnicos++;
        }
    }
    
    // Ordenar os valores únicos 
    for (int i = 0; i < numUnicos - 1; i++) {
        for (int j = 0; j < numUnicos - i - 1; j++) {
            if (valoresUnicos[j] > valoresUnicos[j+1]) {
                int temp = valoresUnicos[j];
                valoresUnicos[j] = valoresUnicos[j+1];
                valoresUnicos[j+1] = temp;
            }
        }
    }
    
    // Mapea cada valor para seu tipo de segmento (1 para o menor, 2 para o próximo, etc)
    for (int i = 0; i < tamVetSimp; i++) {
        for (int j = 0; j < numUnicos; j++) {
            if (vetSimp[i] == valoresUnicos[j]) {
                (*vetSeg)[i] = j + 1;
                break;
            }
        }
    }
    
    // Libera a memória alocada
    free(valoresUnicos);
}

int main(){
    int N;
    scanf("%d", &N);
    
    int vetor[N];  
    int *vetSimp, *vetSeg;
    int tamVetSimp = lerEntrada(N, vetor, &vetSimp);

    criarVetSeg(tamVetSimp, vetSimp, &vetSeg);
    
    for(int i = 0; i < tamVetSimp; i++){
        printf("%d ", vetSimp[i]);
    }

    printf("\n");

    for(int i = 0; i < tamVetSimp; i++){
        printf("%d ", vetSeg[i]);
    }
    
    // Libera a memória alocada
    free(vetSimp);
    free(vetSeg);
    
    return 0;
}