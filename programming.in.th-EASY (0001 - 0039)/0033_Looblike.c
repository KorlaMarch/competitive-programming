#include <stdio.h>

int main(){
    int n, x, temp, maxCom = 1, maxV = 0;
    int a[10005];
    scanf("%d", &n);
    for(x = 0; x <= 10000; x++){
            a[x] = 0;
    }
    for(x = 0; x < n; x++){
        scanf("%d", &temp);
        a[temp]++;
        if(a[temp] > maxV){
            maxV = a[temp];
        }
        if(temp > maxCom){
            maxCom = temp;
        }

    }

    for(x = 0; x <= maxCom; x++){
        if(a[x] == maxV){
            printf("%d ", x);
        }
    }

}
