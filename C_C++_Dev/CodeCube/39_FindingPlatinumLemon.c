#include "stdio.h"
int w,h,wc,hc,q,i,j,k;
char s[300];
unsigned int qs[300][301],bit[16];
int main(){
    scanf("%d %d ",&w,&h);
    for(i = 0; i < h; i++){
        scanf(" %s",s);
        for(j = 1; j <= w; j++){
            qs[i][j] = ((qs[i][j-1]<<1)|(s[j-1]-'A'));
            //printf("qs %d %d = %X\n",i,j,qs[i][j]);
        }

    }
    for(scanf("%d",&q); q; q--){
        scanf("%d %d ",&wc,&hc);
        for(i=0; i < hc; i++){
            scanf(" %s",s);
            bit[i] = 0;
            for(j = 0; j < wc; j++){
                bit[i] = ((bit[i]<<1)|(s[j]=='B'));
            }
        }
        for(i = 0; i+hc <= h; i++){
            for(j = wc; j <= w; j++){
                for(k = 0; k < hc; k++){
                    if((qs[i+k][j]&((1<<wc)-1))!=bit[k]) break;
                }
                if(k==hc){
                    printf("%d %d\n",j-(wc-1)/2,i+1+(hc-1)/2);
                    i = h+1;
                    break;
                }
            }
        }
    }
}
