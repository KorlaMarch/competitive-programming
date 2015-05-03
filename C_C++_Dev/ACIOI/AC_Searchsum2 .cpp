#include "stdio.h"
#include "limits.h"

int main(){
    int price[1001];
    int mem_price[1001];
    int n,k,i,j,t,x,y,mid;
    scanf("%d%d", &n, &k);
    scanf("%d", &mem_price[0]);
    for(i = 1; i < n; i++){
        scanf("%d", &mem_price[i]);
        mem_price[i] += mem_price[i-1];
    }
    for(i = 0; i < n; i++){
        price[i] = INT_MAX;
    }
    for(i = 0; i < n; i++){
        for(j = 0; i+j < n; j++){
            t = mem_price[i+j];
            if(j > 0){
                t -= mem_price[j-1];
            }
            if(t < price[i]){
                price[i] = t;
            }
        }
    }
    /*for(i = 0; i < n; i++){
        printf("%d ", price[i]);
    }*/
    for(i = 0; i < k; i++){
        scanf("%d", &t);
        x = 0,y = n-1;
        while(x < y){
            mid = (x+y)/2;
            if(t == price[mid]){
                j = mid;
                break;
            }else if(t < price[mid]){
                y = mid-1;
            }else{
                x = mid+1;
            }
        }
        if(x >= y){
            if(t < price[x]){
                j = x-1;
            }else{
                j = x;
            }
        }
        printf("%d\n", j+1);
    }
}
