#include <stdio.h>
#include <conio.h>

void printSupSnail(int stn, int n, char ch, int x){
    if(n <= 0) return;

    printf("%c", (ch+n*3-4+x)%26 + 'A');
    printSupSnail(n - 2, ch - (5*4 - 4),x);
    printf("%c", (ch+n+n-x-3)%26 + 'A');
}

void printSnail(int n, char ch){
    int x,y;

    for(x = 0; x < n; x++){
        printf("%c", (ch+n*3-4-x)%26 + 'A');
    }

    printf("\n");

    for(x = 1; x < n - 1; x++){
        printf("%c", (ch+n*3-4+x)%26 + 'A');
        printSupSnail(n, n - 2, ch - (5*4 - 4),x);
        printf("%c", (ch+n+n-x-3)%26 + 'A');
        printf("\n");
    }

    for(x = 0; x < n; x++){
        if(x == 0){
            printf("%c", (ch+n*4-5)%26 + 'A');
        }else if(x == n - 1){
            printf("%c", (ch+n-2)%26 + 'A');
        }else{
            printf("%c", (ch+x-1)%26 + 'A');
        }
    }
}

int main(){
    int n;
    char ch = 9;
    scanf("%d", &n);
    int x,y;
    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){
            if(x == 0){
                printf("%c", (ch+n*3-4-y)%26 + 'A');
            }else if(y == 0){
                printf("%c", (ch+n*3-4-y+x)%26 + 'A');
            }else if(y == n - 1){
                printf("%c", (ch+n-x+n-3)%26 + 'A');
            }else if(x == n - 1){
                printf("%c", (ch+y-1)%26 + 'A');
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    printSnail(n, ch);
    getch();
    return 0;
}
