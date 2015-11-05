#include "stdio.h"

int n,m,i,x,y,mid;
int a[10005];
char isE;
int getG(int k){
    int i,j,g;
    for(i=0,g=1,j=k; i < n; i++){
        if(j<a[i]){
            g++;
            j = k;
        }
        j -= a[i];
    }
    return g;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",a+i);
        if(a[i]>x) x = a[i];
        y += a[i];
    }
    while(x<=y){
        mid = getG((x+y)/2);
        if(mid==m){
            isE = 1;
            x = (x+y)/2+1;
        }else if(mid>m){
            x = (x+y)/2+1;
        }else{
            y = (x+y)/2-1;
        }
    }
    if(isE) printf("%d\n",(x+y)/2);
    else printf("IMPOSSIBLE\n");
}
