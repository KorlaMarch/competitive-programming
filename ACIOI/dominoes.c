#include "stdio.h"
int n;
int pi[500001];
int hi[500001];

int main(){
     int i,j;
     int mp;
     scanf("%d", &n);
     for(i = 0; i < n; i++){
        scanf("%d%d",&pi[i],&hi[i]);
     }
     hi[n-1] = n;
     for(i = n-2;i >= 0; i--){
        mp = i+1;
        for(j = i+1; pi[i]+hi[i] >= pi[j] && j < n; j++){
            if(hi[j]>mp) mp = hi[j];
        }
        hi[i] = mp;
     }
     for(i=0; i< n; i++) printf("%d ", hi[i]);
}
