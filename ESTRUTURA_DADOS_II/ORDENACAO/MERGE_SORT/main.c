#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void merge(int *vetor, int inicio, int meio, int fim) {
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1= 0, fim2= 0;
	tamanho = fim-inicio+1;
	p1 = inicio;//inicio primeira metade do vetor
	p2 = meio+1;//inicio segunda metado do vetor
	temp = malloc(tamanho*sizeof(int));
	if (temp != NULL) {
		for (i=0; i<tamanho; i++){//percorre vetor temp prenchendo cada posição com o menor valor de p1 e p2
			if (!fim1 && !fim2){
				if (vetor[p1] < vetor[p2]) {//encontra o menor valor entre p1 e p2
					temp[i] = vetor[p1++];
				} else {
					temp[i] = vetor[p2++];
				}
				if (p1>meio){//vetor 1 acabou?
					fim1 = 1;
				}
				if (p2>fim){//vetor 2 acabou?
					fim2 = 1;
				}
			} else {
				//como um dos vetores se encerrou não da para fazer comparacao
				if (!fim1){
					//vetor 2 acabou, vetor temp recebe os elementos restantes do vetor1
					temp[i] = vetor[p1++];
				} else {
					//vetor 1 acabou, vetor temp recebe os elementos restantes do vetor2
					temp[i] = vetor[p2++];
				}
			}
		}
		//escreve para o vetor os valores ordenado do vetor temp
		for (j=0, k=inicio; j<tamanho; j++, k++){
			vetor[k] = temp[j];
		}
	}
	free(temp);
}

void mergeSort(int *vetor, int inicio, int fim) {
	int meio;
	if (inicio < fim) {
		meio = floor((inicio+fim)/2);
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

int main(int argc, char *argv[]) {
	return 0;
}
