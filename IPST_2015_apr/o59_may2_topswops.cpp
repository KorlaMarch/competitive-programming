#include "stdio.h"
#include "algorithm"
int n,i,j,c,x,p;
int num[300005];

/*void printNum(){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}*/

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }
    for(i = p = 0; num[p]!=1; i++){
        if(i%2){
            p = (p-num[p]+n+1)%n;
        }else{
            p = (p+num[p]-1)%n;
        }
        //printf("%d : %d\n",p,num[p]);
    }
    printf("%d\n",i);
}
