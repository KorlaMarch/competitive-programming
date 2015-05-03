#include "stdio.h"

int Fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(){
    int n,f;
    FILE* file;
    scanf("%d", &n);
    f = Fibonacci(n);
    printf("%d\n", f);
    file = fopen("DATA1.dat", "w");
    fprintf(file, "%d\n", f);
    fclose(file);
}
