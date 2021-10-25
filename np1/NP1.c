#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    struct IntLinkedList* nextAddress;
} IntLinkedList;

IntLinkedList* start() {
    return NULL;
}

IntLinkedList* insert(IntLinkedList* list) {
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntLinkedList* newElement = (IntLinkedList*) malloc(sizeof(IntLinkedList));

    newElement->value = *num;
    newElement->nextAddress = list;
    
    printf("\nValor %d inserido com sucesso\n", *num);
    free(num);
    return newElement;
}

IntLinkedList* deleteByValue(IntLinkedList* list) {
    if (list == NULL) {
        printf("\nA lista esta vazia, nao ha elementos para apagar.\n");
        return list;
    }
    
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntLinkedList* aux = list;

    while (true) {
        if (aux->value == *num) {
            list = aux->nextAddress;
            free(num);
            free(aux);
            printf("\nNumero excluido com sucesso\n");
            return list;
        }

        IntLinkedList* lastElement = aux;

        aux = aux->nextAddress;
        if (aux == NULL) {
            break;
        }

        if (aux->value == *num) {
            lastElement->nextAddress = aux->nextAddress;
            free(num);
            free(aux);
            printf("\nNumero excluido com sucesso\n");
            return list;
        }
    }
    
    printf("\nNao foi possivel encontrar o valor desejado.\n");
    free(num);
    return list;
}

void findByValue(IntLinkedList* list) {
    int* num = (int*) malloc(sizeof(int));
    printf("\nInsira o numero desejado: ");
    scanf("%d", num);

    IntLinkedList* aux = list;

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

void printAll(IntLinkedList* list) {
    if (list == NULL) {
        printf("\nNenhum valor inserido ate o momento\n");
        return;
    }

    IntLinkedList* aux;
    printf("\nVALUE\n");
    for (aux = list; aux != NULL; aux = aux->nextAddress) {
        printf("%d\n", aux->value);
    }
}

void size(IntLinkedList* list) {
    int tamanho = 0;
    IntLinkedList* aux = list;
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
        IntLinkedList* list;
        printf("\nMENU:\n1. Iniciar/Reiniciar\n2. Inserir\n3. Excluir\n4. Imprimir\n5. Buscar\n6. Numero de Elementos\n7. Fim");
        printf("\nInsira um valor: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                list = start();
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

                list = insert(list);
                break;

            case 3:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }
                list = deleteByValue(list);
                break;

            case 4:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                printAll(list);
                break;

            case 5:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                findByValue(list);
                break;
            
            case 6:
                if (inicio) {
                    printf("\nA lista precisa ser iniciada para o programa comecar\n");
                    break;
                }

                size(list);
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