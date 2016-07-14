#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int xx[60];
int yy[60];
int x[6000];
int max = -1;
int n,l;

int main()
{
	int i,j,t,sum = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&l);
		max = -1;
		memset(x,-1,sizeof(x));
		l -= n+1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&xx[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&yy[i]);
			sum += yy[i];
		}
		x[0] = 0;
		for(i=0;i<n;i++)
		{
			for(j=l;j>=yy[i];j--)
			{
				if(x[j-yy[i]] != -1 && x[j] < x[j-yy[i]]+xx[i])
				{
					x[j] = x[j-yy[i]]+xx[i];
				}
			}
		}
		for(i=0;i<=l;i++)
		{
			max = mx(max,x[i]);
		}
		printf("%d\n",max);
	}
	return 0;
}