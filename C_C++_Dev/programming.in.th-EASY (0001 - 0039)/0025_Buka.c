#include <stdio.h>

int main(){
    int firstPower = 0, secondPower = 0;
    char c;
    char oper;
    int x;
    do{
        c = getc(stdin);
        if(c == '0') firstPower++;
    }while(c != '\n');

    oper = getc(stdin);
    getc(stdin);

    do{
        c = getc(stdin);
        if(c == '0') secondPower++;
    }while(c != '\n');

    if(oper == '*'){
        printf("1");
        for(x = 0; x < firstPower + secondPower; x++){
            printf("0");
        }
    }else{
        if(firstPower == secondPower){
            printf("2");
            for(x = 0; x < firstPower; x++){
                printf("0");
            }
        }else if(firstPower > secondPower){
            printf("1");
            for(x = 0; x < firstPower; x++){
                if(x == firstPower - secondPower - 1){
                    printf("1");
                }else{
                    printf("0");
                }
            }
        }else{
            printf("1");
            for(x = 0; x < secondPower; x++){
                if(x == secondPower - firstPower - 1){
                    printf("1");
                }else{
                    printf("0");
                }
            }
        }
    }
}
