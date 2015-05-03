#include "stdio.h"

int a[100000];
int n;

int bs(int x){
    int i = 0,j = n-1,k;
    while(i < j){
        k = (i+j)/2;
        printf("k = %d (%d %d)\n",k,i,j);
        if(a[k] > x){
            j = k-1;
        }else{
            i = k+1;
        }
    }
    k = (i+j)/2;
    printf("k = %d (%d %d)\n",k,i,j);
}

int main(){
    int m,i,x;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < m; i++){
        scanf("%d", &x);
        printf("%d\n", bs(x));
    }
}
