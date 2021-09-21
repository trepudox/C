#include <stdio.h>

int main() {

    int x = 0;
    int *p = &x;

    printf("Endereco p: %x\n", p);
    printf("Endereco p + 1: %x\n", p + 1);
    printf("Endereco p - 1: %x\n", p - 1);

    return 0;
}