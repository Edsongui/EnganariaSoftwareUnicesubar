#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Fila *fila;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opcao = -1;
	Cliente cliente;
	
	fila = criarFila();
	do {
		printf("\nEscolha uma opção:\n");
		printf("1 - Incluir na Fila\n");
		printf("2 - Excluir da Fila\n");
		printf("3 - imprimir Fila\n");
		printf("0 - Sair\n\n");
		scanf("%d", &opcao);
		switch (opcao){
			case 0:
				printf("Saindo...");
				break;
			case 1:
				if (enfileirar(fila)) {
					printf("\nCliente Adicionado a fila.");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 2:
				desemfileirar(fila);
				system("pause");
				system("cls");
				break;
			case 3:
				imprimir(fila);
				printf("\n");
				system("pause");
				system("cls");
				break;
			default:
				opcao = -1;
				break;
		}
	} while (opcao != 0);
	return 0;
}
