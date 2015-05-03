#include "stdio.h"

int main(){
    FILE* f;
    int i,j;
    f = fopen("pic.txt", "w");
    if(f == NULL) printf("Cannot open file.");
    for(i = 0; i < 4; i++){
        for(j = 0; j <= i; j++){
            fputc('*',f);
        }
        fputc('\n',f);
    }
    fclose(f);
}
