#include "stdio.h"


int k,a,b,i;
char res[20000];
void listP(int d, int a, int b){
    if(a==k||b==k){
        for(i = 0; i < d; i++){
            putchar(res[i]);
            putchar(' ');
        }
        putchar('\n');
    }else{
        res[d] = 'W';
        listP(d+1,a+1,b);
        res[d] = 'L';
        listP(d+1,a,b+1);
    }
}
int main(){
    scanf("%d%d%d",&k,&a,&b);
    listP(0,a,b);
}
