#include "stdio.h"
#include "algorithm"

int n,m,k,i;
int x1,y1,z1;
int x2,y2,z2;
char s[100005];
int main(){
    scanf("%d%d%d %s",&n,&m,&k,&s);
    x1=y1=z1=1;
    x2=n,y2=m,z2=k;
    for(i = 0; s[i]; i++){
        switch(s[i]){
            case 'l': x1 = std::min(x1+1,n); x2 = std::min(x2+1,n); break;
            case 'r': x1 = std::max(x1-1,1); x2 = std::max(x2-1,1); break;
            case 'u': y1 = std::min(y1+1,m); y2 = std::min(y2+1,m); break;
            case 'd': y1 = std::max(y1-1,1); y2 = std::max(y2-1,1); break;
            case 'f': z1 = std::min(z1+1,k); z2 = std::min(z2+1,k); break;
            case 'b': z1 = std::max(z1-1,1); z2 = std::max(z2-1,1); break;
        }
    }
    printf("%lld\n",(x2-x1+1)*(long long)(y2-y1+1)*(z2-z1+1));
}
