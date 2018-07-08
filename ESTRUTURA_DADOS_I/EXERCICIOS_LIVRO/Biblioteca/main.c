#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Pilha *pilha;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opcao = -1;
	Livro livro;
	
	pilha = criarPilha();
	do {
		printf("\nEscolha uma opção:\n");
		printf("1 - Incluir na Pilha\n");
		printf("2 - Excluir da Pilha\n");
		printf("3 - imprimir Pilha\n");
		printf("0 - Sair\n\n");
		scanf("%d", &opcao);
		switch (opcao){
			case 0:
				printf("Saindo...");
				break;
			case 1:
				if (empilhar(pilha)) {
					printf("\nLivro Adicionado a pilha.");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 2:
				desempilhar(pilha);
				system("pause");
				system("cls");
				break;
			case 3:
				imprimir(pilha);
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
