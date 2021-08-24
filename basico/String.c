#include <stdio.h>

void pulaLinha()
{
    printf("\n");
}

int main() 
{
    char nome[] = {'M', 'a', 'r', 'c', 'o', '\0'};
    printf("%s", nome);

    pulaLinha();

    char nome2[] = "Marco";
    printf("%s", nome2);

    return 0;
}