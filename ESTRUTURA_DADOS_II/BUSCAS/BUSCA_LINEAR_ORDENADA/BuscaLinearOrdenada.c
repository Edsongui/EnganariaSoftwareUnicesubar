#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int buscaLinearOrdenada(int *vetor, int tamanhoVetor, int elementoBuscado) {
	int i;
	
	for (i=0; i<tamanhoVetor;i++) {
		if (vetor[i] == elementoBuscado){
			return i;
		} else if (vetor[i] > elementoBuscado) {
			return -1;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	
	int tamanhoVetor, i, elementoBuscado, retorno;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);
	
	int vetor[tamanhoVetor];
	
	for (i=0; i<tamanhoVetor; i++) {
		printf("Informe o numero para posicao %d: ", i);
		scanf("%d", &vetor[i]);
		printf("\n");
	}
	
	printf("Informe o numero para ser encontrado: ");
	scanf("%d", &elementoBuscado);
	printf("\n");
	retorno = buscaLinearOrdenada(vetor, tamanhoVetor, elementoBuscado);
	
	if (retorno != -1) {
		printf("Elemento encontrado na posicao %d", retorno);
	} else {
		printf("Elemento nao encontrado!");
	}
	return 0;
}
