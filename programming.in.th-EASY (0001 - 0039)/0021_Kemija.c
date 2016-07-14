#include <stdio.h>

int isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char in[101];
    int x;
    gets(in);
    for(x = 0; in[x] != '\0'; x++){
        if(isVowel(in[x])){
            printf("%c", in[x]);
            x += 2;
        }else{
            printf("%c", in[x]);
        }
    }
}
