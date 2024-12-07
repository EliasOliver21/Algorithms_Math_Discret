#include <stdio.h>



int somatorio(int x){


    if(x > 0){
        
        return x + somatorio(x-1);

    }else{

        return x;
    }

}

int main(){

printf("%d\n",somatorio(5));

}