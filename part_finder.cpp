#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define WIDTH 5
#define HIGHT 4

#define TURN_TIME 1
#define RUN_TIME 1

typedef struct{
    int x;
    int y;
}pos;

typedef struct{
    int dis;
    int turn;
}res;
// [y][x]
char state[4][5] = {0};
int count = 0;

//return lenght of way
res partfinder(char dri, pos p, pos target, char part[4][5], char way[], res d){
    pos temp;
    res tempD;
    char tempS[100];
    char max_way[100] = "";
    res maxD;

    maxD.dis = 999999999;
    maxD.turn = 999999999;

    int min_time = 999999999;
    int n;
    int turn;
    if(target.x == p.x && target.y == p.y){
        if(dri != 'N'){
            d.turn++;
        }
        return d;
    }
    part[p.y][p.x] = 1;
    count++;
    //down
    if(p.y < 3 && part[p.y + 1][p.x] == 0){
        tempD.dis = d.dis + 1;
        tempD.turn = d.turn;

        temp.x = p.x;
        temp.y = p.y + 1;

        n = strlen(way);
        strcpy(tempS, way);
        if(dri == 'N'){
            tempS[n] = 'B';
            tempD.turn += 2;
        }else if(dri == 'S'){
            tempS[n] = 'F';
        }else if(dri == 'E'){
            tempS[n] = 'R';
            tempD.turn++;
        }else if(dri == 'W'){
            tempS[n] = 'L';
            tempD.turn++;
        }
        tempS[n + 1] = '\0';

        maxD = partfinder('S', temp, target, part, tempS, tempD);
        min_time = maxD.dis * RUN_TIME + maxD.turn * TURN_TIME;
        strcpy(max_way, tempS);
    }
    //up
    if(p.y > 0 && part[p.y - 1][p.x] == 0){
        tempD.dis = d.dis + 1;
        tempD.turn = d.turn;

        temp.x = p.x;
        temp.y = p.y - 1;

        n = strlen(way);
        strcpy(tempS, way);
        if(dri == 'N'){
            tempS[n] = 'F';
        }else if(dri == 'S'){
            tempS[n] = 'B';
            tempD.turn += 2;
        }else if(dri == 'E'){
            tempS[n] = 'L';
            tempD.turn++;
        }else if(dri == 'W'){
            tempS[n] = 'R';
            tempD.turn++;
        }
        tempS[n + 1] = '\0';
        tempD = partfinder('N', temp, target, part, tempS, tempD);
        n = tempD.dis * RUN_TIME + tempD.turn * TURN_TIME;
        if(n < min_time){
            min_time = n;
            maxD = tempD;
            strcpy(max_way, tempS);
        }
    }
    //right
    if(p.x < 4 && part[p.y][p.x + 1] == 0){
        tempD.dis = d.dis + 1;
        tempD.turn = d.turn;

        temp.x = p.x + 1;
        temp.y = p.y;

        n = strlen(way);
        strcpy(tempS, way);
        if(dri == 'N'){
            tempS[n] = 'R';
            tempD.turn++;
        }else if(dri == 'S'){
            tempS[n] = 'L';
            tempD.turn++;
        }else if(dri == 'E'){
            tempS[n] = 'F';
        }else if(dri == 'W'){
            tempS[n] = 'B';
            tempD.turn += 2;
        }
        tempS[n + 1] = '\0';

        tempD = partfinder('E', temp, target, part, tempS, tempD);
        n = tempD.dis * RUN_TIME + tempD.turn * TURN_TIME;
        if(n < min_time){
            min_time = n;
            maxD = tempD;
            strcpy(max_way, tempS);
        }

    }

    //left
    if(p.x > 0 && part[p.y][p.x - 1] == 0){
        tempD.dis = d.dis + 1;
        tempD.turn = d.turn;

        temp.x = p.x - 1;
        temp.y = p.y;

        n = strlen(way);
        strcpy(tempS, way);
        if(dri == 'N'){
            tempS[n] = 'L';
            tempD.turn++;
        }else if(dri == 'S'){
            tempS[n] = 'R';
            tempD.turn++;
        }else if(dri == 'E'){
            tempS[n] = 'B';
            tempD.turn += 2;
        }else if(dri == 'W'){
            tempS[n] = 'F';
        }
        tempS[n + 1] = '\0';

        tempD = partfinder('W', temp, target, part, tempS, tempD);
        n = tempD.dis * RUN_TIME + tempD.turn * TURN_TIME;
        if(n < min_time){
            min_time = n;
            maxD = tempD;
            strcpy(max_way, tempS);
        }

    }

    part[p.y][p.x] = 0;
    strcpy(way, max_way);

    return maxD;
}

int main(){
    int x, y, n;
    char ch;
    char part[4][5];
    char way[100] = "";
    pos p, target;
    res d;
    clock_t t;
    FILE *fp;
    //input
    printf("Input field :\n\n");
    printf("  %c     %c     %c     %c     %c\n", 219, 176, 4, 219, 176);
    printf("  |     |     |     |     |\n");
    for(x = 0; x < HIGHT; x++){
        if(x != 0) printf("  |     |     |     |     |\n");
        printf("  ");
        for(y = 0; y < WIDTH; y++){
            if(y != 0) printf(" --- ");
            ch = getch();
            if(ch == 'x' || ch == 'X'){
                printf("%c", 15);
                state[x][y] = 1;
            }else{
                printf("+");
                state[x][y] = 0;
            }

        }

        printf("\n");
    }
    printf("              |\n");
    printf("              %c\n", 64);

    //calu
    fp = fopen("Part.txt", "w+");
    t = clock();
    p.x = 2;
    p.y = 3;

    for(n = 0; n < 5; n++){
        //reset part
        d.dis = 0;
        d.turn = 0;
        for(x = 0; x < 4; x++){
            for(y = 0; y < 5; y++){
                part[x][y] = state[x][y];
            }
        }
        way[0] = '\0';
        printf("Search Way to #%d\n", n);
        target.x = n;
        target.y = 0;
        d = partfinder('N', p, target, part, way, d);
        printf("\tFind way : %s\n", way);
        printf("\tDis = %d\n\tTurn = %d\n", d.dis, d.turn);
        printf("\tWriting down to file...\n");
        fprintf(fp,"Part to #%d = {", n);
        for(x = 0; way[x+1] != '\0'; x++){
            fprintf(fp,"'%c',", way[x]);
        }
        fprintf(fp,"'%c'};\n", way[x]);

    }
    t = clock() - t;
    fclose(fp);
    printf("\nFinding part succeed!\n");
    printf("Total search : %d in %.3f sec\n", count, ((float)t)/CLOCKS_PER_SEC);
    getch();
    return 0;
}
