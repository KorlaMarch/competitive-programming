#include "stdio.h"

int main(){
    int n,i,k,x,y,d;

    char s[3];
    scanf("%d",&n);
    for(i=x=y=0,d=1; i < n; i++){
        scanf(" %s%d", s, &k);
        switch(s[0]){
        case 'B':
            d = (d+2)%4;
            break;
        case 'R':
            d = (d+1)%4;
            break;
        case 'L':
            d = (d+3)%4;
            break;
        }
        switch(d){
        case 0:
           y += k;
           break;
        case 1:
            x += k;
            break;
        case 2:
            y -= k;
            break;
        case 3:
            x -= k;
            break;
        }

        if(x<=-50000||x>=50000||y<=-50000||y>=50000){
            printf("DEAD\n"); return 0;
        }
    }
    printf("%d %d\n%c\n", x, y, d?d==1?'E':d==2?'S':'W':'N');
}
