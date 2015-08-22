#include "stdio.h"
int n,m,i,j;
int minEN[604];
int w[601][601];
int main(){
    scanf("%d",&n);
    m = n*2;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= m; j++){
            scanf("%d",&w[i][j]);
        }
    }
    for(i = m-1; i >= 2; i--){
        for(j = i+1; j <= m; j++){
            if(minEN[j]+w[j][i]<minEN[i]||!minEN[i]) minEN[i] = minEN[j]+w[j][i];
        }
    }
    printf("%d\n",minEN[2]);
}
