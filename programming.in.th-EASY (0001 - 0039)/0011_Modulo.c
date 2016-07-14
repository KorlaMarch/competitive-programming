#include <stdio.h>

int main(){
    int x, temp, y, x2 = 0;
    int modulo[10];
    int modulo2[10];
    for(x = 0; x < 10; x++){
        scanf("%d", &temp);
        modulo[x] = temp % 42;
    }
    for(x = 0; x < 10; x++){
        temp = 0;
        for(y = 0; y < x2; y++){
            if(modulo[x] == modulo2[y]){
                temp = 1;
            }
        }
        if(temp != 1){
            modulo2[x2] = modulo[x];
            x2++;
        }
    }
    printf("%d", x2);

}
