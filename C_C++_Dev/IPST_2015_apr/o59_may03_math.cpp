#include "stdio.h"
#include "vector"
#define MOD 1000000007

int n,i,j,q;
long long mm[32];
long long fx[1000005];
int l[32],r[32],x[32];

int abs(int n){
    return n<0?-n:n;
}

long long sq(long long n){
    return (n*n)%MOD;
}

long long pow(long long n, int r){
    if(r==0) return 1;
    else if(r%2) return (sq(pow(n,r/2))*n)%MOD;
    else return sq(pow(n,r/2));
}

int comp(int i){
    int j,t;
    long long s;
    for(j = 1,s=0; j <= 987; j++){
        s = (s+pow(i+j*654+321,abs(i-j)))%MOD;
    }
    fx[i] = (i*s+fx[i-1])%MOD;
}

int main(){
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        scanf("%d%d",&l[i],&r[i]);
        if(r[i]>n) n = r[i];
    }
    for(i = 1; i <= n; i++){
        comp(i);
        for(j = 0; j < q; j++){
            if(i>=l[j]&&i<=r[j]){
                if(!x[j]||fx[i]<mm[j]){
                    mm[j] = fx[i];
                    x[j] = i;
                }
            }
        }
    }
    for(i = 0; i < q; i++){
        printf("%d\n",x[i]);
    }

}
