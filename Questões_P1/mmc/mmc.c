#include <stdio.h>

MDC(x,y){

    if (y == 0){

        return x;

    }else{

        
        int n = x % y;

        int m = MDC(y,n);

    }
    

}

int calc_MMC(a,b){

    int z = (a * b) / MDC(a,b);

    printf("%d\n", z);

}

int main(){


calc_MMC(18,45);

}