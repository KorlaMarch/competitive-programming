#include "stdio.h"
int n,i,j;
int pb[20][20];
char isJ[20];

double getUB(int d, double tp){
    int i,j,m;
    double ub = tp;
    /*for(i = 0; i < n; i++) printf("%d ", isJ[i]);
    printf("\n");*/
    for(i = d; i < n; i++){
        for(j = m = 0; j < n; j++){
            //printf("\t\t\tCK %d %d\n", j,pb[d][j]);
            if(!isJ[j] && pb[i][j]>m) m = pb[i][j];
        }
        //printf("\t\tUB ADD %f\n", m/100.0);
        ub *= m/100.0;
    }
    return ub;
}

double bound(int d, double topP){
    int i,j,mp;
    double ub[20] = {},mb=0.0,t;
    //printf("Node %d %lf\n", d, topP);
    if(d >= n) return topP;
    for(i = 0; i < n; i++){
        if(!isJ[i]){
            isJ[i]=1;
            ub[i] = getUB(d+1,topP)*(pb[d][i]/100.0);
            //printf("\tFind UB %d %f\n", i, ub[i]);
            isJ[i]=0;
        }
    }
    while(1){
        for(j = 0,mp = -1; j < n; j++){
            if(!isJ[j]&&(ub[j]>ub[mp]||mp==-1)&&ub[j]>mb) mp = j;
        }
        if(mp==-1) break;
        isJ[mp] = 1;
        t = bound(d+1,topP*(pb[d][mp]/100.0));
        isJ[mp] = 0;
        if(t > mb) mb = t;
        ub[mp] = 0;
    }
    return mb;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &pb[i][j]);
        }
    }
    printf("%lf\n", bound(0,1.0)*100.0);
}
