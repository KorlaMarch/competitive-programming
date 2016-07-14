#include <stdio.h>

int main(){
    int a, b, c, temp;
    int time = 0;
    scanf("%d%d%d", &a, &b, &c);
    while(b-a > 1 || c-b > 1){
        //first is more than second
        if(b-a > c-b){
            temp = b;
            b = a+1;
            c = temp;
        }else{
            a = b;
            b = b+1;
        }
        //printf("a = %d b = %d c = %d\n", a, b, c);
        time++;
    }
    printf("%d", time);
}
