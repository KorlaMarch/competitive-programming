#include "stdio.h"
int a,b,c,x,y,z,l,g;
int absZ(int n){
    return n<0?0:n;
}
int main(){
    scanf("%d%d%d %d%d%d",&a,&b,&c,&x,&y,&z);
    if(absZ(a-x)/2+absZ(b-y)/2+absZ(c-z)/2>=absZ(x-a)+absZ(y-b)+absZ(z-c)) printf("Yes\n");
    else printf("No\n");
}
