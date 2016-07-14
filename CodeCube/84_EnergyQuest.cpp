#include "stdio.h"
#include "list"
typedef struct{
    int b,w;
}path;
path getPa(int b, int w){
    path tmp;
    tmp.b = b;
    tmp.w = w;
    return tmp;
}
int n,i,j,a,b,w,s,t,r,z;
long long int sumP,v;
std::list<path> paths[100001];
int p[100005];
int way[200005];
char isV[100005];

int findW(int a, int b, int d, int o){
    way[d] = a;
    if(a==b){
        z = d;
        isV[a] = 1;
        return 1;
    }else{
        for(std::list<path>::iterator it = paths[a].begin(); it != paths[a].end(); ++it){
            if(it->b != o){
                if(findW(it->b,b,d+1,a)){
                    isV[a] = 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}
long long int checkV(int a, int o){
    long long int v = p[a],t;
    for(std::list<path>::iterator it = paths[a].begin(); it != paths[a].end(); ++it){
        if(it->b != o){
            t = checkV(it->b,a)-(it->w)*2;
            if(t>0) v+=t;
        }
    }
    return v;
}
int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&a,&b,&w);
        paths[a].push_back(getPa(b,w));
        paths[b].push_back(getPa(a,w));
    }
    for(i = 1; i <= n; i++){
        scanf("%d",p+i);
    }
    scanf("%d%d%d",&s,&t,&r);
    findW(s,r,0,0);
    findW(r,t,z,0);
    /*for(i = 0; i <= z; i++) printf("%d ",way[i]);
    printf("\n");*/
    for(i = 0; i <= z; i++){
        //printf("%d :%d ",way[i],p[way[i]]);
        sumP += p[way[i]];
        p[way[i]] = 0;
        for(std::list<path>::iterator it = paths[way[i]].begin(); it != paths[way[i]].end(); ++it){
            if(i<z&&it->b == way[i+1]){
                sumP -= it->w;
                //printf("%d\n",it->w);
            }else if(!isV[it->b]){
                v = checkV(it->b,way[i])-(it->w)*2;
                //printf("CH V = %d %d : %d\n",way[i],it->b,v);
                if(v>0) sumP += v;
                isV[it->b] = 1;
            }
        }
    }
    printf("%lld\n",sumP);
}
