#include <stdio.h>

void pulaLinha() 
{
    printf("\n");
}

int main() 
{
    int num1, num2;

    printf("num1: ");
    scanf("%d", &num1);
    pulaLinha();

    printf("num2: ");
    scanf("%d", &num2);
    pulaLinha();

    printf("resultado: %d", num1 + num2);

    return 0;
}

