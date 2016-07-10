#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

struct node{
    int far,beg,hop;
    node(int _far = 0, int _beg = 0, int _hop = 0) : far(_far),beg(_beg),hop(_hop) {}
};

int n,s,i,j,d;
int l[1000005];
std::pair<int,int> hop[1000005];
std::queue<node> qu;
int suml,tmpb,tmph;
node* t;
int main(){
    scanf("%d%d",&n,&s);
    for(i = 0; i < n; i++){
        scanf("%d",&l[i]);
        suml += l[i];
        l[i] = sum[l];
    }
    for(i = 0; i < s; i++){
        scanf("%d",&d);
        if(d>=suml) printf("1\n");
        else{
            for(j = 0; j < n; j++){
                if(l[i]<d){
                    //can begin
                    qu.push(node(l[i]+d,l[i]));
                }
                tmpb = n;
                tmph = -1;
                while(!qu.empty()&&qu.top().far<l[i+1]){
                    t = qu.top();
                    if(t.hop<)
                    tmpb = std::min(n,t.beg);
                }
                qu.push(node(l[i]+d,tmpb,t.hop));
            }
            printf("%d\n");
        }
    }
}
