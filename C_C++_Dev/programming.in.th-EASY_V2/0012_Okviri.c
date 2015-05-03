#include "stdio.h"

char s[20];
void pd(int i){
    int j;
    for(j = 0; s[j]; j++){
        if(i){
            if(j%3==2) printf(".*.*");
            else printf(".#.#");
        }else{
            if(j%3==2) printf("..*.");
            else printf("..#.");
        }
    }
    printf(".\n");
}

int main(){
    int i;
    scanf(" %s", s);
    for(i = 0; i<2;i++) pd(i);
    for(i = 0; s[i]; i++){
        printf("%c.%c.", (i%3!=1&&i)?'*':'#', s[i]);
    }
    printf("%c\n",i%3?'#':'*');
    for(i = 1; i>=0;i--) pd(i);
}
