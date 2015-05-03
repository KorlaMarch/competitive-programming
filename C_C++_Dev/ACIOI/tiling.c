#include "stdio.h"

void tilling(int l,int x,int y, int x2, int y2){
    int t;
    char s[4] = {};
    if(l==2){
        if(x){
            if(y) t=3;
            else t=1;
        }else{
            if(y) t=2;
            else t=0;
        }
        printf("%d %d %d\n",t,x2,y2);
    }else{
        if(x<l/2){
            if(y<l/2){
                s[1] = s[2] = s[3] = 1;
                tilling(l/2,x,y,x2,y2);
                t = 0;
            }else{
                s[0] = s[1] = s[3] = 1;
                tilling(l/2,x,y-l/2,x2,y2+l/2);
                t = 2;
            }
        }else{
            if(y<l/2){
                s[0] = s[2] = s[3] = 1;
                tilling(l/2,x-l/2,y,x2+l/2,y2);
                t = 1;
            }else{
                s[0] = s[1] = s[2] = 1;
                tilling(l/2,x-l/2,y-l/2,x2+l/2,y2+l/2);
                t = 3;
            }
        }
        printf("%d %d %d\n",t,x2+l/2-1,y2+l/2-1);
        if(s[0]) tilling(l/2,l-1,l-1,x2,y2);
        if(s[1]) tilling(l/2,0,l-1,x2+l/2,y2);
        if(s[2]) tilling(l/2,l-1,0,x2,y2+l/2);
        if(s[3]) tilling(l/2,0,0,x2+l/2,y2+l/2);
    }
}

int main(){
    int l,x,y;
    scanf("%d%d%d", &l, &x, &y);
    printf("%d\n",l*l/3);
    tilling(l,x,y,0,0);
}
