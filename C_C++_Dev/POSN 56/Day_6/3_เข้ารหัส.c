#include <stdio.h>
#include <conio.h>

int main(){
    char plainText[100][5];
    char chiperText[500];
    char key[6];
    char c;
    int n = 0, x, y;
    printf("Input plantext : ");
    do{
        c = getchar();
        if(c != ' ' && c != '\n'){
            plainText[n / 5][n % 5] = c;
            n++;
        }
    }while(c != '\n');

     printf("Input key : ");
     gets(key);
    //fill with Z
    if(n % 5 != 1){
        while(n % 5 != 1){
            plainText[n/5][n%5] = 'z';
            n++;
        }
    }


    for(x = 0; x < n / 5; x++){
        for(y = 0; y < 5; y++){
            chiperText[x*5 + y] = plainText[x][key[y] - '0'];
            //printf("%c", plainText[x][key[y] - '0' - 1]);
        }
        //printf("\n");
    }
    chiperText[x*5] = '\0';
    printf("ChiperText : %s", chiperText);
    getch();
    return 0;
}
