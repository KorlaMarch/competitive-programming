#include "stdio.h"
int a[1000],b[1000],c[1000],d[1000];
char s[1000];
int an,bn,cn,dn,i;
int toBignum(int a[], char s[]){
    int i,j;
    for(i = 0; s[i]; i++);
    for(i--,j=0; i>=0; i--,j++){
        a[j] = s[i]-'0';
    }
    return j;
}
void printN(int a[], int an){
    int i;
    for(i = an-1; i>=0; i--){
        putchar(a[i]+'0');
    }
    putchar('\n');
}
int muti(int a[], int an, int b[], int bn, int d[]){
    int i,j,k,dn;
    for(i = 0; i < an+bn+20; i++) d[i] = 0;
    for(i=0; i<an; i++){
        for(j=0; j<bn; j++){
            d[i+j] += a[i]*b[j];
        }
    }
    dn = an+bn-1;
    for(i=k=0; i<dn||k>0; i++){
        //printf("%d ",d[i]);
        d[i] += k;
        k = d[i]/10;
        d[i] %= 10;
        if(i==dn) dn++;
        //printf("D[%d] = %d %d\n",i,d[i],k);
    }
    return dn;
}
int main(){
    scanf(" %s", s);
    an = toBignum(a,s);
    scanf(" %s", s);
    bn = toBignum(b,s);
    scanf(" %s", s);
    cn = toBignum(c,s);
    dn = muti(a,an,b,bn,d);
    /*printN(a,an);
    printN(b,bn);
    printN(d,dn);*/
    if(cn!=dn){
        printf("dream\n");
    }else{
        for(i = 0; i < cn; i++){
            if(c[i]!=d[i]) break;
        }
        if(i==cn){
            printf("truth\n");
        }else{
            printf("dream\n");
        }
    }
}
