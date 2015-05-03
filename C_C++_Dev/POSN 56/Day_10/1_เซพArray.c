#include <stdio.h>
#include <conio.h>

int main(){
    FILE *fp;
    char s[100];
    if((fp = fopen("output.txt", "w+")) == NULL){
        printf("Error in open file");
        return -1;
    }
    gets(s);
    fputs(s,fp);
    fclose(fp);
    getch();
    return 0;
}
