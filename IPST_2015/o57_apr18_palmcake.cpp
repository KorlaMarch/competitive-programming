#include "stdio.h"
#include "algorithm"
#include "stack"

struct pos{
    int x,y;
    double m;
};

int n,i,minP;
pos a[100005];


int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    /*for(minP = 0, i = 1; i < n; i++){
        if(a[i].)
    }
    std::swap(a);*/
    std::sort(a+1,a+n, [](pos a, pos b) {
        return a.m < b.m;
    });

}
