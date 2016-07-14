#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "list"

struct node{
    bool isC;
    char c;
    std::list<std::pair<int,node>> v;
    node(char _c){
        isC = true;
        c = _c;
    }
    node(){
        isC = false;
        c = 0;
    }
};

bool checkN(node& a, node& b){
    if(a.v.size()!=b.v.size()||a.isC!=b.isC) return false;
    if(a.isC){
        if(a.c!=b.c) return false;
    }else for(auto it = a.v.begin(), it2 = b.v.begin(); it!=a.v.end()&&it2!=b.v.end(); it++, it2++){
        if(it->first!=it2->first||!checkN(it->second,it2->second)) return false;
    }
    return true;
}

void printN(node& a){
    if(a.isC) putchar(a.c);
    else for(auto it = a.v.begin(); it != a.v.end(); it++){
        if(it->first==1){
            printN(it->second);
        }else if(it->first==2&&it->second.isC){
            printN(it->second);
            printN(it->second);
        }else if(it->first==3&&it->second.isC){
            printN(it->second);
            printN(it->second);
            printN(it->second);
        }else{
            printf("%d(",it->first);
            printN(it->second);
            printf(")");
        }
    }
}

char s[105];
int len;
node mother;

int main(){
    scanf(" %s",s);
    for(len = 0; s[len]; len++){
        mother.v.push_back({1,node(s[len])});
    }
    for(int i = len; i >= 1; i--){
        for(auto it = mother.v.begin(); it != mother.v.end(); it++){
            auto it2 = it, it3 = it;
            for(j = 0; j < i && it != mother.v.begin(); it--,j++);

            for(it = mother.v.begin(); ; ++it){

            }
            if(it!=mother.v.begin()){
                auto tmp = it;
                tmp--;
                if(checkN(tmp->second,it->second)){
                    tmp->first += it->first;
                    mother.v.erase(it);
                    it = tmp;
                }
            }
        }
    }
    printN(mother);
}
