#include<stdio.h>
int main()
{
    long long n,i,j,x;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        printf("Case #%lld\n",i+1);
        if(x<=0)
            printf("0\n");
        else
        {
            if(x%2)
                x++;
            x/=2;
            printf("%lld\n",x*(x-1)/2);
        }
    }
}
