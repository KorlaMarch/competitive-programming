#include "stdio.h"
int n,m,i,j,mx,t1,t2;
signed char ans[20][20];

void findMaxT(int d, int s){
    int tmp = t1,tmp2 = t2,i;
    char f,c;
    if(d>=n){
        if(s>mx) mx = s;
    }else{
        for(i=f=0;i<m;i++){
            switch(ans[d][i]){
            case 0: continue;
            case 1: c = 1; break;
            case -1: c = 0; break;
            }
            if(!(t1&(1<<i))){
                t1 = (t1|(1<<i));
                if(c) t2 = (t2|(1<<i));
            }else if(t2/(1<<i)%2!=c){
                f = 1; break;
            }
        }
        if(!f) findMaxT(d+1, s+1);
        t1 = tmp; t2 = tmp2;
        findMaxT(d+1, s);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &ans[i][j]);
        }
    }
    findMaxT(0,0);
    printf("%d\n", n-mx);
}
