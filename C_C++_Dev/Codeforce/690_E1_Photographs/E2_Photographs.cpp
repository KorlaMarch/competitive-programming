#include "stdio.h"
#include "queue"
#include "vector"

struct edge{
    double con;
    int a,b;
    edge(int _a = 0, int _b = 0, double _con = 0.0) : a(_a),b(_b),con(_con) {}
    bool operator()(edge a, edge b){
        return a.con > b.con;
    }
};

double abs(double n){
    return n<0?-n:n;
}

double sq(double n){
    return n*n;
}

int q,h,w,k,i,j,t;
int a[605][605];
double na[605][605],nb[605][605];
int prev[20],next[20];
int p[20];
int pos[20];
std::priority_queue<edge,std::vector<edge>,edge> qu;

int unionF(int x){
    return p[x]==x?x:(p[x]=unionF(p[x]));
}

double findContrast(int x, int y){
    double sum = 0;
    for(int i = 0; i < w; i++){
        sum += sq(abs(na[x][i]-na[y][i]));
        /*if(i) sum += sq(abs(na[x][i]-na[y][i-1]));
        if(i+1<w) sum += sq(abs(na[x][i]-na[y][i+1]));*/
    }
    return sum;
}

void printK(int x, int d){
    pos[x] = d;
    if(next[x]!=-1){
        printK(next[x],d+1);
    }
}

void smooth(double so[605][605],double dis[605][605]){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int co = 1;
            dis[i][j] = so[i][j];
            if(i>0&&i!=h/k) dis[i][j] += so[i-1][j],co++;
            if(i+1<h&&i+1!=h/k) dis[i][j] += so[i+1][j],co++;
            if(j>0){
                dis[i][j] += dis[i][j-1]; co++;
                if(i>0&&i!=h/k) dis[i][j] += so[i-1][j-1],co++;
                if(i+1<h&&i+1!=h/k) dis[i][j] += so[i+1][j-1],co++;
            }
            if(j+1<w){
                dis[i][j+1] += dis[i][j+1]; co++;
                if(i>0&&i!=h/k) dis[i][j] += so[i-1][j+1],co++;
                if(i+1<h&&i+1!=h/k) dis[i][j] += so[i+1][j+1],co++;
            }
            dis[i][j] /= co;
        }
    }
}

int main(){
    scanf("%d",&q);
    for(t = 0; t < q; t++){
        scanf("%d%d%d",&h,&w,&k);
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                scanf("%d",&a[i][j]);
                na[i][j] = (double)a[i][j];
            }
        }
        //try to smooth pic
        smooth(na,nb);
        smooth(nb,na);
        //find contrast between price
        for(i = 0; i < k; i++){
            next[i] = prev[i] = -1;
            p[i] = i;
            for(j = 0; j < k; j++){
                if(i!=j){
                    qu.push(edge(i,j,findContrast((i+1)*(h/k)-1,j*(h/k))));
                }
            }
        }
        edge tmp;
        while(!qu.empty()){
            tmp = qu.top();
            qu.pop();
            if(next[tmp.a]==-1&&prev[tmp.b]==-1&&unionF(tmp.b)!=unionF(tmp.a)){
                //printf("get con : %.4f\n",tmp.con);
                next[tmp.a] = tmp.b;
                prev[tmp.b] = tmp.a;
                p[unionF(tmp.b)] = unionF(tmp.a);
                //printf("NX %d = %d PV %d = %d\n",tmp.a,tmp.b,tmp.b,tmp.a);
            }
        }
        for(i = 0; i < k; i++){
            if(prev[i]==-1){
                printK(i,0);
                break;
            }
        }
        for(i = 0; i < k; i++){
            printf("%d ",pos[i]+1);
        }
        printf("\n");
    }
}
