#include <stdio.h>
#include <string.h>

using namespace std;

int x[3110][3110];

int main()
{
    int t,r,c,cnt,n;
    int i,j,k,l,ii,jj,li,lj,ri,rj;
    scanf("%d",&t);
    while(t--)
    {
        cnt = 0;
        memset(x,0,sizeof(x));
        scanf("%d %d %d",&n,&c,&r);
        while(n--)
        {
            scanf("%d %d",&j,&i);
            x[i+1][j+1]++;
        }
        for(i=1;i<=2100;i++)
        {
            for(j=1;j<=2100;j++)
            {
                x[i][j] += x[i-1][j] + x[i][j-1] - x[i-1][j-1];
            }
        }
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d %d %d",&li,&lj,&ii,&jj);
                li++,k = li+(ii-1),l = lj+1;
                lj = l-(jj-1);
                if(lj < 0)
                    lj = 0;
                cnt += x[l][k] - x[lj-1][k] - x[l][li-1] + x[lj-1][li-1];
        }
        printf("%d\n",cnt);
    }
    return 0;
}
