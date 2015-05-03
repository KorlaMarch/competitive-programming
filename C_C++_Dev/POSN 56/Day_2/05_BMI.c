#include <stdio.h>
#include <conio.h>

int main(){
    int h, w, bmi;
    printf("Enter hight : "); scanf("%d", &h);
    printf("Enter wight : "); scanf("%d", &w);
    bmi = (float)w/(h*h);

    if(bmi >= 40){
        printf("Too Fat 3");
    }else if(bmi >= 35){
        printf("Fat 2");
    }else if(bmi >= 28.5){
        printf("Fat 1");
    }else if(bmi >= 23.5){
        printf("Overwight");
    }else if(bmi >= 18.5){
        printf("Nomal");
    }else{
        printf("Thin");
    }
    getch();
    return 0;
}
