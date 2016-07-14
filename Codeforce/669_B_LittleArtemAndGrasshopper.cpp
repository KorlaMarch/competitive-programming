#include "stdio.h"

int n,i,j;
char s[100005];
int d[100005];
bool isV[100005];
int main(){
    scanf("%d %s",&n,s);
    for(i = 0; i < n; i++){
        scanf("%d",&d[i]);
    }
    i = 0;
    while(1){
        isV[i] = 1;
        if(s[i]=='>') i += d[i];
        else i -= d[i];
        if(i<0||i>=n){
            printf("FINITE\n");
            break;
        }
        if(isV[i]){
            printf("INFINITE\n");
            break;
        }
    }
}
