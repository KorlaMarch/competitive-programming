#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    if(y >= x){
        printf("%d", (int)ceil((float)y / (float)x));
    }else{
        printf("2");
    }
}
