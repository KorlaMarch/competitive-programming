#include "stdio.h"

int main(){
    int n, sumM = 0;
    int h,m,i;
    printf("Enter n? ");
    scanf("%d",&n);
    printf("Enter hours worked? ");
    for(i = 0; i < n; i++){
        scanf(" %d:%d",&h,&m);
        sumM += h*60 + m;
    }
    printf("%d min = %d h %d min\n", sumM, sumM/60, sumM%60);
}
