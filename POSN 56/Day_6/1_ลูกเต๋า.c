#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(){
    int tam, in;
    //scanf("%d", &in);
    srand(time(NULL));
    tam = rand() % 22 + 3;
    if(tam < 11){
        printf("Low\n");
    }else if(tam > 11){
        printf("High\n");
    }else{
        printf("High-Low\n");
    }
    getch();
    return 0;
}
