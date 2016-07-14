#include <stdio.h>

int main(){
    int num[1000];
    int s, t;
    int n, x, y;
    int max = 0;
    int count = 0;
    scanf("%d", &n);
    for(x = 0; x < n; x++){
        scanf("%d", &num[x]);
    }
    scanf("%d", &t);

    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){
            if(x != y && num[x] + num[y] <= t){
                if(t - (num[x] + num[y]) < t - max){
                    max = num[x] + num[y];
                    count = 1;
                }else if(num[x] + num[y] == max){
                    count++;
                }
            }
        }
    }

    printf("%d\n%d\n", max, count / 2);
    return 0;
}
