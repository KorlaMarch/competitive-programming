#include "stdio.h"
#include "stack"

int main(){
    bool part[101][41] = {};
    int m,n,t,i,j,d,p;
    std::stack<char> s;
    scanf("%d%d%d", &m, &n, &t);
    part[0][n-1] = true;
    if(n-2 >= 0) part[0][n-2] = true;
    if(n < m) part[0][n] = true;
    for(i = 0; i < t; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &d);
            if(!d && i > 0 && ((j > 0 && part[i-1][j-1]) || part[i-1][j] || (j+1 < m && part[i-1][j+1]))){
                part[i][j] = true;
            }
        }
    }

    for(i = 0; i < m; i++){
        if(part[t-1][i]){
            break;
        }
    }
    p = i;
    for(i = t-1; i > 0; i--){
        if(j > 0 && part[i-1][p-1]){
            s.push('2');
            p--;
        }else if(part[i-1][p]){
            s.push('3');
        }else if(p+1 < m && part[i-1][p+1]){
            s.push('1');
            p++;
        }
    }
    if(p == n-2){
        s.push('1');
        p--;
    }else if(p == n-1){
        s.push('3');
    }else if(p == n){
        s.push('2');
        p++;
    }
    while(!s.empty()){
        printf("%c\n",s.top());
        s.pop();
    }
}
