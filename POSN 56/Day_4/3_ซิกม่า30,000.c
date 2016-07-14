#include <stdio.h>
#include <conio.h>


int f(int x){
    return x*x + 3*x + 1;
}

int sigma_f(int m){
    int sum = 0, n;
    for(n = 1; n <= m; n++){
        sum += f(n);
    }

    return sum;
}

int main(){
    int n = 1;
    while(sigma_f(n) <= 30000){
        n++;
    }

    printf("Sigma of f(%d) is more than 30,000", n);
    getch();
}
