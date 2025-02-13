#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct Fila {
    Node* frente;
    Node* tras;
} Fila;

//Criar uma fila vazia
Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = NULL;
    f->tras = NULL;
    return f;
}

//Incluir um elemento na fila
void enqueue(Fila* fila, int num) {
    Node* novo_no = (Node*)malloc(sizeof(Node));

    novo_no->valor = num;
    novo_no->proximo = NULL;

    if(fila->tras == NULL) {
        fila->frente = fila->tras = novo_no;
    } else {
        fila->tras = fila->tras = novo_no;
        fila->tras = novo_no;
    }

    printf("Elemento inserido na fila: %d\n", num);
}

//Excluir um elemento da fila
void dequeue(Fila* fila) {
    Node* aux = fila->frente;
    fila->frente = fila->frente->proximo;

    if(fila->frente == NULL) {
        fila->tras = NULL;
    }

    printf("Elemento exluido da fila: %d\n", aux->valor);
    free(aux);
}

//Consultar o primeiro elemendo da fila
void primeiro_elemento(Fila* fila) {
    printf("Primeiro elemento da fila; %d\n", fila->frente->valor);
}

void ultimo_elemento(Fila* fila) {
    printf("Ultimo elemento da fila: %d\n", fila->tras->valor);
}

int main() {
    Fila* minhaFila = criar_fila();

    enqueue(minhaFila, 10);
    enqueue(minhaFila, 20);
    enqueue(minhaFila, 30);

    primeiro_elemento(minhaFila);
    ultimo_elemento(minhaFila);

    dequeue(minhaFila);
}
