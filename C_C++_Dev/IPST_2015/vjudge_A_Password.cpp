#include "stdio.h"
#include "string"
int i,k;
int prefix[1000005];
char s[1000005];
bool isH[1000005];
char tmp;
int main(){
    scanf(" %s", s);
    for(i = 1; s[i]; i++){
        while(k>0&&s[k]!=s[i]){
            k = prefix[k-1];
        }
        if(s[i]==s[k]) k++;
        prefix[i] = k;
        if(s[i+1]) isH[k] = true;
    }
    std::string str(s+1);
    for(;k>0;k=prefix[k-1]){
        if(isH[k]){
            s[k] = '\0';
            break;
        }
    }
    if(k>0) printf("%s\n",s);
    else printf("Just a legend\n");
}
