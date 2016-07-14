#include "stdio.h"

int strlen(char s[]){
    int i;
    for(i = 0; s[i]; i++);
    return i;
}

void reverse(char s[]){
    int i,len = strlen(s);
    char c;
    for(i = 0; i<len-i-1; i++){
        c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
}
void add(char a[], char b[]){
    int i,j;
    for(i = 0; a[i]&&b[i]; i++){
        //printf("ADD %c %c\n",a[i],b[i]);
        a[i] = a[i]-'0'+b[i];
        if(a[i]>'9'){
            a[i] -= 10;
            for(j=i+1; ; j++){
                if(a[j]){
                    a[j]++;
                    if(a[j]>'9'){
                        a[j] -= 10;
                    }else{
                        break;
                    }
                }else{
                    a[j] = '1';
                    a[j+1] = '\0';
                    break;
                }
            }
        }
    }
    if(b[i]){
        for(;b[i];i++){
            a[i] = b[i];
        }
        a[i] = '\0';
    }
    /*reverse(a);
    reverse(b);
    printf("%s %s\n",a,b);
    reverse(a);
    reverse(b);*/
}
int scmp(char a[], char b[]){
    int la=strlen(a),lb=strlen(b),i;
    if(la>lb){
        return 1;
    }else if(lb>la){
        return -1;
    }else{
        for(i=la-1; i >= 0; i--){
            if(a[i]>b[i]){
                return 1;
            }else if(a[i]<b[i]){
                return -1;
            }
        }
    }
    return 0;
}

int main(){
    int i,c;
    char a[2][121];
    char fi[2][121];
    while(1){
        scanf(" %s %s", a[0], a[1]);
        if(a[0][0]=='0'&&a[1][0]=='0'&&a[0][1]=='\0'&&a[1][1]=='\0') break;
        reverse(a[0]);
        reverse(a[1]);
        //printf("%s\n", a[1]);
        fi[0][0] = '0';
        fi[1][0] = '1';
        fi[0][1] = fi[1][1] = '\0';
        for(i = 0; scmp(fi[i%2],a[0])==-1; i++){
            add(fi[i%2],fi[(i+1)%2]);
        }
        if(scmp(fi[i%2],a[1])==1){
            printf("0\n");
        }else{
            for(c = 1; scmp(fi[i%2],a[1])!=1; i++,c++){
                //printf("C:%d\n",c);
                add(fi[i%2],fi[(i+1)%2]);
            }
            printf("%d\n",c-1);
        }
    }
}
