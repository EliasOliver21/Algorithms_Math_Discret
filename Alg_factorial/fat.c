#include <stdio.h>

long int fat(long int x){

    if( x == 0 || x == 1){

        return 1;

    }

    long int numb = x * ( fat( x - 1 ) );

    return numb;

}


int main(){

    int numero;

    scanf("%d", &numero);

    fflush(stdin);

    printf("%li\n", fat(numero));
    
    return 0;

}