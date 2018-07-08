#define tamanho 5
#define max 40

struct ClienteGenerico {
	char nome[max];
	int horaChegada;
	int minutoChegada;
};

typedef struct ClienteGenerico Cliente;

struct FilaGenerica {
	int fim;
	Cliente clientes[tamanho];
};
typedef struct FilaGenerica Fila;  

Fila* criarFila();
int liberarFila(Fila *fila);
int enfileirar(Fila *fila);
void desemfileirar(Fila *fila);
void imprimir(Fila *fila);
