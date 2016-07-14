#include "stdio.h"

int main(){
    int n,a,b,i,j,min,bs,w,l;
    int item[1005];
    scanf("%d%d%d",&n,&a,&b);
    for(i = 0; i < n; i++){
        scanf("%d",item+i);
    }
    min = 100000000;
    for(i = a; i <= b; i++){
        for(j=w=0,l=i; j < n; j++){
            if(item[j]>i){
                w = 100000000;
                break;
            }else if(item[j]>l){
                w += l;
                l = i-item[j];
            }else{
                l -= item[j];
            }
        }
        w += l;
        if(w<min){
            min = w;
            bs = i;
        }
        //printf(":%d %d\n",i,min);
    }
    printf("%d\n",bs);
}
