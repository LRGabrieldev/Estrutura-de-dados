#include <stdio.h>
#include <stdlib.h>

//Declara��o de vari�veis ponteiro e/ou tipos de dados para manipular a Lista
typedef struct Node {
    int valor;
    struct Node* proximo;
}Node;

//Elabore uma fun��o para criar a lista vazia
Node* lista_vazia() {
    return NULL;
}

//Elabore uma fun��o para inserir um elemento na lista no in�cio
void inserir_inicio_lista(Node** lista, int num) {
    Node* novo_no = (Node*)malloc(sizeof(Node));

    novo_no->valor = num;
    novo_no->proximo = *lista;
    *lista = novo_no;
}

//Elabore uma fun��o para imprimir todos os elementos da lista
void imprimir_lista(Node* lista) {
    Node* aux = lista;

    while(aux != NULL) {
        printf("%d -> ", aux -> valor);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

//Elabore uma fun��o para excluir o elemento no in�cio da lista
void excluir_inicio(Node** lista) {
    Node* excluir = *lista;

    *lista = (*lista)->proximo;
    free(excluir);
}

//Elabore uma fun��o para imprimir os n�meros divis�veis por 3 armazenados na lista
void imprimir_divisivel_3(Node** lista) {
    Node* aux = *lista;

    while(aux != NULL) {
        if(aux->valor % 3 == 0) {
            printf("%d -> ",aux->valor);
        }
        aux = aux->proximo;
    }
    printf("NULL\n");
}

//Elabore uma fun��o para imprimir o �ltimo elemento da lista
void imprimir_ultimo(Node* lista) {
    Node* aux = lista;

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }

    printf("Ultimo elemento: %d\n", aux->valor);
}

// Elabore uma fun��o para imprimir o primeiro elemento da lista
void imprimir_primeiro(Node* lista) {
    Node* aux = lista;

    printf("Primeiro elemento: %d\n", aux->valor);
}

//Elabore uma fun��o para consultar se existe num n�mero N armazenado na lista
void existe_armazenado(Node* lista, int num) {
    Node* aux = lista;

    while(aux != NULL) {
        if(aux->valor == num) {
            printf("Elemento: %d\n", num);
            return;
        }
        aux = aux->proximo;
    }
}

//Elabore uma fun��o para eliminar todos os elementos da lista.
void eliminar_todos(Node* lista) {
    Node* aux;

    while(lista != NULL) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

int main() {
    Node* lista = NULL;

    inserir_inicio_lista(&lista, 3);
    inserir_inicio_lista(&lista, 30);
    inserir_inicio_lista(&lista, 4);
    inserir_inicio_lista(&lista, 5);
    inserir_inicio_lista(&lista, 1);
    inserir_inicio_lista(&lista, 2);

    //imprimir_primeiro(lista);
    //imprimir_ultimo(lista);
    //printf("\n");

    //printf("Divisiveis por 3:\n");
    //imprimir_divisivel_3(&lista);
    //printf("\n");

    //existe_armazenado(lista, 1);

    //excluir_inicio(&lista);

    eliminar_todos(lista);
    lista = NULL;

    printf("Lista completa:\n");
    imprimir_lista(lista);
}
