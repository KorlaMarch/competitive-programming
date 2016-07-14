#include "stdio.h"
typedef struct{
    int x,y,z;
}pos;
int n,m,i,j;
pos shop[10],stock[10];
pos s;
char isV[10];
int calCost(pos a, pos b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int minCost(int mi, int ki, int ci, pos cp){
    int min = 1000000,i,j;
    if(mi<=0&&ki<=0&&ci<=0) return 0;
    for(i = 0; i < m; i++){
        if(!isV[i]){
            isV[i] = 1;
            j = calCost(cp,shop[i])+minCost(mi-stock[i].x,ki-stock[i].y,ci-stock[i].z,shop[i]);
            isV[i] = 0;
            if(j < min) min = j;
        }
    }
    return min;
}
int main(){
    scanf("%d %d %d %d %d",&n,&s.x, &s.y, &s.z, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d %d %d %d", &shop[i].x,&shop[i].y,&shop[i].z,&stock[i].x,&stock[i].y,&stock[i].z);
    }
    printf("%d\n", minCost(n,n,n,s));
}
