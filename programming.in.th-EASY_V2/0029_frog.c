#include "stdio.h"
#include "math.h"

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",y>=x?(int)ceil(((float)y)/x):2);
}
