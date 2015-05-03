#include "stdio.h"
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    char s1[201],s2[201];
    int i,j,m,k;
    int lcs[201][201];
    scanf(" %s %s", s1, s2);
    for(i = m = 0; s1[i]; i++){
        for(j = 0; s2[j]; j++){
            if(s1[i]==s2[j]){
                lcs[i+1][j+1] = lcs[i][j]+1;
            }else{
                lcs[i+1][j+1] = 0;
            }
            if(lcs[i+1][j+1] > m) m = lcs[i+1][j+1];
        }
    }
    for(i = 0; s1[i]; i++){
        for(j = 0; s2[j]; j++){
            if(lcs[i+1][j+1]==m){
                for(m--;m>=0;m--){
                    putchar(s1[i-m]);
                }
                putchar('\n');
                return 0;
            }
        }
    }
}
