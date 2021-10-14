#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
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

    newElement->value = *num;
    newElement->nextAddress = array;
    
    printf("\nValor %d inserido com sucesso\n", *num);
    free(num);
    return newElement;
}

IntArray* deleteByValue(IntArray* array) {
    if (array == NULL) {
        printf("\nA lista esta vazia, nao ha elementos para apagar.\n");
        return array;
    }
    
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntArray* aux = array;

    while (true) {
        if (aux->value == *num) {
            array = aux->nextAddress;
            free(num);
            free(aux);
            return array;
        }

        IntArray* lastElement = aux;

        aux = aux->nextAddress;
        if (aux == NULL) {
            break;
        }

        if (aux->value == *num) {
            lastElement->nextAddress = aux->nextAddress;
            free(num);
            free(aux);
            return array;
        }
    }
    
    printf("\nNao foi possivel encontrar o valor desejado.\n");
    free(num);
    return array;
}

void findByValue(IntArray* array) {
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntArray* aux = array;

    while (aux != NULL) {
        if (aux->value == *num) {
            printf("\nVALUE\n");
            printf("%d\n", aux->value);
            free(num);
            return;
        }

        aux = aux->nextAddress;
    }

    printf("\nO numero %d nao foi encontrado\n", *num);
    free(num);
}

void printAll(IntArray* array) {
    if (array == NULL) {
        printf("\nNenhum valor inserido ate o momento\n");
        return;
    }

    IntArray* aux;
    printf("\nVALUE\n");
    for (aux = array; aux != NULL; aux = aux->nextAddress) {
        printf("%d\n", aux->value);
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

    int opcao = 0;
    bool inicio = true;

    do {
        IntArray* array;
        printf("\nMENU:\n1. Iniciar/Reiniciar\n2. Inserir\n3. Excluir\n4. Imprimir\n5. Buscar\n6. Numero de Elementos\n7. Fim");
        printf("\nInsira um valor: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                array = start();
                if (inicio) {
                    printf("\nA lista foi iniciada.\n");
                    inicio = false;
                } else {
                    printf("\nA lista foi reiniciada.\n");
                }
                break;

            case 2:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                array = insert(array);
                break;

            case 3:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }
                array = deleteByValue(array);
                break;

            case 4:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                printAll(array);
                break;

            case 5:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                findByValue(array);
                break;
            
            case 6:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                size(array);
                break;

            case 7: 
                printf("\nFim do programa\n"); 
                break;

            default: 
                printf("Entrada invalida, por favor escolha uma opcao valida.\n");
        }

    } while (opcao != 7);
    


    return 0;
}