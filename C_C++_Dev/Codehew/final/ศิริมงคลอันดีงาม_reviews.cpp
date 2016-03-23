#include "stdio.h"
#include "unordered_map"
#include "math.h"
using namespace std;

int i,ri,ui,r,mx;
double sd,msd;
std::unordered_map<int,int> sum;
std::unordered_map<int,int> ssum;
std::unordered_map<int,int> n;
char s[1000];
double sq(double x){
    return x*x;
}

int main(){
    gets(s);
    while(scanf("%d,%d,%d",&ri,&ui,&r) == 3){
        sum[ui] += r;
        ssum[ui] += r*r;
        n[ui]++;
        //printf("%d %d %d\n",ri,ui,r);
    }
    for(std::unordered_map<int,int>::iterator it = n.begin(); it != n.end(); ++it){
        //printf("%d %d\n",it->first,it->second);
        if(it->second>10){
            //printf("s");
            sd = sqrt((ssum[it->first]/(double)it->second)-sq(sum[it->first]/(double)it->second));
            if(sd>msd){
                msd = sd;
                mx = it->first;
            }
        }
    }
    printf("%d\n%.4f\n",mx,msd);
}
