#include<stdio.h>
#include <stdlib.h>
#include"ordenacao.h"
#include"auxiliares.h"
#include"entradaSaida.h"

void selection(int *vet, int tamVet) {
    int aux, indiceMenor, marcador = 0;
    while (marcador < tamVet - 1) {
        indiceMenor = menor(vet, marcador + 1, tamVet);
        if (vet[indiceMenor] < vet[marcador]) {
            contaComparacoes();
            troca(vet, marcador, indiceMenor);
            contaTrocas();
        }
        marcador++;
    }



}
