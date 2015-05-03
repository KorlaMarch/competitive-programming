#include "stdio.h"

void merge(int number[],int temp1[], int temp2[], int left, int right){
    for()
}

void copyArray(int so[], int dis[], int start, int end){
    for(int i = start; i < end; i++){
        dis[i - start] = so[i];
    }
}

void m_sort(int number[], int temp[], int left, int right){
    if(left == right){
        return;
    }
    m_sort(number, temp, left, (right-left)/2 + left);
    m_sort(number, temp, (right-left)/2+left+1, right);
    merge(number, temp1, temp2, left, right);
}

int main(){
    int temp[10];
    int number[10] = {4,5,3,1,25,9,12,7,6,1};
    m_sort(number, 0, 10);
    for(int n = 0; n < 10; n++){
        printf("%d ", number[n]);
    }
    printf("\n");
}
