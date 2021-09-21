#include <stdio.h>

int main() {

    int a = 10;
    int *p = &a; // *p decalara um ponteiro, &a retorna o endereço da variável

    printf("valor de A: %d\n", a);
    printf("endereco de A: %x\n\n", &a); // %x indica valor HEXADECIMAL

    printf("valor guardado no endereco de P: %d\n", *p);
    printf("endereco de P: %x\n", p);

    return 0;
}