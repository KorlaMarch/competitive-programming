#include "stdio.h"

int main(){
    int t,k,x,r,c,i,s;
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d %d %d", &x, &r, &c);
        for(i=1,s=0; i <= x-i+1; i++){
            if((i>r||x-i+1>c)&&(i>c||x-i+1>r)){
                s = 1;
                break;
            }
        }
        if((r*c)%x!=0||s||(x==4&&((r==2&&c==4)||(r==4&&c==2)))||x>=7){
            printf("Case #%d: RICHARD\n", k);
        }else{
            printf("Case #%d: GABRIEL\n", k);
        }
    }
}
