#include <stdio.h>
#include <conio.h>

int main(){
    int area ,hight;
    int x, x2, y;
    scanf("%d", &hight);
    if(hight % 2 == 1){
        area = (((hight-1)/2)+1)*(((hight-1)/2)+1);
        x2 = (hight-1)/4.0*(2+(hight-1)/2.0-1)+1;
        printf("%d\n", area);
        for(x = 0; x < ((hight-1)/2)+1; x++){
            for(y = 0; y < ((hight-1)/2)+1; y++){
                if(x2 >= 10){
                    x2 = x2 % 10;
                }
                printf("%d ", x2);

                x2++;
            }
            x2 += x;
            //printf("\n");
        }
    }else{
        area = ((hight/2)+1)*(hight/2);
        x2 = (hight)/4.0*(2+(hight)/2.0-1)+1;
        printf("%d\n", area);
        for(x = 0; x < ((hight)/2); x++){
            for(y = 0; y < ((hight)/2)+1; y++){
                if(x2 >= 10){
                    x2 = x2 % 10;
                }
                printf("%d ", x2);

                x2++;
            }
            x2 += x;
            //printf("\n");
        }
    }

    getch();
    return 0;
}
