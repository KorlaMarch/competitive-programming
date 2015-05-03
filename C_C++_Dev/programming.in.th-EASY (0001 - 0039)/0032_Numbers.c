#include <stdio.h>

int main(){
    int digit;
    int n[1000];
    int x,y, smallestPos;
    scanf("%d", &digit);
    for(x = 0; x < digit; x++){
        scanf("%d", &n[x]);
    }
    //หลักแรก
    smallestPos = 0;
        for(y = 1; y < digit; y++){
            if((n[y] < n[smallestPos] && n[y] != 0) || n[smallestPos] == 0){
                smallestPos = y;
            }
        }
        printf("%d", n[smallestPos]);
    n[smallestPos] = 10;
    //หลังจากหลักแรก
    for(x = 1; x < digit; x++){
        smallestPos = 0;
        for(y = 1; y < digit; y++){
            if(n[y] < n[smallestPos]){
                smallestPos = y;
            }
        }
        printf("%d", n[smallestPos]);
        n[smallestPos] = 10;
    }

}
