#include "stdio.h"

int t,n,p,r,s,k,i,j,up,ur,us;
char li[10000];

bool cmp(int a, int b, int x){
    int i;
    for(i = 0; i < x; i++){
        if(li[a+i]<li[b+i]) return false;
        else if(li[a+i]>li[b+i]) return true;
    }
    return false;
}

void swapl(int a, int b, int x){
    int i;
    char t;
    for(i = 0; i < x; i++){
        t = li[a+i];
        li[a+i] = li[b+i];
        li[b+i] = t;
    }
}

void fixWin(int n, int ind, char w){
    if(n==0){
        li[ind] = w;
        if(w=='P') up++;
        else if(w=='R') ur++;
        else us++;
    }else{
        if(w=='P'){
            fixWin(n-1,ind,'P');
            fixWin(n-1,ind+(1<<n)/2,'R');
        }else if(w=='R'){
            fixWin(n-1,ind,'R');
            fixWin(n-1,ind+(1<<n)/2,'S');
        }else{
            fixWin(n-1,ind,'P');
            fixWin(n-1,ind+(1<<n)/2,'S');
        }
        if(cmp(ind,ind+(1<<n)/2,(1<<n)/2)){
            swapl(ind,ind+(1<<n)/2,(1<<n)/2);
        }
    }
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d%d%d",&n,&r,&p,&s);
        li[1<<n] = '\0';
        up = ur = us = 0;
        fixWin(n,0,'P');
        if(p==up&&r==ur&&s==us){
            printf("Case #%d: %s\n",k,li);
            continue;
        }
        up = ur = us = 0;
        fixWin(n,0,'R');
        if(p==up&&r==ur&&s==us){
            printf("Case #%d: %s\n",k,li);
            continue;
        }
        up = ur = us = 0;
        fixWin(n,0,'S');
        if(p==up&&r==ur&&s==us){
            printf("Case #%d: %s\n",k,li);
            continue;
        }else printf("Case #%d: IMPOSSIBLE\n",k);
    }
}
