#include "stdio.h"

char s[1005];
void printRev(int i){
    if(s[i]=='\0'||s[i]=='_') return;
    putchar(s[i]);
    printRev(i+1);
}

void strrev(int i){
    if(s[i]=='\0'){
        return;
    }else if(i==0){
        strrev(i+1);
        printRev(i);
    }else if(s[i]=='_'){
        strrev(i+1);
        printRev(i+1);
        putchar('_');
    }else strrev(i+1);

}
int main(){
    scanf(" %s",s);
    strrev(0);
}

