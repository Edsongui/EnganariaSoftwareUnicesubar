#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insertionSort(int *vetor, int numeroElementos) {
	int i, j, auxiliar;
	for (i=1; i<numeroElementos; i++){//sempre pega o elemento mais a esquerda e considera os anteriores ja totalmente ordenados
		auxiliar = vetor[i];//guarda dado da posicao i
		//compara o auxiliar com os elemetos anteriores(mais a esquerda) enquanto auxiliar for menor que o numero na posicao (j-1)
		for (j = i; (j > 0) && (auxiliar < vetor[j-1]); j--){
			//empurra cada elemento uma posicao para a direita
			vetor[j] = vetor[j-1];
		}
		//quando quebra o loop(auxiliar NAO é menor que a posicao anterior)
		//inseri o auxilar no espaco criado
		vetor[j] = auxiliar;
	}
}

int main(int argc, char *argv[]) {
	
	int tamanhoVetor, i;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);
	
	int vetor[tamanhoVetor];
	
	for (i=0; i<tamanhoVetor; i++) {
		printf("Informe o numero para posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	insertionSort(vetor, tamanhoVetor);
	printf("Vetor ordenado: \n");
	
	for (i=0; i<tamanhoVetor; i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}
