#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int *inteiro;
	
	inteiro = (int*)malloc(4);
	printf("\nEndereco: %p", inteiro);
	*inteiro = 42;
	printf("\nEndereco: %p", inteiro);
	printf("\nValor: %d", *inteiro);
	return 0;
}
