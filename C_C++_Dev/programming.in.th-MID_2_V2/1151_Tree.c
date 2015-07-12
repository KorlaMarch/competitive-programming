#include "stdio.h"
int n,k,hi,p,i,j,m;
int lis[200001];
int main(){
    scanf("%d",&n);
    for(k = 0; k < n; k++){
        scanf("%d",&hi);
        for(i=0,j=p-1; i<=j;){
            m = (i+j)/2;
            if(hi<=lis[m]){
                j = m-1;
            }else{
                i = m+1;
            }
        }
        if(hi>lis[j+1]){
            lis[j+2] = hi;
            p++;
        }else if(hi<lis[j+1]){
            lis[j+1] = hi;
        }
    }
    printf("%d\n",p);
}
