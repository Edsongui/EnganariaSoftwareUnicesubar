#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int tamanho, i;
	int *potencia2;
	int *potencia3;
	
	printf("Informa o tamanho do vetor: ");
	scanf("%i", &tamanho);

	potencia2 = (int*)malloc(tamanho*sizeof(int));
	potencia3 = (int*)malloc(tamanho*2*sizeof(int));
	
	printf("\nPotencias de 2: ");
	for (i = 0; i < tamanho; i++){
		*(potencia2 + i) = pow(i,2);
		printf("%i ", *(potencia2 + i));
	}
	
	printf("\nPotencias de 3: ");
	for (i = 0; i < (tamanho*2); i++){
		*(potencia3 + i) = pow(i,3);
		printf("%i ", *(potencia3 + i));
	}
	
	free(potencia2);
	free(potencia3);
	
	return 0;
}
