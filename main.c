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
    printf("\ncmdline args count= %d", argc);
    /* First argument is executable name only */
    printf("\nexe name=%s", argv[0]);

    //For usado somente para testes
    for (i = 1; i < argc; i++) {
        printf("\narg%d=%s", i, argv[i]);
    }
    
    printf("\n");
    //Aloca��o de vetor de 5 espa�os de inteiros
    tempo = (int*) malloc(5 * sizeof (int));
    
    
    //Checa se o vetor foi alocado adequadamente, caso retorne null
    //o usu�rio ser� avisado que a memoria � insuficiente para a aloca��o
    //e fechar� o programa
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
    //Se op � 1 ele ira utilizar o metodo de ordena��o selection sempre pegando 
    //seu tempo de execu��o que ser�o usados para gerar relatorio
    if (op == 1) {
        for (i = 3; i < 8; i++) {
            vet = leArquivo(argv[i], tamVet);
            gettimeofday(&inicio, NULL);//Pega o tempo inicial de execu��o
            selection(vet, tamVet);
            gettimeofday(&final, NULL);//Pega o tempo final de execu��o
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
        //Se op � 2 ele ira utilizar o metodo de ordena��o rapidSort sempre pegando 
        //seu tempo de execu��o que ser�o usados para gerar relatorio
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
