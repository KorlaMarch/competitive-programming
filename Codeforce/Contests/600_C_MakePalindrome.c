#include "stdio.h"

char s[2000050];
int i,j,lp;
int feq[27];
void repC(char c, int t){
    for(;t>0;t--) putchar(c);
}
int main(){
    scanf(" %[^\n]",s);
    for(i = 0; s[i]; i++){
        feq[s[i]-'a']++;
    }
    for(i=0,j=25,lp=-1; i < j;){
        //printf("FEQ %c = %d\n",'a'+i,feq[i]);
        if(feq[j]%2==0){
            j--;
        }else if(feq[i]%2==0){
            i++;
        }else{
            feq[j++]--;
            feq[i++]++;
        }
    }
    lp = i;
    for(i = 0; i < 26; i++) repC(i+'a',feq[i]/2);
    if(feq[lp]%2==1) putchar(lp+'a');
    for(i = 25; i >= 0; i--) repC(i+'a',feq[i]/2);
}
