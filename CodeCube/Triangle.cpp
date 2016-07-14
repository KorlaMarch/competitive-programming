#include "stdio.h"
#include "vector"
#include "algorithm"

int t,i,j,s,m,n,a,b,c,x;
std::vector<std::pair<int,int> > ans;
bool isCoP(int a, int b){
    int t;
    while(b!=1){
        t = a%b;
        a = b;
        b = t;
    }
    return a==1;
}

int main(){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d",&s);
        ans.clear();
        printf("Case #%d:\n",i);
        for(m = 1; 2*m*m<s; m++){
            for(n = m-1; n > 0; n--){
                a = m*m-n*n;
                b = 2*m*n;
                c = m*m+n*n;
                if(s%(a+b+c)==0){
                    x = s/(a+b+c);
                    //printf("%d %d %d\n",a*x,b*x,c*x);
                    if(a<b) ans.push_back({a*x,b*x});
                    else ans.push_back({b*x,a*x});
                }
            }
        }
        if(ans.size()==0) printf("-1\n");
        else{
            std::sort(ans.begin(),ans.end());
            ans.resize(std::unique(ans.begin(),ans.end())-ans.begin());
            for(auto x : ans){
                printf("%d %d %d\n",x.first,x.second,s-x.first-x.second);
            }
        }
    }
}
