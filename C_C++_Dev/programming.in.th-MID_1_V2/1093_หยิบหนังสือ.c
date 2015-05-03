#include "stdio.h"
int n,i,j,k;
int book[2000];
int t[2000][2000];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&book[i]);
    }

    for(i = n-1; i>=0; i--){
        for(j = i; j < n; j++){
            if(i+1<=j) t[i][j] = max(t[i][j], t[i+1][j]);
            if(j>i) t[i][j] = max(t[i][j], t[i][j-1]);
            if(i+3<=j) t[i][j] = max(t[i][j], t[i+3][j]+book[i]+book[i+1]-book[i+2]);
            if(j-2>=i) t[i][j] = max(t[i][j], t[i][j-3]+book[j-2]+book[j-1]-book[j]);
        }
    }
    printf("%d\n       ",t[0][n-1]);
    /*for(i = 0; i < n; i++) printf("%3d ", i);
    printf("\n\n");
    for(i = 0; i < n; i++){
        printf("I:%3d  ", i);
        for(j = 0; j < n; j++){
            printf("%3d ", t[i][j]);
        }
        printf("\n");
    }*/
}
