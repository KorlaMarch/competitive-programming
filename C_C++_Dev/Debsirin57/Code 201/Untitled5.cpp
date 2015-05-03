#include <stdio.h>

void sort(int a[], int size){
    int x,y;
    for(x = 0; x < size; x++){
          for(y = 0; y < size - x - 1; y++){
                if(a[y] < a[y + 1]){
                        a[y] = a[y] ^ a[y+1];
                        a[y+1] = a[y] ^ a[y+1];
                        a[y] = a[y] ^ a[y+1];
                }       
          }     
    }   
}

int main(){
    int time[100];
    int size, x, y;
    int comSpeed[100] = {0};
    int comN;
    int minS;
    int sum = 0;
    scanf("%d", &comN);
    scanf("%d", &size);
    for(x = 0; x < size; x++){
          scanf("%d", &time[x]);
          sum += time[x];
    }
    sum = sum / comN;
    sort(time, size);
    
    for(x = 0; x < size; x++){
    
          for(y = 0, minS = 0; y < comN; y++){
                if(comSpeed[y] < comSpeed[minS]){
                               minS = y;
                }
          }
          comSpeed[minS] += time[x];
    }
    
    printf("%d %d %d ", comSpeed[0], comSpeed[1], comSpeed[2]);
    scanf("%d", &x);
    return 0;   
}
