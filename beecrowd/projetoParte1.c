/*
LAED1 - Projeto (Parte I) - Busca por padrão em sequência
Aluno: Matheus de Araújo Ramos
Data: 13/06/2025
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

void Retira(TipoApontador p, TipoLista *Lista, Segmento *seg){
    int aux;
    if(Vazia(*Lista) || p >= Lista->Ultimo){
        printf("Erro: posicao nao existe\n");
        return;
    }

    *seg = Lista->Segmentos[p-1];
    Lista->Ultimo--;
    for(aux=p; aux < Lista->Ultimo; aux++){
        Lista->Segmentos[aux-1] = Lista->Segmentos[aux];
    }
}

void Imprime(TipoLista Lista){
    for(int i = Lista.Primeiro-1; i <= (Lista.Ultimo-2); i++){
        printf("%d\n", Lista.Segmentos[i].Chave);
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

/* Essa função une a ordenação dos vetores com a criação de um vetor de mapeamento,
   ao invés de ter uma função para cada uma dessas etapas*/
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

int verificaSeg(int *vetSeg, int tamVetSimp, int sequencia[]){
    for(int i=0; i<tamVetSimp-4; i++){
        int match = 1;
        for(int j=0; j<5; j++){
            if(vetSeg[i+j] != sequencia[j]){
                match = 0;
                break;
            }
        }
        if(match)
            return 1;
    }
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    
    int vetor[N];  
    int sequencia[] = {1, 3, 2, 3, 1};
    int *vetSimp, *vetSeg;
    int tamVetSimp = lerEntrada(N, vetor, &vetSimp);
   
    /*
    printf("\nVetor simplificado: ");
    for(int i = 0; i < tamVetSimp; i++){
        printf("%d ", vetSimp[i]);
    }
    printf("\n");
    */

    criarVetSeg(tamVetSimp, vetSimp, &vetSeg);

    /*
    printf("\nVetor de segmentos: ");
    for(int i = 0; i < tamVetSimp; i++){
        printf("%d ", vetSeg[i]);
    }
    printf("\n");
    */

    TipoLista Lista;
    FLVazia(&Lista);
    preencherLista(&Lista, vetor, N, vetSeg, tamVetSimp);
    
    /*
    printf("\nLista de segmentos:\n");
    printf("Chave | Tipo | NumElementos | PontoMedio\n");
    for(int i = Lista.Primeiro-1; i < (Lista.Ultimo-1); i++){
        printf("%5d | %4d | %11d | %10d\n", 
               Lista.Segmentos[i].Chave,
               Lista.Segmentos[i].TipoSegmento,
               Lista.Segmentos[i].NumElementos,
               Lista.Segmentos[i].PontoMedio);
    }
    printf("\n");
    */
    
    if(verificaSeg(vetSeg, tamVetSimp, sequencia)){
        printf("Resultado: Padrao encontrado.\n");
    } else  
        printf("Resultado: Padrao nao encontrado.\n");
    
    // Libera a memória alocada
    free(vetSimp);
    free(vetSeg);
    
    return 0;
}