#include "stdio.h"

int t,k,n,i,j,c,a;
short d[100005];

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&d[i]);
        }
        for(i=a=c=0; i+1 < n; i++){
            if(a!=3&&d[i+1]-d[i]<=10&&d[i+1]>d[i]){
                a = (a+1)%4;
                continue;
            }else if(a!=3&&d[i+1]-d[i]>10){
                if(d[i+1]-d[i]<=20){
                    a = (a+2)%4;
                    c++;
                    continue;
                }else if(d[i+1]-d[i]<=30&&a==0){
                    c += 2;
                    a = 3;
                    continue;
                }
            }
            c += 3-a;
            a=0;
        }
        c += 3-a;
        printf("Case #%d: %d\n",k,c);
    }
}
