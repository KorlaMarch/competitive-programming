#include<stdio.h>
#include<algorithm>

int x[2000000];

int main()
{
    int t;
    scanf("%d", &t);
    for(int _t = 1; _t <= t; _t++)
    {
        int n, m = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int a, j;
            scanf("%d", &a);
            j = 2;
            while(a != 1)
            {
                if(a % j == 0)
                {
                    a = a / j;
                    x[j]++;
                    m = std::max(m, j);
                }else j++;
            }
        }

        long long ans = 1;
        for(int k = 2; k <= m; k++)
        {
            ans *= x[k] + 1;
        }
        printf("Case #%d\n%lld\n", _t, ans);
        for(int k = 2; k <= m; k++)
        {
            x[k] = 0;
        }

    }
}
