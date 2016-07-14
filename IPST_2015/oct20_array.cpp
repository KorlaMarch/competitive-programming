#include "stdio.h"
#include "algorithm"
#define INF 2000000000
int n,q,i,j,ptr;
char c[100001];
int a[100001],b[100001],v[100001],ep[200002];
int segment[1000001],lazy[1000001];
bool intersect(int a, int b, int x, int y){
    return (x<=a&&a<=y)||(x<=b&&b<=y)||(a<=x&&x<=b)||(a<=y&&y<=b);
}

void lazy_ins(int p, int i, int j, int x, int y, int v){
    //printf("INS %d %d %d : %d %d : %d\n",p,i,j,x,y,v);
    printf("\tINS %d %d %d : %d %d : %d\n",p,ep[i],ep[j],ep[x],ep[y],v);
    if(x<=i&&j<=y){
        lazy[p] = v;
    }else{
        if(i+1!=j){
            if(lazy[p]!=INF){
                lazy[p*2+1] = lazy[p*2+2]= lazy[p];
                lazy[p] = INF;
            }
            if(intersect(i,i+(j-i)/2,x,y)) lazy_ins(p*2+1,i,i+(j-i)/2,x,y,v);
            if(intersect(i+(j-i)/2,j,x,y)) lazy_ins(p*2+2,i+(j-i)/2,j,x,y,v);
        }
    }
}

long long lazy_get(int p, int i, int j, int x, int y){
    long long sum = 0;
    printf("GET %d -> %d %d(%d %d): %d %d(%d %d) == %d\n",p,i,j,ep[i],ep[j],x,y,ep[x],ep[y],lazy[p]);
    if(x<=i&&j<=y){
        if(lazy[p]!=INF){
            printf("return %lld\n",lazy[p]*(long long)(ep[j]-ep[i]+1));
            return lazy[p]*(long long)(ep[j]-ep[i]+1);
        }else{
            sum += lazy_get(p*2+1,i,i+(j-i)/2,x,y);
            sum += lazy_get(p*2+2,i+(j-i)/2,j,x,y);
        }
    }else{
        if(i+1!=j){
            if(lazy[p]!=INF){
                //lazy[p*2+1] = lazy[p*2+2]= lazy[p];
                //lazy[p] = INF;
                printf("return2 %d %d %d : %lld\n",std::max(ep[i],ep[x]),std::min(ep[j],ep[y]),
                       lazy[p],lazy[p]*(long long)(std::min(ep[j],ep[y])-std::max(ep[i],ep[x])+1));
                return lazy[p]*(long long)(std::min(ep[j],ep[y])-std::max(ep[i],ep[x])+1);
            }
            if(intersect(i,i+(j-i)/2,x,y)) sum += lazy_get(p*2+1,i,i+(j-i)/2,x,y);
            if(intersect(i+(j-i)/2+1,j,x,y)) sum += lazy_get(p*2+2,i+(j-i)/2,j,x,y);
        }
    }
    return sum;
}

int main(){
    scanf("%d%d",&n,&q);

    for(i = 0; i < q; i++){
        scanf("%d%d%d",c+i,a+i,b+i);
        if(c[i]==0){
            scanf("%d",v+i);
        }
        b[i]--;
        ep[ptr++] = a[i];
        //ep[ptr++] = a[i]-1;
        ep[ptr++] = b[i];
        //ep[ptr++] = b[i]-1;
    }
    //ep[ptr++] = n;
    std::sort(ep,ep+ptr);
    ptr = std::unique(ep,ep+ptr)-ep;
    for(i = 0; i < ptr; i++){
        printf("ep = %d\n",ep[i]);
    }
    for(i = 0; i <= 2*ptr+1; i++){
        lazy[i] = INF;
    }
    for(i = 0; i < q; i++){
        if(c[i]==0){
            lazy_ins(0,0,ptr-1,std::lower_bound(ep,ep+ptr,a[i])-ep,std::lower_bound(ep,ep+ptr,b[i])-ep,v[i]);
        }else{
            printf("%lld\n",lazy_get(0,0,ptr-1,std::lower_bound(ep,ep+ptr,a[i])-ep,std::lower_bound(ep,ep+ptr,b[i])-ep));
        }
    }
}
