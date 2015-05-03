#include <stdio.h>

int main(){
    int x = 1, y = 2, z = 3;
    x += y += z;
    printf("%d %d %d", x, y, z);


}
