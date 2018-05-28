#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

struct Lista {
	int qtd;
	struct Aluno dados[MAX];
};

struct Lista* criaLista() {
	struct Lista *lista;
	lista = malloc(sizeof(struct Lista));
	if (lista != NULL)
		lista->qtd = 0;
	return lista;
}

void liberaLista(struct Lista* lista) {
	free(lista);
}

int tamanhoLista(struct Lista* lista) {
	if (lista == NULL){
		return -1;
	} else {
		return lista->qtd;
	}
}

int listaCheia(struct Lista* lista) {
	if (lista == NULL){
		return -1;
	} else {
		lista->qtd == MAX;
	}
}

int listaVazia(struct Lista* lista) {
	if (lista == NULL){
		return -1;
	} else {
		lista->qtd == 0;
	}
}

int insereFinal(struct Lista* lista, struct Aluno aluno) {
	if (lista == NULL) return 0;
	if (listaCheia(lista)) return 0;
	lista->dados[lista->qtd] = aluno;
	lista->qtd++;
	return 1;
}

int insereInicio(struct Lista* lista, struct Aluno aluno) {
	
	int i;
	
	if (lista == NULL) return 0;
	if (listaCheia(lista)) return 0;
	for (i=lista->qtd-1; i>=0; i--){
		lista->dados[i+1] = li->dados[i];
	}
	lista->dados[0] = aluno;
	lista->qtd++;
	return 1;
}

int insereOrdenadoMatricula(struct Lista* lista, struct Aluno aluno) {
	if (lista == NULL) return 0;
	if (listaCheia(lista)) return 0;
	int k,i = 0;
	while (i<lista->qtd && lista->dados[i].matricula<aluno.matricula)
		i++;
	for (k=lista->qtd-1;k>=dados[i];k--)
		lista->dados[k+1]=lista->dados[k];
	lista->dados[i]=aluno;
	lista->qtd++;
	return 1;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	struct Lista *lista;
	
	lista = criaLista();
	liberaLista(lista);
	return 0;
}
