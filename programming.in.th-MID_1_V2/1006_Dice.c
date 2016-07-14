#include "stdio.h"

int d[6],t[6];
int templ[6] = {1,2,3,5,4,6};
void rot(int n1, int n2, int n3, int n4, int n5, int n6){
    int i;
    t[0] = d[n1-1];
    t[1] = d[n2-1];
    t[2] = d[n3-1];
    t[3] = d[n4-1];
    t[4] = d[n5-1];
    t[5] = d[n6-1];
    for(i = 0; i < 6; i++) d[i] = t[i];
}

int main(){
    int n,i,j;
    char c;
    scanf("%d ",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < 6; j++){
            d[j] = templ[j];
        }
        while((c=getchar())!='\n'){
            switch(c){
            case 'F':
                rot(4,1,3,6,5,2);
                break;
            case 'B':
                rot(2,6,3,1,5,4);
                break;
            case 'L':
                rot(5,2,1,4,6,3);
                break;
            case 'R':
                rot(3,2,6,4,1,5);
                break;
            case 'C':
                rot(1,5,2,3,4,6);
                break;
            case 'D':
                rot(1,3,4,5,2,6);
                break;
            }
        }
        printf("%d ", d[1]);
    }
}
