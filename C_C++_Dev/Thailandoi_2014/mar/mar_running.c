#include "stdio.h"

int main(){
    int w,n,l,t,k,st,i,j;
    int stop[1001];
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        scanf("%d%d%d",&w,&n,&l);
        l %= w;
        if(l==0){
            printf("%d\n",1);
            continue;
        }
        st = -2;
        for(i = 0; i < n; i++){
            scanf("%d", &stop[i]);
            for(j = 0; j < i; j++){
                if(stop[i]-stop[j]==l&&(st==-2||j<st)) st = j;
            }
        }
        printf("%d\n", st+1);
    }
}
