#include "stdio.h"

int main(){
    int n,k,i,j,t,x,y,mid;
    int bookP[100000];
    int ans[100000];
    scanf("%d%d",&n,&k);
    scanf("%d", &bookP[0]);
    for(i = 1; i < n; i++){
        scanf("%d", &bookP[i]);
        bookP[i] += bookP[i-1];
    }
    for(i = 0; i < k; i++){
        scanf("%d", &t);
        x = 0, y = n-1;
        while(x < y){
            mid = (y-x)/2+x;
            if(t == bookP[mid]){
                j = mid;
                break;
            }else if(t < bookP[mid]){
                y = mid-1;
            }else {
                x = mid+1;
            }
        }
        if(x == y){
            if(t < bookP[x]){
                j = x-1;
            }else{
                j = x;
            }
        }
        ans[i] = j+1;
    }
    for(i = 0; i < k; i++){
        printf("%d\n", ans[i]);
    }
}
