#include "stdio.h"
#include "vector"
#include "queue"
#include "map"

typedef std::priority_queue<std::pair<int,int>> queuePI;
typedef std::pair<int,queuePI*> piq;

struct cmp{
    bool operator()(piq a, piq b){
        return a.first<b.first;
    }
};

int n,k,i,j,x,len,d;
char t,c;
std::vector<std::pair<char,int>> in;
std::vector<int> co,coWO;
std::vector<char> ans;
std::priority_queue<piq,std::vector<piq>,cmp> qu;
//first = length , second = ansPos
queuePI *onDo;

queuePI* mergePQ(queuePI* a, queuePI* b){
    if(a->size()<b->size()){
        while(!a->empty()){
            b->push(a->top());
            a->pop();
        }

        delete a;
        return b;
    }else{
        while(!b->empty()){
            a->push(b->top());
            b->pop();
        }
        delete b;
        return a;
    }
}

int main(){
    scanf("%d",&n);
    len = 0;
    for(k = 0; k < n; k++){
        scanf(" %c",&t);
        if(t=='T'){
            scanf(" %c",&c);
            in.push_back({t,c});
            len++;
        }else if(t=='U'){
            scanf("%d",&x);
            if(coWO.size()-x-1>=0) len = co[coWO[coWO.size()-x-1]];
            else len = 0;
            in.push_back({t,x});
        }else{
            scanf("%d",&x);
            in.push_back({t,x});
        }
        co.push_back(len);
        if(t!='P') coWO.push_back(k);
        ans.push_back(0);
    }
    onDo = new queuePI();
    d = coWO.size()-1;
    for(k = n-1; k >= 0; k--){
        //printf("K = %d\n",k);
        if(in[k].first=='P'){
            onDo->push({in[k].second+1,k});
        }else if(in[k].first=='T'){
            while(!onDo->empty()&&co[k]<=onDo->top().first){
                ans[onDo->top().second] = in[k].second;
                onDo->pop();
            }
            d--;
        }else{
            if(in[k].second!=0){
                qu.push({coWO[d-in[k].second],onDo});
            }
            onDo = new queuePI();
            d--;
        }
        while(!qu.empty()&&qu.top().first==k){
            onDo = mergePQ(onDo,qu.top().second);
            qu.pop();
        }
    }
    for(k = 0; k < n; k++){
        if(ans[k]!=0){
            printf("%c\n",ans[k]);
        }
    }
}
