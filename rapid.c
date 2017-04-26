#include<stdlib.h>
#include<stdio.h>
#include "auxiliares.h"
#include "ordenacao.h"

void rapidSort(int *v, int tamanho_vetor) {
    int lb = menor(v, 0, tamanho_vetor);
    int ub = maior(v, tamanho_vetor, 0);
    int templb;
    int tempub;
    int distanceMin;
    int distanceMax;
    int pos, aux;

    //Coloca o menor numero no inicio
    troca(v, 0, lb);
    contaTrocas();
    //Coloca o maior numero no inicio
    troca(v, tamanho_vetor - 1, ub);
    contaTrocas();
    //Seta Low_bound como o inicio
    lb = 0;
    //Seta o Up_bound como o final
    ub = tamanho_vetor - 1;

    //Armazena o maximo e o minimo em variaveis temporarias
    templb = lb;
    tempub = ub;

    int nextNum = 1; //Variavel que ajudará a percorrer o vetor
    while (nextNum < tempub) {//Enquanto o proximo numero não for menor que o up_bound ele não parará

        //Calcula as distancias minima e maxima do elemento do seus extremos
        distanceMin = abs(v[lb] - v[nextNum]);
        distanceMax = abs(v[ub] - v[nextNum]);

        //Abaixo daqui o programa fará algo semelhante ao insertionSort, onde ele terá um marcador
        //que no caso são nossos Low_bound e Up_bound, ou seja, o que estiver antes ou depois desses
        //Marcadores esta ordenado, e ao adicionar um elemento novo nesta parte ordenada, ele fará
        //o mesmo processo de copia que o insertionSort

        aux = v[nextNum]; //Armazena o valor do elemento que esta sendo ordenado
        if (distanceMin < distanceMax) {
            troca(v, nextNum, templb + 1);
            contaTrocas();
            pos = templb;
            contaTrocas();
            while (pos >= 0 && aux < v[pos]) {
                v[pos + 1] = v[pos];
                pos--;
            }
            v[pos + 1] = aux;
            nextNum++;
            templb++; //Desloca nosso marcador low_bound para a direita
        } else {
            troca(v, nextNum, tempub - 1);
            contaTrocas();
            pos = tempub;
            while (pos <= tamanho_vetor && aux > v[pos]) {
                v[pos - 1] = v[pos];
                pos++;
            }
            v[pos - 1] = aux;
            //Nao haverá nextNum++ aqui, pois o numero foi deslocado pra direita, então o proximo número será este
            //o qual foi deslocado para a posição nova [nextNum]
            tempub--; //Desloca nosso marcador up_bound para a esquerda
        }
    }
}
