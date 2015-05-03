#include "stdio.h"

char a[5][6] = {{5,6,3,1,4,7},
                {6,1,3,8,9,4},
                {5,7,1,8,4,6},
                {1,2,9,1,3,4},
                {9,8,5,2,3,1}};

void print(int x, int y){
    if(y<6){
        printf("%d ", a[x][y]);
    }else{
        printf("_ ");
    }
    //printf("x = %d y = %d\n",x,y);
}

int main(){

    int n,i,pos;
    int in[5];
    for(i = 0; i < 5; i++){
        scanf("%d", &in[i]);
    }
    //find pos
    pos = 4-in[0];
    //printf("pos = %d\n", pos);
    for(i = 0; i < 5; i++){
        if(i%2==0){
            //เลื่อนซ้าย
            print(i, pos+in[i]);
        }else{
            //เลื่อนขวา
            print(i, pos-in[i]);
        }
    }
}
