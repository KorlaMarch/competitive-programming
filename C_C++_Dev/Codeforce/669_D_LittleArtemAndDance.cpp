#include "stdio.h"

int n,q,c,x,i,j,off;
int co;
char b,lc;
int v[1000005];
int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < q; i++){
        scanf("%d",&c);
        if(c==1){
            scanf("%d",&x);
            off = (off+x+n)%n;
        }else{
            if(off%2){
                // Odd
                if(lc=='o'){
                    co--;
                    if(co) lc = 'e';
                    else lc = 0;
                }else{
                    if(co==0) b = 'o';
                    co++;
                    lc = 'o';
                }
            }else{
                // Even
                if(lc=='e'){
                    co--;
                    if(co) lc = 'o';
                    else lc = 0;
                }else{
                    if(co==0) b = 'e';
                    co++;
                    lc = 'e';
                }
            }
        }
    }
    co = co%n;
    if(b=='e'){
        for(i = 0; i < n; i++){
            if(i%2) v[(i-co+n)%n] = i+1;
            else v[(i+co)%n] = i+1;
        }
    }else{
        for(i = 0; i < n; i++){
            if(i%2) v[(i+co)%n] = i+1;
            else v[(i-co+n)%n] = i+1;
        }
    }
    off = (n-off)%n;
    /*for(i = 0; i < n; i++){
        printf("%d ",v[i]);
    }*/
    //printf("\nOFF = %d %d %d\n",off,co,b);
    printf("%d ",v[off]);
    for(i = (off+1)%n; i != off; i = (i+1)%n){
        printf("%d ",v[i]);
        //printf(" i = %d\n",i);
    }
}
