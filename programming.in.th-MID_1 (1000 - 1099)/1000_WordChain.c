#include <stdio.h>
#include <string.h>

int main(){
    int l, n, x;
    int y;
    int diffWord = 0;

    scanf("%d%d", &l, &n);
    char beforeS[1001];
    char s[1001];

    scanf("%s", &beforeS);
    for(x = 1; x < n; x++){
        scanf("%s", &s);
        for(y = 0; y < l; y++){
            if(s[y] != beforeS[y]){
                diffWord++;
            }
        }
        if(diffWord > 2){
            break;
        }else{
            diffWord = 0;
        }
        strcpy(beforeS, s);
    }

    printf("%s", beforeS);
    return 0;

}
