#include "stdio.h"

int n,i,j,k,x,t;
int pos[1002];

int main(){
    scanf("%d%d",&n,&x);
    pos[0] = x;
    for(i = 1; i < n; i++){
        scanf("%d",&x);
        if(pos[0]!=0){
            for(j = 0; j < i && x>=pos[j]; j++){
                if(x>pos[j]) x--;
                pos[j] = pos[j]-1;
            }
            for(k=i;k>j;k--){
                pos[k] = pos[k-1];
            }
            pos[j] = x;
        }else{
            for(j = i; j>0; j--){
                pos[j] = pos[j-1];
                if(pos[j]<x+j) pos[j] = x+j;
            }
            pos[0] = x;
        }
    }
    for(i = n-1; i >= 0; i--){
        printf("%d\n",pos[i]);
    }
}
