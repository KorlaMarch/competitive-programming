#include <stdio.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}coodinate;

int det(coodinate pos[], char size){
    //find det
    int n, det = 0;
    for(n = 0; n < size; n++){
        det += pos[n].x * pos[(n+1)%size].y;
        det -= pos[(n+1)%size].x * pos[n].y;
    }

    return det < 0 ? det * -1 : det;
}

float maxArea(coodinate pos[], char size, coodinate ans_pos[], char ans_size){
    int n, m, m2;
    coodinate t_pos[5];
    float max = 0.0, temp;
    if(size <= 0){
        for(n = 0; n < ans_size; n++){
            printf("(%d,%d), ", ans_pos[n].x, ans_pos[n].y);
        }
        printf(" det = %.2f \n", 0.5 * det(ans_pos, ans_size));
        return det(ans_pos, ans_size) * 0.5;
    }
    for(n = 0; n < size; n++){
        ans_pos[ans_size].x = pos[n].x;
        ans_pos[ans_size].y = pos[n].y;
        for(m = 0, m2 = 0; m < size; m++){
            //skip if m is selected
            if(m != n){
                t_pos[m2].x = pos[m].x;
                t_pos[m2].y = pos[m].y;
                m2++;
            }
        }
        temp = maxArea(t_pos, size - 1, ans_pos, ans_size + 1);
        if(max < temp){
            max = temp;
        }
    }
    return max;

}

int main(){
    coodinate circle;
    int r;
    coodinate pos[5];
    coodinate inner_pos[5];
    char n;
    char innerSize = 0;
    float area;

    printf("Enter coodinate of the circle (x,y) : "); scanf("%d%d", &circle.x, &circle.y);
    printf("Enter radius : "); scanf("%d", &r);

    for(n = 0; n < 5; n++){
        printf("Enter point %d position (x, y): ", n); scanf("%d%d", &pos[n].x, &pos[n].y);
    }

    for(n = 0; n < 5; n++){
        //if in the circle
        if(sqrt((pos[n].x - circle.x)*(pos[n].x - circle.x) + (pos[n].y - circle.y)*(pos[n].y - circle.y)) <= r){
            inner_pos[innerSize].x = pos[n].x;
            inner_pos[innerSize].y = pos[n].y;
            innerSize++;
        }
    }



    if(innerSize < 3){
        area = 0;
    }else{
        pos[0].x = inner_pos[0].x;
        pos[0].y = inner_pos[0].y;
        area = maxArea(inner_pos + 1, innerSize - 1, pos, 1);
    }

    printf("area = %.2f", area);

}
