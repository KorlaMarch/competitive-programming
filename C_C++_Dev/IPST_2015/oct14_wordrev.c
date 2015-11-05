#include "stdio.h"

char s[1005];
void printRev(int i){
    if(i<0||s[i]=='_') return;
    putchar(s[i]);
    printRev(i-1);
}

void wordrev(int i){
    if(s[i]=='\0'){
        printRev(i-1);
    }else if(s[i]=='_'){
        printRev(i-1);
        putchar('_');
        wordrev(i+1);
    }else wordrev(i+1);

}
int main(){
    scanf(" %s",s);
    wordrev(0);
}
