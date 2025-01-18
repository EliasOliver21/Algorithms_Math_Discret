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

    int x;
    scanf("%d", &x);
    imprimirFibonacci(x);
    
    return 0;
}