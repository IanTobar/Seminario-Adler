#include"auxiliares.h"
#include <stdlib.h>

int contaComparacoes() {//conta comparacoes
    static unsigned long long int contador = 0;
    contador++;
    return contador;
}

int contaTrocas() {//conta trocas
    static unsigned long long int contador = 0;
    contador++;
    return contador;
}

int menor(int *vet, int inicio, int tamVet) {//encontra o menor elemento em um vetor ou pedaco de vetor
    int menor, i, indice;
    menor = vet[inicio];
    for (i = inicio; i < tamVet; i++) {
        contaComparacoes();
        if (menor > vet[i]) {
            menor = vet[i];
            indice = i;
        }
    }
    return indice; //retorna o indice do menor
}

int maior(int *vet, int tamVet, int inicio) { // encontra o maior elemento em um vetor ou pedaco de vetor
    int i, indice, maior;
    maior = vet[inicio];
    for (i = inicio; i < tamVet; i++) {
        contaComparacoes();
        if (maior < vet[i]) {
            maior = vet[i];
            indice = i;
        }
    }
    return i;//retorna o indice do maior
}

void troca(int *vet, int indice1, int indice2) {//troca dois elementos de um vetor partindo de seus indices
    int aux;
    aux = vet[indice1];
    indice1 = indice2;
    indice2 = aux;
}


int calculaTempoMili(struct timeval inicio, struct timeval final) {//faz o calculo do tempo em milisegundos
    int tmili;
    tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    return tmili;
}


void escreveArquivoTXT(int *vet, int tamVet) {
    int i;
    FILE *saida;
    saida = fopen("ordenado50000.txt", "w");
    for (i = 0; i < tamVet; i++) {
        fprintf(saida, "%d\n", vet[i]);
    }
}

void geraAleatorios(int *vet, int tamVet) {
    int i;
    srand(time(NULL));
    for (i = 0; i < tamVet; i++)
        vet[i] = (rand() % 200000);

}





