#include <stdio.h>

int fatorial(int x) {
    if (x == 1 || x == 0) {
        return 1;
    } else {
        return x * fatorial(x-1);
    }
}

int main()
{
    printf("%d", fatorial(14));

    return 0;
}