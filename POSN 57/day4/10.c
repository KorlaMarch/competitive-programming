#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "stdlib.h"

#define SIZE 50

int main(){
    int a[50];
    int i,j,n,sum,min,minPos;
    //rand
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        a[i] = rand()%50;
    }
    scanf("%d", &n);
    for(i = 0,sum=0; i < n; i++){
        sum += a[i];
    }
    min = sum;
    minPos = 0;
    for(i = 1; i+n <= SIZE; i++){
        sum -= a[i-1];
        sum += a[i+n-1];
        if(sum < min){
            min = sum;
            minPos = i;
        }
    }
    printf("rand A is :");
    for(i = 0; i < SIZE; i++){
        printf("%d ", a[i]);
    }
    printf("\nMin pos is :");
    for(i = 0; i < n; i++){
        printf("a[%d] ", i+minPos);
    }
    getch();
}
