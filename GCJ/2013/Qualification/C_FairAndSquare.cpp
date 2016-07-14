#include "stdio.h"
#include "string.h"
#include "vector"

void toString(char s[], long long n){
    int i;
    for(i = 0; n != 0;i++){
        s[i] = n%10+'0';
        n /= 10;
    }
    s[i] = '\0';
}

bool isPalin(char s[]){
    int i,len = strlen(s);
    for(i = 0; i < len-i-1; i++){
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}

char s[50];
int t,k,i,j,co;
long long a,b;
std::vector<long long> num;
int main(){
    for(long long n = 0; n <= 100000000; n++){
        toString(s,n);
        if(isPalin(s)){
            toString(s,n*n);
            if(isPalin(s)){
                printf("%lld %lld\n",n,n*n);
                num.push_back(n*n);
            }
        }
    }
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%lld%lld",&a,&b);
        co = 0;
        for(long long x : num){
            if(x>=a&&x<=b) co++;
        }
        printf("Case #%d: %d\n",k,co);
    }
}
