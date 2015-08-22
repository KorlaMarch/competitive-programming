#include "stdio.h"
int a,b,i,j,t;
double n,m,sa,sb;
int A[1000000],B[1000000];

int main(){
    scanf("%d%d",&a,&b);
    n = a, m = b;
    for(i = 0; i < a; i++){
        scanf("%d",A+i);
        sa += A[i];
    }
    for(i = 0; i < b; i++){
        scanf("%d",B+i);
        sb += B[i];
    }
    if(sa/n>sb/m){
        for(i = 0; n>1&&A[i]<sa/n; i++){
            if(A[i]>sb/m){
                n--; m++;
                sa -= A[i];
                sb += A[i];
                t++;
            }
        }
    }else{
        for(i = 0; m>1&&B[i]<sb/m; i++){
            if(B[i]>sa/n){
                n++; m--;
                sb -= B[i];
                sa += B[i];
                t++;
            }
        }
    }
    printf("%d\n",t);
}
