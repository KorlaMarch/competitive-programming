#include "stdio.h"

int main(){
    int i,j,sum=0;
    char s[17];
    gets(s);
    for(i = 0; i < 16; i++){
        j = s[i]-'0';
        if(i%2 == 0){
            j *= 2;
            if(j > 9){
                j = j%10 + j/10;
            }
        }
        sum += j;
    }
    if(sum%10 == 0){
        printf("vaild\n");
    }else{
        printf("not vaild (remainder = %d)\n", sum%10);
    }

}
