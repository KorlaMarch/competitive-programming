#include "stdio.h"

int n,m,i,j,x,y;
char isOn[200];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        for(j = 0; j < x; j++){
            scanf("%d",&y);
            isOn[y] = 1;
        }
    }
    for(i = 1; i <= m; i++){
        if(!isOn[i]) break;
    }
    if(i-1==m) printf("YES\n");
    else printf("NO\n");
}
