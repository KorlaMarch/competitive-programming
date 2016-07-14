#include "stdio.h"
int n,tp;
char mode;
int getRpos(int x){
    if(mode){
        if(x<tp) return tp-x-1;
        else return n-x+tp-1;
    }else{
        return (x+n-tp)%n;
    }
}

int main(){
    int m,i,x,y,k;
    char c;
    int num[500000];
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d", num+i);
    }
    for(i=mode=tp=0; i < m; i++){
        getchar();
        c = getchar();
        switch(c){
        case 'a':
            scanf("%d%d", &x, &y);
            x = getRpos(x-1);
            y = getRpos(y-1);
            k = num[x];
            num[x] = num[y];
            num[y] = k;
            break;
        case 'b':
            scanf("%d%d", &x, &k);
            x = getRpos(x-1);
            num[x] = k;
            break;
        case 'c':
            scanf("%d", &x);
            if(x==tp) tp = 0;
            else if(x<tp) tp = (n-tp+x)%n;
            else tp = x-tp;
            mode = !mode;
            break;
        case 'q':
            scanf("%d", &x);
            x = getRpos(x-1);
            printf("%d\n", num[x]);
            break;
        }
    }
}
