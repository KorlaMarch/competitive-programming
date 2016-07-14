#include "stdio.h"
#include "algorithm"

int n,i,j,k,po;
int el[50001],be[50001];
char isP[100010];
int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&el[i]);
        isP[el[i]] = 1;
    }
    std::sort(el,el+n/2);
    std::sort(el+n/2,el+n);
    for(i=0,k=1; i < n; k++){
        if(!isP[k]){
            be[i++] = k;
        }
    }
    for(i=n/2-1,j=n-1; i>=0&&j>=0;){
        if(be[j]>el[i]){
            isP[be[j]] = 1;
            //printf("1 : %d %d :%d %d\n",i,j,el[i],be[j]);
            i--;
            j--;
            po++;
        }else i--;
    }
    for(i=n/2,j=0; i<n&&j<n;){
        if(be[j]<el[i]){
            isP[be[j]] = 1;
            //printf("2 : %d %d :%d %d\n",i,j,el[i],be[j]);
            i++;
            for(;j<n&&isP[be[j]];j++);
            po++;
        }else i++;
    }
    printf("%d\n",po);
    return 0;
}
