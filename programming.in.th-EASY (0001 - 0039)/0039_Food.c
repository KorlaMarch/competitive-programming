#include <stdio.h>
#include <string.h>

int isValueInList(int list[], int size, int v){
    int x;
    for(x = 0; x < size; x++){
        if(list[x] == v){
            return 1;
        }
    }
    return 0;
}

void listMenu(int list[], int size, char *str){
    int x;
    int isEmpty = 1;
    int temp;
    char copy[100];
    char tempS[3];
    /*printf("list = ");
    for(x = 0; x < size; x++){
        printf("%d ", list[x]);
    }
    printf("\n");*/
    for(x = 0; x < size; x++){
        if(list[x] != 0){
            isEmpty = 0;
            break;
        }
    }
    if(isEmpty){
        printf("%s\n", str);
        return;
    }


    for(x = 0; x < size; x++){
        if(list[x] != 0){
            temp = list[x];
            strcpy(copy, str);
            tempS[0] = list[x] + '0';
            tempS[1] = ' ';
            tempS[2] = '\0';
            strcat(copy, tempS);
            list[x] = 0;
            listMenu(list, size, copy);
            list[x] = temp;
        }
    }

}

int main(){
    int n, danNum;
    int x, y;
    scanf("%d", &n);
    int food[n];
    char tempS[3];
    scanf("%d", &danNum);
    int dangerFood[danNum];
    for(x = 0; x < danNum; x++){
        scanf("%d", &dangerFood[x]);
    }

    for(x = 0; x < n; x++){
        if(!isValueInList(dangerFood, danNum, x + 1)){
            for(y = 0; y < n; y++){
                food[y] = y+1;
            }

            tempS[0] = food[x] + '0';
            tempS[1] = ' ';
            tempS[2] = '\0';
            food[x] = 0;
            listMenu(food, n, tempS);

        }
    }

}
