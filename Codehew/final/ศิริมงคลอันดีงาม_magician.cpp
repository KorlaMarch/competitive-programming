#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char x[15000];
char tmp[15000];
int mic[2][15000];

int main()
{
    int i,j,t,n,mx;
    scanf("%d\n",&t);
    while(t--)
    {
        mx = -1;
        i=1;
        while(1)
        {
            x[i] = getchar();
            if(x[i] >= 'A' && x[i] <= 'Z')
                x[i] += 0x20;
            if(i >= 12 && strncmp(x+i-12,"finem libri.",12) == 0)
            {
                break;
            }
            i++;
        }
        x[i] = '\0';
        n = i;
        for(i = 1;i<n;i++)
        {
            memset(mic[i%2],0,sizeof(mic[i%2]));
            for(j=1;j<n;j++)
            {
                if(i == j)
                    mic[i%2][j] = 0;
                else if(x[i] == x[j] && (mic[(i+1)%2][j-1] != 0||(x[i]!=' '&&x[i]!='\n')))
                    mic[i%2][j] = mic[(i+1)%2][j-1] + 1;
                else mic[i%2][j] = 0;
                if(x[i] != ' ' && x[i] != '\n')
                    mx = max(mx,mic[i%2][j]);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
