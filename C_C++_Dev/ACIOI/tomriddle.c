#include "stdio.h"

int main(){
    int k,i,r,j;
    int a[26];
    char s[2001];
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        for(j = 0; j < 26; j++) a[j] = 0;
        scanf(" %[^\n]", s);
        for(j = 0; s[j]; j++){
            if(s[j]!=' ') a[(s[j]>='a'?s[j]-0x20:s[j])-'A']++;
        }
        scanf(" %[^\n]", s);
        for(j = 0; s[j]; j++){
            if(s[j]!=' ') a[(s[j]>='a'?s[j]-0x20:s[j])-'A']--;
        }
        for(j = 0,r=1; j < 26 && r; j++) if(a[j]) r = 0;
        printf("%c", r?'Y':'N');
    }
}
