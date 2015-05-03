#include "stdio.h"

#define SIZE 1048575

int tree[SIZE] = {};

void add(int a[],int n,int i){
    int j;
    if(a[i] == 0) a[i] = n;
    if(n < a[i]){
        j = i*2+1;
    }else{
        j = i*2+2;
    }

    if(a[j]){
        add(a,n,j);
    }else{
        a[j] = n;
    }
}

int findMin(int a[]){
    int i;
    for(i = 0; a[i*2+1] != 0; i = i*2+1);
    return a[i];
}

int findMax(int a[]){
    int i;
    for(i = 0; a[i*2+2] != 0; i = i*2+2);
    return a[i];
}

int main(){
    int i,j,n;
    for(i = 0; i < 20; i++){
        scanf("%d", &n);
        add(tree,n,0);
    }

    printf("min = %d\n", findMin(tree));
    printf("max = %d\n", findMax(tree));
}
