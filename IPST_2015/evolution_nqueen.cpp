#include "stdio.h"
#include "vector"
#include "array"
#include "time.h"
#include "stdlib.h"
#include "algorithm"

#define N 300

std::vector<std::pair<int,std::array<int,N> > > genotypes;

std::array<int,N> randomSuff(){
    std::array<int,N> a;
    bool isR[N];
    int i,j,r;
    for(i = 0; i < N; i++){
        isR[i] = false;
    }
    for(i = 0; i < N; i++){
        while(isR[r=rand()%N]);
        isR[r] = true;
        a[i] = r;
    }
    return a;
}

int checkFit(std::array<int,N>& a){
    int fit,i;
    int di[2][4*N];
    fit = 0;
    for(i = 0; i < 4*N; i++){
        di[0][i] = di[1][i] = 0;
    }
    for(i = 0; i < N; i++){
        fit += di[0][a[i]-i+2*N]++;
        fit += di[1][a[i]+i]++;
    }
    return fit;
}

bool cmp(std::pair<int,std::array<int,N> > a, std::pair<int,std::array<int,N> > b){
    return a.first<b.first;
}

int main(){
    int i,j,k,cp;
    int ranA[6];
    bool isV[N];
    clock_t ct;
    std::pair<int,std::array<int,N> > par[5];
    std::array<int,N> newI;
    srand(time(NULL));
    //random 100 genotype
    ct = clock();
    for(i = 0; i < 100; i++){
        newI = randomSuff();
        genotypes.push_back(std::make_pair(checkFit(newI),newI));
    }
    for(i = 0; 1; i++){
        if(i%500==0) printf("GEN %d MIN == %d\n",i,genotypes[0].first);
        while(genotypes.size() < 200){
            //select 5 parent
            for(j = 0; j < 5; j++){
                while(1){
                    ranA[j] = rand()%genotypes.size();
                    for(k = 0; k < j; k++){
                        if(ranA[k]==ranA[j]){
                            break;
                        }
                    }
                    if(k==j) break;
                }
                par[j] = genotypes[ranA[j]];
            }
            std::sort(par,par+5,cmp);
            // cross par[0] and par[1]
            cp = rand()%(N-1);
            /*for(j = 0; j < N; j++){
                printf("%d ", par[0].second[j]);
            }
            printf(":\n");*/
            for(j = 0; j < N; j++) isV[j] = false;
            for(j = 0; j <= cp; j++){
                newI[j] = par[0].second[j];
                isV[newI[j]] = true;
            }
            for(;j < N; j++){
                if(isV[newI[j] = par[1].second[j]]){
                    while(isV[newI[j]=rand()%N]);
                }
                isV[newI[j]] = true;
            }
            //mutate
            j = rand()%N;
            k = rand()%N;
            cp = newI[j];
            newI[j] = newI[k];
            newI[k] = cp;
            if(checkFit(newI)==0){
                printf("Time : %d ms\n",clock()-ct);
                for(j = 0; j < N; j++) printf("%d ",newI[j]+1);
                return 0;
            }
            //for(j = 0; j < N; j++) printf("%d ",newI[j]);
            //printf("\n");
            genotypes.push_back(std::make_pair(checkFit(newI),newI));
        }
        std::sort(genotypes.begin(),genotypes.end(),cmp);
        while(genotypes.size()>100) genotypes.pop_back();
    }
}
