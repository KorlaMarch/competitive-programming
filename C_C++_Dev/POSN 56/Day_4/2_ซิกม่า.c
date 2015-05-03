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
    int n;
    printf("Enter n : "); scanf("%d", &n);
    printf("Sigma of f(1) to f(%d) = %d", n, sigma_f(n));
    getch();
}
