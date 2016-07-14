#include "stdio.h"
int isPalin(char s[], int n){
    int i;
    for(i = 0; i < n-i-1; i++){
        if(s[i]!=s[n-i-1]) return 0;
    }
    return 1;
}
int main(){
    char s[201];
    int i,n;
    scanf(" %s", s);
    for(i = 0; s[i]; i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i] -= 0x20;
        }
    }
    n = i;
    if(isPalin(s,n)){
        if(isPalin(s,n/2)&&isPalin(s+n-n/2,n/2)){
            printf("Double Palindrome\n");
        }else{
            printf("Palindrome\n");
        }
    }else{
        printf("No\n");
    }
}
