#include "stdio.h"
#include "vector"
#include "array"
int t,k,j,p,s,i,x,y,z,mx;
std::vector<std::array<int,3>> pl;
std::array<int,3> ar;
bool isSe[30];
bool mxSe[30];

bool check(int d){
    int i,in;
    int feq1[10],feq2[10],feq3[10];
    for(i = 0; i < 10; i++){
        feq1[i] = feq2[i] = feq3[i] = 0;
    }
    for(i = 0; i < d; i++){
        if(isSe[i]){
            in = (pl[i][0]-1)+3*(pl[i][1]-1);
            feq1[in]++;
            if(feq1[in]>k) return false;
            in = (pl[i][0]-1)+3*(pl[i][2]-1);
            feq2[in]++;
            if(feq2[in]>k) return false;
            in = (pl[i][1]-1)+3*(pl[i][2]-1);
            feq3[in]++;
            if(feq3[in]>k) return false;
        }
    }
    return true;
}

void findMax(int d, int c){
    int i;
    if(d==pl.size()){
        if(c>mx&&check(d)){
            for(i = 0; i < d; i++){
                mxSe[i] = isSe[i];
            }
            mx = c;
        }
    }else{
        isSe[d] = true;
        findMax(d+1,c+1);
        isSe[d] = false;
        findMax(d+1,c);
    }
}

int main(){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        mx = -1;
        scanf("%d%d%d%d",&j,&p,&s,&k);
        pl.clear();
        for(x = 1; x <= j; x++){
            for(y = 1; y <= p; y++){
                for(z = 1; z <= s; z++){
                    ar[0] = x;
                    ar[1] = y;
                    ar[2] = z;
                    pl.push_back(ar);
                }
            }
        }
        findMax(0,0);
        printf("Case #%d: %d\n",i,mx);
        for(x = 0; x < pl.size(); x++){
            if(mxSe[x]){
                printf("%d %d %d\n",pl[x][0],pl[x][1],pl[x][2]);
            }
        }
    }
}
