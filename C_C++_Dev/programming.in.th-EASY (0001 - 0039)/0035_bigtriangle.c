#include <stdio.h>
#include <stdlib.h>

typedef struct position{
    int x;
    int y;
} pos;

int main(){
    pos triangle[100];
    int n;
    int x, y, z;
    float maxArea = 0.0;
    float area;
    scanf("%d", &n);

    for(x = 0; x < n; x++){
        scanf("%d%d", &triangle[x].x, &triangle[x].y);
    }
    if(n >= 3){
        for(x = 0; x < n - 2; x++){
            y = x + 1;
            while(y < n - 1){
                z = y + 1;
                while(z < n){

                    area = (float)abs(triangle[x].x*triangle[y].y +
                        triangle[y].x*triangle[z].y +
                        triangle[z].x*triangle[x].y -
                        triangle[x].y*triangle[y].x -
                        triangle[y].y*triangle[z].x -
                        triangle[z].y*triangle[x].x)/2.0;

                    if(area >= maxArea){
                        maxArea = area;
                    }
                    z++;
                }
                y++;
            }
        }
    }
    printf("%.3f", maxArea);
}
