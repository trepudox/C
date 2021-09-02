#include <stdio.h>

int fatorial(int x) {
    if (x == 1 || x == 0) {
        return 1;
    } else {
        return x * fatorial(x-1);
    }
}

int combinacao(int numElementos, int numCasos) {
    return fatorial(numElementos) / fatorial(numCasos) * fatorial(numElementos - numCasos);
}

int main() {
    int num1 = 0, num2 = 0;

    printf("Num1: ");
    scanf("%d", &num1);

    printf("Num2: ");
    scanf("%d", &num2);
	
    printf("Resultado da combinação C(%d, %d): %d", num1, num2, combinacao(num1, num2));

    return 0;
}