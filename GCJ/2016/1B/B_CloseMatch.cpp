#include "stdio.h"
#include "string.h"

int t,k,i,len;
char c[30],s[30];
// 0 = + , 1 = -
bool cc[30][2],cs[30][2];
long long nc,ns;
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf(" %s %s",c,s);
        nc = ns = 0;
        for(i = 0; c[i]; i++){
            if(c[i]=='?'&&s[i]=='?'){
                if(nc%10!=ns%10){
                    if(nc>ns){
                        nc = 10*nc;
                        ns = 10*ns+9;
                    }else{
                        nc = 10*nc+9;
                        ns = 10*ns;
                    }
                }else{
                    ns = 10*ns;
                    nc = 10*nc;
                    cs[i][0] = cc[i][0] = true;
                    cc[i][1] = i?cc[i-1][1]:false;
                    cs[i][1] = i?cs[i-1][1]:false;
                }
            }else if(c[i]=='?'){
                ns = 10*ns+(s[i]-'0');

                cs[i][0] = cs[i][1] = false;
            }else if(s[i]=='?'){
                nc = 10*nc+(c[i]-'0');

                cc[i][0] = cc[i][1] = false;
            }else{
                nc = 10*nc+(c[i]-'0');
                ns = 10*ns+(s[i]-'0');
                cc[i][0] = cc[i][1] = cs[i][0] = cc[i][1] = false;
            }
        }
        len = strlen(c);
        printf("Case #%d: %0*lld %0*lld\n",k,len,nc,len,ns);
    }
}
