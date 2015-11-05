#include "stdio.h"

char p[2000],e[3000];
char s[30][2000];
int ptr,i,j,k,isV;
void assign(){
    int d;
    for(;isV;i++){
        if(p[i]>='A'&&p[i]<='Z'){
            d=0;
            for(k=0;(e[j]>='0'&&e[j]<='9')||d>0||e[j]=='(';k++,j++){
                if(e[j]=='(') d++;
                else if(e[j]==')') d--;
                s[ptr][k] = e[j];
            }
            s[ptr][k] = '\0';
            ptr++;
        }else if(p[i]>='0'&&p[i]<='9'){
            for(;p[i]>='0'&&p[i]<='9';i++,j++){
                if(p[i]!=e[j]){
                    isV = 0;
                }
            }
            i--;
        }else if(p[i]==','){
            if(e[j]==',') j++;
            else{
                isV = 0;
            }
        }else if(p[i]=='('){
            if(e[j]=='('){
                i++;
                j++;
                assign();
                j++;
            }else{
                isV = 0;
            }
        }else if(p[i]==')'){
            return;
        }
    }
}
int main(){
    scanf(" %s %s",p,e);
    i=j=isV=1;
    assign();
    if(isV){
        for(i = 0; i < ptr; i++){
            printf("%s\n",s[i]);
        }
    }else printf("no\n");
}
