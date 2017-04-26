#include <stdio.h>
#include <stdlib.h>
#include "entradaSaida.h"
#include "ordenacao.h"
#include<sys/time.h>

int main(int argc, char* argv[]) {
    int i, tamVet, *vet, j = 0, op;
    struct timeval inicio, final;
    unsigned long long int *tempo, *comparacao, *troca;
    
    printf("Digite o tamanho do vetor que sera utilizado na ordenacao:\n");
    scanf("%d",&tamVet);
    tempo = (int*) malloc(5 * sizeof (int));
    
    if (tempo == NULL) {
        printf("Memoria Insuficiente para alocar vetor de tempo\n");
        return 1;
    }
    troca = (unsigned long long int*) malloc(5 * sizeof (unsigned long long int));
    if (troca == NULL) {
        printf("Memoria Insuficiente para alocar vetor de troca\n");
        return 1;
    }
    comparacao = (unsigned long long int*) malloc(5 * sizeof (unsigned long long int));
    if (comparacao == NULL) {
        printf("Memoria Insuficiente para alocar vetor de comparacao\n");
        return 1;
    }
    op = atoi(argv[1]);
    if (op == 1) {
        for (i = 3; i < 8; i++) {
            vet = leArquivo(argv[i], tamVet);
            gettimeofday(&inicio, NULL);
            selection(vet, tamVet);
            gettimeofday(&final, NULL);
            tempo[i - 3] = calculaTempoMili(inicio, final);
            if (i - 3 == 0) {
                troca[i - 3] = contaTrocas() - 1;
                comparacao[i - 3] = contaComparacoes() - 1;
            } else {
                troca[i - 3] = ((contaTrocas() - 1) - troca[j]);
                comparacao[i - 3] = ((contaComparacoes() - 1) - troca[j]);
                j++;
            }

        }

    } else {
        if (op == 2) {
            for (i = 3; i < 8; i++) {
                vet = leArquivo(argv[i], tamVet);
                gettimeofday(&inicio, NULL);
                rapidSort(vet, tamVet);
                gettimeofday(&final, NULL);
                tempo[i - 3] = calculaTempoMili(inicio, final);
                if (i - 3 == 0) {
                    troca[i - 3] = contaTrocas() - 1;
                    comparacao[i - 3] = contaComparacoes() - 1;
                } else {
                    troca[i - 3] = ((contaTrocas() - 1) - troca[j]);
                    comparacao[i - 3] = ((contaComparacoes() - 1) - troca[j]);
                    j++;
                }
            }


        }


    }
    escreveArquivoCSV(tempo, 5, argv[8]);
    escreveArquivoCSV(comparacao, 5, argv[8]);
    escreveArquivoCSV(troca, 5, argv[8]);
    return (EXIT_SUCCESS);
}
