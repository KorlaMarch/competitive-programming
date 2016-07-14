#include <string.h>
#include <stdio.h>

using namespace std;

int x[10][10];
int r,c;
long long cnt;

void play(int i,int j)
{
    int ii,jj;
    if(i == r+1)
    {
        for(ii = 1;ii<=r;ii++)
        {
            for(jj=1;jj<=c;jj++)
            {
                if(x[ii][jj] == 0)
                    break;
            }
            if(jj<=c)
                break;
        }

        if(ii == r+1)
            cnt++;

        return;
    }

    if(x[i][j])
    {
        if(j < c)
            play(i,j+1);
        else
            play(i+1,1);
        return;
    }

    if(j-1 >= 1 && x[i][j-1] == 0 && x[i][j] == 0 && i+2 <= r && x[i+1][j] == 0 && x[i+2][j] == 0)
    {
        x[i][j-1] = x[i][j] = x[i+1][j] = x[i+2][j] = 1;
        if(j < c)
            play(i,j+1);
        else
            play(i+1,1);
        x[i][j-1] = x[i][j] = x[i+1][j] = x[i+2][j] = 0;
    }
    if(i+1 <= r && j+2 <= c && x[i][j] == 0 && x[i+1][j] == 0 && x[i][j+1] == 0 && x[i][j+2] == 0)
    {
        x[i+1][j] = x[i][j] = x[i][j+1] = x[i][j+2] = 1;
        if(j < c)
            play(i,j+1);
        else
            play(i+1,1);
        x[i+1][j] = x[i][j] = x[i][j+1] = x[i][j+2] = 0;
    }
    if(i-2 >= 1 && j+1 <= c && x[i][j] == 0 && x[i-1][j] == 0 && x[i-2][j] == 0 && x[i][j+1] == 0)
    {
        x[i-1][j] = x[i-2][j] = x[i][j] = x[i][j+1] = 1;
        if(j < c)
            play(i,j+1);
        else
            play(i+1,1);
        x[i-1][j] = x[i-2][j] = x[i][j] = x[i][j+1] = 0;
    }
    if(i-1 >= 1 && j-2 >= 1 && x[i][j] == 0 && x[i-1][j] == 0 && x[i][j-1] == 0 && x[i][j-2] == 0)
    {
        x[i][j] = x[i-1][j] = x[i][j-1] = x[i][j-2] = 1;
        if(j < c)
            play(i,j+1);
        else
            play(i+1,1);
        x[i][j] = x[i-1][j] = x[i][j-1] = x[i][j-2] = 0;
    }
    if(j < c)
        play(i,j+1);
    else
        play(i+1,1);
}

int main()
{
    int i,j,t;
    long long pow;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        memset(x,0,sizeof(x));
        cnt = 0;
        if(r*c % 4 != 0)
        {
            printf("0\n");
            continue;
        }
        play(1,1);
        pow = 1;
        for(i=1;i<=(r*c)/4;i++)
            pow *= (long long)i;
        printf("%lld\n",cnt*pow);
    }
    return 0;
}
