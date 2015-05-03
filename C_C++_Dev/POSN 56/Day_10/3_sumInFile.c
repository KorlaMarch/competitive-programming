#include <stdio.h>
#include <conio.h>

int main(){
    FILE *fp;
    int number;
    int sum = 0;
    int x = 0;
    char c;
    if((fp = fopen("number.txt", "r")) == NULL){
        printf("Error in open file");
        return 0;
    }

    while(!feof(fp)){
        number = 0;
        while((c = fgetc(fp)) != '\n' && c != EOF){
            //printf("c = %c\n", c);
            number *= 10;
            number += c & 0x0F;
        }
        //printf("number = %d\n", number);
        sum += number;
        x++;
    }
    printf("sum = %d\n", sum);
    fclose(fp);
    getch();
    return 0;
}
