#include "stdio.h"

char s[1005];
void printRev(int i){
    if(!s[i]) return;
    printRev(i+1);
    putchar(s[i]);
}
int main(){
    scanf(" %s",s);
    printRev(0);
}
