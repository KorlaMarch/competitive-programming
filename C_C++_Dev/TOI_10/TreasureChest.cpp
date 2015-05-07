#include "stdio.h"
#include "algorithm"
typedef struct{
    int x,y;
}pos;
bool cmp(pos a,pos b){
    return a.x<b.x?true:false;
}
int n,m,i,j,x,t,s,z;
long long int cj,f;
pos cp[400000];
//fac 0:2 1:3 2:5 3:7
int fac[4];

void chFac(int x){
    switch(x){
        //add
        case 8: fac[0]++;
        case 4: fac[0]++;
        case 2: fac[0]++; break;
        case 9: fac[1]++;
        case 3: fac[1]++; break;
        case 10: fac[0]++;
        case 5: fac[2]++; break;
        case 7: fac[3]++; break;
        case 6: fac[0]++; fac[1]++; break;
        //delete
        case -8: fac[0]--;
        case -4: fac[0]--;
        case -2: fac[0]--; break;
        case -9: fac[1]--;
        case -3: fac[1]--; break;
        case -10: fac[0]--;
        case -5: fac[2]--; break;
        case -7: fac[3]--; break;
        case -6: fac[0]--; fac[1]--; break;
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        scanf("%d %d %d",&x,&s,&t);
        cp[i].x = s;
        cp[i].y = x;
        cp[m+i].x = t+1;
        cp[m+i].y = x*-1;
    }
    m *= 2;
    std::sort(cp,cp+m,cmp);
    for(i = 0,cj=1,z=cp[0].x; i < m;){
        chFac(cp[i].y);
        for(i++;i<m&&cp[i-1].x==cp[i].x;i++) chFac(cp[i].y);
        f = ((long long int)fac[0]+1)*(fac[1]+1)*(fac[2]+1)*(fac[3]+1);
        if(f>cj){
            cj = f;
            if(i==m) z = n-cp[i-1].x;
            else z = cp[i].x-cp[i-1].x;
        }else if(f==cj){
            if(i==m) z += n-cp[i-1].x;
            else z += cp[i].x-cp[i-1].x;
        }
    }
    printf("%lld %d\n",cj,z);
}
