 #include "stdio.h"

 int n;
 int next[100000],prev[100000];
 int main(){
    int i,j,p,x;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        next[i] = (i+1)%n;
        prev[i] = (i+n-1)%n;
    }
    for(i=1,p=0; i < n; i++){
        scanf("%d",&x);
        for(j = 0; j < x; j++,p = next[p]);
        next[prev[p]] = next[p];
        prev[next[p]] = prev[p];
        p = prev[p];
    }
    printf("%d\n", p+1);
 }
