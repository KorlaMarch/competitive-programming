#include "stdio.h"

int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if(x+y+z!=100) printf("BUG\n");
    else if(x>y&&x>z) printf("PAPER\n");
    else if(y>x&&y>z) printf("SCISSORS\n");
    else if(z>x&&z>y) printf("ROCK\n");
    else printf("I DON'T KNOW\n");
}
