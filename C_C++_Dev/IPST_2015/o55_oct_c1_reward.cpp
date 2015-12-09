#include "stdio.h"
#include "queue"
#define DIV(a,b) (a/b+(a%b!=0))
struct pos{
    int x,s,g;
    bool operator()(pos a, pos b){
        return a.x<b.x;
    }
};
int n,b,i,j;
pos tmp;
std::priority_queue<pos,std::vector<pos>,pos> qu;
int main(){
    scanf("%d%d",&n,&b);
    b -= n;
    tmp.g = 1;
    for(i = 0; i < n; i++){
        scanf("%d",&tmp.s);
        tmp.x = tmp.s;
        qu.push(tmp);
    }
    for(;b>0;b--){
        tmp = qu.top();
        qu.pop();
        tmp.g++;
        tmp.x = DIV(tmp.s,tmp.g);
        //printf("GET %d %d %d\n",tmp.x,tmp.s,tmp.g);
        qu.push(tmp);
    }
    printf("%d\n",qu.top().x);
}
