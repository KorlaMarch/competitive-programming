#include "stdio.h"
#include "stack"
#include "algorithm"

typedef struct{
    int x,y;
}pos;

pos p[1000001];
bool isN[1000001] = {};

bool cmp(pos a, pos b){
    if(a.x == b.x){
        return a.y >= b.y ? true : false;
    }else{
        return a.x < b.x ? true : false;
    }
}

int main(){
    int n,i,j,maxY = 0;
    std::stack<int> out;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    std::sort(p,p+n,cmp);
    for(i = n-1; i >= 0; i--){
        //printf("i = %d : %d\n", i, isN[i]);
        if(p[i].y >= maxY){
            out.push(i);
            maxY = p[i].y;
        }
    }
    while(!out.empty()){
        printf("%d %d\n", p[out.top()].x, p[out.top()].y);
        out.pop();
    }
}
