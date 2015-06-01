#include "stdio.h"
typedef struct{
    int d,e,f,g;
}eqV;

int q,a,b,c,n,h,i;
eqV v[32];
eqV ans;

eqV mulV(eqV a, eqV b){
    eqV nw;
    nw.d = (a.e*b.f+b.e*a.f + a.d*b.g+b.d*a.g)%h;
    nw.e = (2*a.d*b.f+2*b.d*a.f + a.e*b.g+b.e*a.g)%h;
    nw.f = (3*a.d*b.e+3*b.d*a.e + a.f*b.g+b.f*a.g)%h;
    nw.g = (6*a.d*b.d+3*a.e*b.e+2*a.f*b.f+a.g*b.g)%h;
    return nw;
}

int main(){
    for(scanf("%d",&q);q;q--){
         scanf("%d%d%d%d%d",&a,&b,&c,&n,&h);
         v[0].d = 0;
         v[0].e = a%h;
         v[0].f = b%h;
         v[0].g = c%h;
         for(i = 1; (1<<i)<=n; i++){
            v[i] = mulV(v[i-1],v[i-1]);
         }
         i--;
         ans = v[i];
         n -= (1<<i);
         i--;
         for(;n>0;i--){
            if((1<<i)<=n){
                n -= (1<<i);
                ans = mulV(ans,v[i]);
            }
         }
         printf("%d %d %d %d\n",ans.d,ans.e,ans.f,ans.g);
    }
}
