#include <stdio.h>
#include <stlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
}No;

//Insirir no final da lista - extra
void insirir_no_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        //Verificar se a lista ta vazia
        if(*lista == NULL) {
            *lista = novo;
        } else {
            aux = *lista;

            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;

        }

    } else {
        printf("Erro ao alocar a memoria!");
    }
}

//c) Elabore uma função para inserir um elemento na lista no início
void inserir_no_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;

    } else {
        prinf("Erro ao alocar memoria!\n");
    }
}

int main() {

    return 0;
}
