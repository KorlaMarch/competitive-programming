#include "stdio.h"
#include "algorithm"

int n,i,j,maxC,isEq;
int s[10005];
int sa[10005];

bool cmp(int a, int b){
    int i;
    if(maxC == n) return false;
    for(i = 0; i <= n; i++){
        if(s[(a+i)%n]!=s[(b+i)%n]){
            if(i>maxC) maxC = i;
            return s[(a+i)%n]<s[(b+i)%n];
        }
    }
    maxC = n;
    return false;
}

int main(){
    scanf("%d",&n);
    isEq = true;
    for(i = 0; i < n; i++){
        scanf("%d",&s[i]);
        sa[i] = i;
        if(i&&s[i]!=s[i-1]) isEq = false;
    }
    if(isEq) maxC = n;
    else std::sort(sa,sa+n,cmp);
    if(maxC==n) printf("-1\n");
    else printf("%d\n",maxC);
}

