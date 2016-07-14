#include "stdio.h"

char s[200005];
int i;
long long t,ans;
int main(){
    scanf(" %s",s);
    for(i = 0; s[i]; i++){
        t = (t*10+(i+1)*(s[i]-'0'))%1000000007;
        ans = (ans+t)%1000000007;
    }
    printf("%lld\n",ans);
}
