#include "stdio.h"
int main(){
    int n,i,m,d,mx,k;
    char s[200005];
    scanf("%d", &n);
    for(k=0;k<n;k++){
        scanf(" %s", s);
        for(i=d=m=mx=0; s[i]; i++){
            if(s[i] == '('){
                d++;
                if(d>mx) mx=d;
            }else{
                if(d>0) d--;
                else m++;
            }
        }
        if(m+d) printf("NO %d\n", m+d);
        else printf("YES %d\n", mx);
    }
}
