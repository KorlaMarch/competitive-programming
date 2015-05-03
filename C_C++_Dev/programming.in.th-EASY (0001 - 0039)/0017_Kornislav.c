#include <stdio.h>

int fmax(int x, int y){
    return x > y ? x : y;
}

int fmin(int x, int y){
    return x > y ? y : x;
}

int main(){
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    int max = fmax(fmax(A,B), fmax(C,D));
    int max2;
    if(A == max){
        max2 = fmax(fmax(C,D), B);
        if(B == max2){
            printf("%d", fmin(C,D)* fmin(A,B));
        }else if(max2 == C){
            printf("%d", fmin(B,D)* fmin(A,C));
        }else{
            printf("%d", fmin(B,C)* fmin(A,D));
        }
    }else if(B == max){
        max2 = fmax(fmax(C,D), A);
        if(A == max2){
            printf("%d", fmin(C,D)* fmin(B,A));
        }else if(C == max2){
            printf("%d", fmin(A,D)* fmin(B,C));
        }else{
            printf("%d", fmin(A,C)* fmin(B,D));
        }
    }else if(C == max){
        max2 = fmax(fmax(A,B), D);
        if(A == max2){
            printf("%d", fmin(B,D)* fmin(C,A));
        }else if(B == max2){
            printf("%d", fmin(A,D)* fmin(C,B));
        }else{
            printf("%d", fmin(A,B)* fmin(C,D));
        }
    }else{
        max2 = fmax(fmax(A,B), C);
        if(A == max2){
            printf("%d", fmin(B,C)* fmin(D,A));
        }else if(B == max2){
            printf("%d", fmin(A,C)* fmin(D,B));
        }else{
            printf("%d", fmin(A,B)* fmin(D,C));
        }
    }

}
