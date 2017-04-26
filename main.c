#include <stdio.h>
#include <stdlib.h>
#include "entradaSaida.h"
#include "ordenacao.h"
#include<sys/time.h>

int main(int argc, char* argv[]) {
    int i, tamVet, *vet, j = 0, op;
    struct timeval inicio, final;
    unsigned long long int *tempo, *comparacao, *troca;
    printf("\ncmdline args count= %d", argc);
    /* First argument is executable name only */
    printf("\nexe name=%s", argv[0]);

    //For usado somente para testes
    for (i = 1; i < argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    
    printf("\n");
    //O comando atoi converte uma string em um valor int
    tamVet = atoi(argv[2]);
    //Alocação de vetor de 5 espaços de inteiros
    tempo = (int*) malloc(5 * sizeof (int));
    
    //Checa se o vetor foi alocado adequadamente, caso retorne null
    //o usuário será avisado que a memoria é insuficiente para a alocação
    //e fechará o programa
    if (tempo == NULL) {
        printf("Memoria Insuficiente para alocar vetor de tempo\n");
        return 1;
    }
    
    //Aloca vetor dinamicamente
    troca = (unsigned long long int*) malloc(5 * sizeof (unsigned long long int));
    //Checa se possui memoria para a alocagem
    if (troca == NULL) {
        printf("Memoria Insuficiente para alocar vetor de troca\n");
        return 1;
    }
    //Aloca vetor dinamicamente
    comparacao = (unsigned long long int*) malloc(5 * sizeof (unsigned long long int));
    //Checa se possui memoria para a alocagem
    if (comparacao == NULL) {
        printf("Memoria Insuficiente para alocar vetor de comparacao\n");
        return 1;
    }
    //O comando atoi converte uma string em um valor int
    op = atoi(argv[1]);
    //Se op é 1 ele ira utilizar o metodo de ordenação selection sempre pegando 
    //seu tempo de execução que serão usados para gerar relatorio
    if (op == 1) {
        for (i = 3; i < 8; i++) {
            vet = leArquivo(argv[i], tamVet);
            gettimeofday(&inicio, NULL);//Pega o tempo inicial de execução
            selection(vet, tamVet);
            gettimeofday(&final, NULL);//Pega o tempo final de execução
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
        //Se op é 2 ele ira utilizar o metodo de ordenação rapidSort sempre pegando 
        //seu tempo de execução que serão usados para gerar relatorio
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
