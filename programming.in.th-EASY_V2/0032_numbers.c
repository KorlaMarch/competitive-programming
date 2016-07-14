#include "stdio.h"
char t[1001];

void merge(char a[],char b[],int na,int nb){
    int i,j;
    for(i=j=0; i<na||j<nb;){
        if(i<na&&(j>=nb
                  ||a[i]<=b[j])) t[i+j] = a[i++];
        else t[i+j] = b[j++];
    }
}

void msort(char c[],int n){
    int i;
    if(n<=1) return;
    msort(c,n/2);
    msort(c+n/2,n-n/2);
    merge(c,c+n/2,n/2,n-n/2);
    for(i = 0; i < n; i++) c[i] = t[i];
}

int main(){
    int n,i,mp=0,m='9';
    char s[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf(" %c", &s[i]);
        if(s[i]<s[mp]&&s[i]!='0'){
            mp = i;
        }
    }
    printf("%c",s[mp]);
    s[mp] = s[--n];
    msort(s,n);
    s[n] = '\0';
    printf("%s\n",s);
}
