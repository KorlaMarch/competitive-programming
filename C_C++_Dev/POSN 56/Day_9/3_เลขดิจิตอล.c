#include <stdio.h>
#include <conio.h>

struct digital{
    int value;
    char po;
};

int main(){
    struct digital digit[100];
    char c;
    int x, y, z;
    int n = 0;
    do{
        c = getchar();
        digit[n].value = c & 0x0F;
        switch(digit[n].value){
            case 0:
                digit[n].po = 0x7D;
                break;
            case 1:
                digit[n].po = 0x50;
                break;
            case 2:
                digit[n].po = 0x37;
                break;
            case 3:
                digit[n].po = 0x57;
                break;
            case 4:
                digit[n].po = 0x5A;
                break;
            case 5:
                digit[n].po = 0x4F;
                break;
            case 6:
                digit[n].po = 0x6F;
                break;
            case 7:
                digit[n].po = 0x51;
                break;
            case 8:
                digit[n].po = 0x7F;
                break;
            case 9:
                digit[n].po = 0x5F;
                break;
        }
        n++;
    }while(c != '\n');

    for(x = 0; x < 7; x++){
        for(y = 0; y < n - 1; y++){
            printf(" ");
            for(z = 0; z < 5; z++){
                if((x == 0 && digit[y].po & 0x01) || (x == 3 && digit[y].po & 0x02)
                   || (x == 6 && digit[y].po & 0x04) || (z == 0 && x < 4 && digit[y].po & 0x08)
                   || (z == 4 && x < 4 && digit[y].po & 0x10) || (z == 0 && x > 2 && digit[y].po & 0x20)
                   || (z == 4 && x > 2 && digit[y].po & 0x40)){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
    getch();
    return 0;
}
