#include "stdio.h"
#include <string.h>

using namespace std;

int t,n,i,j,tmp,chk;
char x[1050];
int main(){
    for(scanf("%d",&t); t > 0; t--){
        chk = 0;
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&tmp);
            x[i] = tmp + 'a';
        }
        for(i = 0; i < n; i++)
        {
            for(j = 1;j<n;j++)
            {
                if(strncmp(x+i,x+i+j,j) == 0)
                {
                    chk = 1;
                }
            }
        }
        if(chk)
            printf("yes\n");
        else printf("no\n");
    }
}
