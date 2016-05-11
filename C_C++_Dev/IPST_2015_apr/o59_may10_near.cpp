#include "stdio.h"
#include "algorithm"

struct pos{
    int x,y,z;
    pos(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
};

long long sq(long long n){
    return n*n;
}

int n,i,j,c;
pos p[500005];
long long d,k;
int main(){
    scanf("%d%lld",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        for(j = 0; j < i; j++){
            d = sq(p[i].x-p[j].x)+sq(p[i].y-p[j].y)+sq(p[i].z-p[j].z);
            if(d<=k*k) c++;
        }
    }
    printf("%d\n",c);
    /*std::sort(p,p+n,[=](pos a, pos b){
        return a.x<b.x;
    });*/
}
