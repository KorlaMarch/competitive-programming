#include "stdio.h"

char pos[10] = {119,36,93,109,46,107,123,37,127,111};

int isP(int n, int p){
    return pos[n] & (1 << p);
}

void printDigit(char s[]){
    int i,j,k;
    for(i = 0; i < 7; i++){
        for(j = 0; s[j] != '\0'; j++){
            printf(" ");
            for(k = 0; k < 4; k++){
                if((i == 0 && isP(s[j]-'0',0))||(k == 0 && i <= 3 && isP(s[j]-'0',1))||
                   (k == 3 && i <= 3 && isP(s[j]-'0',2))||(i == 3 && isP(s[j]-'0',3))||
                   (k == 0 && i >= 3 && isP(s[j]-'0',4))||(k == 3 && i >= 3 && isP(s[j]-'0',5))||
                   (i == 6 && isP(s[j]-'0',6))){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    char num[32];
    gets(num);
    printDigit(num);
}
