#include "stdio.h"
int n,p,m,i,sl,h,v;
char s[81];
void pb(){
    m--;
    switch(p){
    case 1:
        sl = sl-m-1>0?sl-m-1:0;
        break;
    case 2: case 3: case 4: case 5: case 6:
        s[sl++] = 'A'+(p-2)*3+m%3;
        break;
    case 7:
        s[sl++] = 'P'+m%4;
        break;
    case 8:
        s[sl++] = 'T'+m%3;
        break;
    case 9:
        s[sl++] = 'W'+m%4;
        break;
    }
}
int main(){
    scanf("%d%d%d",&n,&p,&m);
    pb();
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&h,&v,&m);
        p += h+v*3;
        pb();
    }
    if(sl){
        s[sl] = '\0';
        printf("%s\n", s);
    }else{
        printf("null\n");
    }
}
