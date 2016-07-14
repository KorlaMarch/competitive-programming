#include <stdio.h>

int main(){
    char c;
    printf("Enter Charactor :"); scanf("%c", &c);
    switch(c){
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("%c is vowel\n", c);
        break;
    default:
        printf("%c is alphabet\n", c);
        break;
    }
    return 0;
}
