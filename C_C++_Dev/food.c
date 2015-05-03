#include <stdio.h>
#include <string.h>

void cloneArray(int base[], int *clone[], int len){
    int x;
    for(x = 0; x < len; x++){
        *clone[x] = base[x];
    }
    return;
}

void arrayCut(int* in[], int target, int inputsize){
    int x, y = 0;
    /*printf("{ ");
    for(x = 0; x < inputsize; x++){
        printf("%d ", in[x]);
    }
    printf("}\t");*/

    for(x = 0; x < inputsize; x++){
        if(*in[x] != target){
            *in[y] = *in[x];
            y++;
        }
    }
    /*printf("{ ");
    for(x = 0; x < inputsize - 1; x++){
        printf("%d ", in[x]);
    }
    printf("}\n");*/
    return;
}

void manuList(int food[], int foodsize, char parent[]){
    if(foodsize == 0){
        printf("%s\n", parent);
        return;
    }
    int x;
    int temp[foodsize];
    char tempS[30];
    for(x = 0; x < foodsize; x++){
        //printf("%d ", food[x]);
        sprintf(tempS, "%s%d ", parent, food[x]);
        cloneArray(food, &temp, foodsize);
        arrayCut(&temp, food[x], foodsize);

        /*printf("after cut\n");
        printf("{ ");
        for(x = 0; x < foodsize - 1; x++){
            printf("%d ", temp[x]);
        }
        printf("}\n");*/

        //printf("temps = %s", tempS);
        manuList(temp, foodsize - 1, tempS);
    }
}

int isin(int base[], int target, int len){
    int x;
    for(x = 0; x < len; x++){
        if(base[x] == target){
            return 1;
        }
    }
    return 0;
}

int main(){
    int foodType, danFood, x;
    scanf("%d%d", &foodType, &danFood);
    int food[foodType];
    int dangerFood[danFood];
    int temp[foodType];
    for(x = 0; x < danFood; x++){
        scanf("%d", &dangerFood[x]);
    }

    for(x = 0; x < foodType; x++){
        food[x] = x+1;
    }

    //start output

    for(x = 0; x < sizeof(food) / sizeof(food[0]); x++){
        if(!isin(dangerFood, food[x], danFood)){

            //printf("%d ", food[x]);

            cloneArray(food, &temp, sizeof(food) / sizeof(food[0]));
            arrayCut(&temp, food[x], sizeof(food) / sizeof(food[0]));
            char tempS[50];
            sprintf(tempS,"%d ", food[x]);
            //printf("food x = %d\n", food[x]);
            //printf("tempS = %s\n", tempS);
            manuList(temp, sizeof(food) / sizeof(food[0]) - 1, tempS);

            printf("\n");
        }

    }
    return 0;
}
