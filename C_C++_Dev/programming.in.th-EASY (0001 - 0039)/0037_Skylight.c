#include <stdio.h>
#include <math.h>

int main(){
    int n, m, lightCost = 0, l, k, c, totalCost;
    int x, y, temp;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &l, &k);
    scanf("%d", &c);
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            scanf("%d", &temp);
            lightCost += temp;
        }
    }
    totalCost = lightCost + (l*k*c);
    printf("%d", (int)ceil((float)totalCost/c));

}
