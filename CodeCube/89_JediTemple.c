#include "stdio.h"

int n,m,i,ai,bi;
int a[1001];

void swap_a(int i, int j){
    int t;
    for(; i < j; i++,j--){
        t = a[i%n];
        a[i%n] = a[j%n];
        a[j%n] = t;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&ai,&bi);
        swap_a(ai-1,ai+bi-2);
    }
    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}
