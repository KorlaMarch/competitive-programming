#include "stdio.h"

int r1[4],newr1[4];
int r2[4],newr2[4];

void convert_p(int oldr[], int newr[]){
    // min x,y
    newr[0] = oldr[0];
    newr[1] = oldr[1]-oldr[3];
    // max x,y
    newr[2] = oldr[0]+oldr[2];
    newr[3] = oldr[1];
}

bool insq(int x, int y, int r[]){
    return (r[0]<=x&&x<=r[2]) && (r[1]<=y&&y<=r[3])
}

bool is_intersect(int r1[], int r2[]){
    return insq(r1[0],r1[1],r2) || insq(r1[2],r1[3],r2) || insq(r1[0],r1[3],r2) || insq(r1[2],r1[1],r2)
        insq(r2[0],r2[1],r1) || insq(r2[2],r2[3],r1) || insq(r2[0],r2[3],r1) || insq(r2[2],r2[1],r1);
}

bool isCTouch(int r1[], int r2[]){
}

int main(){
    printf("Enter rectangle1: ");
    scanf(" %d %d %d %d", &r1[0], &r1[1], &r1[2], &r1[3]);
    printf("Enter rectangle2: ");
    scanf(" %d %d %d %d", &r2[0], &r2[1], &r2[2], &r2[3]);

    //convert to a better con
    convert_p(r1, newr1);
    convert_p(r2, newr2);

    //check for collision
    if(is_intersect(newr1,newr2)&&!isCTouch(r1, r2)){
        printf("collision\n");
    }else{
        printf("No collision\n");
    }
    return 0;

}

