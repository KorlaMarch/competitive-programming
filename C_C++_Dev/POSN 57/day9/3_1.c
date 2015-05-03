#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
    char s[21];
    int i;
    srand(time(NULL));
    for(i = 0; i < 20; i++){
        s[i] = rand()%26+'A';
    }
    s[20] = '\0';
    printf("After rand : %s\n", s);
}
