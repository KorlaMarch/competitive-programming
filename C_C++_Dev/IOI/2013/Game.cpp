#include "stdio.h"
#include "vector"

struct num{
    int p,q;
    long long k;
    num(int _p = 0, int _q = 0, long long _k = 0) : p(_p),q(_q),k(_k) {}
};

long long gcd2(long long X, long long Y) {
    long long tmp;
    if(Y>X){
        tmp = Y;
        Y = X;
        X = tmp;
    }
    while (X != Y && Y != 0) {
        tmp = X;
        X = Y;
        Y = tmp % Y;
    }
    return X;
}

int r,c,n,i,j,p,q,u,v,o;
long long gcd,k;
std::vector<num> vec;
int main(){
    scanf("%d%d%d",&r,&c,&n);
    for(i = 0; i < n; i++){
        scanf("%d",&o);
        if(o==1){
            scanf("%d%d%lld",&p,&q,&k);
            for(j = 0; j < vec.size(); j++){
                if(vec[j].p==p&&vec[j].q==q){
                    vec[j].k = k;
                    break;
                }
            }
            if(j==vec.size()){
                vec.push_back(num(p,q,k));
            }
        }else{
            scanf("%d%d%d%d",&p,&q,&u,&v);
            gcd = 0;
            for(j = 0; j < vec.size(); j++){
                if(vec[j].p>=p&&vec[j].q>=q&&vec[j].p<=u&&vec[j].q<=v){
                    gcd = gcd2(vec[j].k,gcd);
                }
            }
            printf("%lld\n",gcd);
        }
    }
}
