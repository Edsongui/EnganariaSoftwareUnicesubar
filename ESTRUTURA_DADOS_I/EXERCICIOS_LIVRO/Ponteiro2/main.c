#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct SemaforoCorGenerica {
	char cor[40];
	int id;
};

typedef struct SemaforoCorGenerica SemaforoCor;

int main(int argc, char *argv[]) {
	
	int i;
	SemaforoCor cores[3];
	SemaforoCor *selecionado;
	
	strcpy(cores[0].cor, "Vermelho");
	cores[0].id = 1;
	strcpy(cores[1].cor, "Amarelo");
	cores[1].id = 2;
	strcpy(cores[2].cor, "Verde");
	cores[2].id = 3;
	
	selecionado = &cores[0];
	
	for (i = 0; i<3 ; i++){
		printf("\nEndereco: %p", selecionado);
		printf("\nId: %i", selecionado->id);
		printf("\nCor: %s", selecionado->cor);
		selecionado = ++selecionado;
	}
	return 0;
}
