#include "stdio.h"

int x,i,sum;
int sc[5];

int main(){
    scanf("%d",&x);
    for(i = 0; i < 5; i++){
        scanf("%d",sc+i);
        sum += sc[i];
    }
    for(i = 0; i < 5; i++){
        if(sum-sc[i]==x){
            sc[i] = 0;
            break;
        }
    }
    if(i==5&&sum!=x) printf("-1\n");
    else for(i = 0; i < 5; i++){
        printf("%d ", sc[i]);
    }

}
