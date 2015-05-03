#include "stdio.h"

int main(){
    int k;
    bool isMatch;
    int c_table[256][2];
    char s[2001];
    int i,j,x;
    scanf("%d ", &k);
    for(i = 0; i < k; i++){
        for(j = 'A'; j <= 'Z'; j++){
            c_table[j][0] = 0;
            c_table[j][1] = 0;
        }
        for(j = 0; j < 2; j++){
            gets(s);
            for(x = 0; s[x] != '\0'; x++){
                if(s[x] >= 'a' && s[x] <= 'z'){
                    s[x] -= 0x20;
                }
                c_table[s[x]][j]++;
            }
        }
        for(j = 'A',isMatch = true; j <= 'Z' && isMatch; j++){
            if(c_table[j][0] != c_table[j][1]){
                //printf("%c\n", j);
                isMatch = false;
            }
        }
        printf("%c", isMatch ? 'Y' : 'N');
    }
}
