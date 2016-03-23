#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

int x[100];
int check[1100];

int main()
{
	int n,t,i,j,chk,sve;
	scanf("%d",&t);
	while(t--)
	{
		memset(check,0,sizeof(check));
		scanf("%d",&n);
		chk = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			chk = mx(chk,x[i]);
			check[x[i]] = 1;
		}
		for(i=0;;i++)
		{
			if(check[i] == 1)
			{
				printf("%d",i);
				break;
			}
		}
		i++;
		for(;i<=chk;i++)
		{
			if(check[i] == 1 && check[i-1] == 0)
				printf(",%d",i);
			else if(check[i] == 1 && check[i+1] == 0 && check[i-1] == 1)
				printf("->%d",i);
		}
		printf("\n");
	}
	return 0;
}