/*
LAED1 - Projeto (Parte III) - Impedimentos na pista
Aluno: Matheus de Araújo Ramos
Data: 11/07/2025
*/

#include <stdio.h>
#include <stdlib.h>

#define INICIOARRANJO 1
#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
    int TipoSegmento;
    int NumElementos;
    int PontoMedio;
} Segmento;

typedef struct{
    Segmento Segmentos[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista){
    return(Lista.Primeiro==Lista.Ultimo);
}

void Insere(Segmento x, TipoLista *Lista){
    if(Lista->Ultimo > MAXTAM){
        printf("Lista cheia\n");
    } else {
        Lista->Segmentos[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
}

void preencherLista(TipoLista *Lista, int vetor[], int N, int *vetSeg, int tamVetSimp){
    int numAtual = vetor[0];
    int cont = 1;
    int chaveAtual = 1;
    int inicio = 0;

    // Insere os segmentos com seus tipos
    for(int i=0; i<tamVetSimp; i++){
        Segmento segAtual;
        segAtual.Chave = i+1;
        segAtual.TipoSegmento = vetSeg[i];
        segAtual.NumElementos = 0;  
        segAtual.PontoMedio = 0;    
        Insere(segAtual, Lista);
    }

    // Atualiza o número de elementos e ponto médio
    for(int i=1; i<N; i++){
        if(vetor[i] == numAtual){
            cont++;
        } else {
            Lista->Segmentos[chaveAtual-1].NumElementos = cont;
            Lista->Segmentos[chaveAtual-1].PontoMedio = inicio + (cont - 1) / 2;
            
            numAtual = vetor[i];
            inicio = i;
            cont = 1;
            chaveAtual++;
        }
    }
    
    // Atualiza o último segmento
    Lista->Segmentos[chaveAtual-1].NumElementos = cont;
    Lista->Segmentos[chaveAtual-1].PontoMedio = inicio + (cont - 1) / 2;
}

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

void criarTiposSeg(int tamVetSimp, int *vetSimp, int **vetSeg) {
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

int verificaSeg(int *tiposSeg, int tamVetSimp, int sequencia[]){
    for(int i=0; i<tamVetSimp-4; i++){
        int match = 1;
        for(int j=0; j<5; j++){
            if(tiposSeg[i+j] != sequencia[j]){
                match = 0;
                break;
            }
        }
        if(match)
            return 1;
    }
    return 0;
}

/*
int detectaObstaculos(int *tiposSeg, int tamVetSimp, int sequencia[], int vetor[], int N){
    // Verifica se há a sequência esperada
    int temSequencia = 0;
    for(int i=0; i<tamVetSimp-4; i++){
        int match = 1;
        for(int j=0; j<5; j++){
            if(tiposSeg[i+j] != sequencia[j]){
                match = 0;
                break;
            }
        }
        if(match){
            temSequencia = 1;
            break;
        }
    }
    
    // Se não encontrou a sequência esperada, há impedimento
    if(!temSequencia)
        return 1;
    
    // Se encontrou a sequência, verifica outras características de obstáculo
    
    // Verifica se há valores muito diferentes dos esperados (0, 128, 255)
    for(int i=0; i<N; i++){
        if(vetor[i] != 0 && vetor[i] != 128 && vetor[i] != 255){
            return 1; 
        }
    }
    
    return 0; // Sem impedimento
}
*/

// Retorna 1 se encontrar o sanduíche 1 3 2 ... 2 3 1, 0 caso contrário
int detectaObstaculo(int *tiposSeg, int tam) {
    for (int i = 0; i <= tam - 3; i++) {
        // Procura {1, 3, 2}
        if (tiposSeg[i] == 1 && tiposSeg[i+1] == 3 && tiposSeg[i+2] == 2) {
            // Procura {2, 3, 1} depois de i+3
            for (int j = i + 3; j <= tam - 3; j++) {
                if (tiposSeg[j] == 2 && tiposSeg[j+1] == 3 && tiposSeg[j+2] == 1) {
                    return 1; // Achou sanduíche de obstáculo, há impedimento
                }
            }
        }
    }
    return 0; // Não há impedimento
}

int verificaCurva(TipoLista Listas[], int L, int entradasN[], int seqIdentificada[]){
    int cont=0, tolerancia=30;
    
    for(int i=0; i<L; i++){
        if(seqIdentificada[i])
            cont++;
    }

    /* Condição para verificar se a quantidade de linhas que contém a sequência é 
       maior ou igual à 70% das linhas */
    if(cont < 0.7 * L)
        return 0;

    // Analisa as linhas de cima para baixo e usa a primeira que contém a sequência
    for(int i=0; i<L; i++){
        if(seqIdentificada[i]){ 
            int j=0;
            while(j < Listas[i].Ultimo - Listas[i].Primeiro && 
                  Listas[i].Segmentos[j].TipoSegmento != 2){
                j++;
            }
            
            // Se encontrou o segmento tipo 2, calcula a variação
            if(j < Listas[i].Ultimo - Listas[i].Primeiro){
                int variacao = entradasN[i]/2 - Listas[i].Segmentos[j].PontoMedio;
                
                if(abs(variacao) > tolerancia){
                    if(variacao < 0){
                        return -1; // Curva à direita
                    } else {
                        return 1;  // Curva à esquerda
                    }
                } else {
                    return 0; // Linha reta
                }
            }
        }
    }
    
    return 0;
}

int main(){

    int sequencia[] = {1, 3, 2, 3, 1};

    int L;
    scanf("%d", &L);

    // Criando um vetor de listas de segmentos
    TipoLista Listas[L];

    // Vetor para armazenar a entrada N de cada linha
    int entradasN[L];

    // Vetor para identificar as linhas nas quais a sequência foi identificada
    int seqIdentificada[L];
    
    // Flag para verificar se há impedimentos na pista
    int impedimentoDetectado = 0;
    for(int i=0; i<L; i++){
        // Lê a qtde de elementos e cria o vetor
        int N;
        scanf("%d", &N);
        entradasN[i] = N;
        int vetor[N];

        int *vetSimp;
        int tamVetSimp = lerEntrada(N, vetor, &vetSimp);

        int *tiposSeg;
        criarTiposSeg(tamVetSimp, vetSimp, &tiposSeg);

        // Verifica se a linha contém a sequência esperada
        seqIdentificada[i] = verificaSeg(tiposSeg, tamVetSimp, sequencia);

        // Verifica se há sanduíche de obstáculo
        if(detectaObstaculo(tiposSeg, tamVetSimp)){
            impedimentoDetectado = 1;
        }

        // Cria uma lista com os segmentos de cada linha
        TipoLista Lista;
        FLVazia(&Lista);
        preencherLista(&Lista, vetor, N, tiposSeg, tamVetSimp);

        Listas[i] = Lista;

        // Libera a memória alocada
        free(vetSimp);
        free(tiposSeg);
    }

    /*
    int resultadoCurva = verificaCurva(Listas, L, entradasN, seqIdentificada);

    if (resultadoCurva == -1) {
        printf("Resultado: Curva a direita.\n");
    } else if (resultadoCurva == 1) {
        printf("Resultado: Curva a esquerda.\n");
    } else if (resultadoCurva == 0) {
        printf("Resultado: Pista em linha reta.\n");
    }
    */
    
    /*
    for(int i=0; i<L; i++){
        printf("\nLista de segmentos (linha %d):\n", i+1);
        printf("Chave | Tipo | NumElementos | PontoMedio\n");
        for(int j = Listas[i].Primeiro-1; j < (Listas[i].Ultimo-1); j++){
            printf("%5d | %4d | %12d | %10d\n", 
                Listas[i].Segmentos[j].Chave,
                Listas[i].Segmentos[j].TipoSegmento,
                Listas[i].Segmentos[j].NumElementos,
                Listas[i].Segmentos[j].PontoMedio);
        }
        printf("\n");
    }
    */

    if (impedimentoDetectado) {
        printf("Resultado: Pista com impedimento.\n");
    } else {
        printf("Resultado: Pista sem impedimento.\n");
    }

    return 0;
}