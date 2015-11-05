#include "stdio.h"
#include "algorithm"
typedef struct{
    int x,y;
}pos;
int abs(int n){
    return n<0?-n:n;
}
int n,m,i,j,mi,mx,c;
pos fi[1005],ti[1005];
int minT[1005];
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d%d",&fi[i].x,&fi[i].y);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&ti[i].x,&ti[i].y);
        for(j = 0,mi=100000000; j < n; j++){
            if(abs(fi[j].x-ti[i].x)+abs(fi[j].y-ti[i].y)<mi) mi = abs(fi[j].x-ti[i].x)+abs(fi[j].y-ti[i].y);
        }
        minT[i] = mi;
    }
    std::sort(minT,minT+m);
    for(i=1,mx=0,c=1; i < m; i++){
        if(minT[i-1]==minT[i]){
            c++;
        }else{
            if(c>mx) mx = c;
            c = 1;
        }
    }
    if(c>mx) mx = c;
    printf("%d\n",mx);
    return 0;
}
