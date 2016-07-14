#include <stdio.h>

int findDwarves(int Dwarves[], int size, int sum){
    int x, y;
    int temp[size];
    int t;
    //printf("Check sum = %d\n", sum);
    if(size <= 2){
        if(sum == 100){
            return 1;
        }else{
            //printf("return 0\n");
            return 0;
        }
    }
    for(x = size - 1; x >= 0; x--){
        //copy the array
        for(y = 0; y < size; y++){
            temp[y] = Dwarves[y];
        }

        //swap
        temp[x] = temp[size - 1];

        if(findDwarves(temp, size-1, sum + Dwarves[x])){
            printf("%d\n", Dwarves[x]);
            return 1;
        }
    }
    return 0;
}

int main(){
    int x;
    int Dwarves[9];
    for(x = 0; x < 9; x++){
        scanf("%d", &Dwarves[x]);
    }

    findDwarves(Dwarves, 9, 0);
}
