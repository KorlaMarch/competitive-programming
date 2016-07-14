#include "stdio.h"
#define SIZE 2000000
int n,k,i,mx;
long long int d;
char c;
int minP[SIZE*2+1];
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d ",&n,&k);
    minP[SIZE] = 1;
    for(i = 2,n += 2; i < n; i++){
        if(getchar()=='R') d -= k;
        else d++;
        if(d>=-SIZE&&d<=SIZE){
            if(minP[d+SIZE]!=0){
                mx = max(mx,i-minP[d+SIZE]);
            }else{
                minP[d+SIZE] = i;
            }
        }
    }
    printf("%d\n",mx);
}
