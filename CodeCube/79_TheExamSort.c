#include "stdio.h"
int i,j,k,n,skip,tmp,x,c;
int pos[1005];
int li[1005];
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",li+i);
        pos[li[i]] = i;
    }
    for(i = 1,j=n,c=0;c<n;){
        if(pos[i]==i) skip++;
        else{
            for(k = pos[i]; k>i; k--){
                tmp = li[k-1];
                li[k-1] = li[k];
                li[k] = tmp;
                pos[li[k-1]] = k-1;
                pos[li[k]] = k;
            }
        }
        i++,c++;
        if(c>=n) break;
        if(pos[j]==j) skip++;
        else{
            for(k = pos[j]; k<j; k++){
                tmp = li[k+1];
                li[k+1] = li[k];
                li[k] = tmp;
                pos[li[k+1]] = k+1;
                pos[li[k]] = k;
            }
        }
        j--,c++;
    }
    printf("%d\n",skip);
}
