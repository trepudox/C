#include <stdio.h>

int main() {

    // & acessa o endereço da variável
    // * acessa o conteúdo da variável
    // declarar uma variável com * na frente significa que ela é um ponteiro

    int A; // variável inteira A
    int *P; // variável ponteiro P

    A = 5; // valor de A = 5
    P = &A; // valor de P = endereço de A

    printf("endereco de A: %x\n", &A);
    printf("endereco de P: %x\n", P);

    printf("%d\n", A);
    *P = 10; // alterando o valor endereçado à P e A
    printf("%d\n", A);

    return 0;
}