#include <stdio.h>

int main(){
    int x, y;
    int temp;
    int point;
    int max = 0;
    int maxPeople = 0;

    for(y = 0; y < 4; y++){
            scanf("%d", &temp);
            max += temp;
    }

    for(x = 1; x < 5;x++){
        point = 0;
        for(y = 0; y < 4; y++){
            scanf("%d", &temp);
            point += temp;
            if(point > max){
                max = point;
                maxPeople = x;
            }
        }
    }
    printf("%d %d", maxPeople + 1, max);
}
