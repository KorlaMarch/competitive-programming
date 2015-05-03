#include <stdio.h>
#include <conio.h>

void sort(int *n){
    int x,y;
    for(x = 1; x <= 10; x++){
        for(y = 0; y < 10 - x; y++){
            if(*(n+y) > *(n+y+1)){
                *(n+y) = *(n+y) ^ *(n+y+1);
                *(n+y+1) = *(n+y) ^ *(n+y+1);
                *(n+y) = *(n+y) ^ *(n+y+1);
            }
        }

    }
    for(x = 0; x < 10; x++){
        printf("%d ", *(n+x));
    }

}

int main(){
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(a);
    getch();
    return 0;
}
