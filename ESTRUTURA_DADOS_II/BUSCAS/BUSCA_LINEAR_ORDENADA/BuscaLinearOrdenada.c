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
	return 0;
}
