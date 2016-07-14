#include "stdio.h"

int n,k,i,j,x;
char s[1000005];
int p[1000005];
bool isDe[1000005];
int main(){
    scanf("%d%d %s",&n,&k,s);
    for(i = 1; i < n; i++){
        while(j>0&&s[i]!=s[j]){
            j = p[j-1];
        }
        if(s[i]==s[j]) j++;
        p[i] = j;
        if((i-j==j-p[j]||p[i])&&isDe[j]){
            isDe[j] = true;
        }
        //for(x = j; x>0&&x*(k+1)>n; x=p[x]);
        printf("%d:%d\n",i,j);
    }
}
