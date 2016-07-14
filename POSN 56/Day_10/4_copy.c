#include <stdio.h>
#include <conio.h>

void copy(char *source, char *dest){
    int x;
    while(*(dest+x) != '\0'){
        *(source+x) = *(dest+x);
        x++;
    }
    *(source+x) = '\0';
}

int main(){
    char temp[20], dest[20] = "Tset";
    copy(temp, dest);
    printf("%s %s", dest, temp);
    getch();
    return 0;
}
