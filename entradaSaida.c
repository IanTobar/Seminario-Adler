#include<stdlib.h>
#include <stdio.h>
#include "entradaSaida.h"

int *leArquivo(char *nomeArquivo, int tamVet) {//le dados de testes do arquivo
    FILE *entrada;
    int *vet, i, aux;
    entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL) {
        printf("Arquivo nomeArquivo Nao Existe\n");
        return 1;
    }
    vet = (int*) malloc(tamVet * sizeof (int));
    if (vet == NULL) {
        printf("Memoria insuficiente para alocar vetor de testes\n");
        return 1;
    }
    for (i = 0; i < tamVet; i++) {
        fscanf(entrada, "%d\n", &vet[i]);
    }
    return vet;
    fclose(entrada);
}

void escreveArquivoCSV(int *vet, int tamVet, char *nomeArquivo) {//escreve o desempenho em arquivo csv
    int i;
    FILE *saida;
    saida = fopen(nomeArquivo, "a");
    for (i = 0; i < tamVet; i++) {
        fprintf(saida, "%d,", vet[i]);
    }
    fprintf(saida, "\n");
    fclose(saida);
}
