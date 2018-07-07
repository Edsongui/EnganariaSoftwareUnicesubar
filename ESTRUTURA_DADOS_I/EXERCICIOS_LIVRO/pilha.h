
#define tamanho  10
#define max 40

struct LivroGenerico {
	int codigo;
	char titulo[max];
	char autor[max];
};

typedef struct LivroGenerico Livro;

struct PilhaGenerica {
	int topo;
	Livro livros[tamanho];
};
typedef struct PilhaGenerica Pilha;  

Pilha* criarPilha();
int liberarPilha(Pilha *pilha);
int empilhar(Pilha *pilha);
void desempilhar(Pilha *pilha);
void imprimir(Pilha *pilha);


