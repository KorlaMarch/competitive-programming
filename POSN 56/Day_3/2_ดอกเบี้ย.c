#include <stdio.h>
#include <conio.h>

int main(){
    int n;
    float base = 2000.0;

    for(n = 1; n <= 10; n++){
        base = base * 1.05;
    }

    printf("Money after 10 years = %f\n", base);

    base = 2000.0;
    n = 0;
    do{
        base = base * 1.05;
        n++;
    }while(base <= 4000);

    printf("You need to deposit for %d years before you get more that 4,000\n", n);

    getch();
    return 0;
}
