#include "stdio.h"
#include "stack"
#include "vector"
using namespace std;

vector<int> edge[5005];
vector<int> tedge[5005];
vector<int> gedge[5005];
int n,p,i,j,a,b,pt;
int st[5005],ans[5005],g[5005];
char isV[5005],isVD[5005];

void topo(int x){
    isV[x] = 1;
    for(vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); ++it){
        if(!isV[*it]) topo(*it);
    }
    //printf("TP:%d\n",x);
    st[pt++] = x;
}
int getC(int x){
    int sum=1;
    isV[x] = 2;
    for(vector<int>::iterator it = tedge[x].begin(); it != tedge[x].end(); ++it){
        if(isV[*it]!=2){
            sum += getC(*it);
        }
    }
    return sum;
}
void dfsSCC(int x){
    isVD[x] = 1;
    //printf("DF%d\n",x);
    if(!isV[x]) topo(x);
    for(vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); ++it){
        if(!isVD[*it]) dfsSCC(*it);
    }
    for(vector<int>::iterator it = tedge[x].begin(); it != tedge[x].end(); ++it){
        if(!isVD[*it]) dfsSCC(*it);
    }
}
int main(){
    scanf("%d%d",&n,&p);
    for(i = 0; i < p; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        tedge[b].push_back(a);
    }
    for(i=0;i<n;i++){
        if(!isVD[i]){
            pt=0;
            dfsSCC(i);
            for(pt--,j=0;pt>=0;pt--){
                //printf("ST %d %d\n",st[pt],isV[st[pt]]);
                if(isV[st[pt]]!=2){
                    if() j++;
                    ans[j] += getC(st[pt]);
                }
            }
        }
    }
    for(i = 0; ans[i]!=0; i++){
        printf("%d ",ans[i]);
    }
}
