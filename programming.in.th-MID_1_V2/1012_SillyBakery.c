#include "stdio.h"
#include "math.h"
int n,i,j,x;
int size[5];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &x);
            size[j] += x;
        }
    }
    printf("%d\n",(int)ceil(size[0]+0.75*size[1]+0.50*size[2]+0.25*size[3]+0.125*size[4]));
}
