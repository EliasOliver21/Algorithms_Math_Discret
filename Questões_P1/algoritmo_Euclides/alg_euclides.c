#include <stdio.h>


algEuclides(x,y){

    if (y == 0){

        return x;

    }else{

        
        int n = x % y;

        int m = algEuclides(y,n);

    }
    

}


int main(){

    printf("%d\n", algEuclides(48,18));

}