#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"

struct oper{
    int i,j,d;
    oper(int _i = 0, int _j = 0, int _d = 0) : i(_i), j(_j), d(_d) {}
};

int n,m,v,i,j,x,y,o;
int a[305],b[305],p[305],oa[305];
int usa[305],usb[305];
std::vector<int> edge[305];
std::vector<oper> op;
int deg[305];
std::queue<int> qu;

bool canM;
int unionF(int x){
    return p[x]==x?x:(p[x]=unionF(p[x]));
}

void importP(int x, int o){
    int lm;
    for(int i = 0; i < edge[x].size() && a[x] < v; i++){
        if(edge[x][i]!=o&&deg[edge[x][i]]>0){
            importP(edge[x][i],x);
        }
    }
    if(o!=-1){
        lm = std::min(a[x],v-a[o]);
        a[o] += lm;
        a[x] -= lm;
        op.push_back({x,o,lm});
    }
}

int calCap(int x, int o){
    int sum = v-a[x];
    for(int i : edge[x]){
        if(i!=o&&deg[i]>0){
            sum += calCap(i,x);
        }
    }
    return sum;
}

void exportP(int x, int o){
    int lm;
    for(int i = 0; i < edge[x].size() && a[x] > v; i++){
        if(edge[x][i]!=o&&deg[edge[x][i]]>0){
            lm = std::min(a[x]-v,calCap(edge[x][i],x));
            a[x] -= lm;
            a[edge[x][i]] += lm;
            exportP(edge[x][i],x);
            op.push_back({x,edge[x][i],lm});
        }
    }
}

bool check(){
    for(oper t : op){
        oa[t.i] -= t.d;
        oa[t.j] += t.d;
        //if(oa[t.i]<0||oa[t.j]>v) return false;
    }
    for(int i = 0; i < n; i++){
        if(oa[i]!=b[i]){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d%d%d",&n,&m,&v);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
        p[i] = i;
        oa[i] = a[i];
    }
    for(i = 0; i < n; i++){
        scanf("%d",&b[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&x,&y);
        if(unionF(y)!=unionF(x)){
            edge[x].push_back(y);
            edge[y].push_back(x);
            deg[x]++;
            deg[y]++;
            p[unionF(y)] = unionF(x);
        }
    }
    for(i = 0; i < n; i++){
        usa[unionF(i)] += a[i];
        usb[unionF(i)] += b[i];
    }

    canM = true;
    for(i = 0; i < n; i++){
        if(usa[i]!=usb[i]){
            canM = false;
            break;
        }
    }
    if(canM){
        for(i = 0; i < n; i++){
            if(deg[i]==1){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            x = qu.front();
            qu.pop();
            //printf("RUN %d %d\n",x,op.size());
            deg[x] = 0;
            o = -1;
            for(int j : edge[x]){
                if(deg[j]!=0){
                    o = j;
                    break;
                }
            }
            if(a[x]==b[x]){
                if(o!=-1){
                    deg[o]--;
                    if(deg[o]<=1) qu.push(o);
                }
                continue;
            }
            //find o
            if(a[x]<b[x]){
                //import
                importP(o,-1);
                a[o] -= b[x]-a[x];
                op.push_back({o,x,b[x]-a[x]});
                a[x] = b[x];
            }else{
                //export
                y = a[x]-b[x];
                a[o] += y;
                a[x] = b[x];
                exportP(o,-1);
                op.push_back({x,o,y});
            }
            deg[o]--;
            if(deg[o]<=1) qu.push(o);
        }
        /*for(i = 0; i < n; i++){
            if(a[i]!=b[i]&&deg[i]<=0) while(1);
        }*/
        printf("%d\n",op.size());
        for(oper t : op){
            printf("%d %d %d\n",t.i,t.j,t.d);
        }
        //if(!check()) while(1);
    }else printf("NO\n");
}
