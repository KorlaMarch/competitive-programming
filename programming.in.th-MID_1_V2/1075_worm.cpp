#include "stdio.h"
#include "algorithm"
typedef struct{
    int d,c;
}worm;
bool cmp(worm a, worm b){
    return a.c<b.c?true:false;
}
int main(){
    int n,i,mc;
    unsigned long long int sumD,mx;
    double mf,t;
    worm w[100000];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&w[i].d,&w[i].c);
    }
    std::sort(w,w+n,cmp);
    for(i = sumD = 0,mf=0.0; i < n; i++){
        sumD += w[i].d;
        t = sumD/(double)w[i].c;
        if(t>mf){
            mf = t;
            mx = sumD;
            mc = w[i].c;
        }
    }
    printf("%llu %d\n", mx,mc);
}
