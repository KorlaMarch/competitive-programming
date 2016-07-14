#include "stdio.h"
#include "string.h"

int f,n,n1,n2,i,j;
char c[2000],s[2000],s1[2000],s2[2000];

void printNum(char s[], int n){
    int i;
    for(i = n-1; i >= 0; i--){
        putchar('0'+s[i]);
    }
    putchar('\n');
}

int div2(char s[], int& n){
    int i,j,v;
    if(s[n-1]==1){
        j = 10;
        n--;
    }else j = 0;
    for(i = n-1; i >= 0; i--){
        v = (s[i]+j);
        s[i] = v/2;
        if(v%2){
            j = 10;
        }else j = 0;
    }
}

int plus1(char s[], int& n){
    int i;
    for(i = 0;; i++){
        s[i]++;
        if(i>=n) n++;
        if(s[i]>=10){
            s[i] = 0;
        }else break;
    }
}

void findUD(char s[], int n){
    if(s[0]%2){
        plus1(s,n);
        div2(s,n);
        if(s[0]%2) putchar('D');
        else putchar('U');
    }else{
        div2(s,n);
        findUD(s,n);
        return;
    }
}

int main(){
    scanf("%d %s",&f,c);
    n = n1 = n2 = strlen(c);
    for(i = n-1,j=0; i >= 0; i--,j++){
        s[j] = c[i]-'0';
        s1[j] = s2[j] = s[j];
    }
    plus1(s1,n1);
    plus1(s2,n2);
    plus1(s2,n2);
    findUD(s,n);
    findUD(s1,n1);
    findUD(s2,n2);
}
