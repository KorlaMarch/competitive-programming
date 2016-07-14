#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

struct qur{
    int x,y,l,i;
    qur(int _x = 0, int _y = 0, int _l = 0, int _i = 0): x(_x), y(_y), l(_l), i(_i) {}
};
bool cmp(qur a, qur b){
    return a.l<b.l;
}

int n,m,i,j,maxP,mid;
int x[100005];
std::vector<qur> qu;
std::pair<int,int> ans[100005];
int s[100005];
int t[100005];
double u[100005];
int segS[400005];
int segC[400005];
int leaf[100005];
int bsX[100005];
int bsY[100005];
long long qs[100005];
double avg;
std::pair<int,int> xi[100005];
//std::vector<int> tp;

void inti_seg(int x, int i, int j){
    if(i==j){
        leaf[i] = x;
        if(x>maxP) maxP = x;
    }else{
        inti_seg(x*2+1,i,(i+j)/2);
        inti_seg(x*2+2,(i+j)/2+1,j);
    }
}

void clearSeg(){
    int i;
    for(i = 0; i <= maxP; i++){
        segC[i] = 0;
        segS[i] = 0;
    }
}
void recIns(int x, int v){
    segC[x]++;
    //printf("UP %d\n",x)
    segS[x] += v;
    if(x) recIns((x-1)/2,v);
}
void insSeg(int x, int v){
    printf("INS %d %d : %d\n",x,v,leaf[x]);
    segC[leaf[x]]++;
    segS[leaf[x]] += v;
    recIns((leaf[x]-1)/2,v);
}
bool isintersert(int x1, int y1, int x2, int y2){
    return (x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2)||(x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1);
}
//first = count , second = sum
std::pair<int,int> rmq(int no, int i, int j, int x, int y){
    std::pair<int,int> pi,tmp;
    if(x<=i&&j<=y){
        printf("CHECK1 %d %d %d : %d %d : %d %d\n",no,i,j,x,y,segC[no],segS[no]);
        return {segC[no],segS[no]};
    }else if(isintersert(i,j,x,y)){
        pi = rmq(no*2+1,i,(i+j)/2,x,y);
        tmp = rmq(no*2+2,(i+j)/2+1,j,x,y);
        pi.first += tmp.first;
        pi.second += tmp.second;
        printf("CHECK2 %d %d %d : %d %d : %d %d\n",no,i,j,x,y,pi.first,pi.second);
        return pi;
    }else return {0,0};
}

void do_querry(){
    int i,j,p;
    printf("Clear\n");
    clearSeg();
    std::sort(qu.begin(),qu.end(),cmp);
    for(i=j=p=0; i < n; i++){
        //while(tp[p]<x[i].first) p++;
        insSeg(xi[i].second,xi[i].first);
        while(i+1 < n && xi[i].first==xi[i+1].first){
            i++;
            insSeg(xi[i].second,xi[i].first);
        }

        while(i>=qu[j].l&&j<qu.size()){
            ans[qu[j].i] = rmq(0,0,n,qu[j].x,qu[j].y);
            printf("SET ANS %d %d : %d %d\n",ans[qu[j].i].first,ans[qu[j].i].second,qu[j].x,qu[j].y);
            j++;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&x[i]);
        //tp.push_back(x[i]);
        xi[i] = {x[i],i};
        qs[i+1] = qs[i]+x[i];
    }
    std::sort(xi,xi+n);
    /*std::sort(tp.begin(),tp.end());
    tp.resize(std::distance(tp.begin(),std::unique(tp.begin(),tp.end())));*/
    inti_seg(0,0,n);
    for(i = 0; i < m; i++){
        scanf("%d %d %lf",&s[i],&t[i],&u[i]);
        s[i]--;
        t[i]--;
        bsX[i] = 0;
        bsY[i] = n-1;
    }
    while(1){
        //qurry
        qu.clear();
        for(i = 0; i < m; i++){
            if(bsX[i]<=bsY[i]){
                mid = (bsX[i]+bsY[i])/2;
                qu.push_back(qur(s[i],t[i],mid,i));
            }
        }
        printf("LOOP\n");
        if(qu.size()==0) break;
        do_querry();
        for(i = 0; i < m; i++){
            if(bsX[i]<=bsY[i]){
                avg = ((double)(qs[t[i]+1]-qs[s[i]]-ans[i].second))/(t[i]-s[i]+1-ans[i].first);
                mid = (bsX[i]+bsY[i])/2;
                printf("ANS %d : %d %d : %f %f (%d) : qs = %d\n",i,ans[i].first,ans[i].second,avg,u[i],mid,qs[t[i]+1]-qs[s[i]]);
                if(avg<u[i]){
                    bsX[i] = mid+1;
                }else{
                    bsY[i] = mid-1;
                }
            }
        }
    }
    for(i = 0; i < m; i++){
        printf("%d\n",bsY[i]);
    }
}
