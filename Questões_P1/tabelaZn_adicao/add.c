#include <stdio.h>

void add(z){

    int tableZn[z][z];

    for (int i = 0; i < z; i++){

        for (int j = 0; j < z; j++){

            tableZn[i][j] = (i + j) % z;
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


    add(10);

}