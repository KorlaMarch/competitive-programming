#include "stdio.h"

#define MOD 1000000007

long long int power(long long int n,long long int r){
    long long int d;
    if(r==1) return n;
    else if(r==0) return 1;
    d = power(n,r/2);
    if(r%2) return (((d*d)%MOD)*n)%MOD;
    else return (d*d)%MOD;
}

int m,i,pi,n;
int p[200500];
int s[200500];
long long int fac[200500];
long long int ans,pow,j,div;

int main(){
    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf("%d",&pi);
        if(!p[pi]){
            s[n++] = pi;
        }
        p[pi]++;
    }
    ans = div = 1;
    for(i = 0; i < n; i++){
        ans = power(ans,p[s[i]]+1);
        j = (long long int)p[s[i]];
        pow = (j*(j+1))/2%(MOD-1);
        ans = (ans*power((long long int)s[i],div*pow))%MOD;
        div = div*(p[s[i]]+1)%(MOD-1);
    }
    /*for(i = 1; i < n; i++){
        ans = (ans*div)%MOD;
    }*/
    printf("%I64d\n",ans%MOD);
}
