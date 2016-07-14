#include "stdio.h"

int main(){
    int i;
    int num[30];
    for(i = 0; i < 30; i++){
        scanf("%d",num+i);
    }
    /*if(num[3]<50){
        while(1);
    }*/
    //printf("no\n");
    //printf("yes\n");
    if(num[0]<50){
        //case 4 5 6 8 9 10
        if(num[1]<50){
            //case 4 6 9
            if(num[2]<50){
                //case 4
                printf("no\n");
            }else{
                //case 6 9
                printf("yes\n");
            }
        }else{
            //case 5 8 10
            if(num[2]<50){
                //case 5 10
                printf("no\n");
            }else{
                //case 8
                printf("yes\n");
            }
        }
    }else{
        //case 1 2 3 7
        if(num[1]<50){
            //case 3
            printf("yes\n");
        }else{
            //case 1 2 7
            if(num[2]<50){
                //case 1
                printf("yes\n");
            }else{
                //case 2 7
                if(num[3]<50){
                    //case 2
                    printf("yes\n");
                }else{
                    //case 7
                    printf("no\n");
                }
            }
        }
    }
}
