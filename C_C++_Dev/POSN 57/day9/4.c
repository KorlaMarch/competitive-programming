#include "stdio.h"

void mutipleRow(double row[], int n, double k){
    int i;
    for(i = 0; i < n; i++){
        row[i] *= k;
    }
}

void plusByRow(double source[], double target[], int n, int k){
    int i;
    for(i = 0; i < n; i++){
        target[i] += source[i]*k;
    }
}

void mutipleToOne(double row[], int n, int pos){
    if(row[pos]){
        mutipleRow(row, n, 1.0/row[pos]);
        row[pos] = 1;
    }
}

void plusToZero(double source[], double target[], int n, int pos){
    plusByRow(source, target, n, target[pos]*-1);
    target[pos] = 0;
}

void printMatrix(double matrix[32][32], int nx, int ny){
    int i,j;
    for(i = 0; i < ny; i++){
        for(j = 0; j < nx; j++){
            printf("%10f", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

double getSum(double row[], double ans[], int from, int to){
    int i;
    double sum;
    for(i = from, sum = 0.0; i < to; i++){
        sum += row[i]*ans[i];
    }
    return sum;
}

int main(){
    int n,i,j;
    double matrix[32][32];
    double ans[32];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j <= n; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
    //forward elimination
    printf("\n");
    for(i = 0; i < n; i++){
        mutipleToOne(matrix[i],n+1,i);
        for(j = i+1; j < n; j++){
            plusToZero(matrix[i], matrix[j],n+1,i);
        }
        printMatrix(matrix, n+1, n);
    }

    //Back Substitution
    for(i = n-1; i >= 0; i--){
        //printf("i = %d %f %f\n", i,matrix[i][n],getSum(matrix[i], ans, i+1, n));
        ans[i] = matrix[i][n]-getSum(matrix[i], ans, i+1, n);
    }

    for(i = 0; i < n; i++){
        printf("x%d = %9f\n", i+1, ans[i]);
    }

}

