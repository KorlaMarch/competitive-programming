#include "stdio.h"
#include "queue"
#include "vector"
#include "unordered_set"
#define N 9
#define HN 3
using namespace std;
typedef struct state{
    char a[N];
    int hv,p,sp;
    state(char a[],int sp):sp(sp)
    {
        for(int i = 0; i < N; i++){
            this->a[i] = a[i];
            if(!a[i]) this->p = i;
        }
        h(this);
    }
    ~state(){
        delete a;
    }
    bool operator()(struct state a, struct state b){
        return a.hv<b.hv;
    }
    bool operator==(struct state st){
        for(int i = 0; i < N; i++){
            if(a[i]!=st.a[i]) return false;
        }
        return true;
    }
}state;
int i,j,tmp;
state s,e,t;
priority_queue<state,vector<state>,state> qu;
unordered_set<long long> isCal;
void h(state& st){
    st.hv = 0;
    for(int i = 0; i < N; i++){
        if(st.a[i] != e.a[i] && st.a[i]) st.hv++;
    }
}
long long hashSt(state st){
    long long hs = 0;
    for(int i = 0; i < N; i++){
        hs = hs*10+st.a[i];
    }
    return hs;
}
int main(){
    for(i = 0; i < N; i++){
        scanf("%d",&s.a[i]);
        e.a[i] = i+1;
        if(s.a[i] == 0) s.p = i;
    }
    e.a[N-1] = 0;
    s.sp = 0;
    h(s);
    qu.push(s);
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        if(t==e){
            printf("MIN STEP = %d\n",t.sp);
            break;
        }
        if()
    }
}
