#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int verifica_mdc(int a, int b) {
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}


void palavra_para_numeros(char *palavra, int *numeros, int *tamanho) {
    int index = 0; 

    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i])) { 
            char letra = toupper(palavra[i]); 
            numeros[index++] = (letra - 'A' + 11); 
        }
    }
    *tamanho = index; 
}


int exponenciacao_modular(int base, int exp, int mod) {
    int resultado = 1;

    base = base % mod; 

    while (exp > 0) {
        if (exp % 2 == 1) { 
            resultado = (resultado * base) % mod;
        }
        exp = exp / 2; 
        base = (base * base) % mod; 
    }

    return resultado;
}


void criptografia_RSA(int p, int q, int e, int *numeros, int tamanho, int bloco) {
    int n = p * q;

    printf("Palavra criptografada: ");

    
    for (int i = 0; i < tamanho; i += bloco) {
        int bloco_num = 0;

        
        for (int j = 0; j < bloco && (i + j) < tamanho; j++) {
            bloco_num = bloco_num * 100 + numeros[i + j]; 
        }

        int criptografado = exponenciacao_modular(bloco_num, e, n); 
        printf("%d ", criptografado);
    }

    printf("\n");
}

int main() {
    int p, q, e, bloco;
    char word[100];
    int numeros[100];
    int tamanho;

    printf("Insira 3 números coprimos para serem p, q e e (p e q devem ser primos e e coprimo com (p-1)*(q-1)):\n");
    scanf("%d %d %d", &p, &q, &e);

    if (verifica_mdc(p, q) != 1) {
        printf("Os números p e q devem ser primos entre si. Tente novamente!\n");
        return -1;
    }

    int phi = (p - 1) * (q - 1);
    if (verifica_mdc(e, phi) != 1) {
        printf("O número e deve ser coprimo com (p-1)*(q-1). Tente novamente!\n");
        return -1;
    }

    printf("Digite o tamanho dos blocos para criptografia:\n");
    scanf("%d", &bloco);

    printf("Digite a palavra a ser criptografada:\n");
    scanf("%s", word);

    palavra_para_numeros(word, numeros, &tamanho);

    criptografia_RSA(p, q, e, numeros, tamanho, bloco);

    return 0;
}
