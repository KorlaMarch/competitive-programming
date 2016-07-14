#include "stdio.h"
#include "algorithm"
#include "vector"

int n,i,j,p;
long long maxW,dp;
double in;
std::pair<int,int> l[50005];
std::vector<std::pair<long,long> > l2;
std::vector<long long> lineM;
std::vector<long long > lineB;
std::vector<double> inter;

double intersert(long long m1, long long b1, long long m2, long long b2){
    return (b2-b1)/(double)(m1-m2);
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%lld%lld",&l[i].first,&l[i].second);
    }
    std::sort(l,l+n);
    for(i = n-1; i >= 0; i--){
        if(l[i].second>maxW){
            maxW = l[i].second;
            l2.push_back(l[i]);
        }
    }
    lineM.push_back(l2[l2.size()-1].second);
    lineB.push_back(0);
    inter.push_back(0);
    for(i = l2.size()-1; i >= 0; i--){
        p = std::lower_bound(inter.begin(),inter.end(),l2[i].first)-inter.begin()-1;
        dp = lineB[p]+lineM[p]*l2[i].first;
        //printf("%d %d\n",p,dp);
        if(i){
            while(lineM.size()>=2&&intersert(l2[i-1].second,dp,lineM[lineM.size()-2],lineB[lineB.size()-2])<*inter.rbegin()){
                inter.pop_back();
                lineB.pop_back();
                lineM.pop_back();
            }
            inter.push_back(intersert(l2[i-1].second,dp,*lineM.rbegin(),*lineB.rbegin()));
            lineM.push_back(l2[i-1].second);
            lineB.push_back(dp);
        }
    }
    printf("%lld\n",dp);
}
