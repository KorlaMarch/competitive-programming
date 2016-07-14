#include "stdio.h"

int main(){
    FILE* f;
    int i = 0;
    f = fopen("text.txt", "w");
    if(f == NULL) printf("Cannot open file");
    for(i = 'A'; i <= 'Z'; i++) fputc(i,f);
    fclose(f);
}
