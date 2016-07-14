#include "stdio.h"
#include "algorithm"

int n,m,q,i,j,c,lq;
char s[1005],p[1005];
int bc[30];
int main(){
    scanf("%d%d %s",&n,&q,s);
    for(;q>0; q--){
        scanf("%d %s",&m,p);
        lq = -1;
        for(i = 0; i < 30; i++) bc[i] = 0;
        for(j = 0; j+1 < m; j++){
            if(p[j]=='?') lq = j+1;
            else bc[p[j]-'a'] = j+1;
        }
        for(i=c=0; i+m-1 < n;){
            //printf("i = %d %c\n",i,s[i]);
            for(j = m-1; j >= 0; j--){
                if(p[j]!='?'&&s[i+j]!=p[j]) break;
            }
            if(j<0) c++;
            i += m-std::max(lq,bc[s[i+m-1]-'a']);
        }
        printf("%d\n",c);
    }
}
