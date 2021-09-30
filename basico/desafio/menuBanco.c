#include <stdio.h>

typedef struct {
    int numeroDaConta;
    int agencia;
    double saldo;
} Conta;

void verConta(Conta *conta) {
    printf("\nNumero da conta: %d\nAgencia: %d\nSaldo: %.2f\n", conta->numeroDaConta, conta->agencia, conta->saldo);
}

void depositar(Conta *conta) {
    int valor;
    printf("\nEscolha quanto deseja depositar: ");
    scanf("%d", &valor);

    if (valor <= 0) {
        printf("Voce nao pode depositar %.2f!\n", valor);
        return;
    }

    conta->saldo+=valor;

    printf("Deposito realizado com sucesso\n");
}

void sacar(Conta *conta) {
    int valor;
    printf("\nEscolha quanto deseja sacar: ");
    scanf("%d", &valor);

    if (valor > conta->saldo) {
        printf("Voce nao pode sacar um valor maior do que possui!\n", valor);
        return;
    }

    conta->saldo-=valor;

    printf("Saque realizado com sucesso\n");
}


int main() {

    Conta conta;
    conta.agencia = 1140;
    conta.numeroDaConta = 6922410;
    conta.saldo = 0;

    int opcao = 10;

    do {
        printf("\nEscolha uma opcao:\n0 - Encerrar\n1 - Ver conta\n2 - Depositar\n3 - Sacar\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;

            case 1:
                verConta(&conta);
                break;

            case 2:
                depositar(&conta);
                break;
            
            case 3:
                sacar(&conta);
                break;

            default:
                printf("\nEscolha uma opcao valida!\n");
                break;
        }

    } while (opcao != 0);

    printf("\nFim do programa");

    return 0;
}