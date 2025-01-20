#include <stdio.h>

int teo_ch(int x){
    
    int a[x];
    int m[x];
    int N[x];
    int n;

    // Inserindo valor da congruencia e universo utilizado
    for (int i = 0; i < x; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }

    n = m[0];

    // salvando a multiplicação dos uuniversos em n
    for (int i = 1; i < x; i++)
    {
        n = n * m[i];
    }

    // Definindo os valores de N
    switch (x)
    {    
    case 3:

        N[0] = m[1] * m[2];
        N[1] = m[0] * m[2];
        N[2] = m[0] * m[1];

        break;
    
    case 4:

        N[0] = m[1] * m[2] * m[3];
        N[1] = m[0] * m[2] * m[3];
        N[2] = m[0] * m[1] * m[3];
        N[3] = m[0] * m[1] * m[2];
        break;
    default:
        break;
    }
    


    for (int i = 0; i < x; i++)
    {
        printf("%d\n", N[i]);
    }
    
    printf("%d\n", n);
    

}




int main(){

    printf("Digite a quantidade de equações para o sistema de congruências a ser resolvido\n");

    int equacoes;

    scanf("%d", &equacoes);

    teo_ch(equacoes);

}