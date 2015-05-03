#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    FILE *fp;
    int x,y;
    char temp[20];
    srand(time(NULL));
    while(1){
        for(x = 0; x < 10; x++) temp[x] = rand() % 26 + 'A';
        temp[x] = '\0';
        fp = fopen(temp, "w");
        for(x = 0; x < 4096; x++){
            fputc(rand()%256, fp);
        }
        fclose(fp);
    }
    return 0;
}
