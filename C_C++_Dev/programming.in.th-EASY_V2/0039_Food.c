#include "stdio.h"

int n,m;
char fob[8],u[8],l[8];
void listF(int d){
    int i;
    if(d>=n){
        for(i=0;i<n;i++) printf("%d ", l[i]);
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(!u[i]){
            u[i] = 1;
            l[d] = i+1;
            listF(d+1);
            u[i] = 0;
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&j);
        fob[j-1]=1;
    }
    for(i=0;i<n;i++){
        if(!fob[i]){
            u[i] = 1;
            l[0] = i+1;
            listF(1);
            u[i] = 0;
        }
    }
}
