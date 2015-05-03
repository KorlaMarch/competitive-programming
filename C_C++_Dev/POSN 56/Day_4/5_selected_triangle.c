#include <stdio.h>
#include <conio.h>

int main(){
    int x,y,size, slot;
    char ch = 0;
    printf("Enter size : "); scanf("%d", &size);
    printf("Enter slot : "); scanf("%d", &slot);

    for(x = 1; x <= size; x++){
        for(y = 0; y < x; y++){
            if(y == slot - 1){
                printf("%c", ch + 'A');
            }
            ch = (ch + 1)%26;
        }
    }
    getch();
}
