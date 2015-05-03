#include "stdio.h"

typedef struct{
    int h;
    int x;
}domi;

int main(){
    domi d[100000];
    int n,i,j,max,c,to,maxp,s,max2,maxp2;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &d[i].x, &d[i].h);
    }

    //to right
    for(i = max = c = s = 0, to = d[0].x+1; i < n; i++){
        if(d[i].x < to){
            c++;
            if(d[i].x+d[i].h > to) to = d[i].x+d[i].h;
        }else{
            //printf("End %d %d %d\n", i, c, s);
            if(c > max){
                max = c;
                maxp = s;
            }
            c = 0;
            s = i;
            to = d[i].x+1;
            i--;
        }
    }
    if(c > max){
        max = c;
        maxp = s;
    }
    //printf("End %d %d %d\n", i, c, s);

    //to left
    for(max2=c=0,i=s=n-1, to = d[n-1].x-1; i >= 0; i--){
        //printf("End %d %d %d %d\n", i, c, s,to);
        if(d[i].x > to){
            c++;
            if(d[i].x-d[i].h < to) to = d[i].x-d[i].h;
        }else{
            if(c > max2){
                max2 = c;
                maxp2 = s;
            }
            c = 0;
            s = i;
            to = d[i].x-1;
            i++;
        }
    }
    if(c > max2){
        max2 = c;
        maxp2 = s;
    }
     //printf("End %d %d %d\n", i, c, s);
    if(max > max2){
        printf("%d R\n", maxp+1);
    }else if(max2 > max){
        printf("%d L\n", maxp2+1);
    }else{
        if(maxp < maxp2){
            printf("%d R\n", maxp+1);
        }else{
            printf("%d L\n", maxp2+1);
        }
    }

}
