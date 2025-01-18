#include <stdio.h>

int impressao(int x){

    if(x > 1 ){

        impressao(x-1);
    }

    printf("%d\n",x);

}


int main(){


    impressao(10);

}