#include <stdio.h>
#include <conio.h>

int main(){
    FILE *fp;
    if((fp = fopen("data1.txt", "r")) == NULL){
        printf("Error in open file");
        return 0;
    }
    while(!feof(fp)){
        putchar(fgetc(fp));
    }
    fclose(fp);
    getch();
    return 0;
}
