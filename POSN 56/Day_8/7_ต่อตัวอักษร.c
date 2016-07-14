#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
    int n;
    int x,y,z;
    int temp;
    char isFind = 0;
    char s[10][150];
    int size;
    printf("Enter number of string : "); scanf("%d", &n);
    for(x = 0; x < n; x++){
        scanf("%s", s[x]);
    }
    size = strlen(s[0]);
    for(x = 0; x < n - 1; isFind = 0, x++){
        for(z = 0; z < strlen(s[x]) && isFind == 0; z++){
            for(y = 0; y < strlen(s[x + 1]) && isFind == 0; y++){
                if(s[x][y] == s[x + 1][z]){
                    temp = (strlen(s[x + 1]) - z) - (strlen(s[x]) - y);
                    if(temp > 0){
                        size += temp;
                    }
                    isFind = 1;
                }
            }
        }
    }

    printf("%d", size);
    getch();
    return 0;
}
