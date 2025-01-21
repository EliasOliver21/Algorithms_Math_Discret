#include <stdio.h>


int calcula_digito_isbn(int isbn[9]) {
    int soma = 0;

    
    for (int i = 0; i < 9; i++) {
        soma += isbn[i] * (10 - i);
    }
    int digito = 11 - (soma % 11);
    if (digito == 10) return 'X'; 
    if (digito == 11) return 0;
    return digito;
}

int main() {
    int isbn[9];

    printf("Digite os 9 primeiros dígitos do ISBN (separados por espaço):\n");
    for (int i = 0; i < 9; i++) {
        scanf("%d", &isbn[i]);
    }

    int digito_isbn = calcula_digito_isbn(isbn);

    printf("Dígito verificador do ISBN: \n");

    if (digito_isbn == 'X') {
        printf("Caso Especial D= X\n");
    } else {
        printf("%d\n", digito_isbn);
    }

    return 0;
}
