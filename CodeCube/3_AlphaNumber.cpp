#include "stdio.h"
#include "algorithm"

int v,i,j;
std::pair<int,int> e[10];
int e2[10];
char num[1000500];

bool cmp(std::pair<int,int> a, std::pair<int,int> b){
    return a.first==b.first?a.second>b.second:a.first<b.first;
}

int main(){
    scanf("%d",&v);
    for(i = 0; i < 10; i++){
        scanf("%d",&e[i].first);
        e[i].second = i;
        e2[i] = e[i].first;
    }
    std::sort(e,e+10,cmp);
    if(e[0].second==0) num[0] = e[1].second+'0', v -= e[1].first;
    else num[0] = e[0].second+'0', v -= e[0].first;
    if(v<0) printf("-1\n");
    else{
        for(i = 1; v-e[0].first >= 0; i++){
            num[i] = e[0].second+'0';
            v -= e[0].first;
        }
        num[i] = '\0';
        for(i = 0; v > 0; i++){
            for(j = 9; j > 0; j--){
                if(e2[j]-e2[num[i]-'0']<=v){
                    v -= e2[j]-e2[num[i]-'0'];
                    num[i] = j+'0';
                    break;
                }
            }
            if(j<=0) break;
        }
        printf("%s\n",num);
    }
}
