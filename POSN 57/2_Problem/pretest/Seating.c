/*
LANG: C
COMPILER: WCB
*/
#include "stdio.h"
int n,x,y,z,i,m;
char canSit[10001] = {};
int sitNum[10001] = {};
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &x,&y,&z);
        if(!canSit[y-z]||x<sitNum[y-z]){
            canSit[y-z] = 1;
            sitNum[y-z] = x;
        }
    }
    scanf("%d", &m);
    for(i = m; !canSit[m]&&i<n; i++);
    if(i<n){
        printf("%d\n", sitNum[i]);
    }else{
        printf("0\n");
    }
}
