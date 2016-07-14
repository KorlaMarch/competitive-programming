#include "stdio.h"

int main(){
    int var[26] = {};
    char a,b,c;

    while(1){
        scanf(" %c", &c);
        switch(c){
        case '!':
            printf("!\n");
            return 0;
        case '=':
            scanf(" %c", &a);
            scanf("%d", &var[a-'A']);
            break;
        case '#':
            scanf(" %c", &a);
            printf("%d\n", var[a-'A']);
            break;
        default:
            scanf(" %c %c", &a, &b);
            switch(c){
            case '+':
                var[a-'A'] += var[b-'A'];
                break;
            case '-':
                var[a-'A'] -= var[b-'A'];
                break;
            case '*':
                var[a-'A'] *= var[b-'A'];
                break;
            case '/':
                var[a-'A'] /= var[b-'A'];
                break;
            }
        }
    }
}
