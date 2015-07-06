#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1005][1005];
int main()
{
    int n,i,j,k,m,ans[3][1005],num,l1,l2;
    char x[1005],y[1005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",x,y);
        l1=strlen(x);
        l2=strlen(y);
        m=0;
        num=0;
        for(j=0;j<l1;j++)
            for(k=0;k<l2;k++)
                a[j+1][k+1]=0;
        for(j=0;j<l1;j++)
            for(k=0;k<l2;k++)
            {
                if(x[j]==y[k])
                    a[j+1][k+1]=a[j][k]+1;
                else
                    a[j+1][k+1]=max(a[j+1][k],a[j][k+1]);
                if(a[j+1][k+1]>m)
                    m=a[j+1][k+1];
            }
        printf("Case #%d\n",i+1);
        if(m<=0)
            printf("N\n");
        else
        {
            printf("Y\n%d\n",m);
            for(j=l1,k=l2;j>=0&&k>=0;)
                if(a[j][k]==a[j-1][k-1]+1&&a[j][k]>a[j-1][k]&&a[j][k]>a[j][k-1])
                {
                    ans[0][num]=x[j-1];
                    ans[1][num]=j;
                    ans[2][num++]=k;
                    j--;
                    k--;
                }
                else if(a[j-1][k]==a[j][k])
                    j--;
                else
                    k--;
            for(j=num-1;j>=0;j--)
                printf("%c %d %d\n",ans[0][j],ans[1][j],ans[2][j]);
        }
    }
}
