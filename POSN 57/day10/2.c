#include "stdio.h"

int main(){
    FILE* f;
    f = fopen("text.txt", "r");
    if(f == NULL) printf("Cannot open file");
    while(!feof(f)){
        putchar(fgetc(f));
    }
    fclose(f);
}
