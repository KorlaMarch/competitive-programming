#include "stdio.h"
#include "math.h"

typedef struct{
    float x,y;
}pos;

pos toRela(pos ori, pos p){
    pos t;
    t.x = p.x-ori.x;
    t.y = p.y-ori.y;
    return t;
}

float getM(pos b){
    if(b.x == 0){
        return (b.y)*9999999;
    }
    return b.y/b.x;
}

int cmp(pos a, pos b){
    if(a.x*b.x < 0){
        return a.x >= 0 ? 1 : 0;
    }else{
        return getM(a)>getM(b) ? 1 : 0;
    }
}

void bbsort(pos a[], int n){
    int isSort = 0,i,j;
    pos t;
    for(i = 0;!isSort; i++){
        isSort = 1;
        for(j = 1; j < n-i; j++){
            if(cmp(a[j],a[j-1])){
                isSort = 0;
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }
}

int main(){
    int n,r,i;
    float area;
    pos o,mid,t;
    pos point[32];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%f%f", &point[i].x, &point[i].y);
    }
    scanf("%f%f%d", &o.x, &o.y, &r);
    //del unused point
    for(i = 0; i < n; i++){
        if(sqrt((o.x-point[i].x)*(o.x-point[i].x)+(o.y-point[i].y)*(o.y-point[i].y))>r){
            point[i] = point[n-1];
            n--;
        }
    }
    //find mid
    for(i = mid.x = mid.y = 0; i < n; i++){
        mid.x += point[i].x;
        mid.y += point[i].y;
    }
    mid.x /= n;
    mid.y /= n;

    //convert all points to relative
    for(i = 0; i < n; i++) point[i] = toRela(mid,point[i]);

    //sorting
    bbsort(point, n);

    //find area
    for(i = 0,area = 0; i < n; i++){
        area += point[i].x*point[(i+1)%n].y;
    }
    for(i = 0; i < n; i++){
        area -= point[i].y*point[(i+1)%n].x;
    }

    printf("Area = %f\n", abs(area/2.0));
}
