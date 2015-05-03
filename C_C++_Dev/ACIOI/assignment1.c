#include "stdio.h"
int n;
int w[10][10];
char used[10];
int min(int a,int b){
    return a<b?a:b;
}
int mint(int d){
    int i,m = 200000;
    if(d >= n) return 0;
    for(i = 0; i < n; i++){
        if(!used[i]){
            used[i] = 1;
            m = min(m,mint(d+1)+w[i][d]);
            used[i] = 0;
        }
    }
    return m;

}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &w[i][j]);
        }
    }
    printf("%d\n",mint(0));
}
