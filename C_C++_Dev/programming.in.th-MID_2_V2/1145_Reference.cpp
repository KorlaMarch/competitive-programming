#include "stdio.h"
#include "string"
#include "map"

int i,j,k,a;
char s[51];
const char *ans;
std::map<std::string,char> word;

int bitc(char c){
    int s = 0;
    if(c&1) s++;
    if(c&2) s++;
    if(c&4) s++;
    if(c&8) s++;
    return s;
}
void toLower(char s[]){
    int i;
    for(i = 0; s[i]; i++){
        if(s[i]<='Z') s[i] += 0x20;
    }
}
int main(){
    for(k = 0; k < 2; k++){
        scanf(" %s",s);
        toLower(s);
        for(i = 0; s[i]; i++){
            for(j = i; s[j]; j++){
                word[std::string(s+i,j-i+1)] |= (1<<k);
            }
        }
    }
    for(k = 2; k < 4; k++){
        scanf(" %s",s);
        toLower(s);
        for(i = 0; s[i]; i++){
            for(j = i; s[j]; j++){
                if(word.count(std::string(s+i,j-i+1))){
                    word[std::string(s+i,j-i+1)] |= (1<<k);
                }
            }
        }
    }
    a = 0;
    for(std::map<std::string,char>::iterator it = word.begin(); it != word.end(); ++it){
        if(bitc(it->second)>=3&&it->first.size()>a){
            a = it->first.size();
            ans = it->first.c_str();
        }
    }
    printf("%s\n",ans);
}
