#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"

struct node{
    int hu,x,d,p;
    int isV;
    bool operator()(node a, node b){
        return a.hu<b.hu;
    }
};
int n,i,j,md;
int hap[30][30];
std::pair<int,int> hua[30][30];
std::priority_queue<node,std::vector<node>,node> qu;
std::priority_queue<std::pair<int,int> > mstq;
//number |= 1 << x;
//number &= ~(1 << x);
//bit = (number >> x) & 1;
int findHu(int isV){
    int i,j,hu;
    for(i=hu=0; i < n; i++){
        if(!((isV>>i)&1)){
            for(j = n-1; j >= 0 && (((isV>>j)&1)||hua[i][j].second==n-1) ; j--);
            hu += hua[i][j].first;
        }
    }
    return hu;
}

node getNode(int x, int d, int p, int isV){
    node tmp;
    tmp.hu = findHu(isV&~(1<<x))+p;
    tmp.x = x;
    tmp.d = d;
    tmp.p = p;
    tmp.isV = isV;
    return tmp;
}

void tsp(){
    int i;
    node t,no;
    qu.push(getNode(0,0,0,0));
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        //printf(":%d %d %d %d %d\n",t.hu,t.x,t.d,t.p,t.isV);
        if(t.d==n-2){
            if(t.p+hap[t.x][n-1]>md){
                md = t.p+hap[t.x][n-1];
            }
        }else{
            t.isV |= (1 << t.x);
            for(i = 0; i < n-1; i++){
                if(!((t.isV>>i)&1)){
                    no = getNode(i,t.d+1,t.p+hap[t.x][i],t.isV);
                    if(no.hu>md){
                        qu.push(no);
                    }
                }
            }
            t.isV &= ~(1 << t.x);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&hap[i][j]);
            hua[j][i].second = j;
            hua[j][i].first = hap[i][j];
        }
    }
    for(i = 0; i < n; i++) std::sort(hua[i],hua[i]+n);
    tsp();
    printf("%d\n",md);
}
