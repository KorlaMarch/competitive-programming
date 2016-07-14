#include "stdio.h"
#include "algorithm"

int n,i,j,k,po;
int el[50001],be[50001];

int main(){
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&el[i]);
    }
    std::sort(el,el+n);
    for(i=j=0,k=1; j < n; k++){
        if(i==n||el[i]!=k){
            be[j++] = k;
        }else i++;
    }
    for(i=j=0; i<n && j<n;){
        if(el[j]<be[i]){
            i++;
            j++;
            po++;
        }else i++;
    }
    printf("%d\n",po);
    return 0;
}
