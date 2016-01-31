#include "stdio.h"
#include "queue"

int n,i,x;
std::queue<int> bw;
char s[100005];
char op;
int main(){
    scanf("%d %s",&n,s);
    for(i = 0; i < n; i++){
        if(s[i]!='X') bw.push(i);
    }
    if(bw.empty()){
        s[0] = 'B';
        bw.push(0);
    }
    while(!bw.empty()){
        x = bw.front();
        bw.pop();
        if(s[x]=='B') op = 'W';
        else op = 'B';
        if(x&&s[x-1]=='X'){
            if(x-1&&s[x-2]==op) s[x-1] = 'G';
            else{
                s[x-1] = op;
                bw.push(x-1);
            }
        }
        if(x+1<n&&s[x+1]=='X'){
            if(x+2<n&&s[x+2]==op) s[x+1] = 'G';
            else{
                s[x+1] = op;
                bw.push(x+1);
            }
        }
    }
    printf("%s\n",s);
}
