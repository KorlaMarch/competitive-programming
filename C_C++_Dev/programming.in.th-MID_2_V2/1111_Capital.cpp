#include "stdio.h"
#include "list"
typedef struct{
    int x,d;
}path;
path getP(int x, int d){
    path p;
    p.x = x;
    p.d = d;
    return p;
}

int n,x,y,z,i,mxD;
char isV[100002];
std::list<path> adjL[100002];
void findMxD(int p, int d){
    isV[p] = 1;
    if(d>mxD) mxD = d;
    for(std::list<path>::iterator it = adjL[p].begin(); it != adjL[p].end(); ++it){
        if(!isV[it->x]) findMxD(it->x,d+it->d);
    }
}
int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&x,&y,&z);
        adjL[x].push_back(getP(y,z));
        adjL[y].push_back(getP(x,z));
    }
    findMxD(1,0);
    printf("%d\n",mxD);
}
