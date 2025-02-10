// An = 8(An - 1) - 16(An - 2), n >=3,
// A1 = 1 e A2 = 12.
//
#include "funcoes.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

void medir_tempo05(int (*funcao)(int), int (*funcao2)(int), int valor) {
    struct timespec start, end;
	
    clock_gettime(CLOCK_MONOTONIC, &start);
    funcao(valor);
    clock_gettime(CLOCK_MONOTONIC, &end); 

    double tempo_decorrido1 = (end.tv_sec - start.tv_sec) + 
                             (end.tv_nsec - start.tv_nsec) / 1e9;
	

    clock_gettime(CLOCK_MONOTONIC, &start);
    funcao2(valor);
    clock_gettime(CLOCK_MONOTONIC, &end); 

    double tempo_decorrido2 = (end.tv_sec - start.tv_sec) + 
                             (end.tv_nsec - start.tv_nsec) / 1e9;
	
	double diferenca_percentual = ((tempo_decorrido2 - tempo_decorrido1) / tempo_decorrido1) * 100;

	printf("Tempo de execucao com o valor %d inserido: %lf \n", valor, tempo_decorrido1 * 1000);
	printf("Tempo de execucao com o valor %d inserido: %lf \n", valor, tempo_decorrido2 * 1000);
	printf("Diferenca em  porcentagem: %g\n", diferenca_percentual);

}

int casebase05(int valor_inicial){
	if (valor_inicial == 1) {
		return 1;
	}
	if (valor_inicial == 2){
		return 12;
	}
	return 8 * (casebase05(valor_inicial - 1)) - 16 * (casebase05(valor_inicial - 1));
}

int conjetura05(int valor){
	
	if(valor < 3){
		printf("O valor tem que ser maior ou igual a 3");
		return -1;
	}

	return pow(4, valor - 1) * (2 * valor - 1);
}
