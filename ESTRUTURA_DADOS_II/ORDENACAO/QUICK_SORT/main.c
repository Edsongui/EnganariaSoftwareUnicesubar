#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int particiona(int *vetor, int inicio, int final){
	int esquerda, direita, pivo, aux;
	esquerda = inicio;
	direita = final;
	pivo = vetor[inicio];
	while (esquerda < direita) {
		while (vetor[esquerda] <= pivo)//avanca esquerda
			esquerda++;
		while (vetor[direita] > pivo)//recua direita
			direita--;
		if (esquerda < direita) {//troca quando um for maior que o outro
			aux = vetor[esquerda];
			vetor[esquerda] = vetor[direita];
			vetor[direita] = aux;
		}
	}
	vetor[inicio] = vetor[direita];
	vetor[direita] = pivo;
	return direita;
}
void quickSort(int *vetor, int inicio, int fim){
	int pivo;
	if (fim > inicio){
		pivo = particiona(vetor, inicio, fim);
		quickSort(vetor, inicio, pivo-1);
		quickSort(vetor, pivo+1, fim);
	}
}
int main(int argc, char *argv[]) {
	
	int tamanhoVetor, i, tipoOrdenacao;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanhoVetor);
	
	int vetor[tamanhoVetor];
	
	for (i=0; i<tamanhoVetor; i++) {
		printf("Informe o numero para posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	quickSort(vetor,0, tamanhoVetor-1);
	printf("Vetor ordenado: ");
	
	for (i=0; i<tamanhoVetor ; i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}
