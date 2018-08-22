#include "stdio.h"

int feq[30];
char s1[10000],s2[10000];

int main(){
    printf("Enter two words? ");
    scanf(" %s %s", s1, s2);
    for(int i = 0; s1[i]; i++){
        feq[s1[i]-'a']++;
    }
    for(int i = 0; s2[i]; i++){
        feq[s2[i]-'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(feq[i]){
            printf("false");
            return 0;
        }
    }

    printf("true");
    return 0;

}
