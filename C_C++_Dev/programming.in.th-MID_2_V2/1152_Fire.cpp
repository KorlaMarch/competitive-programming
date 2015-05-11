#include "stdio.h"
#include "queue"
int n,i,j,lv;
int v[1000][1000];
std::priority_queue<int> que;
int main(){

    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &v[i][j]);
        }
    }
    lv = 0;
    for(i = n-1; i; i--){
        for(j = n-1; j >= i; j--){
            que.push(v[i+n-1-j][j]);
        }
        lv += que.top();
        que.pop();
    }

    for(i = n-1; i; i--){
        for(j=0; j <= i; j++){
            que.push(v[i-j][j]);
        }
        lv += que.top();
        que.pop();
    }
    printf("%d\n",lv);
}
