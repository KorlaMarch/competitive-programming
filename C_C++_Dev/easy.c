#include <stdio.h>

int main(){
    int a, b, c, temp;
    char order[4];
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", &order);

    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }

    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }

    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }

    if(order[0] == 'A'){
        printf("%d ", a);
    }else if(order[0] == 'B'){
        printf("%d ", b);
    }else if(order[0] == 'C'){
        printf("%d ", c);
    }

    if(order[1] == 'A'){
        printf("%d ", a);
    }else if(order[1] == 'B'){
        printf("%d ", b);
    }else if(order[1] == 'C'){
        printf("%d ", c);
    }

    if(order[2] == 'A'){
        printf("%d", a);
    }else if(order[2] == 'B'){
        printf("%d", b);
    }else if(order[2] == 'C'){
        printf("%d", c);
    }
}
