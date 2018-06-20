#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define tamanho 10
enum Bool { False=0, True=1};

typedef struct Fila {
	int elementos[tamanho];
	int numeroElementos;
};

void imprimirFila(struct Fila fila){
	int i;
	if (fila.numeroElementos > 0) {
		printf("Pessoas aguardando: %i\n", fila.numeroElementos);
		printf("Senhas na fila: ");
		for (i=0; i<fila.numeroElementos; i++){
			printf("%i", fila.elementos[i]);
			if (i < (fila.numeroElementos-1)){
				printf(", ");
			}
		}
		printf("\n");
	}
}

int retirarSenha(struct Fila *fila, int ultimaSenha){
	fila->elementos[fila->numeroElementos] = ultimaSenha + 1;
	fila->numeroElementos++;
	return (ultimaSenha + 1);
};

int chamarSenha(struct Fila *fila){
	int i;
	int senhaChamada = fila->elementos[0];
	for (i=0; i<(fila->numeroElementos-1) ; i++){
		fila->elementos[i] = fila->elementos[i+1];	
	}
	fila->numeroElementos--;
	return senhaChamada;
};

int main(int argc, char *argv[]) {
	
	//Declaração de variáveis
	enum Bool sair = False;
	struct Fila fila;
	int ultimaSenha = 0;
	int opcao = 0;
	int senhaAnterior = 0;
	int senhaChamada = 0;
	
	setlocale(LC_ALL, "Portuguese");
	fila.numeroElementos = 0;
	
	do {
		system("cls");
		printf("Selecione uma opção:\n");
		printf("1-Retirar senha.\n");
		printf("2-Chamar senha para atendimento.\n");
		printf("3-Imprimir fila.\n");
		printf("0-Sair.\n");
		scanf("%i",&opcao);
	
		switch(opcao) {
			case 1:
				system("cls");
				if (fila.numeroElementos == tamanho){
					printf("A fila já está completa, tente novamente mais tarde.\n");
				} else {
					ultimaSenha = retirarSenha(&fila, ultimaSenha);
					printf("O número da sua senha é: %i\n", ultimaSenha);
				}
				system("pause");
				break;
			case 2:
				system("cls");
				if (fila.numeroElementos == 0){
					printf("A fila está vazia.\n");	
				} else {
					senhaChamada = chamarSenha(&fila);
					printf("Atenção senha %i dirija-se ao balcão.\n\n", senhaChamada);
					printf("Anterior: %i\n", senhaAnterior);
					printf("Atual: %i\n", senhaChamada);
					if (fila.numeroElementos > 1) {
						printf("Próxima: %i\n", fila.elementos[0]);
					} else {
						printf("Próxima: %i\n", 0);
					}
					senhaAnterior = senhaChamada;
				}
				system("pause");
				break;
			case 3:
				system("cls");
				imprimirFila(fila);
				break;
			case 0:
				system("cls");
				if (fila.numeroElementos > 0){
					printf("Não é possível sair, ainda existem pessoas para serem atendidas.\n");
				} else {
					printf("Saindo...\n");
					sair = True;
				}
				system("pause");
				break;
			default:
				system("cls");
				printf("Opção selecionada é inválida, tente novamente.\n");
				system("pause");
				break;
		}
		system("cls");
		imprimirFila(fila);
		system("pause");
	} while (sair == False);
	
	return 0;
}
