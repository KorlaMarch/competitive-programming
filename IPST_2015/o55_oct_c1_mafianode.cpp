#include "stdio.h"
#include "algorithm"
#include "queue"
using namespace std;
int n,l,r,i,j,a,b;
char c;
priority_queue<pair<int,int>> mafia;
int point[1000001];
bool isDel[1000001];
void updateM(int a, int p){
    point[a] += p;
    mafia.push(make_pair(point[a],a));
}
int main(){
    scanf("%d%d%d",&n,&l,&r);
    l += r;
    for(i = 1; i <= n; i++){
        mafia.push(make_pair(0,i));
    }
    for(i = 0; i < l; i++){
        scanf(" %c",&c);
        while(isDel[mafia.top().second]) mafia.pop();
        if(c=='L'){
            scanf("%d%d",&a,&b);
            updateM(b,1);
        }else if(c=='C'){
            scanf("%d%d",&a,&b);
            updateM(b,3);
        }else if(c=='R'){
            printf("%d\n",mafia.top().second);
        }else{
            isDel[mafia.top().second] = true;
        }
    }
}
