#include "stdio.h"
#include "string.h"

int main(){
    char s[1005];
    char isPalin[1005][1005];
    int i,j,maxL=0,maxC=0,len;
    scanf(" %s",s);
    len = strlen(s);
    for(i = len-1; i >= 0; i--){
        for(j = i; s[j]; j++){
            if(s[i]==s[j]&&(i+1>j-1||isPalin[i+1][j-1])){
                isPalin[i][j] = 1;
                if(j-i+1>maxL){
                    maxL = j-i+1;
                    maxC = 1;
                }else if(j-i+1==maxL){
                    maxC++;
                }
            }
        }
    }
    printf("%d\n%d\n",maxL,maxC);
    return 0;
}
