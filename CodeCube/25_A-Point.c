#include "stdio.h"
int n,i,j,k;
int a[600];
long long int x,y,s,max,maxTS;
long long int maxS[600][600];

int main(){
    scanf("%d%d",&n,a);
    for(i = 1; i < n; i++){
        scanf("%d",a+i);
        a[i] += a[i-1];
    }
    for(i = 0; i < n; i++){
        for(j = n-1; j >= i; j--){
            max = 0;
            x = i?a[j]-a[i-1]:a[j];
            k = j+1;
            if(k<n){
            //for(k = j+1; k < n; k++){
                y = a[k]-a[j];
                if(x>y) s = x+y*2;
                else s = x*2+y;
                s += maxS[i][k];
                if(s>max) max = s;
            //}
            }
            k = i-1;
            if(k>=0){
            //for(k = i-1; k >= 0; k--){
                y = k?a[i-1]-a[k-1]:a[i-1];
                if(x>y) s = x+y*2;
                else s = x*2+y;
                s += maxS[k][j];
                if(s>max) max = s;
            //}
            }
            maxS[i][j] = max;
            if(max>maxTS) maxTS = max;
        }
    }
    printf("%lld\n", maxTS);
}
