#include "stdio.h"
#include "string"
#include "iostream"
#include "list"

int n,i;
char c;
char s[12];
std::list<std::string*> text;
std::list<std::string*>::iterator it;
int main(){
    scanf("%d",&n);
    it = text.begin();
    for(i = 0; i < n; i++){
        scanf(" %c",&c);
        switch(c){
        case 'i':
            scanf(" %s",s);
            it = text.insert(it,new std::string(s));
            ++it;
            break;
        case 'r':
            if(it != text.end()){
                it++;
            }
            break;
        case 'l':
            if(it != text.begin()){
                it--;
            }
            break;
        case 'b':
            if(it != text.begin()){
                it--;
                it = text.erase(it);
            }
            break;
        case 'd':
            if(it != text.end()){
                it = text.erase(it);
            }
            break;
        }
    }
    for(it = text.begin(); it != text.end(); it++){
        std::cout << **it;
        putchar(' ');
    }
}
