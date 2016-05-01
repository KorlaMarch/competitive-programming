#include "stdio.h"

int a,b,ta,tb,h,m,s,e,st,et,c,i;

int main(){
    scanf("%d%d%d%d",&a,&ta,&b,&tb);
    scanf("%d:%d",&h,&m);
    s = 60*h+m;
    e = s+ta;
    for(i = 0; 60*5+i*b < 24*60; i++){
        st = 60*5+i*b;
        et = st+tb;
        //printf("%02d:%02d %02d:%02d\n",st/60,st%60,et/60,et%60);
        if(st<e&&et>s) c++;
    }
    printf("%d\n",c);
}
