#include "stdio.h"

int maxPoint[1001][1001];
int k,i,j,x,max;
char s[1001];

int main(){
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf(" %c", &s[i]);
    }
    for(i = k-2; i>=0; i--){
        for(j = i+1; j < k; j++){
            max = 0;
            for(x = i; x <= j; x++){
                if(maxPoint[i][x]+maxPoint[x+1][j]>max) max = maxPoint[i][x]+maxPoint[x+1][j];
            }
            if(s[i]==s[j]){
                if(maxPoint[i+1][j-1]+1>max) max = maxPoint[i+1][j-1]+1;
            }
            maxPoint[i][j] = max;
        }
    }
    printf("%d\n",maxPoint[0][k-1]);
}
