#include "stdio.h"
int n,k,i,j,x,c;
int a[100];
int rw[20];

int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = j = 0; i < n; i++){
        scanf("%d", &x);
        for(c=0; c <= x; j=(j+1)%n){
            if(a[j]!=-1) c++;
        }

        rw[i%k] += a[(j+n-1)%n];
        a[(j+n-1)%n] = -1;
    }
    for(i = 0; i < k; i++) printf("%d\n", rw[i]);
}
