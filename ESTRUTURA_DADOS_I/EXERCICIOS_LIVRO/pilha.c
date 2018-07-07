#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* criarPilha(){
	Pilha *pilha;
	
	pilha = (Pilha*)malloc(sizeof(Pilha));
	if (pilha){
		pilha->topo = 0;
	}
	return pilha;
}

int liberarPilha(Pilha *pilha){
	free(pilha);
	if (pilha == NULL){
		return 1;
	} else {
		return 0;
	}
}

int empilhar(Pilha *pilha){
	
	Livro livro;
	
	if (pilha == NULL){
		printf("Pilha não foi criada!");
		return 0;
	}
	if (pilha->topo == tamanho){
		printf("Pilha está  cheia!");
		return 0;
	}
	printf("\nInforme o código do livro: ");
	scanf("%d", &livro.codigo);
	fflush(stdin);
	printf("Informe o título do livro: ");
	fgets(livro.titulo,max,stdin);
	fflush(stdin);
	printf("Informe o autor do livro: ");
	fgets(livro.autor,max,stdin);
	
	pilha->livros[pilha->topo];
	pilha->topo++;
	return 1;
}

void desempilhar(Pilha *pilha){
	int i;
	Livro livro;
	
	if (pilha == NULL){
		printf("Pilha não foi criada!");
	}
	livro = pilha->livros[pilha->topo-1];
	printf("Desempilhando livro: ");
	printf("\nCódigo: %d Título: %s Autor: %s", livro.codigo, livro.titulo, livro.autor);
	for (i = 0; i < pilha->topo-1; i++){
		pilha->livros[i] = pilha->livros[i+1];
	}
	pilha->topo--;
}

void imprimir(Pilha *pilha){
	int i;
	Livro livro;
	printf("\nNúmero de livros na pilha: %d", pilha->topo);
	for (i = 0; i < pilha->topo; i++){
		livro = pilha->livros[i];
		printf("\nCódigo: %d Título: %s Autor: %s", livro.codigo, livro.titulo, livro.autor);
	}
}
