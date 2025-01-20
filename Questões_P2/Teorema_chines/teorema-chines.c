#include <stdio.h>

int teo_ch(int qtde_eq){
    
    int a[qtde_eq];
    int m[qtde_eq];
    int N[qtde_eq];
    int x[qtde_eq];
    int n;

    // Inserindo valor da congruencia e universo utilizado
    for (int i = 0; i < qtde_eq; i++)
    {
        scanf("%d %d", &a[i], &m[i]);
    }

    n = m[0];

    // salvando a multiplicação dos uuniversos em n
    for (int i = 1; i < qtde_eq; i++)
    {
        n = n * m[i];
    }

    // Definindo os valores de N
    switch (qtde_eq)
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

    int var_con = 0;

    int countx;

    while(var_con < 1){

        int s = N[0] * countx;
        
        if (s % m[0] == 1){

            var_con = 1;
            x[0] = countx;
            
        }
        countx++;
    }

    var_con = 0;

    countx = 0;

    while(var_con < 1){

        int s = N[1] * countx;
        
        if (s % m[1] == 1){

            var_con = 1;
            x[1] = countx;
            
        }
        countx++;
    }

    var_con = 0;

    countx = 0;

    while(var_con < 1){

        int s = N[2] * countx;
        
        if (s % m[2] == 1){

            var_con = 1;
            x[2] = countx;
            
        }
        countx++;
    }


    for (int i = 0; i < qtde_eq; i++)
    {
        printf("%d\n", x[i]);
    }
    


    //Resultado final: Somatório(a * N * x)
    


}




int main(){

    printf("Digite a quantidade de equações para o sistema de congruências a ser resolvido\n");

    int equacoes;

    scanf("%d", &equacoes);

    teo_ch(equacoes);

}