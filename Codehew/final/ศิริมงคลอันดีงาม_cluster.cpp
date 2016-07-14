#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

struct pt
{
    int i,j;
};

int i,j,r,c,t,n;
int x[1010][1010];
int cnt,mx;

void play(int i,int j)
{
    int ii,jj;
    cnt++;
    x[i][j] = 0;
    if(x[i+1][j] && i+1 < r)
    {
        play(i+1,j);
    }
    if(i-1 >= 0 && x[i-1][j])
    {
        play(i-1,j);
    }
    if(x[i][j+1] && j+1 <c)
        play(i,j+1);
    if(j-1 >= 0 && x[i][j-1])
        play(i,j-1);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        memset(x,0,sizeof(x));
        scanf("%d",&n);
        mx = -1;
        while(n--)
        {
            scanf("%d %d",&i,&j);
            x[i][j] = 1;
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(x[i][j] == 1)
                {
                    cnt = 0;
                    play(i,j);
                    if(cnt > mx)
                        mx = cnt;
                }

            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
