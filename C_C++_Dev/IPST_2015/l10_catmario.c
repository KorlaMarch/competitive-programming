#include "stdio.h"
int n,m,i,sum,a,b;
int time[105];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        if(b<time[a]||time[a]==0) time[a] = b;
    }
    for(i = 1; i <= n; i++){
        sum += time[i];
    }
    printf("%d\n",sum);
    for(i = 1; i <= n; i++){
        printf("%d %d\n",i,time[i]);
    }
}
