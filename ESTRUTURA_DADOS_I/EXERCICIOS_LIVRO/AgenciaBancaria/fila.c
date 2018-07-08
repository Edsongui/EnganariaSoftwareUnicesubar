#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criarFila(){
	Fila *fila;
	
	fila = (Fila*)malloc(sizeof(Fila));
	if (fila){
		fila->fim = 0;
	}
	return fila;
}

int liberarFila(Fila *fila){
	free(fila);
	if (fila == NULL){
		return 1;
	} else {
		return 0;
	}
}

int enfileirar(Fila *fila){
	
	Cliente cliente;
	
	if (fila == NULL){
		printf("Fila não foi criada!");
		return 0;
	}
	if (fila->fim == tamanho){
		printf("Fila está  cheia!");
		return 0;
	}
	fflush(stdin);
	printf("\nInforme o nome do cliente: ");
	fgets(cliente.nome,max,stdin);
	fflush(stdin);
	printf("Informe a hora da chegada no formato(00 00): ");
	scanf("%d%d", &cliente.horaChegada, &cliente.minutoChegada);
	
	fila->clientes[fila->fim] = cliente;
	fila->fim++;
	return 1;
}

void desemfileirar(Fila *fila){
	int i;
	Cliente cliente;
	
	if (fila == NULL){
		printf("Fila não foi criada!");
		return;
	}
	if (fila->fim == 0){
		printf("Fila está vazia!");
		return;
	}
	cliente = fila->clientes[0];
	printf("Chamando Cliente: ");
	printf("\nNome: %s Hora da Chegada: %d:%d", cliente.nome, cliente.horaChegada, cliente.minutoChegada);
	for (i = 0; i < fila->fim; i++){
		fila->clientes[i]= fila->clientes[i+1];
	}
	fila->fim--;
}

void imprimir(Fila *fila){
	int i;
	Cliente cliente;
	printf("\nClientes: %d", fila->fim);
	printf("\n");
	for (i = 0; i < fila->fim; i++){
		cliente = fila->clientes[i];
		printf("\nNome: %s Hora da Chegada: %d:%d", cliente.nome, cliente.horaChegada, cliente.minutoChegada);
	}
}

