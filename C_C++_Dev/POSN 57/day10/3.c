#include "stdio.h"

int main(){
    FILE* f;
    int sum = 0,x;
    f = fopen("text.txt", "r");
    if(f == NULL) printf("Cannot open file");
    while(fscanf(f," %d",&x) == 1){
        sum += x;
    }
    fclose(f);
    printf("Sum = %d\n", sum);
}
