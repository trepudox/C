#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int index;
    struct IntArray* nextAddress;
} IntArray;

IntArray* start() {
    return NULL;
}

IntArray* insert(IntArray* array) {
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntArray* newElement = (IntArray*) malloc(sizeof(IntArray));

    if (array == NULL) {
        newElement-> index = 0;
    } else {
        newElement->index = array->index + 1;
    }
    newElement->value = *num;
    newElement->nextAddress = array;
    
    printf("\nValor %d inserido com sucesso\n", *num);
    free(num);
    return newElement;
}

IntArray* deleteByIndex(IntArray* array) {
    IntArray* aux = array;
    IntArray* deletedElement = start();
    bool erased = false;

    int* desiredIndex = (int*) malloc(sizeof(int));
    printf("\nInsira o indice que deseja apagar: ");
    scanf("%d", desiredIndex);

    while (aux != NULL) {
        if (aux->index == *desiredIndex) {
            deletedElement = aux;
            erased = true;
            printf("antes do break");
            break;
        }

        aux = aux->nextAddress;
    }

    if (erased == true) {

        if (desiredIndex == 0) {
            aux = deletedElement->nextAddress;
            while (aux != NULL) {
                aux->index -= 1;
                aux = aux->nextAddress;
            }
        }

    } else {
        printf("O indice %d não foi encontrado", desiredIndex);
    }
    
    free(aux);
    free(desiredIndex);
    return;
}

void printAll(IntArray* array) {
    IntArray* aux = array;

    if (aux == NULL) {
        printf("\nNenhum valor inserido ate o momento\n");
        return;
    }

    printf("\nINDEX   VALUE\n");
    while (aux != NULL)
    {
        printf("%d.      %d\n", aux->index, aux->value);
        aux = aux->nextAddress;
    }
    
}

void size(IntArray* array) {
    int tamanho = 0;
    IntArray* aux = array;
    while (aux != NULL) {
        tamanho++;
        aux = aux->nextAddress;
    }
    printf("\nO tamanho atual da lista e de %d valor(es)\n", tamanho);
}

int main() {
    IntArray* array = start();

    int opcao = 1;

    do {
        
        printf("\nInsira um valor: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: 
                printf("adeus humanos\n"); 
                break;

            case 1:
                array = insert(array);
                break;

            case 2:
                array = deleteByIndex(array);
                break;

            case 3:
                printf("imprimir valor por indice\n");
                break;

            case 4:
                printAll(array);
                
                break;

            case 5:
                size(array);
                break;

            default: 
                printf("Entrada invalida, por favor escolha uma opcao valida.\n");
        }

    } while (opcao != 0);
    


    return 0;
}