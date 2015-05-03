#include <stdio.h>
#include <string.h>

int main(){
    int x,y,z;
    char text[16];
    scanf("%s", &text);
    for(x = 0; x < 5;x++){
        for(y = 0; y < strlen(text);y++){
            for(z = 0; z < 4;z++){
                if((y+1)%3 == 0){
                    if(z == 2 - x || z == 2 + x || z == x - 2 || (z == 3 && x == 3)){
                        printf("*");
                    }else if(z == 2 && x == 2){
                        printf("%c", text[y]);
                    }else{
                        printf(".");
                    }
                }else if(y%3 == 0 && y != 0){
                    if(z == 2 - x || z == 2 + x || z == x - 2 || (z == 3 && x == 3)){
                        if(x != 2){
                            printf("#");
                        }else{
                            printf("*");
                        }
                    }else if(z == 2 && x == 2){
                        printf("%c", text[y]);
                    }else{
                        printf(".");
                    }
                }else{
                    if(z == 2 - x || z == 2 + x || z == x - 2 || (z == 3 && x == 3)){
                        printf("#");
                    }else if(z == 2 && x == 2){
                        printf("%c", text[y]);
                    }else{
                        printf(".");
                    }
                }
            }
        }
        if(x == 2){
            if(strlen(text)%3 == 0){
                printf("*");
            }else{
                printf("#");
            }
        }else{
            printf(".");
        }
        printf("\n");
    }

}
