#include "stdio.h"

int isVowel(char c){
    switch(c){
        case 'a': case 'e': case 'i': case 'o': case 'u': return 1;
    }
    return 0;
}

int main(){
    int n,i,j,c;
    char s[30];
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %s",s);
        for(j=c=0; s[j]; j++){
            if(isVowel(s[j])&&(j==0||!isVowel(s[j-1]))){
                c++;
            }
        }
        printf("%d\n",c);
    }
}
