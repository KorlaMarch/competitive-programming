 #include "stdio.h"

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quickSort(int a[], int len){
    int pivot = a[0];
    int i = 1, j = len - 1, k;
    //printf("len = %d\n", len);
    if(len <= 1){
        return 0;
    }

    /*for(k = 0; k < len; k++){
        printf("%d ", a[k]);
    }
    printf("\n");*/
    while(i <= j){
        if(a[i] >= pivot && a[j] < pivot){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
        if(a[i] < pivot){
            i++;
        }
        if(a[j] >= pivot){
            j--;
        }


        //printf("%d %d %d %d %d\n", pivot, i, j, a[i], a[j]);
    }

    swap(&a[0], &a[j]);
    quickSort(a, j);
    quickSort(a+j+1, len-j-1);
    return j;
}

int main(){
    int a[] = {5,1,2,9,11,8,5,45,8};
    int i;
    quickSort(a, sizeof(a)/sizeof(int));
    for(i = 0; i < sizeof(a)/sizeof(int); i++){
        printf("%d ", a[i]);
    }
}
