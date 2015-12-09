#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int n,k,i,j,mn,smn;
int a[3001],minC[3001];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    if(k<n){
        minC[0] = a[0];
        for(i = 1; i < n; i++){
            minC[i] = 1000000000;
            if(i<k){
                for(j = 0; j < i; j++){
                    if(a[j]<minC[i]) minC[i] = a[j];
                }
            }else{
                for(j = i-k+1; j < i; j++){
                    if(minC[j]<minC[i]) minC[i] = minC[j];
                }
            }
            minC[i] += a[i];
            //printf("i = %d %d\n",i,minC[i]);
        }
        mn = 1000000000;
        for(i = n-k+1; i < n; i++){
            if(minC[i]<mn) mn = minC[i];
        }
        printf("%d\n",mn);
    }else{
        mn = smn = 1000000000;
        for(i = 0; i < n; i++){
            if(a[i]<mn){
                smn = mn;
                mn = a[i];
            }else if(a[i]<smn){
                smn = a[i];
            }
        }
        printf("%d\n",mn+smn);
    }
}
