#include<limits.h> 
#include <stdio.h>
#include <stdlib.h>

// ALGORITMO DE KADANE
void kadane (int *v, int n, int *x, int * y, int *max_total){
    
    int max_atual;
    int xtemp;
	int i;
    max_atual = 0; 
    *max_total = INT_MIN;
    xtemp = 0;

    for (i = 0; i < n; i++){
        max_atual = max_atual + v[i];

        if (max_atual < 0) { 
            max_atual = 0;
            xtemp = i + 1;
        }

        if (max_atual > *max_total){
            *max_total = max_atual;
            *x = xtemp;
            *y = i;
        } 
    }
}

int main (){ 
    int indiceInicial, indiceFinal, somaMaxima, i;

    // entrada de dados
    int numeroElementos = 0;
    scanf("%d", &numeroElementos);
    int vetor[numeroElementos];
	
    for(i = 0; i < numeroElementos; i++)
        scanf("%d", &(vetor[i]));


	// execução do algoritmo de kadane
    kadane(vetor, numeroElementos, &indiceInicial, &indiceFinal, &somaMaxima);

    // saída
	printf("Soma: %d\n", somaMaxima);
	printf("%cndices: %d a %d\n", 214, indiceInicial+1, indiceFinal+1);

	return 0; 
} 

