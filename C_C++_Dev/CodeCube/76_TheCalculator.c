#include "stdio.h"
char a[20],b[20],c[20],d[20];
char s[20];
int tmp;
void toF(char s[], char d[]){
    int i,j;
    for(i = 0; s[i]!='.'; i++);
    for(j = i+1; s[j]; j++){
        d[j-i+2] = s[j]-'0';
    }
    for(j = i-1; j >= 0; j--){
        d[3-i-j] = s[j]-'0';
    }
}
/*void print(char s[]){
    int i;
    for(i = 0; i < 20; i++){
        putchar(s[i]+'0');
    }
    putchar('\n');
}*/
int main(){
    int i;
    scanf("%s",s);
    toF(s,a);
    scanf("%s",s);
    toF(s,b);
    scanf("%s",s);
    toF(s,c);
    /*print(a);
    print(b);
    print(c);*/
    for(i = 19,tmp=0; i >= 0; i--){
        d[i] = (a[i]+b[i]+tmp)%10;
        tmp = (a[i]+b[i]+tmp)/10;
    }
    //print(d);
    for(i = 0; i < 20; i++){
        if(c[i]!=d[i]) break;
    }
    if(i==20) printf("Correct\n");
    else printf("Wrong\n");
}
