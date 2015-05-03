#include "stdio.h"
int l,x,y,n;
char a[1024][1024];

void p(int x,int y){
    if(a[x][y]) printf("Error %d %d!\n",x,y);
    else a[x][y] = 1;
}

int main(){
    int i,t;
    scanf("%d%d%d%d",&l,&x,&y,&n);
    a[x][y] = 1;
    for(i = 0; i < n; i++){
        scanf("%d%d%d",&t,&x,&y);
        switch(t){
        case 0:
            p(x+1,y);
            p(x,y+1);
            p(x+1,y+1);
            break;
        case 1:
            p(x,y);
            p(x,y+1);
            p(x+1,y+1);
            break;
        case 2:
            p(x,y);
            p(x+1,y);
            p(x+1,y+1);
            break;
        case 3:
            p(x,y);
            p(x,y+1);
            p(x+1,y);
            break;
        }
    }
    /*for(y = 0; y < l; y++){
        for(x = 0; x < l; x++){
            if(!a[x][y]) printf("Empty %d %d!\n", x,y);
        }
    }*/
}
