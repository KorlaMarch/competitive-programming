#include "stdio.h"
int n,i,j,p;
int st[2000],a[2000];
int main(){
    while(1){
        scanf("%d",&n);
        if(!n) break;
        while(1){
            scanf("%d",&a[0]);
            if(!a[0]) break;
            for(i = 1; i < n; i++){
                scanf("%d",&a[i]);
            }
            for(i=1,j=p=0; i <= n; i++){
                st[p++] = i;
                for(;p>0&&st[p-1]==a[j];j++,p--);
            }
            if(p) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }
}
