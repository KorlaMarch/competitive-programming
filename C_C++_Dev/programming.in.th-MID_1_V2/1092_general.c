#include "stdio.h"

int n,m,i,a,b;
int p[100000],s[100000];

int findP(int n){
    if(p[n]!=-1){
        return findP(p[n]);
    }else{
        return n;
    }
}

int main(){
    scanf("%d%d", &n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&s[i]);
        p[i] = -1;
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        a = findP(a-1);
        b = findP(b-1);
        if(a == b){
            printf("-1\n");
        }else if(s[a]>s[b]||(s[a]==s[b]&&a<b)){
            printf("%d\n", a+1);
            p[b] = a;
            s[a] += s[b]/2;
        }else{
            printf("%d\n", b+1);
            p[a] = b;
            s[b] += s[a]/2;
        }
    }
}
