#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
# define tamanho 100
enum Bool{False, True};
enum Lado{Esquerdo = 0, Direito = 1, Raiz = -1};

struct No {
	char dado;
	int pai;
	int esquerda;
	int direita;
};
struct No arvore[tamanho];
int index = 0;	
int opt = 0;
char pai, no;
enum Lado lado;

int buscar(char dado){
	int i;
	if (index != 0){
		for (i=0; i<index; i++){
			if (arvore[i].dado == dado){
				return i;
			}
		}
	} else {
		return 0;
	}
}

void inserir(int pai, char dado, enum Lado lado){
	switch (lado){
		case Esquerdo:
			arvore[pai].esquerda = index;
			arvore[index].dado = dado;
			arvore[index].pai = pai;
			arvore[index].esquerda = Raiz;
			arvore[index].direita = Raiz;
			index++;
			break;
		case Direito:
			arvore[pai].direita = index;
			arvore[index].dado = dado;
			arvore[index].pai = pai;
			arvore[index].esquerda = Raiz;
			arvore[index].direita = Raiz;
			index++;
			break;
		case Raiz:
			arvore[index].dado = dado;
			arvore[index].pai = Raiz;
			arvore[index].esquerda = Raiz;
			arvore[index].direita = Raiz;
			index++;
			break;
	}
}

void menuMostrar(){
	int i;
	system("cls");
	for (i=0; i<index; i++){
		printf("| %c ", arvore[i].dado);
	}
	printf("\n1 - Inserir um NO na arvore");
	printf("\n2 - Pesquisar um NO na arvore");
	printf("\n3 - Executar arvore");
	printf("\n0 - Sair...");
}

int executarCalculo(int indexCalculo){
	struct No noCalculo = arvore[indexCalculo];
	int dadoEsquerdo = -1;
	int dadoDireito = -1;
	
	if ((noCalculo.direita == Raiz) && (noCalculo.esquerda == Raiz)) {
		printf("\nnoCalculo %c", noCalculo.dado);
		return noCalculo.dado;
	} else {
		if (noCalculo.esquerda != Raiz){
			dadoEsquerdo = executarCalculo(noCalculo.esquerda);
		}
		if (noCalculo.direita != Raiz){
			dadoDireito = executarCalculo(noCalculo.direita);
		}
		
		if (dadoEsquerdo > -1 && dadoDireito > -1) {
			printf("\nnoDado %c", noCalculo.dado);
			printf("\ndadoEsquerdo: %c", dadoEsquerdo);
			printf("\ndadoDireito: %c", dadoDireito);
			if (noCalculo.dado == "+"){
				printf("\n+");
				return ((int)dadoEsquerdo + (int)dadoDireito);
			} else if (noCalculo.dado == "-"){
				printf("\n-");
				return ((int)dadoEsquerdo - (int)dadoDireito);
			} else if (noCalculo.dado == "*") {
				printf("\n*");
				return ((int)dadoEsquerdo * (int)dadoDireito);
			}
		}
		if (dadoEsquerdo > -1){
			return dadoEsquerdo;
		} else {
			return dadoDireito;
		}
	}
}

int main(int argc, char *argv[]) {
	int temp, resultado = 0;
	do {
		menuMostrar();
		scanf("%d", &opt);
		switch (opt){
			case 1:
				printf("\nDigite o valor do PAI: ");
				scanf("%c",&pai);
				scanf("%c",&pai);
				printf("Digite o valor do NO: ");
				scanf("%c",&no);
				scanf("%c",&no);
				printf("Digite o lado da subarvore (Esquerda=%d/Direita=%d/Raiz=%d): ", Esquerdo,Direito,Raiz);
				scanf("%d",&lado);
				temp = buscar(pai);
				inserir(temp,no,lado);
				break;
			case 2:
				printf("\nDigite o valor do NO: ");
				scanf("%c",&no);
				temp = buscar(no);
				printf("No %c\nFilho Esquerda: %c \nFilho Direita: %c\n\n", arvore[temp].dado,
				arvore[arvore[temp].esquerda].dado,
				arvore[arvore[temp].direita].dado);
				system("pause"); 
				break; 
			case 3:
				resultado = executarCalculo(0);
				printf("\nResultado: %d", resultado);
				system("pause"); 
				break;
		}
	} while (opt!=0);
	system("pause");
	return 0;
}
