#include "stdio.h"
#include "algorithm"
#include "vector"
#include "math.h"

int n,sq,t,p,i,j,cl,cr;
int num[80000];
int l[60000],r[60000];
long long sol[60000];
std::vector<int> buk[300];
std::vector<int> qu;
int f[1000005];
long long sum;

long long sqr(long long n){
    return (n*n)%p;
}

long long pow(long long n, int r){
    if(r==0) return 1;
    else if(r%2) return (sqr(pow(n,r/2))*n)%p;
    else return sqr(pow(n,r/2));
}

void add(int x){
    long long pw = pow(x,f[x]);
    //printf("add %d %lld %d\n",x,pw,f[x]);
    sum = (sum-f[x]*pw+p)%p;
    f[x]++;
    sum = (sum+f[x]*x%p*pw)%p;
}

void sub(int x){
    //printf("sub %d\n",x);
    f[x]--;
    long long pw = pow(x,f[x]);
    sum = ((sum-(f[x]+1)*x%p*pw)%p+p+f[x]*pw)%p;
}

void slideR(int fr, int to){
    int i;
    if(fr<to){
        for(i = fr+1; i <= to; i++) add(num[i]);
    }else{
        for(i = fr; i > to; i--) sub(num[i]);
    }
}

void slideL(int fr, int to){
    int i;
    if(fr<to){
        for(i = fr; i < to; i++) sub(num[i]);
    }else{
        for(i = fr-1; i >= to; i--) add(num[i]);
    }
}

int main(){
    scanf("%d%d%d",&n,&t,&p);
    sq = (int)ceil(sqrt(n));
    for(i = 1; i <= n; i++){
        scanf("%d",&num[i]);
    }
    for(i = 0; i < t; i++){
        scanf("%d%d",&l[i],&r[i]);
        buk[l[i]/sq].push_back(i);
    }
    for(i = 0; i <= n/sq; i++){
        std::sort(buk[i].begin(),buk[i].end(),
            [=](int a, int b) {
                return r[a] < r[b];
            });
        for(int x : buk[i]){
            qu.push_back(x);
        }
    }
    cl = l[qu[0]];
    cr = r[qu[0]];
    for(i = cl; i <= cr; i++){
        add(num[i]);
    }
    sol[qu[0]] = sum;
    for(i = 1; i < t; i++){
        //printf("i = %d\n",i);
        if(cl<l[qu[i]]){
            slideR(cr,r[qu[i]]);
            slideL(cl,l[qu[i]]);
        }else{
            slideL(cl,l[qu[i]]);
            slideR(cr,r[qu[i]]);
        }
        sol[qu[i]] = sum;
        cl = l[qu[i]];
        cr = r[qu[i]];
    }
    for(i = 0; i < t; i++){
        printf("%lld\n",sol[i]);
    }
}
