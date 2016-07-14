#include "stdio.h"
#include "string.h"
int t,k,i,len;
char c[30],s[30];
long long nc,ns;

long long abs(long long n){
    return n<0?-n:n;
}

void bf(int d, long long a, long long b){
    int i,j;
    //printf("%d %lld %lld\n",d,a,b);
    if(c[d]){
        if(c[d]=='?'&&s[d]=='?'){
            for(i = 0; i <= 9; i++){
                for(j = 0; j <= 9; j++){
                    bf(d+1,10*a+i,10*b+j);
                }
            }
        }else if(c[d]=='?'){
            for(i = 0; i <= 9; i++){
                bf(d+1,10*a+i,10*b+(s[d]-'0'));
            }
        }else if(s[d]=='?'){
            for(i = 0; i <= 9; i++){
                bf(d+1,10*a+(c[d]-'0'),10*b+i);
            }
        }else{
            bf(d+1,10*a+(c[d]-'0'),10*b+(s[d]-'0'));
        }
    }else{
        if(abs(a-b)<abs(nc-ns)){
            nc = a;
            ns = b;
        }else if(abs(a-b)==abs(nc-ns)){
            if(a<nc||(a==nc&&b<ns)){
                nc = a;
                ns = b;
            }
        }
    }
}
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        nc = 0,ns = 9999999;
        scanf(" %s %s",c,s);
        len = strlen(c);
        bf(0,0,0);
        printf("Case #%d: %0*lld %0*lld\n",k,len,nc,len,ns);
    }
}
