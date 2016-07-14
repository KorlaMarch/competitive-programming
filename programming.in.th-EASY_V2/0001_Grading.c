#include "stdio.h"

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a += b+c;
    if(a>=80){
        printf("A\n");
    }else if(a>=75){
        printf("B+\n");
    }else if(a>=70){
        printf("B\n");
    }else if(a>=65){
        printf("C+\n");
    }else if(a>=60){
        printf("C\n");
    }else if(a>=55){
        printf("D+\n");
    }else if(a>=50){
        printf("D\n");
    }else{
        printf("F\n");
    }
}
