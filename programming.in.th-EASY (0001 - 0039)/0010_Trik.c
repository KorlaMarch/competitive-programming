#include <stdio.h>
#include <string.h>

int main(){
    char code[51], ball = 1;
    scanf("%s", &code);
    int x;
    for(x = 0; strlen(code) > x; x++){
        if(code[x] == 'A'){
            if(ball == 1){
                ball = 2;
            }else if(ball == 2){
                ball = 1;
            }
        }else if(code[x] == 'B'){
            if(ball == 2){
                ball = 3;
            }else if(ball == 3){
                ball = 2;
            }
        }else{
            if(ball == 1){
                ball = 3;
            }else if(ball == 3){
                ball = 1;
            }
        }
    }

    printf("%d", ball);
}
