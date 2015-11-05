#include "stdio.h"
int n,i,j;
int w[105];
int maxD[105][105];
int max(int a, int b){
    return a>b?a:b;
}

int fmaxd2(int i, int j){
    if(i>j) return 0;
    else if(maxD[i][j]) return maxD[i][j];
    else if(i==j) return 0;
    else{
        return max(fmaxd(i+1,j),fmaxd(i,j-1));
    }
}

int fmaxd(int i, int j){
    if(i>j) return 0;
    else if(maxD[i][j]) return maxD[i][j];
    else if(i==j) return maxD[i][j]=w[i];
    else{
        maxD[i][j] = max(w[i]+fmaxd2(i+1,j),w[j]+fmaxd2(i,j-1));
        return maxD[i][j];
    }
}

int main(){
    scanf("%d",&n);
    n *= 2;
    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    fmaxd(0,n-1);
    printf("%d\n",max(maxD[0][n-1],max(maxD[1][n-1],maxD[0][n-2])));
}
