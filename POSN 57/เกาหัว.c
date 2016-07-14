#include "stdio.h"

int abs(int i){
    return i < 0 ? i*-1 : i;
}

int main(){
    int i,j,n,max;
    int h[32];
    scanf("%d",&n);
    for(i = 0,max = 0; i < n; i++){
        scanf("%d", &h[i]);
        if(h[i] > max) max = h[i];
    }

    for(i = max*-1+1; i < max; i++){
        for(j = 0; j < (n-1)*5+h[n-1];j++){
                if((j-abs(i))%5 == 0 && abs(i) < h[(j-abs(i))/5]){
                    printf("*");
                }else{
                    printf(" ");
                }
        }
        printf("\n");
        }

}
