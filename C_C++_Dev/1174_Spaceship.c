#include "stdio.h"

typedef struct{
    int x,y,z;
}pos;

typedef struct{
    int m,k,c;
}compu;

int dis(pos a, pos b){
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)+(b.z-a.z)*(b.z-a.z);
}

pos loc[20];
compu stock[20];
char isHave[20] = {};
int n,m;
int minPart;

void FindShortestPart(int d,int lm, int lk, int lc, pos lo){
    int i;
    pos k;
    //printf("d = %d\n", d);
    if(d > minPart){
        return;
    }
    if(lm >= n && lk >= n && lc >= n){
        if(d < minPart){
            minPart = d;
        }
        return;
    }
    for(i = 1; i <= m; i++){
        if(!isHave[i]){
            isHave[i] = 1;
            FindShortestPart(d+dis(lo,loc[i]),lm+stock[i].m,lk+stock[i].k,lc+stock[i].c,loc[i]);
            isHave[i] = 0;
        }
    }
}

int main(){
    int i;

    stock[0].m = 0;
    stock[0].k = 0;
    stock[0].c = 0;

    scanf("%d", &n);
    scanf("%d %d %d", &loc[0].x, &loc[0].y, &loc[0].z);
    scanf("%d", &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &loc[i].x, &loc[i].y, &loc[i].z);
        scanf("%d %d %d", &stock[i].m, &stock[i].k, &stock[i].c);
    }
    minPart = 9999999;
    FindShortestPart(0,0,0,0,loc[0]);
    printf("%d\n",minPart);
}
