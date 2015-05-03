#include <stdio.h>
#include <conio.h>

int main(){
    int number[10] = {0};
    char s[21];
    int x;
    int max = 0;
    printf("Enter Number :"); gets(s);
    for(x = 0; s[x] != '\0'; x++){
        if(s[x] >= '0' && s[x] <= '9'){
            number[s[x] - '0']++;
        }else{
            printf("Error! not a number.");
            getch();
            return;
        }
    }

    for(x = 0; x < 10; x++){
       if(number[x] > max) max = number[x];
    }

    for(x = 0; x < 10; x++){
        if(number[x] == max){
            printf("%d |> %d\n", x, max);
        }
    }
    getch();
    return 0;
}
