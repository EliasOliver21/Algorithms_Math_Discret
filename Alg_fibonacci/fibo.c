#include <stdio.h>

int fibonacci(int x){


    if(x <= 1){
        return 1;
    }else{
        return fibonacci(x-1) + fibonacci(x-2);
    }

}

void imprimirFibonacci(x){

    for(int i=0;i < x; i++){
        printf("%d\n", fibonacci(i));
    }

}



int main(){

    // Impressão dos 10 primerios elementos da sequência de Fibonacci
    imprimirFibonacci(15);
    
    return 0;
}