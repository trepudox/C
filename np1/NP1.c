#include <stdio.h>

typedef struct {
    int index[100];
    int element[100];
} ListaInt;


int main() {
    ListaInt listaInt;

    printf("%d", listaInt.index[0]);
    printf("\n");
    printf("%d", listaInt.index[1]);
    printf("\n");
    printf("%d", listaInt.index[2]);
    printf("\n");
    printf("%d", listaInt.index[3]);

    int opcao = 1;

    do {
        
        printf("Insira um valor: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: 
                printf("adeus humanos\n"); 
                break;

            case 1:
                printf("inserir\n");
                break;

            case 2:
                printf("excluir por indice\n");
                break;

            case 3:
                printf("imprimir valor por indice\n");
                break;

            case 4:
                printf("imprimir tudo\n");
                break;

            case 5:
                printf("mostrar tamanho\n");
                break;

            default: 
                printf("Entrada invalida, por favor insira um valor valido.\n");
        }

    } while (opcao != 0);
    


    return 0;
}