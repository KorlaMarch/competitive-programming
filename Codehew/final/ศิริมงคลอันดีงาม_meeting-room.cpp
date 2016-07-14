#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int x[100];

int main()
{
    int i,j,n,t,s,e,mx;
    scanf("%d",&t);
    while(t--)
    {
        mx = -1;
        scanf("%d",&n);
        memset(x,0,sizeof(x));
        while(n--)
        {
            scanf("%d %d",&s,&e);
            x[s]++;
            x[e+1]--;
        }

        for(i=1;i<=50;i++)
            x[i]+=x[i-1];
        for(i=1;i<=50;i++)
        {
            if(mx < x[i])
                mx = x[i];
        }
        printf("%d\n",mx);
    }
    return 0;
}
