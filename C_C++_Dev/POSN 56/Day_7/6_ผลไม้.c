#include <stdio.h>
#include <conio.h>

int checkDelicious(int n){
    if(n == 0){
        return 1;
    }else if(n < 0){
        return 0;
    }
    return checkDelicious(n - 4) || checkDelicious(n - 6) || checkDelicious(n - 9) || checkDelicious(n - 20);
}

int main(){
    int n;
    int x;
    int isPrint = 0;
    scanf("%d", &n);
    for(x = 1; x <= n; x++){
        if(checkDelicious(x)){
            isPrint = 1;
            printf("%d\n", x);
        }
    }
    if(isPrint == 0){
        printf("No\n");
    }
    getch();
    return 0;
}
