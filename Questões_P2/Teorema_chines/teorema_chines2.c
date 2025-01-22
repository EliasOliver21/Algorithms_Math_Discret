#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sao_coprimos(int m[], int qtde_eq) {
    for (int i = 0; i < qtde_eq; i++) {
        for (int j = i + 1; j < qtde_eq; j++) {
            if (mdc(m[i], m[j]) != 1) {
                return 0; 
            }
        }
    }
    return 1; 
}

int teo_ch(int qtde_eq) {
    int a[qtde_eq];
    int b[qtde_eq];
    int m[qtde_eq];
    int N[qtde_eq];
    int x[qtde_eq];
    int n;
    
    for (int i = 0; i < qtde_eq; i++) {
        scanf("%d %d %d", &a[i], &b[i], &m[i]);

        if (m[i] <= 0) {
            printf("Erro: m[%d] deve ser maior que 0.\n", i);
            return -1;
        }

        
        a[i] = (b[i] % m[i] + m[i]) % m[i];
    }

    
    if (!sao_coprimos(m, qtde_eq)) {
        printf("Erro: os módulos não são coprimos.\n");
        return -1;
    }

    
    n = 1;
    for (int i = 0; i < qtde_eq; i++) {
        n *= m[i];
    }

    
    for (int i = 0; i < qtde_eq; i++) {
        N[i] = n / m[i];
    }

    
    for (int i = 0; i < qtde_eq; i++) {
        int var_con = 0;
        int countx = 1;
        int limite = 1000000; 

        while (var_con < 1 && limite > 0) {
            long int s = N[i] * countx;

            if (s % m[i] == 1) {
                var_con = 1;
                x[i] = countx;
            }
            countx++;
            limite--;
        }

        if (limite == 0) {
            printf("Erro: não foi possível encontrar x[%d] dentro do limite de iterações.\n", i);
            return -1;
        }
    }

    
    long long result = 0;
    for (int i = 0; i < qtde_eq; i++) {
        result += (long long)a[i] * N[i] * x[i];
    }

    result = result % n;

    return result;
}

int main() {

    printf("Digite a quantidade de equações para o sistema de congruências a ser resolvido:\n");

    int equacoes;
    scanf("%d", &equacoes);

    if (equacoes < 1 || equacoes > 4) {
        printf("Erro: o número de equações deve ser entre 1 e 4.\n");
        return -1;
    }

    printf("Digite os valores de a, b e m para cada equação no formato(a b m) linha a linha para a quantidade de equações:\n");

    int resultado = teo_ch(equacoes);

    if (resultado != -1) {
        printf("O resultado do sistema de congruências é: %d\n", resultado);
    }

    return 0;
}
