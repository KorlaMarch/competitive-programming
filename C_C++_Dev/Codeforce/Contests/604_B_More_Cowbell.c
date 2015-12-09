#include "stdio.h"

int n,k,i,j,s[205005],box[205005],mx;

int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&s[i]);
    }
    mx = s[n-1];
    for(i = k-1,j=n-1; i >= 0 && j >= 0; i--,j--){
        box[i] = s[j];
    }
    for(i = 0; j >= 0; j--,i++){
        box[i] += s[j];
        if(box[i]>mx) mx = box[i];
    }
    printf("%d",mx);
}
