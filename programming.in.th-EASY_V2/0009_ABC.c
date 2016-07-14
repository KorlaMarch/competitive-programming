#include "stdio.h"
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int i,t;
    int num[3];
    char p[3];
    scanf(" %d %d %d",num,num+1,num+2);
    scanf(" %c%c%c", p,p+1,p+2);

    if(num[1]<num[0] && num[1]<num[2]){
        swap(num+1,num);
    }else if(num[2]<num[0] && num[2]<num[1]){
        swap(num+2,num);
    }

    if(num[2]<num[1]){
        swap(num+1,num+2);
    }

    for(i = 0; i < 3; i++){
        switch(p[i]){
        case 'A':
            printf("%d ",num[0]);
            break;
        case 'B':
            printf("%d ",num[1]);
            break;
        case 'C':
            printf("%d ",num[2]);
            break;
        }
    }
}
