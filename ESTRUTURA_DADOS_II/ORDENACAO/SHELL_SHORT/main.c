#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void shellSort(int *vetor, int numeroElementos){
	
	int auxiliar, i, j, gap = numeroElementos/2;
	
	while (gap > 0) {
		i = gap;
		while (i < numeroElementos) {
			auxiliar = vetor[i];
			j = i;
			while (j >= gap && auxiliar < vetor[j-gap]){
				vetor[j] = vetor[j-gap];
				j = j-gap;
			}
			vetor[j] = auxiliar;
			i++;
		}
		gap = gap/2;
	}
}

int main(int argc, char *argv[]) {
	int tamanhoVetor, i, elementoBuscado, retorno;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);
	
	int vetor[tamanhoVetor];
	
	for (i=0; i<tamanhoVetor; i++) {
		printf("Informe o numero para posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	shellSort(vetor, tamanhoVetor);
	
	printf("Vetor ordenado: \n");
	for (i=0; i<tamanhoVetor; i++) {
		printf("%d ", vetor[i]);
	}
	return 0;
}
