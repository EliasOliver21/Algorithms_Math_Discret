#include <stdio.h>

int table_mul(z){

    int tableZn[z][z];

    for (int i = 0; i < z; i++){

        for (int j = 0; j < z; j++){

            tableZn[i][j] = (i * j) % z;
        }
        
    }

    for (int i = 0; i < z; i++){

        for (int j = 0; j < z; j++){

            printf("%d |", tableZn[i][j] );
        }

            printf("\n");
        
    }


}


int main(){


    table_mul(10);

}