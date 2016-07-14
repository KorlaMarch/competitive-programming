#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
    char his[26] = {};
    char s[21];
    int i,j;
    srand(time(NULL));
    for(i = 0; i < 20; i++){
        do{
            j = rand()%26;
        }while(his[j]);
        s[i] = j+'A';
        his[j] = 1;
    }
    s[20] = '\0';
    printf("After rand : %s\n", s);
}
