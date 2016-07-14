#include "stdio.h"

int compareTime;
int swapTime;

void swap(int *a, int *b){
    /**a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;*/
    int t = *a;
    *a = *b;
    *b = t;
    swapTime++;
}

void copyArray(int so[], int dis[], int len){
    int n;
    for(n = 0; n < len; n++){
        dis[n] = so[n];
    }
}

void printArray(int a[], int len){
    int n;
    for(n = 0; n < len; n++){
        printf("%d ", a[n]);
    }
    printf("\n");
}

void bubbleSort(int a[], int len){
    int i, j;
    int isSwap;
    compareTime = 0;
    swapTime = 0;
    for(i = 0; i < len; i++){
        isSwap = 0;
        for(j = 0; j < len-i-1; j++){
            compareTime++;
            if(a[j] > a[j+1]){
                isSwap = 1;
                swap(&a[j], &a[j+1]);
            }
        }
        if(isSwap == 0){
            break;
        }
    }
    printf("End of bubble sort\n");
    printf("\tTotal Compare : %d\n", compareTime);
    printf("\tTotal Swap : %d\n", swapTime);
}

void selectionSort(int a[], int len){
    int i, j, min;
    compareTime = 0;
    swapTime = 0;
    for(i = 0; i < len - 1; i++){
        min = i;
        for(j = i + 1; j < len; j++){
            compareTime++;
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(&a[min], &a[i]);
        //printArray(a, len);
    }
    printf("End of selection sort\n");
    printf("\tTotal Compare : %d\n", compareTime);
    printf("\tTotal Swap : %d\n", swapTime);
}

void insertionSort(int a[], int len){
    int i, j;
    compareTime = 0;
    swapTime = 0;
    for(i = 1; i < len; i++){
        compareTime++;
        for(j = i; j > 0 && a[j] < a[j - 1]; j--, compareTime++){
            swap(&a[j], &a[j-1]);
        }
    }
    printf("End of insertion sort\n");
    printf("\tTotal Compare : %d\n", compareTime);
    printf("\tTotal Swap : %d\n", swapTime);
}

int main(){
    int array[] = {4,5,3,1,25,9,12,7,6,1};
    int a[10];

    copyArray(array, a, 10);
    bubbleSort(a, 10);
    printArray(a, 10);

    copyArray(array, a, 10);
    selectionSort(a, 10);
    printArray(a, 10);

    copyArray(array, a, 10);
    insertionSort(a, 10);
    printArray(a, 10);
}
