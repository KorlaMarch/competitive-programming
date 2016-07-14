#include <stdio.h>

int A, B, C;

int main(){
    int times = 0;
    scanf("%d%d%d", &A, &B, &C);
    while(A > 1 || B > 1 || C > 1){
        //printf("A = %d B = %d C = %d\n", A, B, C);
        //if it's odd cut it into even
        if(A % 2 != 0){
            A -= 1;
        }
        if(B % 2 != 0){
            B -= 1;
        }
        if(C % 2 != 0){
            C -= 1;
        }

        if(A >= B && A >= C){
            A = A / 2;
        }else if(B >= A && B >= C){
            B = B / 2;
        }else{
            C = C / 2;
        }
        times++;
    }
    printf("%d", times);
}
