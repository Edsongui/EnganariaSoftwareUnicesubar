#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void selectionSort(int *vetor, int numeroElementos){
	int i, j, menor, auxiliar;
	//loop ate o penultimo elemento
	for (i = 0 ; i < numeroElementos-1; i++){
		menor = i;
		//busca a partir da posicao de i
		for(j = i+1 ; j < numeroElementos ; j++){//encontra menor valor em relacao a i
			if(vetor[j] < vetor[menor]){
				menor = j;
			}
		}
		if (i != menor) {//troca o elemento da posicao i pelo elemento da posicao j(menor)
			auxiliar = vetor[i];//guarda valor a ser trocado
			vetor[i] = vetor[menor];
			vetor[menor] = auxiliar;
		}
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
	
	selectionSort(vetor, tamanhoVetor);
	
	printf("Vetor ordenado: \n");
	for (i=0; i<tamanhoVetor; i++) {
		printf("%d ", vetor[i]);
	}
	return 0;
}
