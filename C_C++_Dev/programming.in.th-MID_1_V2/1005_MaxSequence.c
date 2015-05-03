#include "stdio.h"

int main(){
    int n,i,j,m,s,e;
    int in[2501],qs[2501];
    scanf("%d", &n);
    qs[0] = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &in[i]);
        qs[i] = qs[i-1]+in[i];
    }

    for(i = 1,m = 0; i <= n; i++){
        for(j = i; j <= n; j++){
            if(qs[j]-qs[i-1] > m){
                m = qs[j]-qs[i-1];
                s = i; e = j;
            }
        }
    }
    if(m){
        for(i = s; i <= e; i++) printf("%d ", in[i]);
        printf("\n%d\n",m);
    }else{
        printf("Empty sequence\n");
    }
}
