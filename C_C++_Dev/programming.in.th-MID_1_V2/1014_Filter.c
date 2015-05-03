#include "stdio.h"

char fill[3000];
int w,h,n,i,j,x,a,c0,c1;

int main(){
    scanf("%d%d%d", &w, &h, &n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &x,&a);
        for(j = x; j-x<a&&j<w; j++) fill[j]++;
    }
    for(i = 0; i < w; i++){
        if(fill[i]==1) c1++;
        else if(fill[i]==0) c0++;
    }
    printf("%d %d\n", c0*h, c1*h);
}
