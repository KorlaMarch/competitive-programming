#include "stdio.h"
#include "list"
#include "string"
#include "iostream"
char s[100005];
char tmp[100005];
std::list<std::string> a,b;
std::string str;
int i,j,n;
void pushS(char s[]){
    int i;
    for(i = 0; s[i]; i++){
        if(!(s[i]>='0'&&s[i]<='9')) break;
    }
    str = s;
    if(!s[i]&&(s[0]!='0'||s[1]=='\0')&&i){
        a.push_back(str);
    }else{
        b.push_back(str);
    }
}
int main(){
    scanf("%[^\n]",s);
    for(i=j=0;; i++){
        if(s[i]==';'||s[i]==','||s[i]=='\0'){
            tmp[j] = '\0';
            pushS(tmp);
            j = 0;
            if(s[i]=='\0') break;
        }else{
            tmp[j++] = s[i];
        }
    }

    if(!a.empty()){
        putchar('\"');
        std::cout << *a.begin();
        for(auto it = ++a.begin(); it != a.end(); ++it){
            putchar(',');
            std::cout << *it;
        }
        putchar('\"');
    }else printf("-");
    printf("\n");

    if(!b.empty()){
        putchar('\"');
        std::cout << *b.begin();
        for(auto it = ++b.begin(); it != b.end(); ++it){
            putchar(',');
            std::cout << *it;
        }
        putchar('\"');
    }else printf("-");
    printf("\n");
}
