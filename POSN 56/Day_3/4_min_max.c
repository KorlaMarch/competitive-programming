#include <stdio.h>
#include <conio.h>

int main(){
    int min, max, in, i;

    printf("Enter value 1 : "); scanf("%d", &in);
    min = in;
    max = in;
    for(i = 2; i <= 10; i++){
        printf("Enter value %d : ", i); scanf("%d", &in);
        if(in > max){
            max = in;
        }
        if(in < min){
            min = in;
        }
    }

    printf("Max value = %d, min value = %d", max, min);
    getch();
}
