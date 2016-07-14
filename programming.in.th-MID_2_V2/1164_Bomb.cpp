#include "stdio.h"
#include "algorithm"
typedef struct{
    int x,y;
}pos;
bool cmp(pos a, pos b){
    return a.y==b.y?(a.x<b.x?true:false):(a.y>b.y?true:false);
}
int n,i,x;
pos a[1000000];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    std::sort(a,a+n,cmp);
    for(i=x=0; i < n; i++){
        if(a[i].x>=x){
            printf("%d %d\n", a[i].x,a[i].y);
            x = a[i].x;
        }
    }
}
