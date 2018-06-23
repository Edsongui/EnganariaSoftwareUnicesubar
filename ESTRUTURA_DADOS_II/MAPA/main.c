#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum Lado{Esquerdo, Direito, Raiz};

struct No {
	char dado;
	struct No *esquerdo;
	struct No *direito;
};

int isOperator(char dado){
	switch (dado){
		//*
		case 42:
			return 1;
			break;
		//+
		case 43:
			return 1;
			break;
		//-
		case 45:
			return 1;
			break;
		default:
			return 0;
			break;	
	}
}

void limpaTela(){
	#ifdef _WIN32
		system("cls");
	#elif defined(unix) || defined(_unix_) || defined(_unix) || (defined(_APPLE_) && defined(_MACH_))
		system("clear");
	#else
		#error "SO n�o suportado."
	#endif
}

void pause(){
	#ifdef _WIN32
		system("pause");
	#elif defined(unix) || defined(_unix_) || defined(_unix) || (defined(_APPLE_) && defined(_MACH_))
		getchar();
		getchar();
	#else
		#error "SO n�o suportado."
	#endif
}

struct No* localizarNo(struct No* raiz, char dado){
	struct No *esquerdo = NULL;
	struct No *direito = NULL;
	if (raiz) {
		if ((raiz->dado == dado) && (raiz->esquerdo == NULL || raiz->direito == NULL)){
			return raiz;
		} else {
			esquerdo = localizarNo(raiz->esquerdo, dado);
			if (esquerdo){
				return esquerdo;
			}
			direito = localizarNo(raiz->direito, dado);
			if (direito){
				return direito;
			}
		}
	} 
	return NULL;
}

char solicitarDado(){
	char dado = 0;
	do {
		printf("\nInforme o dado para inserir no n�:");
		scanf(" %c", &dado);
		if ((!isdigit(dado) && (!isOperator(dado)))){
			printf("\nDado Inv�lido, Informar somente d�gitos[1,3,4,5,6,7,8,9] ou os peradores[+,-,*]");
			pause();
			limpaTela();
			dado = 0;
		}
	} while (dado == 0);
	
	return dado;
}

char solicitarDadoPai(){
	char dado = 0;
	do {
		printf("\nInforme o dado do n� pai:");
		scanf(" %c", &dado);
		if ((!isdigit(dado) && (!isOperator(dado)))){
			printf("\nDado Inv�lido, Informar somente d�gitos[1,3,4,5,6,7,8,9] ou os peradores[+,-,*]");
			pause();
			limpaTela();
			dado = 0;
		}
	} while (dado == 0);
	
	return dado;
}

enum Lado solicitarLado(){
	enum Lado lado;
	int opcao = 0;
	do {
		printf("\nInforme o lado em que ser� inserido o n�:\n");
		printf("1-Esquerdo.\n");
		printf("2-Direito.\n");
		scanf("%i", &opcao);
		switch (opcao){
			case 1:
				lado = Esquerdo;
				break;
			case 2:
				lado = Direito;
				break;
			default:
				printf("Informa��o inv�lida, tente novamente.\n");
				opcao = 0;
		}
	} while (opcao == 0);
	
	return lado;
}

int calcularArvore(struct No* raiz){
	int esquerdo;
	int direito;
	
	if (raiz){
		if (isOperator(raiz->dado)){
			esquerdo = calcularArvore(raiz->esquerdo);
			direito = calcularArvore(raiz->direito);	
				switch (raiz->dado){
					case 42:
						return esquerdo * direito;
						break;
					case 43:
						return esquerdo + direito;
						break;
					case 45:
						return esquerdo - direito;
						break;
					default:
						return -1;
						break;	
				}
		} else {
			return (raiz->dado - '0');
		}
	}
	return -1;
}

void liberaNo(struct No* no){
	if (no == NULL){
		return;
	}
	liberaNo(no->esquerdo);
	liberaNo(no->direito);
	free(no);
	no = NULL;
}

int main(int argc, char *argv[]) {
	
	struct No *raiz = NULL, *no = NULL, *pai = NULL;
	enum Lado lado = Esquerdo;
	int opcao = 0, sair = 0, resultado;
	char dadoPai;
	
	setlocale(LC_ALL, "Portuguese");
	
	do {
		printf("Selecione uma op��o:\n");
		printf("1-Inserir N�.\n");
		printf("2-Calcular Arvore.\n");
		printf("0-Sair.\n");
		scanf("%i",&opcao);
		
		switch (opcao) {
			case 0:
				sair = 1;
				break;
			case 1:
				if (!raiz){
					raiz = (struct No*)malloc(sizeof(struct No));
					raiz->dado = solicitarDado();
					raiz->esquerdo = NULL;
					raiz->direito = NULL;
					printf("N� raiz criado!\n");
					pause();
				} else {
					dadoPai = solicitarDadoPai();
					pai = localizarNo(raiz,dadoPai);
					if (pai){
						no = (struct No*)malloc(sizeof(struct No));
						no->dado = solicitarDado();
						no->esquerdo = NULL;
						no->direito = NULL;
	
						lado = solicitarLado();
						if (lado == Esquerdo){
							pai->esquerdo = no;
						} else if (lado == Direito) {
							pai->direito = no;
						}
						printf("\nN� criado!\n");
						pause();
					} else {
						printf("\nN� n�o encontrado, ou os dois galhos j� est�o preenchidos.\n");
						pause();
					}
				}
				limpaTela();
				break;
			case 2:
				resultado = calcularArvore(raiz);
				printf("\nResultado: %i\n", resultado);
				pause();
				limpaTela();
				break;
			default:
				sair = 0;
				break;
		}
		
	} while (sair == 0);
	liberaNo(raiz);
	return 0;
}
