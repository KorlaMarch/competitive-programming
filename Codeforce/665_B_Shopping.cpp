#include "stdio.h"

int n,k,m,i,j,x,t,a;
int pos[105];
int ip[105];

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 1; i <= k; i++){
        scanf("%d",&pos[i]);
        ip[pos[i]] = i;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&a);
            t += ip[a];
            for(x = ip[a]; x > 1; x--){
                swap(pos[x-1],pos[x]);
                ip[pos[x]] = x;
                ip[pos[x-1]] = x-1;
            }
        }
    }
    printf("%d\n",t);
}
