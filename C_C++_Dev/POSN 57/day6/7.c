#include "stdio.h"

#define SIZE 3

int input_matrix(int n[SIZE][SIZE]){
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            scanf("%d", &n[i][j]);
        }
    }
}


int main(){
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE] = {};
    int i,j,k;

    printf("Input A:\n");
    input_matrix(A);
    printf("Input B:\n");
    input_matrix(B);

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            for(k = 0; k < SIZE; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}
