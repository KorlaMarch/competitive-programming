#include <stdio.h>

int main(){
    int A,B,C;
    printf("A = "); scanf("%d", &A);
    printf("B = "); scanf("%d", &B);
    printf("C = "); scanf("%d", &C);
    if(A <= 0){
        printf("x = %f", (float)C/B);
    }else{
        if(B*B - 4*A*C < 0){
            printf("x = %.3fi and %.3fi", ((float)-1*B + sqrt((B*B - 4*A*C)*-1))/ (float)(2*A),
                    ((float)-1*B - sqrt((B*B - 4*A*C)*-1))/ (float)(2*A));
        }else{
            printf("x = %.3f and %.3f", ((float)-1*B + sqrt(B*B - 4*A*C))/ (float)(2*A),
                   ((float)-1*B - sqrt(B*B - 4*A*C))/ (float)(2*A));
        }
    }
    return 0;
}
