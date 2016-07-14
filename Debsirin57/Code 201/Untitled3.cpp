#include <stdio.h>

int bank[] = {1000,500,100,50,20,10,5,4,3,1,-1};

int main(){
    int n;
    int x;
    int count = 0;
    char moneyType[20];
    scanf("%d %s", &n, &moneyType);   
    
    for(x = 0; bank[x] != -1; x++){
          if(n / bank[x] != 0){
               printf("%d - %d %s\n", n / bank[x], bank[x], moneyType);
               count += n / bank[x];
               n %= bank[x];
          }     
    }
    
    printf("Min Bill/Coin Total : %d", count);
    scanf("%d", &n);
    
}
