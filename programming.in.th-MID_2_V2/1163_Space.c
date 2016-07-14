#include "stdio.h"
int i,j,d,li;
char bitA[15],bitB[15];
char clock(char b[]){
    int i;
    for(i = d-1; i>=0&&b[i]=='1'; i--) b[i] = '0';
    if(i>=0) b[i] = '1';
    else return 0;
    return 1;
}

int main(){
    scanf("%d",&d);
    li = (1<<d);
    for(i = 0; i < d; i++) bitA[i] = '0';
    bitB[d] = bitA[d] = '\0';
    do{
        for(i = 0; i < d; i++) bitB[i] = bitA[i];
        for(i = d-1; i >= 0; i--){
            if(bitB[i]=='0'){
                bitB[i] = '1';
                printf("%s %s\n", bitA, bitB);
                bitB[i] = '0';
            }
        }
    }while(clock(bitA));
}
