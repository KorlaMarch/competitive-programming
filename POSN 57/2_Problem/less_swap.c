#include "stdio.h"

int main(){
    int num[64];
    int n,i,c,j,k,l,min,t;
    scanf("%d",&k);
    for(l = 0; l < k; l++){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        for(i=c=0; i<n; i++){
            min = i;
            for(j = i+1; j < n; j++){
                if(num[j]<num[min]) min = j;
            }
            if(min != i){
                c++;
                t=num[i];
                num[i]=num[min];
                num[min]=t;
            }
        }
        printf("%d\n",c);
    }
}
