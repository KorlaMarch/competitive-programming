#include "stdio.h"
#include "set"

int n,l,h,i,j,a,p,x,y;
double d;
std::multiset<int> mush;
int main(){
    scanf("%d%d%d",&n,&l,&h);
    for(i = 0; i < n; i++){
        scanf("%d",&a);
        for(j = 0; j < a; j++){
            scanf("%d",&p);
            mush.insert(p);
        }
        scanf("%d%d",&x,&y);
        d = l+((double)x)/y*h;
        while(!mush.empty()&&*(--mush.end())>=d){
            mush.erase(--mush.end());
        }
        printf("%d\n",mush.size());
    }
}
