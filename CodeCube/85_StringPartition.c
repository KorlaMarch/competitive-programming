#include "stdio.h"
#include "string.h"

char s[100020];
int prime[15000];
int feq[256];
int i,j,k,n,len,subl,ch,min,mx;

void clearA(){
    int i;
    for(i = 'a'; i <= 'z'; i++) feq[i] = 0;
}

int main(){
    for(i = 2; i < 100000; i++){
        if(!s[i]){
            prime[n++] = i;
            for(j = i; j < 100000; j += i) s[j] = 1;
        }
    }
    scanf(" %s",s);
    len = strlen(s);
    min = len;
    for(i = 0; i<n&&prime[i]<=len; i++){
        if(len%prime[i]==0){
            subl = len/prime[i];
            ch = 0;
            for(j = 0; j < subl; j++){
                clearA();
                for(k = 0; k < prime[i]; k++){
                    feq[s[subl*k+j]]++;
                }
                for(k = 'a',mx = 0; k <= 'z'; k++){
                    if(feq[k]>mx) mx = feq[k];
                }
                //printf("J: %d %d\n",j,mx);
                ch += prime[i]-mx;
            }
            //printf("%d %d ch=%d\n",len,subl,ch);
            if(ch<min) min = ch;
        }
    }
    printf("%d\n",min);
}

