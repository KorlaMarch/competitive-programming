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
    int i,j;
    printf("Input A:");
    input_matrix(A);
    printf("Input B:");
    input_matrix(B);
    printf("C is:");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%d ", A[i][j]+B[i][j]);
        }
        printf("\n");
    }
}
