#include "stdio.h"
#include "algorithm"
#include "queue"

int n,k,i,j;
char s[100005];
std::queue<int> ca,cb;
int mx,la,lb;
int main(){
    scanf("%d%d %s",&n,&k,s);
    mx = 0;
    la = lb = 0;
    for(i = 0; s[i]; i++){
        if(s[i]=='a'){
            cb.push(i);
            if(cb.size()>k){
                lb = cb.front()+1;
                cb.pop();
            }
        }else{
            ca.push(i);
            if(ca.size()>k){
                la = ca.front()+1;
                ca.pop();
            }
        }
        //printf("%d %d\n",i-lb+1,i-la+1);
        mx = std::max(mx,std::max(i-lb+1,i-la+1));
    }
    printf("%d\n",mx);
}
