#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bubbleSortCrescente(int *vetor, int numeroElementos) {
	int i;//Contador
	int continua;//para saber se já chegou ao final ou nao 
	int auxiliar;//armazena valor a ser alterado de posição 
	int fim = numeroElementos;
	
	do {//precisa ser executado pelo menos uma vez
		continua = 0;
		for(i=0; i<fim-1; i++){
			if(vetor[i] > vetor[i+1]){//se o elemento for MAIOR que o proximo
				auxiliar = vetor[i];//armazena valor a ter posicao alterada na var auxiliar
				vetor[i] = vetor[i+1];//posicao i recebe o proximo valor
				vetor[i+1] = auxiliar;//posicao proxima recebe o valor da posicao atual que estava na auxiliarS
				continua = i;
			}
		}
		fim--;
	}while(continua != 0);
}

void bubbleSortDecrescente(int *vetor, int numeroElementos) {
	int i;//Contador
	int continua;//para saber se já chegou ao final ou nao 
	int auxiliar;//armazena valor a ser alterado de posição 
	int fim = numeroElementos;
	
	do {//precisa ser executado pelo menos uma vez
		continua = 0;
		for(i=0; i<fim-1; i++){
			if(vetor[i] < vetor[i+1]){//se o elemento for MENOR que o proximo
				auxiliar = vetor[i];//armazena valor a ter posicao alterada na var auxiliar
				vetor[i] = vetor[i+1];//posicao i recebe o proximo valor
				vetor[i+1] = auxiliar;//posicao proxima recebe o valor da posicao atual que estava na auxiliarS
				continua = i;
			}
		}
		fim--;
	}while(continua != 0);
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
	
	do {
		printf("Informe o tipo de ordenacao a ser realizada: \n");
		printf("1-Crescente \n");
		printf("2-Decrescente \n");
		scanf("%d", &tipoOrdenacao);
		if ((tipoOrdenacao != 1) && (tipoOrdenacao != 2)) {
			printf("Valor informado nao e valido!\n");
		}	
	} while ((tipoOrdenacao != 1) && (tipoOrdenacao != 2));
	
	if (tipoOrdenacao == 1) {
		bubbleSortCrescente(vetor, tamanhoVetor);
	} else {
		bubbleSortDecrescente(vetor, tamanhoVetor);
	}
	
	printf("Vetor Ordenado:  \n");
	for (i=0; i<tamanhoVetor; i++ ){
		printf("%d ", vetor[i]);
	}
	system("pause");
	return 0;
}
