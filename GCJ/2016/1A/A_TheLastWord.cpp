#include "stdio.h"
#include "deque"

int t,i,k;
char s[1005];
std::deque<char> qu;

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf(" %s",s);
        qu.push_back(s[0]);
        for(i = 1; s[i]; i++){
            if(s[i]>=qu.front()) qu.push_front(s[i]);
            else qu.push_back(s[i]);
        }
        printf("Case #%d: ",k);
        while(!qu.empty()){
            putchar(qu.front());
            qu.pop_front();
        }
        putchar('\n');
    }
}
