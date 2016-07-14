#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *n, int size){
    int x,y;
    for(x = 1; x <= size; x++){
        for(y = 0; y < size - x; y++){
            if(*(n+y) > *(n+y+1)){
                *(n+y) = *(n+y) ^ *(n+y+1);
                *(n+y+1) = *(n+y) ^ *(n+y+1);
                *(n+y) = *(n+y) ^ *(n+y+1);
            }
        }

    }
    for(x = 0; x < size; x++){
        printf("%d ", *(n+x));
    }

}

int main(){
    int x;
    int a[10000];
    srand(time(NULL));
    for(x = 0; x < 10000; x++){
        a[x] = rand() % 500 + 1;
    }
    sort(a, 10000);
    getch();
    return 0;
}
