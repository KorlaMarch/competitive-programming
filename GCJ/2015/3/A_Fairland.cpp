#include "stdio.h"
#include "algorithm"
#include "vector"

struct employ{
    int m,s,i;
    employ(int _s = 0, int _m = 0, int _i = 0) : m(_m), s(_s), i(_i) {}
};

bool cmp(employ a, employ b){
    return a.s<b.s;
}

int t,k,as,cs,rs,am,cm,rm,n,d,mn;

employ sm[1000005];
std::vector<int> child[1000005];
bool isU[1000005];
int minC[1000005];
int le[2][1000005];

int countC(int x, bool vis){
    int sum = 1;
    if(isU[x]==vis){
        return 0;
    }
    isU[x] = vis;
    for(int t : child[x]){
        sum += countC(t,vis);
    }
    return sum;
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d",&n,&d);
        scanf("%d%d%d%d",&sm[0].s,&as,&cs,&rs);
        scanf("%d%d%d%d",&sm[0].m,&am,&cm,&rm);
        sm[0].i = 0;
        for(int i = 1; i < n; i++){
            child[i].clear();
            sm[i].s = (sm[i-1].s*(long long)as+cs)%rs;
            sm[i].m = (sm[i-1].m*(long long)am+cm)%rm;
            sm[i].i = i;
            isU[i] = false;
        }
        sm[0].m = -1;
        for(int i = 1; i < n; i++){
            sm[i].m %= i;
            printf("SM %d = %d %d\n",i,sm[i].s,sm[i].m);
        }
        child[0].clear();
        isU[0] = false;
        mn = 1000000000;
        std::sort(sm,sm+n,cmp);
        for(int i = 0; i < n; i++){
            if(sm[i].m!=-1) child[sm[i].m].push_back(sm[i].i);
        }
        le[0][0] = countC(sm[0].i,true);
        for(int i = 1; i < n; i++){
            le[0][i] = le[0][i-1]+countC(sm[i].i,true);
            printf("LE 0 %d ID %d : %d\n",i,sm[i].i,le[0][i]);
        }
        le[1][n] = 0;
        for(int i = n-1; i >= 0; i--){
            le[1][i] = le[1][i+1]+countC(sm[i].i,false);
            printf("LE 1 %d ID %d : %d\n",i,sm[i].i,le[1][i]);
        }

        int j = 1;
        for(int j = 1; j < n && sm[j].s-sm[0].s<=d; j++);
        mn = le[1][j];
        printf("MN:%d\n",mn);
        for(int i = 0; i < n; i++){
            while(j<n && sm[j].s-sm[i+1].s<=d) j++;
            printf("%d %d = %d(%d %d)\n",sm[i+1].i,sm[j-1].i,le[0][i]+le[1][j],le[0][i],le[1][j]);
            if(le[0][i]+le[1][j]<mn) mn = le[0][i]+le[1][j];
        }

        printf("Case #%d: %d\n",k,n-mn);
    }
}
