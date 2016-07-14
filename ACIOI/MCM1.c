#include "stdio.h"

int main(){
    int n,i,j,k,min;
    int size[101];
    int time[100][100];
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &size[i]);
    for(i = n-1; i>=0; i--){
        time[i][i] = 0;
        for(j = i+1; j<n; j++){
            for(k = i; k < j; k++){
                min = time[i][k]+
            }
        }
    }
}
