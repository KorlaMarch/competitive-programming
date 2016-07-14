#include "stdio.h"
int n,i,j,c,c2,num,v,mx;
char canR[60001];
int li[1000009];
int main(){
    scanf("%d",&n);
    li[c++] = 0;
    for(i = 0; i < n; i++){
        scanf("%d",&num);
        for(j = 0,c2=c; j < c; j++){
            v = (li[j]+num+90001)%60001-30000;
            if(!canR[v+30000]){
                canR[v+30000] = 1;
                li[c2++] = v;
            }
        }
        c = c2;
    }
    for(i = 0; i < c; i++) if(li[i]>mx) mx = li[i];
    printf("%d\n",mx);
}
