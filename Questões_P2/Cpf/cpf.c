#include <stdio.h>


void calcula_digito_cpf(int cpf[9], int *digito1, int *digito2) {
    int soma1 = 0, soma2 = 0;

    
    for (int i = 0; i < 9; i++) {
        soma1 += cpf[i] * (10 - i);
    }
    *digito1 = (soma1 * 10) % 11;
    if (*digito1 == 10) *digito1 = 0;

    
    for (int i = 0; i < 9; i++) {
        soma2 += cpf[i] * (11 - i);
    }
    soma2 += *digito1 * 2;
    *digito2 = (soma2 * 10) % 11;
    if (*digito2 == 10) *digito2 = 0;
}

int main() {
    int cpf[9];
    int digito1, digito2;

    printf("Digite os 9 primeiros dígitos do CPF (separados por espaço):\n");
    for (int i = 0; i < 9; i++) {
        scanf("%d", &cpf[i]);
    }

    calcula_digito_cpf(cpf, &digito1, &digito2);

    printf("Dígitos verificadores: ");
    printf("%d e %d\n", digito1, digito2);

    return 0;
}
