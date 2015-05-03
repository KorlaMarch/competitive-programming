#include <stdio.h>

int main(){
    int x,y;
    int cirx, ciry;
    int r;
    printf("Enter X"); scanf("%d", &x);
    printf("Enter Y"); scanf("%d", &y);
    printf("Enter Circle's X"); scanf("%d", &cirx);
    printf("Enter Circle's Y"); scanf("%d", &ciry);
    printf("Enter Radius"); scanf("%d", &r);

    if(sqrt((x-cirx)*(x-cirx) + (y-ciry)*(y-ciry)) > r){
        printf("This coodinate is out of circle");
    }else{
        printf("This coodinate is in circle");
    }
    return 0;
}
